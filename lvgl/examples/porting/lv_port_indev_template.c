/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_indev_template.h"
#include "../../lvgl.h"
#include "bsp.h"
#include "lv_mainstart.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
#if 0
static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool touchpad_is_pressed(void);
static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);

static void mouse_init(void);
static void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static bool mouse_is_pressed(void);
static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y);

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);

static void encoder_init(void);
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static void encoder_handler(void);
#endif 

static void button_init(void);
static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static int8_t button_get_pressed_id(void);
static bool button_is_pressed(uint8_t id);
static void update_button_color(lv_obj_t* btn ,bool pressed);

static void event_handler(lv_event_t * e);


//static void button1_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
//static void button2_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

//static bool button1_pressed = false;
//static bool button2_pressed = false;

uint8_t current1_state;



/**********************
 *  STATIC VARIABLES
 **********************/
#if 0
lv_indev_t * indev_touchpad;
lv_indev_t * indev_mouse;
lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
#endif 
lv_indev_t * indev_button;


static lv_obj_t *btn1;
static lv_obj_t *btn2;



/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
#if 0
void lv_port_indev_init(void)
{

     static lv_indev_drv_t indev_drv1,indev_drv2;
    lv_obj_t * label;
  /*Initialize your button if you have*/
    button_init();

    /*Register a button input device*/
//    lv_indev_drv_init(&indev_drv);
//    indev_drv.type = LV_INDEV_TYPE_BUTTON;
//    indev_drv.read_cb = button_read;
//    indev_button = lv_indev_drv_register(&indev_drv);

     lv_indev_drv_init(&indev_drv1);
    indev_drv1.type = LV_INDEV_TYPE_BUTTON;
    indev_drv1.read_cb = button_read;

    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_BUTTON;
    indev_drv2.read_cb = button_read;




    
    lv_indev_t* indev_button1 = lv_indev_drv_register(&indev_drv1);
    lv_indev_t* indev_button2 = lv_indev_drv_register(&indev_drv2);

    /*Assign buttons to points on the screen*/
    // static const lv_point_t btn_points[2] = {
    //     {10, 10},   /*Button 0 -> x:10; y:10*/
    //     {40, 100},  /*Button 1 -> x:40; y:100*/
    // };
    // lv_indev_set_button_points(indev_button, btn_points);
    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
   

}  
#endif 


#if 0
/*------------------
 * Button
 * -----------------*/

/*Initialize your buttons*/
static void button_init(void)
{
    /*Your code comes here*/
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;
    
    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
        lv_obj_set_style_bg_color(btn1,lv_color_hex(0xff0000),0) ; //red color
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for(i = 0; i < 2; i++) {
        /*Return the pressed button's ID*/
        if(button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id)
{

    /*Your code comes here*/
    if(id ==0){
        if(KEY0==0)return 1;

    }
    else if(id ==1){

       if(KEY1==0) return 1;
    }

    return false;
}

#endif 

static void update_button_color(lv_obj_t* btn ,bool pressed)
{
    if(pressed){

        lv_obj_set_style_bg_color(btn,lv_color_hex(0xff0000),0) ; //red color
    
     }
     else{
      lv_obj_set_style_bg_color(btn,lv_color_hex(0x00ff00),0) ;  //green
     }


}


static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    //lv_obj_t*  btn = lv_event_get_user_data(e);
    lv_obj_t * btn = lv_event_get_target(e);     // 获取触发事件的按钮对象

    if(code == LV_EVENT_PRESSED){ //if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
        update_button_color(btn1,true);
       
    }
    else if(code == LV_EVENT_RELEASED){
       LV_LOG_USER("Toggle");
        update_button_color(btn1,false);


    }
   
}




#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
