#include "bsp.h"

#include "FreeRTOS.h"
#include "task.h"



#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lvgl.h"
#include "lv_mainstart.h"
#include "gui_guider.h"
#include "events_init.h"
#include "lv_bsp.h"



/*
**********************************************************************************************************
											宏定义
**********************************************************************************************************
*/
#define BIT_0	(1 << 0)
#define BIT_1	(1 << 1)

/*
**********************************************************************************************************
											函数声明
**********************************************************************************************************
*/

static void vTaskMsgPro(void *pvParameters);
static void vTaskStart(void *pvParameters);
static void AppTaskCreate (void);


/*
**********************************************************************************************************
											变量声明
**********************************************************************************************************
*/

static TaskHandle_t xHandleTaskMsgPro = NULL;
static TaskHandle_t xHandleTaskStart = NULL;


void freeRTOS_handler(void)
{

 
     /* 创建任务 */
     AppTaskCreate();
        
    /* 启动调度，开始执行任务 */
    vTaskStartScheduler();

}

/*
*********************************************************************************************************
*	函 数 名: vTaskMsgPro
*	功能说明: 使用函数xTaskNotifyWait接收任务vTaskTaskUserIF发送的事件标志位设置
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 3  
*********************************************************************************************************
*/
static void vTaskMsgPro(void *pvParameters)
{
   
    while(1)
    {
	    lv_timer_handler();
        update_works_time(&guider_ui);
        check_button_state(&guider_ui);
        
        check_select_icon_hidden(&guider_ui);
       
     //   update_wifi_blinkicon_fun(&guider_ui);
        vTaskDelay(5);
      
		
    }
}

/*
*********************************************************************************************************
*	函 数 名: vTaskStart
*	功能说明: 启动任务，也就是最高优先级任务，这里用作按键扫描。
*	形    参: pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*   优 先 级: 4  
*********************************************************************************************************
*/
static void vTaskStart(void *pvParameters)
{
   // uint8_t keyvalue;
    while(1)
    {

	  LED0_TOGGLE();
      
      lv_dispTempHumidity_value(&guider_ui);

      // update_wifi_blinkicon_fun(&guider_ui);
    
      vTaskDelay(1000);
    }
}



/*
*********************************************************************************************************
*	函 数 名: AppTaskCreate
*	功能说明: 创建应用任务
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void AppTaskCreate (void)
{

	
	
	xTaskCreate( vTaskMsgPro,     		/* 任务函数  */
                 "vTaskMsgPro",   		/* 任务名    */
                 1024,             		/* 任务栈大小，单位word，也就是4字节 */
                 NULL,           		/* 任务参数  */
                 1,               		/* 任务优先级*/
                 &xHandleTaskMsgPro );  /* 任务句柄  */
	
	
	xTaskCreate( vTaskStart,     		/* 任务函数  */
                 "vTaskStart",   		/* 任务名    */
                 128,            		/* 任务栈大小，单位word，也就是4字节 */
                 NULL,           		/* 任务参数  */
                 2,              		/* 任务优先级*/
                 &xHandleTaskStart );   /* 任务句柄  */
}


