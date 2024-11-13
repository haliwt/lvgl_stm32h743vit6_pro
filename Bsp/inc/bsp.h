#ifndef __BSP_H
#define __BSP_H
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#include "usart.h"

#include "bsp_st7789v.h"
#include "bsp_tft.h"
#include "bsp_tft_app.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_freertos.h"
#include "interrupt_manager.h"



typedef struct _bsp_pro_t{

   uint8_t gTimer_lv_disp_time; 



}bsp_pro_t;



extern bsp_pro_t gpro_t;


#endif 


