#include "delay.h"

/* delay macros */
#define STEP_DELAY_MS                    50

/* delay variable */
static __IO uint32_t fac_us;                               // number of microseconds
static __IO uint32_t fac_ms;                               // number of milliseconds

/*----------------------------------------------------------------------------*/
/**
  * @brief  initialize delay function
  */
void delay_init(void)
{
  /* configure systick */
  systick_clock_source_config(SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV);
  fac_us = system_core_clock / (1000000U);
  fac_ms = fac_us * (1000U);
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  inserts a delay time.
  * @param  nus: specifies the delay time length, in microsecond.
  */
void delay_us(uint32_t nus)
{
  uint32_t temp = 0;
  SysTick->LOAD = (uint32_t)(nus * fac_us);                // load the necessary value
  SysTick->VAL = 0x00;                                     // reset the timer value
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;               
  do
  {
    temp = SysTick->CTRL;
  }while((temp & 0x01) && !(temp & (1 << 16)));            // while timer is enable and check don't overflow

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->VAL = 0x00;
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  inserts a delay time.
  * @param  nms: specifies the delay time length, in milliseconds.
  */
void delay_ms(uint16_t nms)
{
  uint32_t temp = 0;
  while(nms)
  {
    if(nms > STEP_DELAY_MS)                                // this function counts 50 milliseconds time intervals
    {
      SysTick->LOAD = (uint32_t)(STEP_DELAY_MS * fac_ms);
      nms -= STEP_DELAY_MS;
    }
    else
    {
      SysTick->LOAD = (uint32_t)(nms * fac_ms);
      nms = 0;
    }
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
      temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
  }
}

/*----------------------------------------------------------------------------*/
/**
  * @brief  inserts a delay time.
  * @param  sec: specifies the delay time, in seconds.
  */
void delay_sec(uint16_t sec)
{
  uint16_t index;
  for(index = 0; index < sec; index++)
  {
    delay_ms(500);
    delay_ms(500);
  }
}
