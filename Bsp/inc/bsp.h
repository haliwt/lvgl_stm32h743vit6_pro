#ifndef __BSP_H
#define __BSP_H
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#include "usart.h"
#include "i2c.h"
#include "tim.h"




#include "bsp_delay.h"
#include "bsp_st7789v.h"
#include "bsp_tft.h"
#include "bsp_tft_app.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_buzzer.h"
#include "bsp_freertos.h"
#include "bsp_i2c_app.h"
#include "bsp_gxhtc3.h"

#include "interrupt_manager.h"


#include "FreeRTOS.h"
#include "task.h"

#include "cmsis_os.h"

extern uint8_t (*function_state)(void);


typedef enum _state_open{

    close,
    open,


}state_open;


typedef struct _bsp_pro_t{


   char lv_disp_minutes_value[1];
   char lv_disp_hours_value[1];
   int8_t sensor_temp_value;
   uint8_t sensor_huimidity_value;
  
   uint8_t dry_open;
   uint8_t plasma_open;
   uint8_t mouse_open;

   uint8_t key_select_item_enable;

 
   //wifi ref:
   uint8_t wifi_link_led_fast;
   uint8_t wifi_link_success;
  
   //timer ref:
   uint8_t gTimer_lv_disp_time_colon;
   uint8_t gTimer_lv_disp_time; 
   uint8_t gTimer_lv_disp_icon_hold;
   uint8_t gTimer_lv_disp_wifi_colon ;



}bsp_pro_t;



extern bsp_pro_t gpro_t;

uint8_t wifi_state(void);
uint8_t dry_state(void);
uint8_t plasma_state(void);
uint8_t mouse_state(void);


// 回调函数类型
typedef void (*CallbackFunction)(uint8_t);

// 注册回调函数
void registerCallback(CallbackFunction callback);

// 触发回调函数
void triggerCallback(uint8_t data);

void bsp_init(void);


void process_mainboard(void);

#endif 


