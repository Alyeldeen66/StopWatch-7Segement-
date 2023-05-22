/*
 * Timer1.c
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */


#include <D:\MT diploma\Interfacing\Project\Project\Timer1.h>

unsigned char stopWatchSecondsCounter ;
unsigned char stopWatchMinutesCounter ;
unsigned char stopWatchHoursCounter ;

void Timer1_init(unsigned int ticks){
	OCR1A = ticks;
	TIMSK |= (1<<OCIE1A);
	TCCR1A |= (1<<FOC1A) ;
	TCCR1B |= (1<<CS12) | (1<<CS10) | (1<<WGM12) ;
}

ISR(TIMER1_COMPA_vect){
	TCNT1 = 0;
	stopWatchSecondsCounter++;
	if(stopWatchSecondsCounter == 60){
		stopWatchSecondsCounter = 0;
		stopWatchMinutesCounter++;
	}
	if(stopWatchMinutesCounter == 60){
		stopWatchSecondsCounter = 0;
		stopWatchMinutesCounter = 0;
		stopWatchHoursCounter++;
	}
}
