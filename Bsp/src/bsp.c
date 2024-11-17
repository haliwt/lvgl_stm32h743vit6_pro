#include "bsp.h"



void bsp_init(void)
{
   EE_IIC_Init();

}

void process_mainboard(void)
{
   readSensorGXHTC3_data();

}



