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
#include "lvgl.h"
#include <stdio.h>

static void button1_event_cb(lv_event_t *e);
static void button2_event_cb(lv_event_t *e);




//LV_FONT_DECLARE(myFont24)
//LV_FONT_DECLARE(myFont14)
//LV_FONT_DECLARE(lv_font_montserrat_12)
LV_FONT_DECLARE(lv_font_montserrat_14)

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
    lv_obj_set_style_text_font(font_label,&lv_font_montserrat_14,LV_STATE_DEFAULT);
    lv_label_set_text(font_label, "hello world!!");

   // lv_obj_set_style_text_font(font_label,&myFont24,LV_STATE_DEFAULT);
   // lv_label_set_text(font_label, "你好 世界");
    //lv_obj_center(font_label);
    
    lv_obj_set_pos(font_label,100,0);
    

}


void lv_display_button_init(void)
{
    lv_obj_t *screen = lv_scr_act(); //creat a display screen 
    
    //creat two buttons 
    lv_obj_t* btn1= lv_btn_create(screen);
    lv_obj_set_pos(btn1,100,50);
    lv_obj_set_size(btn1,100,50);
    lv_obj_t * label1= lv_label_create(btn1);
    lv_label_set_text(label1,"Button 1");

    //send button 
    lv_obj_t * btn2 = lv_btn_create(screen);
    lv_obj_set_pos(btn2,200,50);
    lv_obj_set_size(btn2,100,50);
    lv_obj_t* label2 = lv_label_create(btn2);
    lv_label_set_text(label2,"Button 2");
    
    
    //set be preseed button of event with callback function.
    lv_obj_add_event_cb(btn1,button1_event_cb,LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(btn2,button2_event_cb,LV_EVENT_ALL,NULL);


}



static void button1_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn = lv_event_get_target(e);

    if(code==LV_EVENT_PREPROCESS){

       lv_obj_add_state(btn,LV_STATE_PRESSED);
    }
    else if(code ==LV_EVENT_RELEASED){
       lv_obj_clear_state(btn,LV_STATE_PRESSED);

    }

}

static void button2_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* btn= lv_event_get_target(e);

    if(code == LV_EVENT_PREPROCESS){
        lv_obj_add_state(btn,LV_STATE_PRESSED);
     }
     else if(code == LV_EVENT_RELEASED){
        lv_obj_clear_state(btn,LV_STATE_PRESSED);
     }


}
