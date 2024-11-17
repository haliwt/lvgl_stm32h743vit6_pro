#include "bsp.h"





uint8_t i2c_send_data[2]={0x5c,0x24};
uint8_t i2c_read_data[5]={0,0,0,0,0};







static uint8_t  gxhtc3_read_sensor_humidity_value(void)
{
    
    uint16_t hum_value;

    uint8_t RH;

    hum_value = (i2c_read_data[0] <<8 ) | (i2c_read_data[1]);

     RH = (100 * (hum_value)) >> 16;

     return RH;

}


static int8_t  gxhtc3_read_sensor_temperature_value(void)
{
    
    uint16_t temp_value;

    uint8_t SR;

    int8_t SR_TEMP;

    temp_value = (i2c_read_data[3] <<8 ) | (i2c_read_data[4]);

     SR = (175 * temp_value ) >> 16;

     SR_TEMP = -45 + SR;

     return SR_TEMP;

}



void readSensorGXHTC3_data(void)
{
   uint8_t i;
  
   gxhtc3_read_ee_i2c_data();
   
   gpro_t.sensor_huimidity_value = gxhtc3_read_sensor_humidity_value();
   gpro_t.sensor_temp_value = gxhtc3_read_sensor_temperature_value();

  

   for(i=0;i< 5;i++){

   i2c_read_data[i]=0;

   }
 

}




