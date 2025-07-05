#include <stdio.h>
#include "buffered_input.h"

void selectorInputCallback(uint8_t joy, uint8_t key, uint8_t parm);


int main()
{
	buffered_init(selectorInputCallback);		// INIT
	
	
	while (1) { 
		//HALT;		//NEXT_FRAME;

		uint8_t joy = joyRead();				// Read from hardware to variable
		
		buffered_input(joy);					// update buffered handler for autorepeat
		
		update();
	}
	
	
	return 0;
}



// This callback is called automagically
void selectorInputCallback(uint8_t joy, uint8_t key, uint8_t parm)
{
	
	switch (key)
	{
		case JOY_UP:
			//CONIO_WriteString("UP    ");
			if (parm == BI_PRESSED && selectorPageCur > 0)
			{
				HALT;
				selectorSetCursor(selectorPageCur - 1);
			}
			break;
		
		case JOY_DOWN:
			//CONIO_WriteString("DOWN  ");
			if (parm == BI_PRESSED && (selectorPageCur < selectorPageEnd))
			{
				HALT;
				selectorSetCursor(selectorPageCur + 1);
			}
			break;
		
		case JOY_LEFT:
			//CONIO_WriteString("LEFT  ");
			if (parm == BI_PRESSED)
			{
				if (selectorPage > 0)
				{
					selectorPage--;
					selectorDrawPage(selectorPageCur);
				}
				else if (selectorPageCur > 0)
				{
					HALT;
					selectorSetCursor(0);
				}
			}
			
			break;
			
		case JOY_RIGHT:
			//CONIO_WriteString("RIGHT ");
			if (parm == BI_PRESSED)
			{
				if (selectorPage < (selectorPages - 1))
				{
					selectorPage++;
					selectorDrawPage(selectorPageCur);
				}
				else if (selectorPageCur < selectorPageEnd)
				{
					HALT;
					selectorSetCursor(selectorPageEnd);
				}
			}
			break;

		case JOY_FIRE1:
			//CONIO_WriteString("FIRE1 ");
			if (parm == BI_PRESSED)
			{
				selectorClickItem();
			}
			break;

		case JOY_FIRE2:
			//CONIO_WriteString("FIRE2 ");
			if (parm == BI_PRESSED)
			{
				selectorParentFolder();
			}
			break;
	};
	
	// if (parm == BI_PRESSED)
	// CONIO_WriteString(" PRESSED  ");
	// else if (parm == BI_RELEASED)
	// CONIO_WriteString(" RELEASED ");
	// CONIO_SetCursor(1, 1);
	// CONIO_SetFontMode(CONIO_FONT_NORMAL | CONIO_FONT_CAPSLOCK);
	// CONIO_WriteByte(selectorPageCur);
	
}



