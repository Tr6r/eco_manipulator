/*
 * timer2_5_driver.h
 *
 *  Created on: Mar 13, 2025
 *      Author: tr6r2
 */

#ifndef INC_TIMER2_5_DRIVER_H_
#define INC_TIMER2_5_DRIVER_H_

#include <stm32f411ce.h>

#define Timer_no2 	2
#define Timer_no3	3
#define Timer_no4	4
#define Timer_no5	5

typedef struct {

	_vo uint8_t timer_number;
	_vo uint32_t prc;
	_vo uint32_t arr;
	_vo uint8_t mode;
	_vo uint8_t PUPD;

} Timer2_5_Config_t;

typedef struct {

	Timer2_5_Config_t Config;
	Timer2_5_RegDef_t *Timer;

} Timer2_5_Handle_t;

Timer2_5_Handle_t Timer2_5_CreateHandle(Timer2_5_RegDef_t* timerx,uint8_t timer_number, uint32_t prc, uint32_t arr);
void Init_Timer2_5(Timer2_5_Handle_t* Timer);
void Delay(Timer2_5_Handle_t* Timer);
#endif /* INC_TIMER2_5_DRIVER_H_ */
