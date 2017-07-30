/***********************************************************************
* Register Abstraction for AVR Microcontrollers GPIO Driver			   *
* @author Ahmed Elzoughby											   *
* @date July 26, 2017												   *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/

#ifndef HW_GPIO_H_
#define HW_GPIO_H_


#define BASE_A 0x39
#define BASE_B 0x36
#define BASE_C 0x33
#define BASE_D 0x30

#define OFFSET_PIN 0x00
#define OFFSET_DIR 0x01
#define OFFSET_PORT 0x02

#define SFIOR 0x50
#define PUD 2


#endif //HW_GPIO_H_
