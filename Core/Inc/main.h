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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern ADC_HandleTypeDef hadc1;

extern I2C_HandleTypeDef hi2c2;

extern SPI_HandleTypeDef hspi1;

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim17;

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_spi1_tx;

extern RTC_HandleTypeDef hrtc;
extern IWDG_HandleTypeDef hiwdg;
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RS_MCU_Pin GPIO_PIN_2
#define RS_MCU_GPIO_Port GPIOA
#define SPI1_NSS_Pin GPIO_PIN_4
#define SPI1_NSS_GPIO_Port GPIOA
#define SPI1_SCK_Pin GPIO_PIN_5
#define SPI1_SCK_GPIO_Port GPIOA
#define LCD_RESET_Pin GPIO_PIN_6
#define LCD_RESET_GPIO_Port GPIOA
#define SPI1_MOSI_Pin GPIO_PIN_7
#define SPI1_MOSI_GPIO_Port GPIOA
#define BRTNS_CTRL_Pin GPIO_PIN_1
#define BRTNS_CTRL_GPIO_Port GPIOB
#define PWN_BTN_MCU_Pin GPIO_PIN_2
#define PWN_BTN_MCU_GPIO_Port GPIOB
#define I2C_SCL_Pin GPIO_PIN_13
#define I2C_SCL_GPIO_Port GPIOB
#define I2C_SDA_Pin GPIO_PIN_14
#define I2C_SDA_GPIO_Port GPIOB
#define USART1_TX_Pin GPIO_PIN_9
#define USART1_TX_GPIO_Port GPIOA
#define USART1_RX_Pin GPIO_PIN_10
#define USART1_RX_GPIO_Port GPIOA
#define PWR_CTRL_Pin GPIO_PIN_15
#define PWR_CTRL_GPIO_Port GPIOA
#define VBATT_MES_Pin GPIO_PIN_0
#define VBATT_MES_GPIO_Port GPIOD
#define VBUS_DTCT_Pin GPIO_PIN_1
#define VBUS_DTCT_GPIO_Port GPIOD
#define VBUS_OUT_EN_Pin GPIO_PIN_3
#define VBUS_OUT_EN_GPIO_Port GPIOD
#define CHG_FLT_Pin GPIO_PIN_3
#define CHG_FLT_GPIO_Port GPIOB
#define CHG_EN_Pin GPIO_PIN_4
#define CHG_EN_GPIO_Port GPIOB
#define USB_DTCT_Pin GPIO_PIN_5
#define USB_DTCT_GPIO_Port GPIOB
#define USB_INT_N_Pin GPIO_PIN_6
#define USB_INT_N_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
