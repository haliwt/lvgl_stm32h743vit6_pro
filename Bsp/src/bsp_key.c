#include "bsp.h"

uint16_t  k1;
uint16_t  k2 ;
uint16_t  k3 ;
uint16_t cnt;

#if 1
/**
 * @brief       按键扫描函数
 * @note        该函数有响应优先级(同时按下多个按键): WK_UP > KEY2 > KEY1 > KEY0!!
 * @param       mode:0 / 1, 具体含义如下:
 *   @arg       0,  不支持连续按(当按键按下不放时, 只有第一次调用会返回键值,
 *                  必须松开以后, 再次按下才会返回其他键值)
 *   @arg       1,  支持连续按(当按键按下不放时, 每次调用该函数都会返回键值)
 * @retval      键值, 定义如下:
 *              KEY0_PRES, 1, KEY0按下
 *              KEY1_PRES, 2, KEY1按下
 *              KEY2_PRES, 3, KEY2按下
 *              WKUP_PRES, 4, WKUP按下
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;  /* 按键按松开标志 */
    uint8_t keyval = 0;

    if (mode) key_up = 1;       /* 支持连按 */

    if (key_up && (KEY_MODE == 0 || KEY_UP == 0 || KEY_DOWN==0))  /* 按键松开标志为1, 且有任意一个按键按下了 */
    {
        HAL_Delay(10);           /* 去抖动 */
        key_up = 0;

        if (KEY_MODE == 0)  keyval = KEY_MODE_PRES;

        if (KEY_UP == 0)  keyval = KEY_UP_PRES;

        if(KEY_DOWN==0)   keyval = KEY_DOWN;

       
    }
    else if (KEY_MODE == 1 && KEY_UP == 1 && KEY_DOWN==1)         /* 没有任何按键按下, 标记按键松开 */
    {
        key_up = 0;
    }

    return keyval;              /* 返回键值 */
}


#else 

uint8_t key_scan(uint8_t mode)
{
//    static uint16_t  k1=0 ;
//    static uint16_t  k2=0 ;
//    static uint16_t  k3 =0 ;
  //  static uint16_t cnt;
    uint8_t value;
   if(KEY_MODE ==0){
        cnt=0;
        k1++;   
   }
   else if(KEY_UP==0){
        cnt =0;
        k2++; 
       
   }
   else if(KEY_DOWN == 0){
      cnt = 0;
      k3++;

   }

   if(KEY_MODE==1 && KEY_UP==1 && KEY_DOWN ==1){ //key release loose 
        cnt++;   // 必须要有的参数，否则，一直有按键按下
        if(cnt<30) return 0; // cnt > 30,按键释放了。返回一个“0”
        
        cnt=0;
        if(k1 >1800 && k1< 2000){
            value = 0x01;
        }
//        else if(k1>300){
//            value = 0x11;
//        }
        else 
            value =0;
        
       if(k2 >1800 && k2< 2000){
            value = 0x02; //sort time pressed key 
        }
//        else if(k2>500){
//            value = 0x22; //long time pressed key 
//        }
        else 
            value =0;

       if(k3 > 1800 && k3< 2000){

            value = 0x03;

       }
       else
           value = 0;
        
       k1=0;
       k2=0;
       k3=0;
       return value ; 
    
    
    }
    return 0;
}

#endif 


