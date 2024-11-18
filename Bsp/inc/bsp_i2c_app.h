#ifndef __BSP_I2C_APP_H
#define __BSP_I2C_APP_H
#include "main.h"


#define GXHTC3_ADDR_W     0xE0
#define GXHTC3_ADDR_R     0xE1

#define GXHTC3_MEASURE_HIGH_CMD      0x5C

#define GXHTC3_MEASURE_LOW_CMD       0x24


void EE_IIC_Init(void);





void gxhtc3_read_ee_i2c_data(void);




#endif 



