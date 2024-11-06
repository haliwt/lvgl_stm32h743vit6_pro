#ifndef __BSP_TFT_H
#define __BSP_TFT_H
#include "main.h"

/* 定义颜色像素格式,一般用RGB565 */
#define LTDC_PIXEL_FORMAT_RGB565          0x00000002U   /*!< RGB565 LTDC pixel format   */
#define LTDC_PIXFORMAT           LTDC_PIXEL_FORMAT_RGB565


/* LCD LTDC重要参数集 */
typedef struct  
{
    uint32_t pwidth;      /* LTDC面板的宽度,固定参数,不随显示方向改变,如果为0,说明没有任何RGB屏接入 */
    uint32_t pheight;     /* LTDC面板的高度,固定参数,不随显示方向改变 */
    uint16_t hsw;         /* 水平同步宽度 */
    uint16_t vsw;         /* 垂直同步宽度 */
    uint16_t hbp;         /* 水平后廊 */
    uint16_t vbp;         /* 垂直后廊 */
    uint16_t hfp;         /* 水平前廊 */
    uint16_t vfp;         /* 垂直前廊  */
    uint8_t activelayer;  /* 当前层编号:0/1 */
    uint8_t dir;          /* 0,竖屏;1,横屏; */
    uint16_t width;       /* LTDC宽度 */
    uint16_t height;      /* LTDC高度 */
    uint32_t pixsize;     /* 每个像素所占字节数 */
}_ltdc_dev; 

/* LCD????? */
typedef struct
{
    uint16_t width;                 /* LCD ?? */
    uint16_t height;                /* LCD ?? */
    uint16_t id;                    /* LCD ID */
    uint8_t dir;                    /* ????????:0,??;1,??? */
    uint16_t wramcmd;               /* ???gram?? */
    uint16_t setxcmd;               /* ??x???? */
    uint16_t setycmd;               /* ??y???? */
} _lcd_dev;

void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color);


void TFT_Disp_Red_Color(uint8_t mode);

void tft_display_handler(void);

void lcd_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color);

void LCD_DrawPoint(uint8_t x,uint8_t y, uint16_t Color);

void LCD_SetBackground(uint16_t Color);

//void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);

#endif 


