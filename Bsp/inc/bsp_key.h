#ifndef  __BSP_KEY_H
#define __BSP_KEY_H
#include "main.h"


/******************************************************************************************/
/* 引脚 定义 */

#define KEY1_GPIO_PORT                  GPIOC//GPIOE
#define KEY1_GPIO_PIN                   GPIO_PIN_5// GPIO_PIN_3
#define KEY0_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PH口时钟使能 *///  do{ __HAL_RCC_GPIOE_CLK_ENABLE(); }while(0)   /* PH口时钟使能 */

#define KEY2_GPIO_PORT                  GPIOE// GPIOC
#define KEY2_GPIO_PIN                   GPIO_PIN_3 //GPIO_PIN_5
#define KEY1_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOE_CLK_ENABLE(); }while(0)   /* PH口时钟使能 */  //do{ __HAL_RCC_GPIOC_CLK_ENABLE(); }while(0)   /* PH口时钟使能 */





/******************************************************************************************/

#define KEY1            HAL_GPIO_ReadPin(KEY1_GPIO_PORT, KEY1_GPIO_PIN)     /* 读取KEY1引脚 */
#define KEY2            HAL_GPIO_ReadPin(KEY2_GPIO_PORT, KEY2_GPIO_PIN)     /* 读取KEY2引脚 */
#define KEY_MODE        HAL_GPIO_ReadPin(KEY_3_GPIO_Port, KEY_3_Pin)     /* 读取KEY3引脚 */
#define KEY_UP          HAL_GPIO_ReadPin(KEY_4_GPIO_Port, KEY_4_Pin)     /* 读取KEY4引脚 */
#define KEY_DOWN        HAL_GPIO_ReadPin(KEY_5_GPIO_Port, KEY_5_Pin)     /* 读取WKUP引脚 */


#define KEY_MODE_PRES      1              /* KEY1按下 */
#define KEY_UP_PRES        2              /* KEY1按下 */
#define KEY_DOWN_PRES      3              /* KEY3按下 */
//#define WKUP_PRES    4              /* KEY_UP按下(即WK_UP) */

//void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(uint8_t mode);     /* 按键扫描函数 */








#endif 


