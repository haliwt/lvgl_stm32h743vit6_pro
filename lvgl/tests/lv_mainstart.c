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



char lv_disp_time[2] ;

//static void button1_event_cb(lv_event_t *e);
////static void button1_event_cb(lv_obj_t * btn, lv_event_t event);
//
//static void button2_event_cb(lv_event_t *e);
//
//static void update_button_color(lv_obj_t* btn ,bool pressed);
//
//static void event_handler(lv_event_t * e);
//
//void lv_example_btn_1(void);
//
//static void update_button_color(lv_obj_t* btn, bool pressed);
//static void button1_read(lv_indev_drv_t * drv, lv_indev_data_t *data) ;
//
//static void button2_read(lv_indev_drv_t * drv, lv_indev_data_t *data) ;
//
//static void lv_example_btn_1(void) ;    



//LV_FONT_DECLARE(myFont24)
//LV_FONT_DECLARE(myFont14)
//LV_FONT_DECLARE(lv_font_montserrat_12)
//LV_FONT_DECLARE(lv_font_montserrat_14)

#if 0


// 全局变量定义
lv_obj_t* btn1; // 定义按钮 1
lv_obj_t* btn2; // 定义按钮 2

lv_obj_t *font_label;







/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{
  

    lv_obj_set_style_bg_color(lv_scr_act(),lv_palette_main(LV_PALETTE_BLUE),LV_STATE_DEFAULT);  /* 设置背景颜色 */
    font_label = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(font_label,&lv_font_montserrat_12,LV_STATE_DEFAULT);
    lv_label_set_text(font_label, "hello world!!");

   // lv_obj_set_style_text_font(font_label,&myFont24,LV_STATE_DEFAULT);
   // lv_label_set_text(font_label, "你好 世界");
    //lv_obj_center(font_label);
    
    lv_obj_set_pos(font_label,100,0);
    

}
#else 

#if 0

/*********************
 *  STATIC PROTOTYPES
 **********************/
static void button_init(void);
static void button1_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void button2_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

static int8_t button_get_pressed_id(void);
static uint8_t button_is_pressed(uint8_t id);
static void update_button_color(lv_obj_t* btn, bool pressed);
static void event1_handler(lv_event_t * e);

static void event2_handler(lv_event_t * e);


/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t *btn1;
static lv_obj_t *btn2;

uint8_t key1_pressed,key2_pressed;


lv_event_code_t code0 ;

/* Initialize input devices */
void lv_port_indev_init(void) 
{
   static lv_indev_drv_t indev_drv1;
   static lv_indev_drv_t indev_drv2;

   lv_indev_drv_init(&indev_drv1);
    indev_drv1.type = LV_INDEV_TYPE_BUTTON;
  //  indev_drv1.read_cb = button1_read; // Read callback for the first button

    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;
   // indev_drv2.read_cb = button2_read; // Read callback for the second button

     lv_indev_drv_register(&indev_drv1);
     lv_indev_drv_register(&indev_drv2);

    /* Create buttons */
    button_init();
}

/* Initialize your buttons */
static void button_init(void) {
    lv_obj_t *label;

    /* Create button 1 */
    btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1, event1_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button 1");
    lv_obj_center(label);

    /* Create button 2 */
    btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event2_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
}

/* Will be called by the library to read the button */
static void button1_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) 
{
    static uint8_t last_btn = 0,key1=0xff;

    /* Get the pressed button's ID */
   // int8_t btn_act = button_get_pressed_id();

    if(KEY1 == 0){//if(btn_act >= 0) {
      HAL_Delay(10);
      if(KEY1==0){
       // update_button_color(btn1, true);    // Change color of button 1
        key1_pressed++;
        
        data->state = LV_INDEV_STATE_PR;
        last_btn = 1;
        #if 0
       // code0 = LV_EVENT_PRESSED;
        if(key1_pressed==1){
           update_button_color(btn1, true);
        }
        else if(key1_pressed > 1){
             key1_pressed=0;


             update_button_color(btn1, false);   // Reset color of button 1 when released

        }
        #endif 
       lv_obj_set_style_bg_color(btn1, lv_color_hex(0xFF0000), 0);
     
    }
    }
    else{
        data->state = LV_INDEV_STATE_REL;
       
    }

    /* Save the last pressed button's ID */
    data->btn_id = last_btn;
}

static void button2_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
    static uint8_t last_btn = 0;

    /* Get the pressed button's ID */
  //  int8_t btn_act = button_get_pressed_id();

    if(KEY2 == 0){//if(btn_act >= 0) {
        
        HAL_Delay(10);//osDelay(20);
       if(KEY2==0){
     //   update_button_color(btn2, true);    // Change color of button 1
        key2_pressed ++;
        data->state = LV_INDEV_STATE_PR;
        last_btn = 1;
       }
    }else {
        data->state = LV_INDEV_STATE_REL;
       // update_button_color(btn2, false);   // Reset color of button 1 when released
    }

    /* Save the last pressed button's ID */
    data->btn_id = last_btn;
}


/* Get ID (0, 1, 2 ..) of the pressed button */


/* Update button color based on pressed state */
static void update_button_color(lv_obj_t* btn, bool pressed) {
    if(pressed) {
        lv_obj_set_style_bg_color(btn, lv_color_hex(0xff0000), 0); // Change to red
    } else {
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x00ff00), 0); // Change to green
    }
}

static void event1_handler(lv_event_t * e) {
      code0 = lv_event_get_code(e);
     //btn = lv_event_get_target(e); // 获取触发事件的按钮对象
    lv_obj_t *target = lv_event_get_target(e); // 获取触发源
    if(code0 == LV_EVENT_PRESSED) {
        LV_LOG_USER("Button 1 Pressed");
       // update_button_color(btn1, true);
        lv_obj_set_style_bg_color(target, lv_color_hex(0xff0000), 0); // 按下变为红色
    }
    else if(code0 == LV_EVENT_RELEASED) {
        LV_LOG_USER("Button 1 Released");
       // update_button_color(btn1, false);
        lv_obj_set_style_bg_color(target, lv_color_hex(0x00ff00), 0); // 释放变为绿色（或其他颜色）
    }
}


static void event2_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
   // lv_obj_t * btn = lv_event_get_target(e); // 获取触发事件的按钮对象
      lv_obj_t *target = lv_event_get_target(e); // 获取触发源
    if(code == LV_EVENT_PRESSED) {
        LV_LOG_USER("Button 1 Pressed");
       // update_button_color(btn2, true);

         lv_obj_set_style_bg_color(target, lv_color_hex(0xff0000), 0); // 按下变为红色
    
    }
    else if(code == LV_EVENT_RELEASED) {
        LV_LOG_USER("Button 1 Released");
       // update_button_color(btn2, false);
       lv_obj_set_style_bg_color(target, lv_color_hex(0x00ff00), 0); // 释放变为绿色（或其他颜色）
    }
}


// 检查按键状态并更新按钮颜色
void check_button_state(void) 
{
    ///static uint32_t last_debounce_time = 0;
    //uint32_t debounce_delay = 50; // 去抖动延迟，单位为毫秒

   

   //key2

   if(KEY2 == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY2==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
             key2_pressed++;
            lv_obj_set_style_bg_color(btn2, lv_color_hex(0xFF0000), 0); // 使用lv_color_hex设置颜色
    }
   } 
   else{
        if(key2_pressed > 0){
            key2_pressed=0;
        // 检测到按键释放
        lv_obj_set_style_bg_color(btn2, lv_color_hex(0x00ff00), 0); // 使用lv_color_hex设置颜色
        }
    }


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
   
}
#endif 

#endif 

uint8_t time_numbers_buffer[60]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a};

uint8_t min_value;


void update_works_time(lv_ui *ui)
{
  static uint8_t hour_value,power_on_first;


   lv_span_t span;
   span.txt = NULL;
   span.static_flag = 0;
   char text[4]; // 60个数字 * 3个字符（假设最大为两位数）+ 1个空字符

  if(power_on_first ==0){

      power_on_first++ ; 

    lv_label_set_text(ui->scrHome_hourNumbers, "00");
    lv_label_set_long_mode(ui->scrHome_hourNumbers, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrHome_hourNumbers, 9, 51);
    lv_obj_set_size(ui->scrHome_hourNumbers, 76, 46);
  
     lv_label_set_text(ui->scrHome_minuteNumbers, "00");
     //lv_style_set_text_font(&ui->scrHome_minuteNumbers_span->style, &lv_font_montserratMedium_50);
    lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
    lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);

  }


  
  if(gpro_t.gTimer_lv_disp_time > 59){
     gpro_t.gTimer_lv_disp_time =0;
     
        min_value++;
        char num_str[3]; // 3个字符 + 1个空字符
        snprintf(num_str, sizeof(num_str), "%02d", min_value); // 格式化数字为两位字符串
        strcat(text, num_str); // 将数字字符串追加到 text
        
        lv_label_set_text(ui->scrHome_minuteNumbers,text);
        lv_obj_set_pos(ui->scrHome_minuteNumbers, 94, 51);
        lv_obj_set_size(ui->scrHome_minuteNumbers, 72, 44);
     if(min_value > 59){//59 minutes 
          min_value =0;

          hour_value ++ ;
         
          char num_str[3]; // 3个字符 + 1个空字符
          snprintf(num_str, sizeof(num_str), "%02d", hour_value); // 格式化数字为两位字符串
          strcat(text, num_str); // 将数字字符串追加到 text
          
         lv_label_set_text(ui->scrHome_hourNumbers,text);
         lv_obj_set_pos(ui->scrHome_hourNumbers, 9, 51);
         lv_obj_set_size(ui->scrHome_hourNumbers, 76, 46);


      }


  }



  if(gpro_t.gTimer_lv_disp_time_colon <  1){

      
        lv_obj_clear_flag(ui->scrHome_timeColon, LV_OBJ_FLAG_HIDDEN); // 显示标签
   }
  else if(gpro_t.gTimer_lv_disp_time_colon > 0 && gpro_t.gTimer_lv_disp_time_colon < 2){
       gpro_t.gTimer_lv_disp_time_colon=0;

       lv_obj_add_flag(ui->scrHome_timeColon,LV_OBJ_FLAG_HIDDEN);

  }
   

}



