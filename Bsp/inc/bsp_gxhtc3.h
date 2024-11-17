#ifndef __BSP_GXHTC3_H
#define __BSP_GXHTC3_H
#include "main.h"


#define GX_ADDR_W     0xE0
#define GX_ADDR_R     0xE1

//#define GX_WK_UP    0x3517

extern uint8_t i2c_read_data[5];

void readSensorGXHTC3_data(void);


#endif 

