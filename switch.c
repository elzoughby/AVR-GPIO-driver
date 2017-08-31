/***********************************************************************
* GPIO switch ECUAL layer                                              *
* @author Ahmed Elzoughby                                              *
* @date July 30, 2017                                                  *
* Purpose: Show how to use the GPIO driver in a simple switch driver   *
***********************************************************************/

#include "switch.h"


switch_error_t switch_init(switch_t* the_switch) {
	switch_error_t result_state = SWITCH_STATE_SUCCESS;
	if(the_switch -> wiring_state == WIRING_PULLDOWN) {
		result_state = gpio_pin_init(the_switch -> base_addr, the_switch -> pin_num, DIR_INPUT) != STATE_SUCCESS? SWITCH_GPIO_ERROR : SWITCH_STATE_SUCCESS;
	} else if(the_switch -> wiring_state == WIRING_PULLUP) {
		result_state = gpio_pin_init(the_switch -> base_addr, the_switch -> pin_num, DIR_PULLUP_INPUT) != STATE_SUCCESS? SWITCH_GPIO_ERROR : SWITCH_STATE_SUCCESS;
	} else {
		result_state = SWITCH_STATE_INVALID_WIRING;
	}
	return result_state;
}

switch_error_t switch_get_state(switch_t* the_switch, bit_t* result) {
	switch_error_t result_state = SWITCH_STATE_SUCCESS;
	bit_t pin;
	result_state = gpio_pin_read(the_switch -> base_addr, the_switch -> pin_num, &pin) != STATE_SUCCESS? SWITCH_GPIO_ERROR : SWITCH_STATE_SUCCESS;
	if(the_switch -> wiring_state == WIRING_PULLDOWN) {
		*result = pin;
	} else if(the_switch -> wiring_state == WIRING_PULLUP) {
		*result = pin? OFF : ON;
	} else {
		result_state = SWITCH_STATE_INVALID_WIRING;
	}
	return result_state;
}
