/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY_1_Pin                           GPIO_PIN_3
#define KEY_1_GPIO_Port                     GPIOE

#define KEY_2_Pin                           GPIO_PIN_5
#define KEY_2_GPIO_Port                     GPIOC

#define KEY_3_Pin                           GPIO_PIN_4
#define KEY_3_GPIO_Port                     GPIOC


#define KEY_4_Pin                           GPIO_PIN_6
#define KEY_4_GPIO_Port                      GPIOA


#define KEY_5_Pin                           GPIO_PIN_7
#define KEY_5_GPIO_Port                     GPIOA




#define LED_Pin                         GPIO_PIN_1
#define LED_GPIO_Port                    GPIOA

#define BACKLIGHT_Pin                       GPIO_PIN_0
#define BACKLIGHT_GPIO_Port                 GPIOB


#define CMD_DIP_Pin GPIO_PIN_1
#define CMD_DIP_GPIO_Port GPIOB

#define TFT_RESET_Pin GPIO_PIN_2
#define TFT_RESET_GPIO_Port GPIOB

#define CS_Pin                          GPIO_PIN_12
#define CS_GPIO_Port                    GPIOB


#define TIM2_CH3_BEEP_Pin GPIO_PIN_2
#define TIM2_CH3_BEEP_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
