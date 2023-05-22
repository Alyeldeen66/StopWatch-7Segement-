/*
 * StopWatch.h
 *
 *  Created on: May 21, 2023
 *      Author: Alyel
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <avr/io.h>


extern unsigned char stopWatchSecondsCounter;
extern unsigned char stopWatchMinutesCounter;
extern unsigned char stopWatchHoursCounter;

void StopWatch_init();
void StopWatch_show();

#endif /* STOPWATCH_H_ */
