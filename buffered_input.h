#ifndef _BUFFERED_INPUT_DEFINED
#define _BUFFERED_INPUT_DEFINED

#ifdef __cplusplus
extern "C" {
#endif

//#include "main.h"
#include "core.h"

#define BI_PRESSED			0x00
#define BI_RELEASED			0x80

#define BI_COUNTER_START 	12
#define BI_COUNTER_RUN 		4

typedef void (*BufferedInputCallback)(uint8_t, uint8_t, uint8_t);

void buffered_init(BufferedInputCallback callb);
void buffered_input(uint8_t joy);


#ifdef __cplusplus
}
#endif

#endif // _BUFFERED_INPUT_DEFINED

