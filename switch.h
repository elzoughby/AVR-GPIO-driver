/***********************************************************************
* GPIO switch ECUAL layer	                                           *
* @author Ahmed Elzoughby											   *
* @date July 30, 2017												   *
* Purpose: Show how to use the GPIO driver in a simple switch driver   *
***********************************************************************/

#ifndef SWITCH_H_
#define SWITCH_H_


#include "GPIO/gpio.h"


typedef enum wiring {
	WIRING_PULLUP,
	WIRING_PULLDOWN
} wiring_t;

typedef enum switch_error {
	SWITCH_STATE_SUCCESS,
	SWITCH_STATE_INVALID_WIRING,
	SWITCH_GPIO_ERROR
} switch_error_t;

typedef struct swtch {
	uint8_t base_addr;
	uint8_t pin_num;
	wiring_t wiring_state;
} switch_t;


switch_error_t switch_init(switch_t* the_switch);

switch_error_t switch_get_state(switch_t* the_switch, bit_t* result);


#endif //SWITCH_H_
