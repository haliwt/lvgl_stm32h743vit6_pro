#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H
#include "main.h"




void delay_init(uint16_t sysclk); /* 初始化延迟函数 */
void delay_ms(uint16_t nms);      /* 延时nms */
void delay_us(uint32_t nus);      /* 延时nus */




#endif 


