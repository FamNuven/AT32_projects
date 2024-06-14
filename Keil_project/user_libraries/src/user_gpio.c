/* This library includes fuctions for work with gpio */

#include "user_gpio.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief  The function switches pin
 * @param  port
 * @param  pin number pin (1,2,3,4...)
 */
void toggle_pin (gpio_type * port, uint8_t pin)
{
	if (((port->odt << pin)&&1) == TRUE)
	{
		port->odt &= ~(1<<pin);
	}
	else 
        port->odt |= (1<<pin);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief  The function sets or clears the selected data port bit. Don't work with GPIO_ODT
 * @param  port 
 * @param  pins - one or several pins (GPIO_PIN_0, GPIO_PIN_1 ...)
 * @param  state - SET or RESET (1 or 0) 
 */
void write_pins (gpio_type * port, uint16_t pins, uint8_t state)
{
    if (state)
        port->scr = pins;
    else
        port->scr = (pins << 16);
}


/*----------------------------------------------------------------------------*/
/**
 * @param pins - one or several pins (GPIO_PIN_0, GPIO_PIN_1 ...)
 * @param mode - GPIO_MODE_OUTPUT or GPIO_MODE_INPUT
 */
void init_pin (gpio_type * port, uint16_t pins, uint8_t mode)
{ 
    volatile uint32_t var1 = 0, var2 = 0;        // variable for math             
    uint8_t mask = 0;
    if (mode == GPIO_MODE_OUTPUT)                // if pins is OUTPUT, PUSH-PULL, large sourcing/sinking strength
        mask = 1;
    else if (mode == GPIO_MODE_INPUT )           // if pins is INPUT, Analog mode
        mask = 0;
    
    
    for (uint8_t i = 0; i < 8; ++i)
    {
        uint8_t bit = (pins >> i) & mask;
        if (bit)
            var1 |= (1 << (4 * i));
        bit = (pins >> (i + 8)) & mask;
        if (bit)
            var2 |= (1 << (4 * i));
        
    }
    port->cfglr = var1;
    port->cfghr = var2;  
}

/*----------------------------------------------------------------------------*/
// gpio_read_pin