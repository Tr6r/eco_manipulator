/*
 * rcc_driver.h
 *
 *  Created on: Mar 4, 2025
 *      Author: tr6r2
 */

#ifndef INC_RCC_DRIVER_H_
#define INC_RCC_DRIVER_H_

#include <stdint.h>
#include <stm32f411ce.h>


typedef struct
{
	_vo uint8_t Bus;
	_vo uint8_t Port;


} RccConfig;

typedef struct
{
	RccDef *X;
	RccConfig Config;
} RccHandle;


void InitRcc(RccHandle *rcc);
void TurnOn(RccHandle *rcc);
#endif /* INC_RCC_DRIVER_H_ */
