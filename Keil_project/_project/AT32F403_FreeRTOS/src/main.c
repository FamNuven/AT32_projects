/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */

#include "at32f403a_407_clock.h"
#include "FreeRTOS.h"
#include "task.h"

/** @addtogroup UTILITIES_examples
  * @{
  */

/** @addtogroup FreeRTOS_demo
  * @{
  */
TaskHandle_t led2_handler;
TaskHandle_t led3_handler;

/* led2 task */
void led2_task_function(void *pvParameters);
/* led3 task */
void led3_task_function(void *pvParameters);

/**
  * @brief  main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  nvic_priority_group_config(NVIC_PRIORITY_GROUP_4);

  system_clock_config();


  /* create led2 task */
  if(xTaskCreate((TaskFunction_t )led2_task_function,
                 (const char*    )"LED2_task",
                 (uint16_t       )512,
                 (void*          )NULL,
                 (UBaseType_t    )2,
                 (TaskHandle_t*  )&led2_handler) != pdPASS)
  {
    
  }
  else
  {
    
  }
  /* create led3 task */
  if(xTaskCreate((TaskFunction_t )led3_task_function,
                 (const char*    )"LED3_task",
                 (uint16_t       )512,
                 (void*          )NULL,
                 (UBaseType_t    )2,
                 (TaskHandle_t*  )&led3_handler) != pdPASS)
  {
    
  }
  else
  {
    
  }

  /* exit critical */
  taskEXIT_CRITICAL();

  /* start scheduler */
  vTaskStartScheduler();
}

/* led2 task function */
void led2_task_function(void *pvParameters)
{
  while(1)
  {
    vTaskDelay(1000);
  }
}

/* led3 task function */
void led3_task_function(void *pvParameters)
{
  while(1)
  {
    vTaskDelay(500);
  }
}

/**
  * @}
  */

/**
  * @}
  */
