/***********************************************************************
* Custom types for AVR Microcontrollers GPIO Driver					   *
* @author Ahmed Elzoughby											   *
* @date July 26, 2017												   *
* Purpose: Provide an easy interface to deal with digital I/O devices  *
***********************************************************************/

#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef enum bit {
	LOW = 0,
	HIGH = 1,
	ZERO = 0,
	ONE = 1,
	OFF = 0,
	ON = 1
} bit_t;


#endif //TYPES_H_
