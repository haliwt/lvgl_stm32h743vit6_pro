#include "bsp.h"


#define EE_SCL_PIN               GPIO_PIN_6   //模拟IIC的SCL信号  1.修改引脚即可修改IIC接口
#define EE_SDA_PIN               GPIO_PIN_7   //模拟IIC的SDA信号
#define EE_IIC_SCL(val)         HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,val)                    //SCL 输出高或者低     2.修改引脚即可修改IIC接口        
#define EE_IIC_SDA(val)         HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,val)                    //SDA 输出高或者低 

/******************************************************************************
*函  数：void EE_SDA_IN(void) 	//PB11配置成输入 
*功　能：IIC初始化
*参  数：无
*返回值：无
*备  注：无
*******************************************************************************/
void EE_SDA_IN(void) 	//PB11配置成输入  
{  
	__HAL_RCC_GPIOB_CLK_ENABLE();//GPIO时钟使能
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  
  GPIO_InitStruct.Pin = EE_SDA_PIN ;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
} 

void EE_SDA_OUT(void)//PB11配置成开漏输出
{
	__HAL_RCC_GPIOB_CLK_ENABLE();//GPIO时钟使能
	GPIO_InitTypeDef GPIO_InitStruct = {0};
    
	GPIO_InitStruct.Pin = EE_SDA_PIN ;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}

void EE_SCK_OUT(void) //PB10配置成开漏输出
{
	__HAL_RCC_GPIOB_CLK_ENABLE();//GPIO时钟使能
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin =  EE_SCL_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

//读DATA引脚状态
unsigned char EE_READ_SDA(void)
{
return HAL_GPIO_ReadPin(GPIOB,EE_SDA_PIN);
}	

/******************************************************************************
*函  数：void IIC_Init(void)
*功　能：IIC初始化
*参  数：无
*返回值：无
*备  注：无
*******************************************************************************/


/******************************************************************************
*函  数：void EE_IIC_Delay(void)
*功　能：IIC延时
*参  数：无
*返回值：无
*备  注: 移植时只需要将EE_IIC_Delay()换成自己的延时即可,目前是在16M主频下运行，大约等待10us
*******************************************************************************/	
void EE_IIC_Delay(uint16_t us)
{
	uint16_t j;
	for(j=0;j<us;j++)
	{
        for(int i = 0; i < 100; i++) //20   
        {
            __asm("NOP");//等待1个指令周期，系统主频16M
         //  __asm("NOP");    //48OMHZ
      
        }
	}
    
}
/******************************************************************************
*函  数：void IIC_Init(void)
*功　能：IIC初始化
*参  数：无
*返回值：无
*备  注：无
*******************************************************************************/

void EE_IIC_Init(void)
{			
    EE_SCK_OUT();//CLK引脚配置成输出
    EE_SDA_OUT();//DATA引脚配置成输出
    EE_IIC_SCL((GPIO_PinState)1);//CLK引脚输出高
    EE_IIC_SDA((GPIO_PinState)1);//DATA引脚输出高   
}
/***********************************************************************************************
*
*Function Name:void EE_IIC_Start(void)
*Function : SDA -> HIGH ->LOW: SCL = H
*
*
***********************************************************************************************/	
void EE_IIC_Start(void)
{
	EE_SDA_OUT(); //DATA引脚配置成输出
	EE_IIC_SDA((GPIO_PinState)1);//DATA引脚输出高	
	EE_IIC_SCL((GPIO_PinState)1);//CLK引脚输出高
	delay_us(40);//EE_IIC_Delay(4);//等待大约40us
 	EE_IIC_SDA((GPIO_PinState)0); //DATA引脚输出低
	EE_IIC_Delay(4);//等待大约40us
	EE_IIC_SCL((GPIO_PinState)0); //CLK引脚输出低，钳住I2C总线，准备发送或接收数据 
}

/***********************************************************************************************
*
*Function Name:void EE_IIC_Stop(void)
*Function : SDA -> LOW ->HIGH : SCL = H
*
*
***********************************************************************************************/
void EE_IIC_Stop(void)
{
    EE_SDA_OUT(); //DATA引脚配置成输出
    EE_IIC_SCL((GPIO_PinState)0);//CLK引脚输出低 数据更改
    EE_IIC_SDA((GPIO_PinState)0); //DATA引脚输出--->低 (low-> 高  ---》I2C finish )
    delay_us(40); //EE_IIC_Delay(4);//等待大约40us
    EE_IIC_SCL((GPIO_PinState)1); //CLK引脚输出高 -->SCL--高
    EE_IIC_SDA((GPIO_PinState)1); //DATA引脚输出---> 高，发送I2C总线结束信号
    EE_IIC_Delay(4);//等待大约40us							   	
}
/********************************************************************************
*
*Function Name:uint8_t EE_IIC_WaitAck(void)
*Function : 应答信号，在第9个clock，SDA被拉低--应答， SDA-被拉高-结束，SCL-高电平
*           传输数据，SCL-低电平，数据变更。
*
*
*
********************************************************************************/
uint8_t EE_IIC_WaitAck(void)
{
	uint8_t ucErrTime=0;
	EE_SDA_IN(); //DATA引脚配置成输入  （从机给一个低电平做为应答） 
	EE_IIC_SDA((GPIO_PinState)1);
	delay_us(10);//EE_IIC_Delay(1);	   
	EE_IIC_SCL((GPIO_PinState)1);
	delay_us(10);//EE_IIC_Delay(1);//等待约10us 
	while(EE_READ_SDA())//一直读，直到读取到低电平应答
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			EE_IIC_Stop();
			return 1;
		}
	}
	EE_IIC_SCL((GPIO_PinState)0); //时钟输出0 	   
	return 0;  
} 

/********************************************************************************
*
*Function Name:void EE_IIC_Ack(void)
*Function : 应答信号，在第9个clock，SDA被拉低-低电平--应答， SDA-被拉高-结束，
*           SCL-高电平，传输数据，SCL-低电平，数据变更。
*
*
*
********************************************************************************/
void EE_IIC_Ack(void)
{
	EE_IIC_SCL((GPIO_PinState)0); //SCL bus is pull low ,changed transmit data. 
	EE_SDA_OUT();
	EE_IIC_SDA((GPIO_PinState)0);  // transmit data is SDA = 0, answer signal
	delay_us(10);//EE_IIC_Delay(1);
	EE_IIC_SCL((GPIO_PinState)1); //SCL bus  is pull high ,bigin transmit data.
	delay_us(10);//EE_IIC_Delay(2); //hold delay data
	EE_IIC_SCL((GPIO_PinState)0); //release SCL bus
}

/********************************************************************************
*
*Function Name:void EE_IIC_Ack(void)
*Function : 非应答信号，在第9个clock，SDA被拉低--应答， SDA-被拉高-高电平-结束，
*           SCL-高电平，传输数据，SCL-低电平，数据变更
*
*
*
********************************************************************************/
void EE_IIC_NAck(void)
{
	EE_IIC_SCL((GPIO_PinState)0);
	EE_SDA_OUT();
	EE_IIC_SDA((GPIO_PinState)1);
	EE_IIC_Delay((GPIO_PinState)1);
	EE_IIC_SCL((GPIO_PinState)1);
	delay_us(10);//EE_IIC_Delay(1);
	EE_IIC_SCL((GPIO_PinState)0); //relaeas SCL bus.
}					 				     
/********************************************************************************
*
*Function Name:void EE_IIC_SendByte(uint8_t data)
*Function : 发送数据，8bit，SCL-高电平
*           传输数据，SCL-低电平，数据变更。
*Input Ref: send data :"data"
*
*
********************************************************************************/
void EE_IIC_SendByte(uint8_t data)
{                        
    uint8_t t;   
    EE_SDA_OUT(); 	    
    EE_IIC_SCL((GPIO_PinState)0); //拉低时钟开始数据传输,数据可以更改
    for(t=0;t<8;t++)
    {              
	    EE_IIC_SDA((GPIO_PinState)((data&0x80)>>7));//发送数据,从最高位开始发送。
        EE_IIC_Delay(1);			
        EE_IIC_SCL((GPIO_PinState)1); //传输数据-SCL bus must pull high is send data.,slc is low changed data.
        
        data<<=1; // shift left one bit.
        delay_us(10);//EE_IIC_Delay(1); // about times 10us.hold up SCL is high level 1ous.
        EE_IIC_SCL((GPIO_PinState)0); // release SCL bus. 
    }
   delay_us(10);// EE_IIC_Delay(1);
} 	 

/********************************************************************************
*
*Function Name:uint8_t EE_IIC_ReadByte(uint8_t ack)
*Function : 发送数据，8bit，SCL-高电平
*           传输数据，SCL-低电平，数据变更。
*Input Ref: send data :"data"
*Reftern Ref: receive data from slave device .
*
********************************************************************************/
uint8_t EE_IIC_ReadByte(uint8_t ack)
{
	uint8_t i,receive_data=0;
	EE_SDA_IN(); //SDA设置为输入模式 等待接收从机返回数据
    for(i=0;i<8;i++ )
	{
        EE_IIC_SCL((GPIO_PinState)0);  // SCL =0, maybe changed data.
        EE_IIC_Delay(1);
        EE_IIC_SCL((GPIO_PinState)1); // SCL =1 ,receive data 
        receive_data<<=1;
        if(EE_READ_SDA())receive_data++; //读取从机发送的电平，如果是高，就记录高
        delay_us(10);//EE_IIC_Delay(1); 
    }					 
    if(ack)
        EE_IIC_Ack(); //发送ACK 
    else
        EE_IIC_NAck(); //发送nACK  
    return receive_data;
}


/********************************************************************************
*
*Function Name:uint8_t EE_IIC_ReadByteFromSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t *buf)
*Function : 从EE指定地址读取一个字节
*           
*Input Ref: read_address = I2C_Addr+1,wich of register ,data be save *buf
*Reftern Ref: receive data from slave device .
*
********************************************************************************/
uint8_t EE_IIC_ReadByteFromSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t *buf)
{
	
    uint8_t buf_t;
    EE_IIC_Start();	
    #if 0
	EE_IIC_SendByte(I2C_Addr);	 //发送从机地址
	if(EE_IIC_WaitAck()) //如果从机未应答则数据发送失败
	{
		EE_IIC_Stop();
		return 1;
	}
	EE_IIC_SendByte(reg); //发送寄存器地址
	EE_IIC_WaitAck();	  
	
	EE_IIC_Start();
    #endif 
	//EE_IIC_SendByte(I2C_Addr+1); //进入接收模式		
	EE_IIC_SendByte(I2C_Addr);  //read Address 
	EE_IIC_WaitAck();
	
   
	buf[0]=EE_IIC_ReadByte(1); //humidity value 
    
    buf[1]=EE_IIC_ReadByte(1);
 
    buf[2]=EE_IIC_ReadByte(1); //humidity of CRC
 
    buf[3]=EE_IIC_ReadByte(1);
 
    buf[4]=EE_IIC_ReadByte(1);

    buf_t=EE_IIC_ReadByte(0);
 
    EE_IIC_Stop();
    
	return 0;
}

//发送一个字节内容到EE指定地址
uint8_t EE_IIC_SendByteToSlave(uint8_t I2C_Addr,uint8_t reg,uint8_t data)
{
	EE_IIC_Start();
	EE_IIC_SendByte(I2C_Addr); //发送从机地址
	if(EE_IIC_WaitAck())
	{
		EE_IIC_Stop();
		return 1; //从机地址写入失败
	}
	EE_IIC_SendByte(reg); //发送寄存器地址
        EE_IIC_WaitAck();	  
	EE_IIC_SendByte(data); 
	if(EE_IIC_WaitAck())
	{
		EE_IIC_Stop(); 
		return 1; //数据写入失败
	}
	EE_IIC_Stop(); //产生一个停止条件
    
	return 0;
}




void gxhtc3_read_ee_i2c_data(void)
{

	//EE_IIC_SendByteToSlave(GXHTC3_ADDR_W,0x5C,0x24);//0地址存储0xE0
	EE_IIC_SendByteToSlave(GXHTC3_ADDR_W,GXHTC3_MEASURE_HIGH_CMD,GXHTC3_MEASURE_LOW_CMD);//0地址存储0xE0

   // EE_IIC_ReadByteFromSlave(0XE0,0x00,i2c_read_data);//从0地址读取1字节内容到EEDATA变量

    EE_IIC_ReadByteFromSlave(GXHTC3_ADDR_R,0x00,i2c_read_data);//从0地址读取1字节内容到EEDATA变量



}


















