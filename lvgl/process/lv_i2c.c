#include "lv_bsp.h"



void lv_dispTempHumidity_value(lv_ui* ui)
{

    static uint8_t temp_value, humidity_value;
    readSensorGXHTC3_data();
   
     if(gpro_t.sensor_temp_value <  120 && gpro_t.sensor_huimidity_value != 0x63){ 
        

          temp_value = gpro_t.sensor_temp_value;
          humidity_value = gpro_t.sensor_huimidity_value;
     
              
         lv_label_set_text_fmt(ui->scrHome_tempNumbers,"%02d",temp_value);
         lv_obj_set_pos(ui->scrHome_tempNumbers, 194, 148);
         lv_obj_set_size(ui->scrHome_tempNumbers, 71, 45);
          

          lv_label_set_text_fmt(ui->scrHome_humidityNumber,"%02d",humidity_value );
          lv_obj_set_pos(ui->scrHome_humidityNumber, 194, 41);
          lv_obj_set_size(ui->scrHome_humidityNumber, 71, 45);

       }






}











