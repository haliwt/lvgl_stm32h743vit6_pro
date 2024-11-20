#include "lv_bsp.h"

static lv_obj_t *btn1;
static lv_obj_t *btn2;
static lv_obj_t *btn3;
static lv_obj_t *btn4;

static void button_init(lv_ui *ui);

static void lv_port_indev_init(lv_ui *ui) ;


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

 static uint8_t key3_high_pressed,key3_low_pressed,key3_default= 0xff,key3_off_default=0xff;
 static uint8_t key4_high_pressed,key4_low_pressed,key4_default= 0xff,key4_off_default=0xff;
 static uint8_t key5_high_pressed,key5_low_pressed,key5_default= 0xff,key5_off_default=0xff;

  
 //KEY3-SELECT KEY 
  if(KEY3 == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY3==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
          
            if(key3_default != key3_high_pressed){
               key3_default= key3_high_pressed;
               key3_low_pressed++;
               gpro_t.gTimer_lv_disp_icon_hold=0;
               lv_gpro_t.lv_seletc_time++;
               lv_key_select_item(lv_gpro_t.lv_seletc_time,ui);
               gpro_t.gTimer_lv_disp_icon_hold=0;
               
            }
    }
   } 
   else{
       if(key3_off_default != key3_low_pressed){
              key3_off_default= key3_low_pressed;
              key3_high_pressed++;
     
        }
    }

   
   //key_up 
   if(KEY_UP == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(10);
        
   if(KEY_UP==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
         
    if(key4_default != key4_high_pressed){
        key4_default= key4_high_pressed;
        key4_low_pressed++;
        gpro_t.gTimer_lv_disp_icon_hold=0;
        

    }
        
    }
   }
   else{
     
       if(key4_off_default != key4_low_pressed){
              key4_off_default= key4_low_pressed;
              key4_high_pressed++;
      
        }
    }
   

    //key5 
   if(KEY_DOWN == GPIO_PIN_SET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(10);
        
   if(KEY_DOWN==GPIO_PIN_SET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
        
            if(key5_default != key5_high_pressed){
               key5_default= key5_high_pressed;
               key5_low_pressed++;
               gpro_t.gTimer_lv_disp_icon_hold=0;
             
           }
        } 
    }
   else{
       if(key5_off_default != key5_low_pressed){
              key5_off_default= key5_low_pressed;
              key5_high_pressed++;
      
        }
    }

}
   
   #if 0
    //key1 button 
   if(KEY1 == GPIO_PIN_RESET){ // 替换为实际的GPIO端口和引脚号
        // 检测到按键按下
        osDelay(20);
        
   if(KEY1==GPIO_PIN_RESET){ //if (HAL_GetTick() - last_debounce_time > debounce_delay) {
            //last_debounce_time = HAL_GetTick();
            // 改变按键颜色为红色
            //btn3= ui->scrHome_timerNumbers;
           // btn3 = lv_label_create(ui->scrHome);
           if(lv_gpro_t.adjustTimerValue_enable ==1){
           
               
                lv_gpro_t.adjustTimerValue++;
                if(lv_gpro_t.adjustTimerValue > 24)lv_gpro_t.adjustTimerValue=0;
                //lv_label_set_text(ui->scrHome_timerNumbers, "00:00");
                lv_label_set_text_fmt(ui->scrHome_timerHoursNumbers,"%02d",lv_gpro_t.adjustTimerValue);
                
                 lv_obj_set_pos(ui->scrHome_timerHoursNumbers, 51, 189);
                 lv_obj_set_size(ui->scrHome_timerHoursNumbers, 34, 13);

               
                
            }
    
   } 
   }

   #endif 

