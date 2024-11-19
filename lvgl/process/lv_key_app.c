#include "lv_bsp.h"



static void lv_edit_select_item(uint8_t item,lv_ui* ui);

/****************************************************************************************
*
*Function Name:void lv_key_select_item(uint8_t select,lv_ui* ui)
*Function:     检查按键状态并更新按钮颜色
*
*
****************************************************************************************/
void lv_key_select_item(uint8_t select,lv_ui* ui)
{

  switch(select){


  case null_item:

  break;

  case wifi_item:

    lv_gpro_t.selectItem_enable = wifi_item;
    // 创建一个红色颜色滤镜
     ui->scrHome_wifiIcon = lv_img_create(ui->scrHome);
     lv_obj_add_flag(ui->scrHome_wifiIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_wifiIcon, &_wifi_symbol_black_alpha_22x17);
     lv_obj_set_style_img_recolor(ui->scrHome_wifiIcon,lv_color_hex(0xFF0000),LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_img_recolor_opa(ui->scrHome_wifiIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_pos(ui->scrHome_wifiIcon, 15, 10);
   

   break;

   case dry_item:
    lv_gpro_t.selectItem_enable = dry_item;

   break;

   case plasma_item:
    lv_gpro_t.selectItem_enable = plasma_item;

   break;

   case mouse_item:
    lv_gpro_t.selectItem_enable = mouse_item;

   break;


   case temp_item:
      lv_gpro_t.selectItem_enable = temp_item;


   break;


   case timer_item:

     lv_gpro_t.selectItem_enable = timer_item;

     lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0xFF0000), 0); //red color

     //shut off 
     lv_obj_set_style_img_recolor(ui->scrHome_wifiIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);

     lv_gpro_t.lv_seletc_time=0;


   break;


}




}




/****************************************************************************************
*
*Function Name:static void lv_edit_select_item(uint8_t item,lv_ui* ui)
*Function:  display    
*
*
****************************************************************************************/
static void lv_edit_select_item(uint8_t item,lv_ui* ui)
{

    switch(lv_gpro_t.selectItem_enable){
    case null_item:
    
      break;
    
      case wifi_item:
    
      
          lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0x000000), 0); //black color
       break;
    
       case dry_item:
    
       break;
    
       case plasma_item:
    
       break;
    
       case mouse_item:
    
       break;
    
    
       case temp_item:
    
    
       break;
    
    
       case timer_item:
    
        
    
    
       break;



}
}




