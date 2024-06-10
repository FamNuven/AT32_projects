#include "at32f403a_407.h"
#include "at32f403a_407_wk_config.h"

// reference from user (Timer 2 and 5)
// TMRx_CTRL1   - Control register 1
// TMRx_CTRL2   - Control register 2
// TMRx_STCTRL  -
// TMRx_IDEN    - 
// TMRx_ISTS    - 
// TMRx_SWEVT   - 
// TMRx_CM1     -
// TMRx_CM2     - 
// TMRx_CCTRL   -
// TMRx_CVAL    - Counter value
// TMRx_DIV     - Divider value
// TMRx_PR      - Period value
// TMRx_C1DT    - counter channel 1 value (pulse stm32)
// TMRx_C2DT    - counter channel 2 value (pulse stm32)
// TMRx_C3DT    - counter channel 3 value (pulse stm32)
// TMRx_C4DT    - counter channel 4 value (pulse stm32)
// TMRx_DMACTRL - 
// TMRx_DMADT   - 
void init_timer_test (void);
void init_pwm_A0 (uint32_t freq, uint8_t duty);