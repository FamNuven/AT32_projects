#include "at32f403a_407.h"
#include "at32f403a_407_wk_config.h"

// reference from user
// GPIOx_CFGLR  -  function configuration 0-7 pins
// GPIOx_CFGHR  -  function configuration 8-15 pins
// GPIOx_IDT    -  GPIOx input data
// GPIOx_ODT    -  GPIOx output data
// GPIOx_SCR    -  GPIOx clear or set ODT bit (0-15 set, 16-31 reset)
// GPIOx_CLR    -  GPIOx clear ODT bit (0-15)
// GPIOx_WPR    -  Write protect sequence
// GPIOx_HDRV    - set maximum current for gpio
void toggle_pin (gpio_type * port, uint8_t pin);
void write_pin (gpio_type * port, uint16_t pins, uint8_t state);




// doxygen example
/*----------------------------------------------------------------------------*/
/**
 * @brief 
 * @param  
 * @return 
 */