/*
 * Timer1.h
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */



#ifndef TIMER1_H_
#define TIMER1_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <D:\MT diploma\Interfacing\Project\Project\StopWatch.h>

#define SECOND 1000



void Timer1_init(unsigned int ticks);



#endif /* TIMER1_H_ */
