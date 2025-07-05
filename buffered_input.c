#include "buffered_input.h"

static uint8_t bi_counter = 0;
static uint8_t bi_count_f = 0;
static uint8_t bi_joy_old = 0;
static BufferedInputCallback bi_callback = 0;

void buffered_init(BufferedInputCallback callb)
{
	bi_counter = 0;
	bi_count_f = 0;
	bi_joy_old = 0;
	bi_callback = callb;
}

void buffered_do_counter()
{
	if (bi_count_f == 0)
	{
		bi_count_f = 1;
		bi_counter = BI_COUNTER_START;
	}
	else
	{
		bi_counter = BI_COUNTER_RUN;
	}
	
}


void buffered_do_callback(uint8_t joy, uint8_t key, uint8_t parm)
{
	if (bi_callback)
		bi_callback(joy, key, parm);
}

void buffered_input(uint8_t joy)
{

	if (joy == 0)
	{
		bi_counter = 0;
		bi_count_f = 0;
		
		if (bi_joy_old & JOY_UP)
		{
			buffered_do_callback(joy, JOY_UP, BI_RELEASED);
		}
		else if (bi_joy_old & JOY_DOWN)
		{
			buffered_do_callback(joy, JOY_DOWN, BI_RELEASED);
		}
		else if (bi_joy_old & JOY_LEFT)
		{
			buffered_do_callback(joy, JOY_LEFT, BI_RELEASED);
		}
		else if (bi_joy_old & JOY_RIGHT)
		{
			buffered_do_callback(joy, JOY_RIGHT, BI_RELEASED);
		}
		else if (bi_joy_old & JOY_FIRE1)
		{
			buffered_do_callback(joy, JOY_FIRE1, BI_RELEASED);
		}
		else if (bi_joy_old & JOY_FIRE2)
		{
			buffered_do_callback(joy, JOY_FIRE2, BI_RELEASED);
		}
	}
	else
	{
		if (joy & JOY_UP)
		{
			if (bi_counter > 0) 
				bi_counter--;

				
			if (bi_counter == 0)
			{
				buffered_do_callback(joy, JOY_UP, BI_PRESSED);

				buffered_do_counter();
			}
		}
		else if (joy & JOY_DOWN)
		{
			if (bi_counter > 0) 
				bi_counter--;

			if (bi_counter == 0)
			{
				buffered_do_callback(joy, JOY_DOWN, BI_PRESSED);

				buffered_do_counter();
			}
		}
		else if (joy & JOY_LEFT)
		{
			if (bi_counter > 0) 
				bi_counter--;

			if (bi_counter == 0)
			{
				buffered_do_callback(joy, JOY_LEFT, BI_PRESSED);

				buffered_do_counter();
			}
		}
		else if (joy & JOY_RIGHT)
		{
			if (bi_counter > 0) 
				bi_counter--;

			if (bi_counter == 0)
			{
				buffered_do_callback(joy, JOY_RIGHT, BI_PRESSED);

				buffered_do_counter();
			}
		}
		else if (joy & JOY_FIRE1)
		{
			if ((bi_joy_old & JOY_FIRE1) == 0) 
			{
				buffered_do_callback(joy, JOY_FIRE1, BI_PRESSED);
			}
		}
		else if (joy & JOY_FIRE2)
		{
			if ((bi_joy_old & JOY_FIRE2) == 0) 
			{
				buffered_do_callback(joy, JOY_FIRE2, BI_PRESSED);
			}
		}
		
		
	}
	
	
	bi_joy_old = joy;
}

