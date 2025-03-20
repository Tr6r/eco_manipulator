/*
 * gpio_driver.c
 *
 *  Created on: Mar 4, 2025
 *      Author: tr6r2
 */


#include <stm32f411ce.h>
#include <gpio_driver.h>


Gpio_Handle_t Gpio_CreateHandle(Gpio_RegDef_t *port, uint8_t pin, uint8_t mode, uint8_t speed, uint8_t type, uint8_t pupd)
{
    Gpio_Handle_t gpio;
    gpio.X = port;
    gpio.Config.Pin = pin;
    gpio.Config.Mode = mode;
    gpio.Config.Speed = speed;
    gpio.Config.Type = type;
    gpio.Config.PUPD = pupd;
    return gpio;
}
void InitGpio(Gpio_Handle_t *gpio)
{

	if (gpio->X == GPIOD)
	{
		GPIOD_PCLOCK_EN();
		gpio->X->OSPEEDR |= (gpio->Config.Speed << (gpio->Config.Pin *2) );

	}
	if(gpio->Config.Mode == OUTPUT)
	{
		gpio->X->OTYPER |= (gpio->Config.Type << gpio->Config.Pin  );
		gpio->X->MODER |= (gpio->Config.Mode << (gpio->Config.Pin *2) );
	}
}

void TurnOn(Gpio_Handle_t *gpio)
{
	gpio->X->ODR  |= (0b1 << gpio->Config.Pin);

}
void TurnOff(Gpio_Handle_t *gpio)
{
    gpio->X->ODR &= ~(0b1 << gpio->Config.Pin);
}


