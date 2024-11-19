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
#include "lv_bsp.h"

bsp_pro_t gpro_t;

uint8_t min_value;

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

           lv_obj_add_flag(ui->scrHome_timeColon,LV_OBJ_FLAG_HIDDEN); //hidden icon
           
       }


  }
  else{
    gpro_t.gTimer_lv_disp_time_colon=0;
  

  }
   

}

void update_wifi_blinkicon_fun(lv_ui* ui)
{
      
    static uint8_t wifi_symbol,wifi_not,wifi_disp_default=0xff,wifi_not_default=0xff;

    if(gpro_t.wifi_link_success ==0){

    if(gpro_t.gTimer_lv_disp_wifi_colon <  2){
    

         if(wifi_disp_default != wifi_symbol){
             
             wifi_disp_default = wifi_symbol;
             wifi_not++;
          
            lv_obj_clear_flag(ui->scrHome_wifiIcon,LV_OBJ_FLAG_HIDDEN); //display wifi icon
            
        }
   }
   else if(gpro_t.gTimer_lv_disp_wifi_colon  > 1 &&  gpro_t.gTimer_lv_disp_wifi_colon  < 4){

     if(wifi_not_default != wifi_not){
      
         wifi_not_default = wifi_not;
         wifi_symbol ++;
       

         lv_obj_add_flag(ui->scrHome_wifiIcon,LV_OBJ_FLAG_HIDDEN);//wifi icon hidden
        

       }
    }
    else{

        gpro_t.gTimer_lv_disp_wifi_colon =0;
         wifi_not++;
         wifi_symbol ++;
    }

  }
}



