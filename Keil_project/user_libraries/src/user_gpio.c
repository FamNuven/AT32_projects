/* This library includes fuctions for work with gpio */

#include "user_gpio.h"

/*----------------------------------------------------------------------------*/
/**
 * @brief  The function switches pin
 * @param  port
 * @param  pin
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
 * @param  pins - one or several pins. Don't work with 1,2,3.., work with 1,2,4,8...
 * @param  state - SET or RESET (1 or 0) 
 */
void write_pin (gpio_type * port, uint16_t pins, uint8_t state)
{
    if (state)
        port->scr = pins;
    else
        port->scr = (pins << 16);
}

/*----------------------------------------------------------------------------*/
// gpio_read_pin