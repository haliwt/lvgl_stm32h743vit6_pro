#include "bsp.h"


void (*buzzer_sound)(void);

static void buzzer_sound_fun(void);

static void buzzer_sound_register_handler(void(*buzzer_handler)(void));


void buzzer_init(void)
{

   buzzer_sound_register_handler(buzzer_sound_fun);


}

static void buzzer_sound_fun(void)
{
  HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
  osDelay(30);
  HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_3);


}






static void buzzer_sound_register_handler(void(*buzzer_handler)(void))
{
   buzzer_sound = buzzer_handler;

}






