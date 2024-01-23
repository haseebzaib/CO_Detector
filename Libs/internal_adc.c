/*
 * internal_adc.c
 *
 *  Created on: Dec 24, 2023
 *      Author: hzaib
 */


/************************************************************************/
/* Program:    Enviornmental_Sensor    Date: Dec 24, 2023               */
/* Version:     V1                                                      */
/* Autor: Haseeb Zaib                                                   */
/* This file handles internal ADC functions to measure batt voltage		*/
/************************************************************************/
#include "main.h"
#include "internal_adc.h"
//#include "app_main.h"

#define ratio 3.2
extern ADC_HandleTypeDef hadc1;
#define adc_Start()	   HAL_ADC_Start(&hadc1)
#define adc_Stop()	    HAL_ADC_Stop(&hadc1)
#define adc_Disable() HAL_ADC_DeInit(&hadc1)

static void adc_InitOneShotMode ()
{
	  ADC_ChannelConfTypeDef sConfig = {0};
	  hadc1.Instance = ADC1;
	  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
	  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
	  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
	  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	  hadc1.Init.LowPowerAutoWait = DISABLE;
	  hadc1.Init.LowPowerAutoPowerOff = DISABLE;
	  hadc1.Init.ContinuousConvMode = DISABLE;
	  hadc1.Init.NbrOfConversion = 1;
	  hadc1.Init.DiscontinuousConvMode = DISABLE;
	  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	  hadc1.Init.DMAContinuousRequests = DISABLE;
	  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
	  hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_1CYCLE_5;
	  hadc1.Init.SamplingTimeCommon2 = ADC_SAMPLETIME_1CYCLE_5;
	  hadc1.Init.OversamplingMode = DISABLE;
	  hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
	  if (HAL_ADC_Init(&hadc1) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure Regular Channel
	  */
	  sConfig.Channel = ADC_CHANNEL_0;
	  sConfig.Rank = ADC_REGULAR_RANK_1;
	  sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }

}

static uint32_t adc_Getval ()
{

	return HAL_ADC_GetValue(&hadc1);

}

uint8_t adc_Measure (float *bat_volt)
{
	uint32_t val;
	adc_InitOneShotMode();
	HAL_Delay(1);
	adc_Start();
	HAL_Delay(1);

	if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
		{
		   HAL_Delay(1);
		   adc_Start();
			if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
			{
				HAL_Delay(1);
				adc_Start();
				if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
				{
					return 0;
				}
			}
		}

	adc_Stop();

	val = adc_Getval();

	HAL_Delay(1);
	adc_Start();
	HAL_Delay(1);

	if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
		{
		   HAL_Delay(1);
		   adc_Start();
			if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
			{
				HAL_Delay(1);
				adc_Start();
				if (HAL_ADC_PollForConversion(&hadc1, 1000) != HAL_OK)
				{
					return 0;
				}
			}
		}

	adc_Stop();

	val =(uint32_t)((val + adc_Getval()) / 2);	//Read and average ADC

	//value * (2.8/4095) * ((R1 + R2)/R2);
	// Max = 3.3Vref * 365k / 100k = 12.045V
	// MAx =2.8Vref * 22k / 10k = 6.16V (Because controller is working on 2.8V so Vref is 2.8V)
//	*bat_volt = (float) val * (6.16f / 4096.0f);	// 12 bit
	*bat_volt = (float)((( val * (2.8f / 4095.0f)) * ratio)-0.3); // 12 bit //0.3 for offset
	return 1;



}
