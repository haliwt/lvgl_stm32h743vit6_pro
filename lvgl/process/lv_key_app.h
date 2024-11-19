#ifndef __LV_KEY_APP_H
#define __LV_KEY_APP_H


#include "gui_guider.h"
#include "events_init.h"


#define LV_COLOR_RED     0xF800        



typedef enum _lv_select{

   null_item ,
   wifi_item,
   dry_item,
   plasma_item,
   mouse_item,
   temp_item,
   timer_item,

}lv_select_item;


void lv_key_select_item(uint8_t data,lv_ui* ui);



#endif 


