#include "bsp.h"


uint8_t (*function_state)(void) = dry_state;


// 存储回调函数
CallbackFunction callback = NULL;

// 注册回调函数
void registerCallback(CallbackFunction cb) {
    callback = cb;
}

// 触发回调函数
void triggerCallback(uint8_t data) {
    if (callback != NULL) {
        callback(data); // 调用回调函数
    }
}


void bsp_init(void)
{
   EE_IIC_Init();
   buzzer_init();
   gpro_t.wifi_link_success =0;
   gpro_t.dry_open = open;
   gpro_t.plasma_open = open;
   gpro_t.mouse_open = open;

}





uint8_t wifi_state(void)
{
   if(gpro_t.wifi_link_success == 1){
       return 1;

   }
   else 
      return 0;

}

uint8_t dry_state(void)
{
   if(gpro_t.dry_open == 1){
      return 1;
   }
   else
     return 0;
}
uint8_t plasma_state(void)
{
    if(gpro_t.plasma_open == 1){
         return 1;
      }
      else
        return 0;


}
uint8_t mouse_state(void)
{
    if(gpro_t.mouse_open == 1){
      return 1;
   }
   else
     return 0;

}




void process_mainboard(void)
{
  

}



