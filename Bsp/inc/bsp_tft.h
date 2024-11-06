#ifndef __BSP_TFT_H
#define __BSP_TFT_H
#include "main.h"

/* ������ɫ���ظ�ʽ,һ����RGB565 */
#define LTDC_PIXEL_FORMAT_RGB565          0x00000002U   /*!< RGB565 LTDC pixel format   */
#define LTDC_PIXFORMAT           LTDC_PIXEL_FORMAT_RGB565


/* LCD LTDC��Ҫ������ */
typedef struct  
{
    uint32_t pwidth;      /* LTDC���Ŀ��,�̶�����,������ʾ����ı�,���Ϊ0,˵��û���κ�RGB������ */
    uint32_t pheight;     /* LTDC���ĸ߶�,�̶�����,������ʾ����ı� */
    uint16_t hsw;         /* ˮƽͬ����� */
    uint16_t vsw;         /* ��ֱͬ����� */
    uint16_t hbp;         /* ˮƽ���� */
    uint16_t vbp;         /* ��ֱ���� */
    uint16_t hfp;         /* ˮƽǰ�� */
    uint16_t vfp;         /* ��ֱǰ��  */
    uint8_t activelayer;  /* ��ǰ����:0/1 */
    uint8_t dir;          /* 0,����;1,����; */
    uint16_t width;       /* LTDC��� */
    uint16_t height;      /* LTDC�߶� */
    uint32_t pixsize;     /* ÿ��������ռ�ֽ��� */
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


