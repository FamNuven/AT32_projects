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

/*----------------------------------------------------------------------------*/
#define GPIO_PIN_0                      0x0001 /*!< gpio pin number 0 */
#define GPIO_PIN_1                      0x0002 /*!< gpio pin number 1 */
#define GPIO_PIN_2                      0x0004 /*!< gpio pin number 2 */
#define GPIO_PIN_3                      0x0008 /*!< gpio pin number 3 */
#define GPIO_PIN_4                      0x0010 /*!< gpio pin number 4 */
#define GPIO_PIN_5                      0x0020 /*!< gpio pin number 5 */
#define GPIO_PIN_6                      0x0040 /*!< gpio pin number 6 */
#define GPIO_PIN_7                      0x0080 /*!< gpio pin number 7 */
#define GPIO_PIN_8                      0x0100 /*!< gpio pin number 8 */
#define GPIO_PIN_9                      0x0200 /*!< gpio pin number 9 */
#define GPIO_PIN_10                     0x0400 /*!< gpio pin number 10 */
#define GPIO_PIN_11                     0x0800 /*!< gpio pin number 11 */
#define GPIO_PIN_12                     0x1000 /*!< gpio pin number 12 */
#define GPIO_PIN_13                     0x2000 /*!< gpio pin number 13 */
#define GPIO_PIN_14                     0x4000 /*!< gpio pin number 14 */
#define GPIO_PIN_15                     0x8000 /*!< gpio pin number 15 */
#define GPIO_PIN_ALL                    0xFFFF /*!< gpio all pins */

/*----------------------------------------------------------------------------*/
void toggle_pin (gpio_type * port, uint8_t pin);
void write_pins (gpio_type * port, uint16_t pins, uint8_t state);




// doxygen example
/*----------------------------------------------------------------------------*/
/**
 * @brief 
 * @param  
 * @return 
 */