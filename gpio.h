	/***********************************************************************
    * Hardware Abstraction for AVR Microcontrollers GPIO Driver			   *
    * @author Ahmed Elzoughby											   *
    * @date July 26, 2017												   *
    * Purpose: Provide an easy interface to deal with digital I/O devices  *
    ***********************************************************************/

#ifndef GPIO_H_
#define GPIO_H_


#include "types.h"
#include "hw_gpio.h"
#include "hw_types.h"


typedef enum gpio_error {
	STATE_SUCCESS,
	STATE_ERROR,
	STATE_INVALID_ADDR,
	STATE_INVAILD_PIN,
	STATE_INVALID_DIR,
	STATE_PULLUP_OFF
} gpio_error_t;

typedef enum gpio_dir {
	DIR_OUTPUT = 1,
	DIR_INPUT = 0,
	DIR_PULLUP_INPUT
} gpio_dir_t;


gpio_error_t gpio_pin_init(uint8_t base_addr, uint8_t pin_num, gpio_dir_t dir);

gpio_error_t gpio_port_init(uint8_t base_addr, gpio_dir_t dir);

gpio_error_t gpio_pin_read(uint8_t base_addr, uint8_t pin_num, bit_t* result);

gpio_error_t gpio_pin_write(uint8_t base_addr, uint8_t pin_num, bit_t state);

gpio_error_t gpio_port_read(uint8_t base_addr, uint8_t* result);

gpio_error_t gpio_port_write(uint8_t base_addr, uint8_t val);


#endif //GPIO_H_
