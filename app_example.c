/***********************************************************************
* GPIO Exmaple Application                                             *
* @author Ahmed Elzoughby											   *
* @date July 30, 2017												   *
* Purpose: Show how to use the GPIO driver in the applications         *
***********************************************************************/

#include "led.h"


int main(void) {

	led_t test_led;
	test_led.base_addr = BASE_B;
	test_led.pin_num = 0;
	test_led.wiring = CURRENT_SOURCING;
	
	led_set_state(&test_led, ON);

	return 0;
}
