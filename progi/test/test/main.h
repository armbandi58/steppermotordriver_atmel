/*
 * main.h
 *
 * Created: 25/06/2021 11:13:33
 *  Author: Administrator
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <inttypes.h>
#include <avr/interrupt.h>

#define STEP PORTB0
#define DIR PORTC0
/*#define MS1 PORTD3
#define MS2 PORTD4
#define MS3 PORTD5*/
#define MS1 PORTD6
#define MS2 PORTD5
#define MS3 PORTD4
#define ENABLE PORTC3
#define LED PORTB5

typedef uint8_t u8;
typedef volatile uint8_t v8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef volatile uint32_t vu32;
typedef volatile bool vb;

#endif /* MAIN_H_ */