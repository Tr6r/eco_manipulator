/*
 * gpio_driver.c
 *
 *  Created on: Mar 4, 2025
 *      Author: tr6r2
 */


#include <stm32f411ce.h>
#include <gpio_driver.h>

void InitGpio(GpioHandle *gpio)
{

	if (gpio->X == GPIOD)
	{
		RCC->RCC_AHB1ENR |= (1<<3);
	}
	if(gpio->Config.Mode == OUTPUT)
	{
		gpio->X->MODER |= (OUTPUT << (gpio->Config.Pin *2) );
	}
}

void TurnOn(GpioHandle *gpio)
{
	gpio->X->ODR  |= (1 << gpio->Config.Pin);

}
