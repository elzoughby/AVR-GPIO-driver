/***********************************************************************
* GPIO Exmaple Application                                             *
* @author Ahmed Elzoughby											   *
* @date July 30, 2017												   *
* Purpose: Show how to use the GPIO driver in the applications         *
***********************************************************************/

#include "led.h"
#include "switch.h"


int main(void) {

	led_t test_led;
	test_led.base_addr = BASE_B;
	test_led.pin_num = 0;
	test_led.wiring = CURRENT_SOURCING;
	led_init(&test_led);
	switch_t test_switch;
	test_switch.base_addr = BASE_B;
	test_switch.pin_num = 1;
	test_switch.wiring_state = WIRING_PULLUP;
	switch_init(&test_switch);

	while(1) {
		bit_t switch_pin;
		switch_get_state(&test_switch, &switch_pin);
		while(switch_pin == ON) {
			led_set_state(&test_led, ON);
			switch_get_state(&test_switch, &switch_pin);
		}
		led_set_state(&test_led, OFF);
	}

}
