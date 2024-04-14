/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void set_buzzer_frequency(uint32_t freq){
  __HAL_TIM_SetAutoreload(&htim4, freq);
  __HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_3, freq/2);
}
uint32_t music[3][205]={{9, 10, 9, 6, 9, 0, 6, 10, 9, 10, 12, 10, 9, 10, 9, 6, 8, 0, 10, 9, 12, 10}, {5, 9, 8, 3, 0, 8, 9, 10, 9, 8, 9, 5, 9, 8, 3, 0, 8, 9, 10, 9, 8, 9, 5, 9, 8, 3, 0, 8, 9, 10, 9, 8, 9, 5, 9, 8, 3, 0, 8, 10, 12,    13, 12, 0, 8, 9, 9, 8, 9, 10, 0, 10, 12, 13, 14, 13, 12, 10, 9, 9, 8,      9, 9, 9, 8, 0, 8, 10, 12, 13, 12, 0, 8, 9, 9, 8, 10, 0, 9, 10, 12,       13, 15, 16, 17, 16, 15, 12, 13, 15, 17, 17, 17, 16, 0, 12, 13, 15, 17, 17, 17, 16, 0}};
uint32_t lst[3][205]={{  1, 1,  1, 1, 4, 2, 1, 1,  1, 1,  1,  1,  1, 1,  1, 1, 4, 2, 2,  1, 1,  2},  {2, 2, 2, 2, 2, 1, 1, 1,  1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1,  1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1,  1, 1, 1, 2, 2, 2, 2, 2, 2, 2,  2,     6,  6,  3, 1, 2, 2, 2, 2, 4,  2, 1,  1,  2,  2,  2,  2,  2,  2, 2, 2,      2, 2, 2, 2, 5, 1, 1,  1,  6,  6,  3, 1, 2, 2, 2, 2,  4, 1, 1,  2,        2,  2,  2,  2,  2,  2,  1,  1,  2,  2,  2,  2,  2,  4, 1,  1,  2,  2,  2,  2,  2,  8}};
uint32_t tones[]={21000000, 262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1046, 1174, 1318, 1396, 1568, 1760, 1976};
uint32_t lenth[]={22, 103};
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  MX_TIM5_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_TIM_Base_Start(&htim4);
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3);
  uint32_t frequency = 21000000;
  uint32_t nw = 0, time_base = 125;
  uint32_t song = 1;
  while (1)
  {
    /* USER CODE END WHILE */
    set_buzzer_frequency(frequency/tones[music[song][nw]]);
    /* USER CODE BEGIN 3 */
    HAL_Delay(time_base*lst[song][nw]-time_base*1/4);
    set_buzzer_frequency(frequency/tones[0]);
    HAL_Delay(time_base*1/4);
    nw = (nw + 1) % lenth[song];
    // temp += 1000;
    // set_buzzer_frequency(temp);
    // HAL_Delay(100);
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
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
