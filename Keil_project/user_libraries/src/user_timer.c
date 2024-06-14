/* This library includes fuctions for work with timer */

#include "user_timer.h"
#include "user_gpio.h"

uint32_t sys_clock = 0;

/*----------------------------------------------------------------------------*/
/**
 * @brief this fuction initialize TIMER2 channel 1 as PWM (test version)
 */
void init_timer_test (void)
{   
    // set gpio A0
    GPIOA->cfglr_bit.iofc0 = 2;
    GPIOA->cfglr_bit.iomc0 = 2;
      
    // set timer 2
    TMR2->cm1_output_bit.c1octrl = 0x6;                    // PWM mode A
    TMR2->div = 639;
    TMR2->pr = 9999;
    TMR2->c1dt = 4999;
    TMR2->ctrl1_bit.tmren = 1;                             // Timer ENABLE
    TMR2->cctrl_bit.c1en = 1;                              // Channel 1 ENABLE
}

/*----------------------------------------------------------------------------*/
/**
 * @brief this fuction initialize TIMER2 channel 1 as PWM  
 * @param freq - PWM freq (from 1 to sys_clock/1000-1)
 * @param duty - PWM duty (from 0 to 100)  
 */
void init_pwm_A0 (uint32_t freq, uint8_t duty)
{
    // set gpio A0
    GPIOA->cfglr_bit.iofc0 = 2;
    GPIOA->cfglr_bit.iomc0 = 2;  
    // set timer 2
    sys_clock = (system_core_clock/1000)/freq - 1;         // read system clock and calculation div  
    TMR2->div = sys_clock;
    TMR2->cm1_output_bit.c1octrl = 0x6;                    // PWM mode A
    TMR2->pr = 999;                                        // Period 
    TMR2->c1dt = duty * 10 - 1;                                
    TMR2->ctrl1_bit.tmren = 1;                             // Timer 2 ENABLE
    TMR2->cctrl_bit.c1en = 1;                              // Channel 1 ENABLE
}


/*----------------------------------------------------------------------------*/
/**
 * @brief this fuction initialize TIMER2 channel 1 as PWM with interrupt (overflow)  
 */
void init_timer2_int (void)
{
    TMR2->iden_bit.c1ien = 1;                              // Channel 1 interrupt enable
    TMR2->div = 6399;
    TMR2->pr = 9999;       
    TMR2->ctrl1_bit.tmren = 1;                             // Timer 2 ENABLE
    TMR2->cctrl_bit.c1en = 1;                              // Channel 1 ENABLE
}


/*----------------------------------------------------------------------------*/
/**
 * @brief this fuction initialize TIMER6's interrupt (overflow)  
 */
void init_timer6_int (void)
{
    crm_periph_clock_enable(CRM_TMR6_PERIPH_CLOCK, TRUE);
    nvic_irq_enable(TMR6_GLOBAL_IRQn, 0, 0);
    TMR6->ctrl1_bit.ovfs = 1;
    TMR6->div = 6399;
    TMR6->pr = 9999;
    TMR6->iden_bit.ovfien = 1;                             // overflow interrupt ON
    TMR6->ists_bit.ovfif = 1;
    TMR6->ctrl1_bit.tmren = 1;                             // Timer 6 enable   
}