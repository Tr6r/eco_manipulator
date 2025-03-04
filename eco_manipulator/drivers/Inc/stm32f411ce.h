/*
 * stm32f411ce.h
 *
 *  Created on: Mar 3, 2025
 *      Author: tr6r2
 */

#ifndef INC_STM32F411CE_H_
#define INC_STM32F411CE_H_
#include <stdint.h>
//define violent
#define _vo volatile
#define ui32 uint32_t
//define address
#define BASE_ADDRESS 0x08000000U
//define bus address
#define AHB1_ADDRESS 0x40020000U

#define OUTPUT 	0x01
#define INPUT  	0x00

#define GPIOA 	0x40020000U
#define GPIOB  	0x40020400U
#define GPIOC 	0x40020800U
#define GPIOE 	0x40021000U
#define GPIOH  	0x40021C00U

//define struct clock rcc
typedef struct {
	_vo uint32_t RCC_CR;
	_vo uint32_t RCC_PLLCFGR;
	_vo uint32_t RCC_CFGR;
	_vo uint32_t RCC_CIR;
	_vo uint32_t RCC_AHB1RSTR;
	_vo uint32_t RCC_AHB2RSTR;
	uint32_t Reserved1[2];   // Đúng số lượng Reserved

	_vo uint32_t RCC_APB1RSTR;
	_vo uint32_t RCC_APB2RSTR;
	uint32_t Reserved2[2];

	_vo uint32_t RCC_AHB1ENR;
	_vo uint32_t RCC_AHB2ENR;
	uint32_t Reserved3[2];

	_vo uint32_t RCC_APB1ENR;
	_vo uint32_t RCC_APB2ENR;
	uint32_t Reserved4[2];

	_vo uint32_t RCC_AHB1LPENR;
	_vo uint32_t RCC_AHB2LPENR;
	uint32_t Reserved5[2];

	_vo uint32_t RCC_APB1LPENR;
	_vo uint32_t RCC_APB2LPENR;
	uint32_t Reserved6[2];

	_vo uint32_t RCC_BDCR;
	_vo uint32_t RCC_CSR;
	uint32_t Reserved7[2];

	_vo uint32_t RCC_SSCGR;
	_vo uint32_t RCC_PLLI2SCFGR;
	uint32_t Reserved8;   // Chỉ cần 1 Reserved ở đây

	_vo uint32_t RCC_DCKCFGR;
} RccDef;

#define RCC_BASE_ADDR   0x40023800U

#define RCC				((RccDef*) RCC_BASE_ADDR)

//define struct gpio

typedef struct {
	_vo uint32_t MODER;
	_vo uint32_t OTYPER;
	_vo uint32_t OSPEEDR;
	_vo uint32_t PUPDR;
	_vo uint32_t IDR;
	_vo uint32_t ODR;
	_vo uint32_t BSRR;
	_vo uint32_t LCKR;
	_vo uint32_t AFRL;
	_vo uint32_t AFRH;

} GpioDef;

#define GPIOD  	((GpioDef*) 0x40020C00U)


#endif /* INC_STM32F411CE_H_ */
