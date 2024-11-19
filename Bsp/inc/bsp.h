#ifndef __BSP_H
#define __BSP_H
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#include "usart.h"
#include "i2c.h"




#include "bsp_delay.h"
#include "bsp_st7789v.h"
#include "bsp_tft.h"
#include "bsp_tft_app.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_freertos.h"
#include "bsp_i2c_app.h"
#include "bsp_gxhtc3.h"

#include "interrupt_manager.h"


#include "FreeRTOS.h"
#include "task.h"

#include "cmsis_os.h"




typedef struct _bsp_pro_t{


   char lv_disp_minutes_value[1];
   char lv_disp_hours_value[1];
   int8_t sensor_temp_value;
   uint8_t sensor_huimidity_value;

 
  



   uint8_t gTimer_lv_disp_time_colon;
   uint8_t gTimer_lv_disp_time; 



}bsp_pro_t;



extern bsp_pro_t gpro_t;
void bsp_init(void);


void process_mainboard(void);

#endif 


