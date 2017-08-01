/***********************************************************************
* GPIO Exmaple Application                                             *
* @author Ahmed Elzoughby											   *
* @date July 30, 2017												   *
* Purpose: Show how to use the GPIO driver in the applications         *
***********************************************************************/

#ifndef LED_H_
#define LED_H_


#include "GPIO/gpio.h"


typedef enum wiring {
	CURRENT_SOURCING,
	CURRENT_SINKING
} wiring_t;

typedef enum led_error {
	LED_STATE_SUCCESS,
	LED_STATE_ERROR,
	LED_STATE_INVALID_ADDR,
	LED_STATE_INVAILD_PIN,
	LED_STATE_INVALID_WIRING
} led_error_t;

typedef struct led {
	uint8_t base_addr;
	uint8_t pin_num;
	wiring_t wiring;
} led_t;


led_error_t led_set_state(led_t* the_led, bit_t state);

led_error_t led_get_state(led_t* the_led, bit_t* result);


#endif //LED_H_
