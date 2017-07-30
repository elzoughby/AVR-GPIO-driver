	/***********************************************************************
    * Hardware Abstraction for AVR Microcontrollers GPIO Driver			   *
    * @author Ahmed Elzoughby											   *
    * @date July 26, 2017												   *
    * Purpose: Providie an easy interface to deal with digital I/O devices  *
    ***********************************************************************/

#include "gpio.h"


gpio_error_t gpio_pin_init(uint8_t base_addr, uint8_t pin_num, gpio_dir_t dir) {
	gpio_error_t state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(pin_num < 8) {
			if(dir == DIR_OUTPUT) {
				hw_bit_write(base_addr + OFFSET_DIR, pin_num, HIGH);
			} else if (dir == DIR_INPUT) {
				hw_bit_write(base_addr + OFFSET_DIR, pin_num, LOW);
				hw_bit_write(base_addr + OFFSET_PORT, pin_num, LOW);
			} else if(dir == DIR_PULLUP_INPUT) {
				if(hw_bit_read(SFIOR, PUD) == 0) {
					hw_bit_write(base_addr + OFFSET_DIR, pin_num, LOW);
					hw_bit_write(base_addr + OFFSET_PORT, pin_num, HIGH);
				} else {
					state = STATE_PULLUP_OFF;
				}
			} else {
				state = STATE_INVALID_DIR;
			}
		} else {
			state = STATE_INVAILD_PIN;
		}
	} else {
		state = STATE_INVALID_ADDR;
	}
	return state;
}

gpio_error_t gpio_port_init(uint8_t base_addr, gpio_dir_t dir) {
	gpio_error_t state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(dir == DIR_OUTPUT) {
			hw_reg8_write(base_addr + OFFSET_DIR, 0xFF);
		} else if (dir == DIR_INPUT) {
			hw_reg8_write(base_addr + OFFSET_DIR, 0x00);
			hw_reg8_write(base_addr + OFFSET_PORT, 0x00);
		} else if(dir == DIR_PULLUP_INPUT) {
			if(hw_bit_read(SFIOR, PUD) == 0) {
				hw_reg8_write(base_addr + OFFSET_DIR, 0x00);
				hw_reg8_write(base_addr + OFFSET_PORT, 0xFF);
			} else {
				state = STATE_PULLUP_OFF;
			}
		} else {
			state = STATE_INVALID_DIR;
		}
	} else {
		state = STATE_INVALID_ADDR;
	}
	return state;
}

gpio_error_t gpio_pin_read(uint8_t base_addr, uint8_t pin_num, bit_t* result) {
	gpio_error_t result_state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(pin_num < 8) {
			if(hw_bit_read(base_addr + OFFSET_DIR, pin_num) == 1) {
				*result = hw_bit_read(base_addr + OFFSET_PORT, pin_num);
			} else {
				*result = hw_bit_read(base_addr + OFFSET_PIN, pin_num);
			}
		} else {
			result_state = STATE_INVAILD_PIN;
		}
	} else {
		result_state = STATE_INVALID_ADDR;
	}
	return result_state;
}

gpio_error_t gpio_pin_write(uint8_t base_addr, uint8_t pin_num, bit_t state) {
	gpio_error_t result_state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(pin_num < 8) {
			if(state == 0 || state == 1) {
				if(hw_bit_read(base_addr + OFFSET_DIR, pin_num) == 1) {
					hw_bit_write(base_addr + OFFSET_PORT, pin_num, state);
				} else {
					result_state = STATE_INVALID_DIR;
				}
			} else {
				result_state = STATE_ERROR;
			}
		} else {
			result_state = STATE_INVAILD_PIN;
		}
	} else {
		result_state = STATE_INVALID_ADDR;
	}
	return result_state;
}

gpio_error_t gpio_port_read(uint8_t base_addr, uint8_t* result) {
	gpio_error_t result_state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(hw_reg8_read(base_addr + OFFSET_DIR) == 0xFF) {
			*result = hw_reg8_read(base_addr + OFFSET_PORT);
		} else if(hw_reg8_read(base_addr + OFFSET_DIR) == 0x00) {
			*result = hw_reg8_read(base_addr + OFFSET_PIN);
		} else {
			result_state = STATE_INVALID_DIR;
		}
	} else {
		result_state = STATE_INVALID_ADDR;
	}
	return result_state;
}

gpio_error_t gpio_port_write(uint8_t base_addr, uint8_t val) {
	gpio_error_t result_state = STATE_SUCCESS;
	if(base_addr == BASE_A || base_addr == BASE_B || base_addr == BASE_C || base_addr == BASE_D) {
		if(hw_reg8_read(base_addr + OFFSET_DIR) == 0xFF) {
			hw_reg8_write(base_addr + OFFSET_PORT, val);
		} else {
			result_state = STATE_INVALID_DIR;
		}
	} else {
		result_state = STATE_INVALID_ADDR;
	}
	return result_state;
}
