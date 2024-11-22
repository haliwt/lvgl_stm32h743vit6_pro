#include "lv_bsp.h"

static lv_obj_t *btn1;
static lv_obj_t *btn2;
static lv_obj_t *btn3;
static lv_obj_t *btn4;

static void button_init(lv_ui *ui);

static void lv_port_indev_init(lv_ui *ui) ;
static void keySelectItem_doing(uint8_t select,lv_ui* ui);


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

   // lv_port_indev_init(ui) ;
   // button_init(ui);


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
   static lv_indev_drv_t indev_drv5;

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

    lv_indev_drv_init(&indev_drv5);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;

     lv_indev_drv_register(&indev_drv1);
     lv_indev_drv_register(&indev_drv2);
     lv_indev_drv_register(&indev_drv3);
     lv_indev_drv_register(&indev_drv4);
     lv_indev_drv_register(&indev_drv5);

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
   
    
    btn1= ui->scrHome_timerHoursNumbers; 
    btn2= ui->scrHome_timerHoursNumbers; 
    btn3= ui->scrHome_timerHoursNumbers;
   
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

      

    if(KEY_MODE==0){
          
         lv_gpro_t.lv_model_key =1;
          
       
      }
     else if(KEY_UP==0){

        lv_gpro_t.lv_up_key = 1;
       
     }
     else if(KEY_DOWN==0){
        
         lv_gpro_t.lv_down_key=1;
             
     
     }
  

}

void run_button_cmd(lv_ui* ui)
{
    if(KEY_MODE == 1 && lv_gpro_t.lv_model_key == 1){
               lv_gpro_t.lv_model_key++;


               buzzer_sound();      
              gpro_t.key_select_item_enable = 1;
              gpro_t.gTimer_lv_disp_icon_hold=0;
              lv_gpro_t.lv_seletc_time++;
              lv_key_select_item(lv_gpro_t.lv_seletc_time,ui);
              gpro_t.gTimer_lv_disp_icon_hold=0;
              


    }
    else if(KEY_UP == 1 && lv_gpro_t.lv_up_key == 1){

         lv_gpro_t.lv_up_key++;

             buzzer_sound();   
            gpro_t.gTimer_lv_disp_icon_hold=0;
            keySelectItem_doing(lv_gpro_t.lv_seletc_time,ui);

     }
    else if(KEY_DOWN == 1 && lv_gpro_t.lv_down_key == 1){

         lv_gpro_t.lv_down_key++;

             buzzer_sound();   
            gpro_t.gTimer_lv_disp_icon_hold=0;
            keySelectItem_doing(lv_gpro_t.lv_seletc_time,ui);

     }


}

/****************************************************************************************
*
*Function Name:static void keySelectItem_doning(uint8_t select,lv_ui* ui)
*Function:  key be selected item doing fun
*Inuput Ref: be selected item ,struct lv_ui of ref 
*Return Ref:
*
****************************************************************************************/
static void keySelectItem_doing(uint8_t select,lv_ui* ui)
{

    static uint8_t wifi_flag,dry_flag,plasma_flag,mouse_flag;
    switch(select){

    case null_item:


    break;

    case wifi_item: //link wifi doing ,wifi icon fast and fast blink .

         gpro_t.wifi_link_led_fast = 1;
        
    break;

    case dry_item:
        
           function_state= dry_state;
           dry_flag = function_state();
           if(dry_flag == open){
    
               gpro_t.dry_open = close;
               ui->scrHome_dryIcon= lv_img_create(ui->scrHome);
               lv_img_set_src(ui->scrHome_dryIcon,NULL);
               lv_obj_set_pos(ui->scrHome_dryIcon, 48, 10);
               lv_obj_add_flag(ui->scrHome_dryIcon,LV_OBJ_FLAG_HIDDEN);
               
              
               lv_obj_invalidate(ui->scrHome);
               osDelay(2000);

             
            }
            else{
    
               gpro_t.dry_open = open;
               //lv_obj_clear_flag(ui->scrHome_dryIcon,LV_OBJ_FLAG_HIDDEN);
               
               //lv_obj_set_style_opa(ui->scrHome_dryIcon,LV_OPA_COVER,0);
              /// lv_obj_set_style_img_recolor_opa(ui->scrHome_dryIcon,255,LV_PART_MAIN | LV_STATE_DEFAULT);
               //lv_obj_clear_flag(ui->scrHome_dryIcon,LV_OBJ_FLAG_HIDDEN);
               // lv_obj_add_flag(ui->scrHome_dryIcon,LV_OBJ_FLAG_HIDDEN);
            }

    break;


    case plasma_item:


    break;


    case mouse_item:


    break;


    case temp_item:


    break;


    case timer_item:


    break;

    case month_item:

    break;

    case day_item:

    break;

    case week_item:


    break;

    default:

    break;





    }


}


