/*
 * Interrupts.c
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */

#include <D:\MT diploma\Interfacing\Project\Project\Interrupts.h>

unsigned char stopWatchSecondsCounter;
unsigned char stopWatchMinutesCounter;
unsigned char stopWatchHoursCounter;

void INT0_init(){
	DDRD &= ~(1<<PD2);
	PORTD |= (1<<PD2);
	MCUCR |= (1<<ISC01);
	MCUCR &= ~(1<ISC00);
	GICR |= (1<<6);
}

void INT1_init(){
	DDRD &= ~(1<<PD3);
	MCUCR |= (1<<ISC11) |(1<ISC10);
	GICR |= (1<<7);
}
void INT2_init(){
	DDRB &= ~(1<<PB2);
	PORTB |= (1<<PB2);
	MCUCSR &= ~(1<<ISC2);
	GICR |= (1<<5);

}

ISR(INT0_vect){
	stopWatchSecondsCounter = 0;
	stopWatchMinutesCounter = 0;
	stopWatchHoursCounter = 0;

}
ISR(INT1_vect){
	TCCR1B &= ~(1<<CS12) & ~(1<<CS11) & ~(1<<CS10);
}
ISR(INT2_vect){
	TCCR1B |= (1<<CS12) | (1<<CS10) | (1<<WGM12) ;
}
