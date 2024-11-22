#ifndef __LV_BSP_H
#define __LV_BSP_H


#include "main.h"
#include "bsp.h"

#include "lv_mainstart.h"
#include <stdio.h>
#include <time.h>

#include "lv_port_indev_template.h"
#include "lvgl.h"

#include "gui_guider.h"
#include "events_init.h"


#include "lv_i2c.h"
#include "lv_key.h"
#include "lv_key_app.h"


typedef struct _lv_gpro{

    

   uint8_t lv_seletc_time;
   uint8_t lv_model_key;
   uint8_t lv_up_key;
   uint8_t lv_down_key;

   uint8_t selectItem_add_numbers;

   uint8_t adjustTimerValue_enable;
   uint8_t adjustTempValue;
   int8_t adjustTimerValue;


}lv_gpro;


extern lv_gpro lv_gpro_t;




void lv_action_select_time(lv_ui* ui);




#endif 


