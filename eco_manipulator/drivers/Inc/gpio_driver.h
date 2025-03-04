/*
 * gpio_driver.h
 *
 *  Created on: Mar 4, 2025
 *      Author: tr6r2
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_

#include <stdint.h>
#include <stm32f411ce.h>

typedef struct
{
	_vo uint8_t Pin;
	_vo uint8_t Mode;
	_vo uint8_t Speed;
	_vo uint8_t State;


} GpioConfig;

typedef struct
{
	GpioDef *X;
	GpioConfig Config;
} GpioHandle;


void InitGpio(GpioHandle *gpio);
void TurnOn(GpioHandle *gpio);

#endif /* INC_GPIO_DRIVER_H_ */
