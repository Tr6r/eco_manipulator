/*
 * gpio_driver.h
 *
 *  Created on: Mar 4, 2025
 *      Author: tr6r2
 */

#ifndef INC_GPIO_DRIVER_H_
#define INC_GPIO_DRIVER_H_


#include <stm32f411ce.h>

#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7
#define GPIO_PIN_8 8
#define GPIO_PIN_9 9
#define GPIO_PIN_10 10
#define GPIO_PIN_11 11
#define GPIO_PIN_12 12
#define GPIO_PIN_13 13
#define GPIO_PIN_14 14
#define GPIO_PIN_15 15


#define OUTPUT 	0b01
#define INPUT  	0b00

#define PUSH_PULL 0b0
#define OPEN_DRAIN 0b1

#define	LOW_SPEED 0b0
#define MEDIUM_SPEED 0b01
#define FAST_SPEED 0b10
#define HIGH_SPEED 0b11

#define NO_PUPD 0b0
#define PULL_UP 0b01
#define PULL_DOWN 0b10


typedef struct
{
	_vo uint8_t Mode;
	_vo uint8_t Pin;
	_vo uint8_t Speed;
	_vo uint8_t Type;
	_vo uint8_t PUPD;

} Gpio_Config_t;

typedef struct
{
	Gpio_RegDef_t *X;
	Gpio_Config_t Config;
} Gpio_Handle_t;

Gpio_Handle_t Gpio_CreateHandle(Gpio_RegDef_t *port, uint8_t pin, uint8_t mode, uint8_t speed, uint8_t type, uint8_t pupd);
void InitGpio(Gpio_Handle_t *gpio);
void TurnOn(Gpio_Handle_t *gpio);
void TurnOff(Gpio_Handle_t *gpio);

#endif /* INC_GPIO_DRIVER_H_ */
