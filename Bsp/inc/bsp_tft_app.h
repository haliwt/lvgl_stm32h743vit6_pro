#ifndef __BSP_TFT_APP_H
#define __BSP_TFT_APP_H
#include "main.h"

void LCDF4_DrawHLine(uint16_t _usX, uint16_t _usY, uint16_t _usLen , uint16_t _usColor);

void LCDF4_DrawVLine(uint16_t _usX , uint16_t _usY , uint16_t _usLen , uint16_t _usColor);


void LCD_DrawLine(uint16_t _usX1 , uint16_t _usY1 , uint16_t _usX2 , uint16_t _usY2 , uint16_t _usColor);

void LCDF4_DrawRect(uint16_t _usX, uint16_t _usY, uint16_t _usHeight, uint16_t _usWidth, uint16_t _usColor);

void lcd_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);

void lcd_draw_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);


#endif 

