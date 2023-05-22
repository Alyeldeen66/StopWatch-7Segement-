/*
 * StopWatch.c
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */


#include <D:\MT diploma\Interfacing\Project\Project\StopWatch.h>
#include <util/delay.h>



//unsigned char stopWatchValues[] = {0x7E,0x0C,0xB6,0x9E,0xCC,0xDA,0xFA,0x0E,0xFF,0xCE};
unsigned char stopWatchValues[] = {0,1,2,3,4,5,6,7,8,9};
unsigned char stopWatchSecondsCounter;
unsigned char stopWatchMinutesCounter;
unsigned char stopWatchHoursCounter;

unsigned char Screen1,Screen2,Screen3,Screen4,Screen5,Screen6;



void getScreenCount(){
	if(stopWatchSecondsCounter > 9){
		Screen1 = stopWatchSecondsCounter % 10;
		Screen2 = stopWatchSecondsCounter / 10;
	}
	else if(stopWatchSecondsCounter <= 9)
	{
		Screen1 = stopWatchSecondsCounter;
		Screen2 = 0;

	}
	if(stopWatchMinutesCounter > 9){
		Screen3 = stopWatchMinutesCounter % 10;
		Screen4 = stopWatchMinutesCounter / 10;
	}
	else if(stopWatchMinutesCounter <= 9)
	{
		Screen3 = stopWatchMinutesCounter;
		Screen4 = 0;

	}
	if(stopWatchHoursCounter > 9){
		Screen5 = stopWatchHoursCounter % 10;
		Screen6 = stopWatchHoursCounter / 10;
	}
	else if(stopWatchHoursCounter <= 9)
	{
		Screen5 = stopWatchHoursCounter;
		Screen6 = 0;

	}

}

void StopWatch_init(){
	DDRA |= 0x3F;
	DDRC |= 0x0F;
	PORTA &= ~(0x3F);
	Screen1 = stopWatchSecondsCounter;
	Screen2 = 0;
	Screen3 = 0;
	Screen4 = 0;
	Screen5 = 0;
	Screen6 = 0;

}


void StopWatch_show(){
	getScreenCount();
	PORTA &= (0x80);
	PORTA |= (1<<PA0);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen1];
	_delay_ms(1);
	PORTA &= (0x80);
	PORTA |= (1<<PA1);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen2];
	_delay_ms(1);
	PORTA &= (0x80);
	PORTA |= (1<<PA2);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen3];
	_delay_ms(1);
	PORTA &= (0x80);
	PORTA |= (1<<PA3);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen4];
	_delay_ms(1);
	PORTA &= (0x80);
	PORTA |= (1<<PA4);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen5];
	_delay_ms(1);
	PORTA &= (0x80);
	PORTA |= (1<<PA5);
	PORTC = (PORTC & 0x00) | stopWatchValues[Screen6];
	_delay_ms(1);

}





