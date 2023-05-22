/*
 * main.c
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <D:\MT diploma\Interfacing\Project\Project\Timer1.h>
#include <D:\MT diploma\Interfacing\Project\Project\StopWatch.h>
#include <D:\MT diploma\Interfacing\Project\Project\Interrupts.h>



int main(){
	DDRC |= (1<<PC0);
	PORTC &= ~(1<<PC0);
	SREG |= (1<<7);
	Timer1_init(SECOND);
	StopWatch_init();
	INT0_init();
	INT1_init();
	INT2_init();
	while(1)
	{
		StopWatch_show();
	}

	return 0;
}
