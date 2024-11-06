#ifndef __BSP_ST7789V_H
#define __BSP_ST7789V_H
#include "main.h"


//LCD屏幕分辨率定义
//横屏显示
#define TFT_Width   320//240
#define TFT_Height  240 //320
//颜色定义
#define WHITE   0xFFFF  //白色
#define YELLOW  0xFFE0  //黄色
#define BRRED   0XFC07  //棕红色
#define PINK    0XF81F  //粉色
#define RED     0xF800  //红色
#define BROWN   0XBC40  //棕色
#define GRAY    0X8430  //灰色
#define GBLUE   0X07FF  //兰色
#define GREEN   0x07E0  //绿色
#define BLUE    0x001F  //蓝色
#define BLACK   0x0000  //黑色




#define BACKLIGHT_Pin GPIO_PIN_0
#define BACKLIGHT_GPIO_Port GPIOB

#define CMD_DIP_Pin                         GPIO_PIN_1
#define CMD_DIP_GPIO_Port                   GPIOB

#define TFT_RESET_Pin                       GPIO_PIN_2
#define TFT_RESET_GPIO_Port                 GPIOB

#define CS_Pin    GPIO_PIN_12
#define CS_GPIO_Port GPIOB


extern uint8_t spi_tx_buffer[1];

#define TFT_BACKLIGHT_ON()     HAL_GPIO_WritePin(BACKLIGHT_GPIO_Port,BACKLIGHT_Pin,GPIO_PIN_RESET)
#define TFT_BACKLIGHT_OFF()     HAL_GPIO_WritePin(BACKLIGHT_GPIO_Port,BACKLIGHT_Pin,GPIO_PIN_SET)

#define TFT_DCX_CMD()         HAL_GPIO_WritePin(CMD_DIP_GPIO_Port,CMD_DIP_Pin,GPIO_PIN_RESET)  
#define TFT_DCX_DATA()        HAL_GPIO_WritePin(CMD_DIP_GPIO_Port,CMD_DIP_Pin,GPIO_PIN_SET)


#define LCD_RST_SetHigh()     HAL_GPIO_WritePin(TFT_RESET_GPIO_Port,TFT_RESET_Pin,GPIO_PIN_SET)
#define LCD_RST_SetLow()       HAL_GPIO_WritePin(TFT_RESET_GPIO_Port,TFT_RESET_Pin,GPIO_PIN_RESET)

#define LCD_NSS_SetHigh()      HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin ,GPIO_PIN_SET)
#define LCD_NSS_SetLow()      HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin ,GPIO_PIN_RESET)


void tft_gpio_init(void);


void TFT_LCD_Init(void);


void TFT_GPIO_Reset(void);
void LCD_Clear(uint16_t color);



void LCD_GPIO_Reset(void);



void LCD_Write_Cmd(uint8_t cmd);

void LCD_Write_Data(uint8_t data);

void LCD_Write_16bit_Data(uint16_t data);

void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);


void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);


void Frame(void);

void DISP_WINDOWS(void);

void DISPLAY_image(void);





#endif 

