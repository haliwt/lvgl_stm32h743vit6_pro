#include "bsp_tft.h"
#include "bsp_st7789v.h"
#include "spi.h"

// 定义屏幕的大小
#define Width   320 // 宽度,x轴
#define Height  240 // 高度,y轴
 
/******命令表*****/
#define SET_COL     (0x2A)    // 设置列地址
#define SET_ROW     (0x2B)    // 设置行地址
#define SET_RAM     (0x2C)    // 写入RAM
/****************/

static void LCD_SPI_Send(uint8_t *data, uint32_t size);

static void lcd_set_cursor(uint16_t x, uint16_t y);



int8_t font_pic_warning_words[2][60]={

  	0x00,0x00,0x00,0x20,0x00,0x00,0x31,0xFF,0xC0,0x19,0x80,0xC0,0x09,0x80,0xC0,0x01,
	0xFF,0xC0,0x41,0x80,0xC0,0x61,0x80,0xC0,0x39,0xFF,0xC0,0x01,0xFF,0xC0,0x00,0x26,
	0x00,0x13,0x26,0x20,0x1B,0x26,0x60,0x11,0x26,0x40,0x11,0xA6,0xC0,0x30,0xA7,0x80,
	0x20,0x26,0x00,0x63,0xFF,0xE0,0x20,0x00,0x00,0x00,0x00,0x00,/*"湿",0*/
	
	0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x30,0x00,0x1F,0xFF,0xC0,0x10,0x00,0x00,0x10,
	0x86,0x00,0x10,0x86,0x00,0x17,0xFF,0xC0,0x10,0x86,0x00,0x10,0x86,0x00,0x10,0xFE,
	0x00,0x10,0x00,0x00,0x17,0xFF,0x00,0x30,0x86,0x00,0x30,0xC4,0x00,0x20,0x6C,0x00,
	0x20,0x38,0x00,0x63,0xEF,0xE0,0x0F,0x01,0xC0,0x00,0x00,0x00,/*"度",1*/

};

const uint8_t font2424_temp_symbol[72]={

 0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x24,0x00,0x00,0x24,0x03,0x00,0x24,
 0x1F,0xE0,0x18,0x38,0x70,0x00,0x60,0x18,0x00,0xC0,0x1C,0x00,0xC0,0x00,0x00,0xC0,
 0x00,0x00,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x01,0x80,0x00,0x00,0xC0,0x00,
 0x00,0xC0,0x0C,0x00,0xC0,0x18,0x00,0x60,0x38,0x00,0x38,0xF0,0x00,0x1F,0xE0,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,/*"℃",0*/

};

uint8_t fontred_color[320];

///**
// * @brief       ×¼±¸Ð´GRAM
// * @param       ÎÞ
// * @retval      ÎÞ
// */
//void lcd_write_ram_prepare(void)
//{
//    //LCD->LCD_REG = lcddev.wramcmd;
//    LCD_Write_16bit_Data(&lcddev.wramcmd);
//    
//}

/**************************************************************************
*
* Function Name:void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
* Function : 画点
* Input Ref:x，y:起始坐标  color:颜色
* Return Ref: NO
*
***********************************************************************/
void TFT_DrawPoint(uint16_t x,uint16_t y,uint16_t color)
{
   LCD_Write_Cmd(0x2a);
   LCD_Write_Data(x >>8);
   LCD_Write_Data(x);

   LCD_Write_Cmd(0x2b);
   LCD_Write_Data(y >>8);
   LCD_Write_Data(y);

   LCD_Write_Cmd(0x2c);
   LCD_Write_Data(color >>8);
   LCD_Write_Data(color);
}


/****************************************************************************************************
	*
	*Function Name:void TFT_Disp_Set_TimerTime_Init(void)
	*Function: display set up timer timing value how meny value 
	*Input Ref:NO
	*Return Ref:NO
	*
****************************************************************************************************/
void TFT_Disp_Red_Color(uint8_t mode)
{

    static uint16_t x=0,y=0;
	uint8_t tbit,temp,t;
	uint8_t x0=x;
   

	static uint16_t color;


	for(t = 0; t < 320; t++)	/*遍历打印所有像素点到LCD */
	{   
	
		//temp = font2424_temp_symbol[t]; 
		
		temp = fontred_color[t];
		for(tbit = 0; tbit < 8; tbit++)	/* 打印一个像素点到液晶 */
		{	
			
			
			if(mode==0)	color = RED;//GREEN;
			else if(mode ==1)color = GREEN;//BLUE;
			else if(mode == 2)color = BLUE;//RED;
            
			TFT_DrawPoint(x, y,color );
			
			temp <<= 1;			
			//y++; // 垂直扫描
			x++;//水平扫描

			if(x >= TFT_Width){
                   
					return;	/* 超区域了 */

			}
			
			if((x - x0) == 319){
				x = x0;
				y++;
				
			    if(y >= TFT_Height){
				
				return;		/* 超区域了 */

			     }
 
				break;
			}
		}  	 
	}  
}




/****************************************************************************************
	*
	*Function  Name :void TFT_Disp_Time_Split_Symbol(void)
	*Function:
	*Input Ref:NO
	*Return Ref:NO
	*
****************************************************************************************/
void TFT_Disp_Time_Split_Symbol(uint16_t x,uint16_t y,uint8_t dat)
{
    uint16_t temp, t, tbit,mode;
    uint16_t x0=x;
    mode =0;
	static uint16_t color;

	for(t = 0; t < 144; t++)	/*遍历打印所有像素点到LCD */
	{   
	
		
		//  temp = font_colon_symbol[0][t];
		
		for(tbit = 0; tbit < 8; tbit++)	/* 打印一个像素点到液晶 */
		{	
			
			
			if(temp & 0x80)	{
				if(dat==0)
				   color = WHITE;
				else
				   color = BLACK;

			}
			else if(0 == mode)	color = BLACK;
			else color = BLACK;
			TFT_DrawPoint(x, y,color );
			
			temp <<= 1;			
			//y++; // 垂直扫描
			x++;//水平扫描

			if(x >= TFT_Width){
                  
					return;	/* 超区域了 */

			}
			
			if((x - x0) == 24){
				x = x0;
				y++;
				
			    if(y >= TFT_Height){
				
				return;		/* 超区域了 */

			     }
 
				break;
			}
		}  	 
	}  

}
#if 0
void lcd_color_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color)
{
     uint16_t i, j;
    uint16_t xlen = 0,ylen=0;
    xlen = ex - sx + 1;//end-x - start-x +1
    ylen = ey - sy + 1;

    for (i = sy; i < ylen; i++)
    {
      //  LCDF4_PutPixel(sx,i,color);//lcd_set_cursor(sx, i);      /* ÉèÖÃ¹â±êÎ»ÖÃ */
       // lcd_write_ram_prepare();    /* ¿ªÊ¼Ð´ÈëGRAM */

        for (j = sx; j <xlen; j++)
        {
           // LCD->LCD_RAM = color;   /* ÏÔÊ¾ÑÕÉ« */
    
		   TFT_DrawPoint(j,i,*color);
        }
    }



}
#endif 

void tft_display_handler(void)
{

   LCD_Clear(RED);//TFT_Disp_Red_Color(0);
   HAL_Delay(1000);
   LCD_Clear(GREEN);
   HAL_Delay(1000);
   LCD_Clear(BLUE);//TFT_Disp_Red_Color(2);
   HAL_Delay(1000);

}


/*
    函数功能: 设置写入ram的范围
    参数:    xs:x轴起始 xe:x轴终止  (0~239)
             ys:y轴起始 ye:y轴终止  (0~239)
    返回值:  无
*/
void LCD_SetDisplayRange(uint16_t xs,uint16_t xe,uint16_t ys,uint16_t ye)
{
    // 对输入的范围进行限制,如果超出范围不允许写入(start=end表示写入一行/列)
    if(xs > (Width-1) ||  xe > (Width-1) || xe < xs) return;
    if(ys > (Height-1) || ye > (Height-1) || ye < ys) return;
    // 设置列地址
    LCD_Write_Cmd(SET_COL);
    LCD_Write_Data(xs>>8);
    LCD_Write_Data(xs);
    LCD_Write_Data(xe>>8);
    LCD_Write_Data(xe); 
    // 设置行地址
    LCD_Write_Cmd(SET_ROW);
    LCD_Write_Data(ys>>8);
    LCD_Write_Data(ys);
    LCD_Write_Data(ye>>8);
    LCD_Write_Data(ye); 
    // 写入内存
    LCD_Write_Cmd(SET_RAM); 
}



 
#define Color_Clear WHITE

/*
    函数功能: LCD指定X、Y轴画一个点
    参数:    x:点的x轴,y:点的y轴
            (从上到下,从左到右，0~239范围)
            Color: 写入的颜色
    返回值:  无
*/
void lcd_drawpoint(uint8_t x,uint8_t y, uint16_t Color)
{
    LCD_SetDisplayRange(x,x,y,y); // 显示点，起始和终止位置相同
    // 写入颜色(16位)
    //LCD_SendHalfByte(Color);
    LCD_Write_16bit_Data(Color);
}


// 默认的背景色
static uint16_t Background = WHITE;
 
/***********缓冲区适合写入大量数据******/
// 定义发送缓冲区的最大大小
#define LCD_BUF_MAXSIZE (Width*Height*2)
// 定义发送的次数
#define SPI_SendCount   100
// 单次发送的缓冲区大小
#define LCD_BUF_SIZE    (LCD_BUF_MAXSIZE/SPI_SendCount)
// 单次发送缓冲区
static uint8_t LCD_BUF[LCD_BUF_SIZE];

/*
    函数功能: 重新设置默认背景颜色
    参数:    Color:重设的背景色
    返回值:  无
*/
void LCD_SetBackground(uint16_t Color)
{
    uint32_t i,j;
    uint8_t data[2] = {0};
    Background = Color;
    data[0] = ((uint16_t)Background)>>8;
    data[1] = (uint8_t)Background;
    LCD_SetDisplayRange(0,Width-1,0,Height-1); 
 
    // 填充缓冲区
    for(i = 0; i < LCD_BUF_SIZE/2; i++)
    {
        LCD_BUF[i * 2] = data[0];
        LCD_BUF[i * 2 + 1] = data[1];
    }
 
   // LCD_Write_Data(); //写数据
    for(j = 0; j < SPI_SendCount; j++)
    {
        LCD_SPI_Send(LCD_BUF,LCD_BUF_SIZE);
    }
}

// LCD批量发送数据函数
static void LCD_SPI_Send(uint8_t *data, uint32_t size)
{
    uint32_t i;
    uint32_t delta;
    
    //一次最多65536个uint8_t类型数据,超过分多次发送
    delta = size/0xFFFF; 
    
    // size小于0xFFFF时,相当于执行一次
    for(i = 0; i<=delta; i++)
    {
        if( i==delta )  /* 发送最后一帧数据 */
            //SPI3_Transmit_Byte(&data[i*0xFFFF], size%0xFFFF);
            HAL_SPI_Transmit(&hspi2,&data[i*0xFFFF],1,0xffffffff);
        
        else    /* 超长数据一次发送0xFFFF字节数据 */
            //SPI3_Transmit_Byte(&data[i*0xFFFF], 0xFFFF);
            HAL_SPI_Transmit(&hspi2,&data[i*0xFFFF],1,0xffffffff);
    }
}

//在指定区域内填充指定颜色块
//(sx,sy),(ex,ey):填充矩形对角坐标，区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void lcd_color_fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color)
{  
	uint16_t height,width;
	uint16_t i,j;
    
	width=ex-sx+1; 			//得到填充的宽度
	height=ey-sy+1;			//高度
    
 	for(i=0;i<height;i++)
	{
 		lcd_set_cursor(sx,sy+i);   	//设置光标的位置
	    LCD_Write_Cmd(SET_RAM);  //开始写入GRAM
        
		for(j=0;j<width;j++)
		LCD_Write_16bit_Data(color[i*width+j]);//LCD->LCD_RAM=color[i*width+j];//写入数据
	}		  
}  


/**
 * @brief       ÉèÖÃ¹â±êÎ»ÖÃ(¶ÔRGBÆÁÎÞÐ§)
 * @param       x,y: ×ø±ê
 * @retval      ÎÞ
 */
static void lcd_set_cursor(uint16_t x, uint16_t y)
{
 
        LCD_Write_Cmd(0x2a);
        LCD_Write_Data(x >> 8);
        LCD_Write_Data(x & 0xFF);
        LCD_Write_Cmd(0x2b);
        LCD_Write_Data(y >> 8);
        LCD_Write_Data(y & 0xFF);
    
}


