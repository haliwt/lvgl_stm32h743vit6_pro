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
    lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);
    // 创建一个红色颜色滤镜
     ui->scrHome_wifiIcon = lv_img_create(ui->scrHome);
     lv_obj_add_flag(ui->scrHome_wifiIcon, LV_OBJ_FLAG_CLICKABLE);
     lv_img_set_src(ui->scrHome_wifiIcon, &_wifi_symbol_black_alpha_22x17);

     
         lv_obj_clear_flag(ui->scrHome_wifiIcon,LV_OBJ_FLAG_HIDDEN); //display wifi icon
         lv_obj_set_style_img_recolor(ui->scrHome_wifiIcon,lv_color_hex(0xFF0000),LV_PART_MAIN | LV_STATE_DEFAULT);
         lv_obj_set_style_img_recolor_opa(ui->scrHome_wifiIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
         lv_obj_set_pos(ui->scrHome_wifiIcon, 15, 10);

     
     lv_gpro_t.selectItem_add_numbers=wifi_item;

   break;

   case dry_item:
    lv_gpro_t.selectItem_enable = dry_item;
    lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);

     ui->scrHome_dryIcon = lv_img_create(ui->scrHome);
     lv_obj_add_flag(ui->scrHome_dryIcon, LV_OBJ_FLAG_CLICKABLE);
     lv_img_set_src(ui->scrHome_dryIcon, &_dry_black_2_alpha_22x17);
     
     lv_obj_set_style_img_recolor(ui->scrHome_dryIcon,lv_color_hex(0xFF0000),LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_img_recolor_opa(ui->scrHome_dryIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_pos(ui->scrHome_dryIcon, 48, 10);

      lv_gpro_t.selectItem_add_numbers=dry_item;

   break;

   case plasma_item:
    lv_gpro_t.selectItem_enable = plasma_item;
    lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);

    ui->scrHome_plasmaIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_plasmaIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_plasmaIcon, &_plasma_black_2_alpha_22x17);
    
    lv_obj_set_style_img_recolor(ui->scrHome_plasmaIcon,lv_color_hex(0xFF0000),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->scrHome_plasmaIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->scrHome_plasmaIcon, 81, 10);
   
    lv_gpro_t.selectItem_add_numbers=plasma_item;

   break;

   case mouse_item:
    lv_gpro_t.selectItem_enable = mouse_item;
    lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);

    ui->scrHome_mouseIcon = lv_img_create(ui->scrHome);
    lv_obj_add_flag(ui->scrHome_mouseIcon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrHome_mouseIcon, &_mouse_black_alpha_22x17);
    
    lv_obj_set_style_img_recolor(ui->scrHome_mouseIcon,lv_color_hex(0xFF0000),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->scrHome_mouseIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->scrHome_mouseIcon, 112, 10);
    
   lv_gpro_t.selectItem_add_numbers=mouse_item;

   break;


   case temp_item:
      lv_gpro_t.selectItem_enable = temp_item;
      lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);


      lv_obj_set_style_text_color(ui->scrHome_tempNumbers,lv_color_hex(0xFF0000), 0); //red color
       
       lv_gpro_t.selectItem_add_numbers=temp_item;


   break;


   case timer_item:

     lv_gpro_t.selectItem_enable = timer_item;
     lv_edit_select_item(lv_gpro_t.selectItem_enable,ui);

     lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0xFF0000), 0); //red color

     lv_gpro_t.selectItem_add_numbers=timer_item;

     lv_gpro_t.lv_seletc_time=0;


   break;

   default:

   break;


    }

   

}

/****************************************************************************************
*
*Function Name:static void lv_edit_select_item(uint8_t item,lv_ui* ui)
*Function:  only display edit lable image be selection color is red.   
*
*
****************************************************************************************/
static void lv_edit_select_item(uint8_t item,lv_ui* ui)
{

    switch(lv_gpro_t.selectItem_enable){
      case null_item:
    
      break;
    
      case wifi_item:
        
          //shut off display color red that timer timing defalult color is black
          lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0x000000), 0); //black color
       break;
    
       case dry_item:

           //shut off display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_wifiIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
    
       break;
    
       case plasma_item:
        
            //shut off DRY_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_dryIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
       
    
       break;
    
       case mouse_item:

           //shut off PLASMA_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_plasmaIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
    
       break;
    
    
       case temp_item:


            //shut off MOUSE_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_mouseIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
    
    
       break;
    
    
       case timer_item:
    
           //shut off tempNumbers display color red that default is color black.
            lv_obj_set_style_text_color(ui->scrHome_tempNumbers, lv_color_hex(0x000000), 0); //black color
    
    
       break;

       default:

       break;



}
}

/****************************************************************************************
*
*Function Name:static void lv_edit_select_item(uint8_t item,lv_ui* ui)
*Function:  only display edit lable image be selection color is red. 
*Input Ref:lv_ui
*Return Ref:NO
*
****************************************************************************************/
void check_select_icon_hidden(lv_ui* ui)
{

    static uint8_t changed_icon_default =0xff;

    if(gpro_t.gTimer_lv_disp_icon_hold > 3){

          gpro_t.gTimer_lv_disp_icon_hold=0;
          
    switch(lv_gpro_t.selectItem_add_numbers){

    
    case null_item:
     
    
    break;
    
      case wifi_item:
        
//          //shut off display color red that default is color black.
//           lv_obj_set_style_img_recolor(ui->scrHome_wifiIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
//            lv_obj_set_style_img_opa(ui->scrHome_wifiIcon,0, LV_PART_MAIN | LV_STATE_DEFAULT);
//            lv_obj_set_pos(ui->scrHome_wifiIcon, 15, 10);
          lv_gpro_t.selectItem_add_numbers= 0xfe;
       break;
    
       case dry_item:

            //shut off DRY_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_dryIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
            
          lv_gpro_t.selectItem_add_numbers= 0xff;
       break;
    
       case plasma_item:
        
          
           //shut off PLASMA_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_plasmaIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_gpro_t.selectItem_add_numbers= 0xff;
       break;
    
       case mouse_item:

            //shut off MOUSE_ICON display color red that default is color black.
           lv_obj_set_style_img_recolor(ui->scrHome_mouseIcon,lv_color_hex(0x000000),LV_PART_MAIN | LV_STATE_DEFAULT);
           lv_gpro_t.selectItem_add_numbers= 0xff;
       break;
    
    
       case temp_item:
            
         //shut off tempNumbers display color red that default is color black.
               lv_obj_set_style_text_color(ui->scrHome_tempNumbers, lv_color_hex(0x000000), 0); //black color

          
            lv_gpro_t.selectItem_add_numbers= 0xff;
    
       break;
    
    
       case timer_item:
    
            //shut off display color red that timer timing defalult color is black

           lv_obj_set_style_text_color(ui->scrHome_timerHoursNumbers, lv_color_hex(0x000000), 0); //black color
    
           lv_gpro_t.selectItem_add_numbers= 0xff;
         break;

         default:

         break;



        }
       

       }

}
