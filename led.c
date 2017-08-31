/***********************************************************************
* GPIO LED ECUAL layer                                                 *
* @author Ahmed Elzoughby                                              *
* @date July 30, 2017                                                  *
* Purpose: Show how to use the GPIO driver in a simple LED driver      *
***********************************************************************/

#include "led.h"


led_error_t led_init(led_t* the_led) {
	led_error_t result_state = LED_STATE_SUCCESS;
	if(the_led -> wiring == CURRENT_SOURCING || the_led -> wiring == CURRENT_SINKING) {
		result_state = gpio_pin_init(the_led -> base_addr, the_led -> pin_num, DIR_OUTPUT) != STATE_SUCCESS? LED_GPIO_ERROR : LED_STATE_SUCCESS;
	} else {
		result_state = LED_STATE_INVALID_CURRENT;
	}
	return result_state;
}

led_error_t led_set_state(led_t* the_led, bit_t state) {
	led_error_t result_state = LED_STATE_SUCCESS;
	if(the_led -> wiring == CURRENT_SOURCING) {
		result_state = gpio_pin_write(the_led -> base_addr, the_led -> pin_num, state) != STATE_SUCCESS? LED_GPIO_ERROR : LED_STATE_SUCCESS;
	} else if(the_led -> wiring == CURRENT_SINKING) {
		result_state = gpio_pin_write(the_led -> base_addr, the_led -> pin_num, state? OFF : ON) != STATE_SUCCESS? LED_GPIO_ERROR : LED_STATE_SUCCESS;
	} else {
		result_state = LED_STATE_INVALID_CURRENT;
	}
	return result_state;
}

led_error_t led_get_state(led_t* the_led, bit_t* result) {
	led_error_t result_state = LED_STATE_SUCCESS;
	bit_t pin;
	result_state = gpio_pin_read(the_led -> base_addr, the_led -> pin_num, &pin) != STATE_SUCCESS? LED_GPIO_ERROR : LED_STATE_SUCCESS;
	if(the_led -> wiring == CURRENT_SOURCING) {
		*result = pin;
	} else if(the_led -> wiring == CURRENT_SINKING) {
		*result = pin? OFF : ON;
	} else {
		result_state = LED_STATE_INVALID_CURRENT;
	}
	return result_state;
}
