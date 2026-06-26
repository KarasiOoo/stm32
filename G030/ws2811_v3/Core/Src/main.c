#include "main.h"
#define LED_STRIP 9

uint8_t i, j;
//uint8_t led_strip = 9;
uint8_t tablica_ledow[LED_STRIP];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void ws2811(uint8_t state)
{
	if(state == 0)
	{
		GPIOA->BSRR = GPIO_BSRR_BS2;
		GPIOA->BSRR = GPIO_BSRR_BS5;				// HIGH for 500ns, and it is
		__NOPten();									// with compensation RAW time should be 250ns
		__NOPten();
		__NOPten();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();

		GPIOA->BRR = GPIO_BRR_BR2;
		GPIOA->BRR = GPIO_BRR_BR5;					// LOW for 2000ns, and it is
		__NOPten();									// with compensation RAW time should be 1700ns
		__NOPten();
		__NOPten();
		__NOP();
		__NOP();
	}
	else
	{
		GPIOA->BSRR = GPIO_BSRR_BS2;
		GPIOA->BSRR = GPIO_BSRR_BS5;				// HIGH for 1200ns
		__NOPten();									// with compensation RAW time should be 900ns
		__NOPten();
		__NOPten();
		__NOPten();
		__NOPten();
		__NOP();
		__NOP();
		GPIOA->BRR = GPIO_BRR_BR2;
		GPIOA->BRR = GPIO_BRR_BR5;					// LOW for 1300ns
		__NOP();									// with compensation RAW time should be 1000ns

	}
}

void ws2811_deploy(void)
{
	HAL_Delay(1);
	GPIOA->BSRR = GPIO_BSRR_BS2;
	GPIOA->BSRR = GPIO_BSRR_BS5;
	return;
}

void end_command(void)
{
	GPIOA->BSRR = GPIO_BSRR_BS2;
	GPIOA->BSRR = GPIO_BSRR_BS5;
	return;
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();

	__NOP();
	GPIOA->BSRR = GPIO_BSRR_BS2;
	GPIOA->BSRR = GPIO_BSRR_BS5;
	__NOP();
	__NOP();

	while (1)
	{
		for(i=0; i<=(LED_STRIP/2); i++)				//pętla wywołująca kolejne komendy
		{
			for(j=0; j<=LED_STRIP; j++)				//wysłanie bitów do ustawienia całego paska
			{
				if(tablica_ledow[j] == 0)
				{
					ws2811(0);
					ws2811(0);
					ws2811(0);
					ws2811(0);
					ws2811(0);
					ws2811(0);
					ws2811(0);
					ws2811(0);
				}
				else
				{
					ws2811(1);
					ws2811(1);
					ws2811(1);
					ws2811(1);
					ws2811(1);
					ws2811(1);
					ws2811(1);
					ws2811(1);
				}
			end_command();
			}
		}
		tablica_ledow[j] = 1;
		tablica_ledow[LED_STRIP-j] = 1;
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
