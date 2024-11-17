/**
 ****************************************************************************************************
 * @file        lv_mainstart.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-03-23
 * @brief       LVGL 内部字库 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 阿波罗 H743开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */
 
#include "lv_mainstart.h"
#include <stdio.h>
#include <time.h>

#include "lv_port_indev_template.h"
#include "lvgl.h"

#include "bsp.h"
#include "gui_guider.h"
#include "events_init.h"

bsp_pro_t gpro_t;


static void button_init(lv_ui *ui);


static void lv_port_indev_init(lv_ui *ui) ;




char lv_disp_time[2] ;






static lv_obj_t *btn1;
static lv_obj_t *btn2;
static lv_obj_t *btn3;
static lv_obj_t *btn4;


uint8_t min_value;

/****************************************************************************************
*
*Function Name:void lv_hardware_init(lv_ui *ui)
*Function:     
*Input Ref:lv_ui 
*Return Ref:NO
*
****************************************************************************************/
void lv_hardware_init(lv_ui* ui)
{

    lv_port_indev_init(ui) ;
    button_init(ui);


}


/****************************************************************************************
*
*Function Name:void check_button_state(void) 
*Function:     
*Input Ref:lv_ui 
*Return Ref:NO
*
****************************************************************************************/
void update_works_time(lv_ui *ui)
{
  static uint8_t hour_value,power_on_first;
  static uint8_t time_colon_symbol,time_colon_not,timeColon_disp_default=0xff,timeColon_not_default=0xff;

   lv_span_t span;
   span.txt = NULL;
   span.static_flag = 0;
  // uint8_t minute_text[3],hour_text[3]; // 60个数字 * 3个字符（假设最大为两位数）+ 1个空字符
   
  if(power_on_first ==0){

      power_on_first++ ; 

    //lv_label_set_text(ui->scrHome_hourNumbers, "00");
    //lv_label_set_long_mode(ui->scrHome_hourNumbers, LV_LABEL_LONG_WRAP);
    lv_label_set_text_fmt(ui->scrHome_hourNumbers,"%02d",0x00);
    lv_obj_set_pos(ui->scrHome_hourNumbers, 9, 51);
    lv_obj_set_size(ui->scrHome_hourNumbers, 76, 46);
  
    // lv_label_set_text(ui->scrHome_minuteNumbers, "00");
    lv_label_set_text_fmt(ui->scrHome_minuteNumbers,"%02d",0x00);
    lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
    lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);

  }


  
  if(gpro_t.gTimer_lv_disp_time > 59){
     gpro_t.gTimer_lv_disp_time =0;
     
        min_value++;
//        char num_str[3]; // 3个字符 + 1个空字符
//        snprintf(num_str, sizeof(num_str), "%02d", min_value); // 格式化数字为两位字符串
//        strcat(text, num_str); // 将数字字符串追加到 text
     //   sprintf(text,"%02d",min_value);
       // lv_label_set_text(ui->scrHome_minuteNumbers,text);
     if(min_value < 60){
        lv_label_set_text_fmt(ui->scrHome_minuteNumbers,"%02d",min_value);
        lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
        lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);
     }
     else if(min_value > 59){//59 minutes 
          min_value =0;

          lv_label_set_text_fmt(ui->scrHome_minuteNumbers,"%02d",min_value);
          lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
          lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);

          hour_value ++ ;
         #if 0
          char num_str[3]; // 3个字符 + 1个空字符
          snprintf(num_str, sizeof(num_str), "%02d", hour_value); // 格式化数字为两位字符串
          strcat(text, num_str); // 将数字字符串追加到 text
           lv_label_set_text(ui->scrHome_hourNumbers,text);
         #endif 
         if(hour_value > 23)hour_value=0;
         lv_label_set_text_fmt(ui->scrHome_hourNumbers,"%02d",hour_value);
        
         lv_obj_set_pos(ui->scrHome_hourNumbers, 9, 51);
         lv_obj_set_size(ui->scrHome_hourNumbers, 76, 46);


      }


  }



  if(gpro_t.gTimer_lv_disp_time_colon <  1){

      if(timeColon_disp_default != time_colon_symbol){
        timeColon_disp_default = time_colon_symbol;
        time_colon_not++;
        lv_obj_clear_flag(ui->scrHome_timeColon, LV_OBJ_FLAG_HIDDEN); // 显示标签

       }
   }
  else if(gpro_t.gTimer_lv_disp_time_colon > 0 && gpro_t.gTimer_lv_disp_time_colon < 2){
      
       
       if(timeColon_not_default != time_colon_not){
               timeColon_not_default = time_colon_not;
               time_colon_symbol++;

           lv_obj_add_flag(ui->scrHome_timeColon,LV_OBJ_FLAG_HIDDEN);
       }

  }
  else{
    gpro_t.gTimer_lv_disp_time_colon=0;


  }
   

}





/****************************************************************************************
*
*Function Name:static void lv_port_indev_init(lv_ui *ui)
*Function:     
*Input Ref:lv_ui 
*Return Ref:NO
*
****************************************************************************************/
static void lv_port_indev_init(lv_ui *ui) 
{
   static lv_indev_drv_t indev_drv1;
   static lv_indev_drv_t indev_drv2;
   static lv_indev_drv_t indev_drv3;
   static lv_indev_drv_t indev_drv4;

   lv_indev_drv_init(&indev_drv1);
    indev_drv1.type = LV_INDEV_TYPE_BUTTON;
  //  indev_drv1.read_cb = button1_read; // Read callback for the first button

    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;
   // indev_drv2.read_cb = button2_read; // Read callback for the second button

   lv_indev_drv_init(&indev_drv3);
   indev_drv2.type = LV_INDEV_TYPE_BUTTON;

    lv_indev_drv_init(&indev_drv4);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;

     lv_indev_drv_register(&indev_drv1);
     lv_indev_drv_register(&indev_drv2);
     lv_indev_drv_register(&indev_drv3);
     lv_indev_drv_register(&indev_drv4);

    /* Create buttons */
}
/****************************************************************************************
*
*Function Name:void check_button_state(void) 
*Function:     检查按键状态并更新按钮颜色
*Input Ref:
*Return Ref:
*
****************************************************************************************/
static void button_init(lv_ui *ui) 
{
    lv_obj_t *label;
    #if 0
    /* Create button 1 */
    btn1 = lv_btn_create(lv_scr_act());
    //lv_obj_add_event_cb(btn1, event1_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button 1");
    lv_obj_center(label);

    /* Create button 2 */
    btn2 = lv_btn_create(lv_scr_act());
    //lv_obj_add_event_cb(btn2, event2_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
    #endif 
    /* Create button 2 */
    
    btn3= ui->scrHome_timerHoursNumbers;
    btn1= ui->scrHome_timerHoursNumbers; 
    btn2= ui->scrHome_timerHoursNumbers; 
    #if 0
    btn3 = lv_label_create(ui->scrHome);
    lv_label_set_text(ui->scrHome_timerNumbers, "00:00");
    lv_label_set_long_mode(ui->scrHome_timerNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_timerNumbers, 44, 189);
    lv_obj_set_size(ui->scrHome_timerNumbers, 93, 17);
    #endif 
   
}


/****************************************************************************************
*
*Function Name:void check_button_state(void) 
*Function:     检查按键状态并更新按钮颜色
*
*
****************************************************************************************/
void check_button_state(lv_ui *ui) 
{

 static uint8_t key3_high_pressed,key3_low_pressed,key3_default= 0xff,key3_off_default=0xff;
 static uint8_t key4_high_pressed,key4_low_pressed,key4_default= 0xff,key4_off_default=0xff;
   

  

  if(KEY3 == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY3==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
            //btn3= ui->scrHome_timerNumbers;
           // btn3 = lv_label_create(ui->scrHome);
            if(key3_default != key3_high_pressed){
               key3_default= key3_high_pressed;
               key3_low_pressed++;
               gpro_t.adjustTimerValue_enable = 1;
               lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0xFF0000), 0); //red color
            }
    }
   } 
   else{
      //btn3= ui->scrHome_timerNumbers;
      ///btn3 = lv_label_create(ui->scrHome);
       if(key3_off_default != key3_low_pressed){
              key3_off_default= key3_low_pressed;
              key3_high_pressed++;
        // 检测到按键释放
        //lv_obj_set_style_bg_color(btn3, lv_color_hex(0x00ff00), 0); // 使用lv_color_hex设置颜色
              gpro_t.adjustTimerValue_enable = 0;
              lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0x000000), 0); //black color
        }
    }
   //key4 
   if(KEY4 == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY4==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
            //btn3= ui->scrHome_timerNumbers;
           // btn3 = lv_label_create(ui->scrHome);
            if(key4_default != key4_high_pressed){
               key4_default= key4_high_pressed;
               key4_low_pressed++;
              if(gpro_t.adjustTimerValue_enable ==1){
                gpro_t.adjustTimerValue++;
                if(gpro_t.adjustTimerValue > 24)gpro_t.adjustTimerValue=0;
                //lv_label_set_text(ui->scrHome_timerNumbers, "00:00");
                lv_label_set_text_fmt(ui->scrHome_timerHoursNumbers,"%02d",gpro_t.adjustTimerValue);
                
                 lv_obj_set_pos(ui->scrHome_timerHoursNumbers, 51, 189);
                 lv_obj_set_size(ui->scrHome_timerHoursNumbers, 34, 13);
              
             }
           }
        } 
    }
   else{
      //btn3= ui->scrHome_timerNumbers;
      ///btn3 = lv_label_create(ui->scrHome);
       if(key4_off_default != key4_low_pressed){
              key4_off_default= key4_low_pressed;
              key4_high_pressed++;
      
        }
    }

  

   

  //key1 button 
   if(KEY1 == GPIO_PIN_RESET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY1==GPIO_PIN_RESET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
            //btn3= ui->scrHome_timerNumbers;
           // btn3 = lv_label_create(ui->scrHome);
           if(gpro_t.adjustTimerValue_enable ==1){
           
               
                gpro_t.adjustTimerValue++;
                if(gpro_t.adjustTimerValue > 24)gpro_t.adjustTimerValue=0;
                //lv_label_set_text(ui->scrHome_timerNumbers, "00:00");
                lv_label_set_text_fmt(ui->scrHome_timerHoursNumbers,"%02d",gpro_t.adjustTimerValue);
                
                 lv_obj_set_pos(ui->scrHome_timerHoursNumbers, 51, 189);
                 lv_obj_set_size(ui->scrHome_timerHoursNumbers, 34, 13);

               
                
            }
    
   } 
   }


   //key1 button 
   if(KEY2 == GPIO_PIN_RESET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY2==GPIO_PIN_RESET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
            //btn3= ui->scrHome_timerNumbers;
           // btn3 = lv_label_create(ui->scrHome);
           if(gpro_t.adjustTimerValue_enable ==1){
           
               
                gpro_t.adjustTimerValue--;
                if(gpro_t.adjustTimerValue <  0)gpro_t.adjustTimerValue=24;
                //lv_label_set_text(ui->scrHome_timerNumbers, "00:00");
                lv_label_set_text_fmt(ui->scrHome_timerHoursNumbers,"%02d",gpro_t.adjustTimerValue);
               
                lv_obj_set_pos(ui->scrHome_timerHoursNumbers, 51, 189);
                lv_obj_set_size(ui->scrHome_timerHoursNumbers, 34, 13);

               
                
            }
    
   } 
   }


   

  #if 0
   // 读取按键状态
   if (KEY1 == GPIO_PIN_RESET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY1==GPIO_PIN_RESET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
             key1_pressed++;
            lv_obj_set_style_bg_color(btn1, lv_color_hex(0xFF0000), 0); // 使用lv_color_hex设置颜色
    }
   } 
   else if(KEY1==GPIO_PIN_SET){
        if(key1_pressed > 0){
            key1_pressed=0;
        // 检测到按键释放
        lv_obj_set_style_bg_color(btn1, lv_color_hex(0x00ff00), 0); // 使用lv_color_hex设置颜色
        }
    }
   #endif 
}


