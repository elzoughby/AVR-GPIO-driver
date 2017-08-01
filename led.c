/***********************************************************************
* GPIO Exmaple Application                                             *
* @author Ahmed Elzoughby											   *
* @date July 30, 2017												   *
* Purpose: Show how to use the GPIO driver in the applications         *
***********************************************************************/

#include "led.h"


led_error_t led_set_state(led_t* the_led, bit_t state) {
	led_error_t result_state = LED_STATE_SUCCESS;
	if(the_led -> base_addr == BASE_A || the_led -> base_addr == BASE_B || the_led -> base_addr == BASE_C || the_led -> base_addr == BASE_D) {
		if(the_led -> pin_num < 8) {
			if(state == ON || state == OFF) {
				gpio_pin_init(the_led -> base_addr, the_led -> pin_num, DIR_OUTPUT);
				if(the_led -> wiring == CURRENT_SOURCING) {
					gpio_pin_write(the_led -> base_addr, the_led -> pin_num, state);
				} else if(the_led -> wiring == CURRENT_SINKING) {
					gpio_pin_write(the_led -> base_addr, the_led -> pin_num, state? OFF : ON);
				} else {
					result_state = LED_STATE_INVALID_WIRING;
				}
			} else {
				result_state = LED_STATE_ERROR;
			}
		} else {
			result_state = LED_STATE_INVAILD_PIN;
		}
	} else {
		result_state = LED_STATE_INVALID_ADDR;
	}
	return result_state;
}

led_error_t led_get_state(led_t* the_led, bit_t* result) {
	led_error_t result_state = LED_STATE_SUCCESS;
	if(the_led -> base_addr == BASE_A || the_led -> base_addr == BASE_B || the_led -> base_addr == BASE_C || the_led -> base_addr == BASE_D) {
		if(the_led -> pin_num < 8) {
			bit_t pin;
			gpio_pin_read(the_led -> base_addr, the_led -> pin_num, &pin);
			if(the_led -> wiring == CURRENT_SOURCING) {
				*result = pin;
			} else if(the_led -> wiring == CURRENT_SINKING) {
				*result = pin? OFF : ON;
			} else {
				result_state = LED_STATE_INVALID_WIRING;
			}
		} else {
			result_state = LED_STATE_INVAILD_PIN;
		}
	} else {
		result_state = LED_STATE_INVALID_ADDR;
	}
	return result_state;
}
