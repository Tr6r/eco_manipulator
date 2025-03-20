/*
 * stm32f411ce.h
 *
 *  Created on: Mar 3, 2025
 *      Author: tr6r2
 */

#ifndef INC_STM32F411CE_H_
#define INC_STM32F411CE_H_
#include <stdint.h>
#include <stddef.h> // Định nghĩa NULL

//define violent
#define _vo volatile
#define ui32 uint32_t
//define address
#define BASE_ADDRESS 0x08000000U
//define bus address
#define AHB1_ADDRESS 0x40020000U
#define APB1_ADDRESS 0x40000000U

#define GPIOA_BASEADDRESS 	0x40020000U
#define GPIOB_BASEADDRESS  	0x40020400U
#define GPIOC_BASEADDRESS 	0x40020800U
#define GPIOD_BASEADDRESS 	0x40020C00U
#define GPIOE_BASEADDRESS 	0x40021000U
#define GPIOH_BASEADDRESS  	0x40021C00U

#define TIMER2_BASEADDRESS  0x40000000U
#define TIMER3_BASEADDRESS  0x40000400U
#define TIMER4_BASEADDRESS  0x40000800U
#define TIMER5_BASEADDRESS  0x40000C00U

#define NVIC_BASEADDRESS  	0xE000E100U


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
} Rcc_RegDef_t;

#define RCC_BASE_ADDR   0x40023800U

#define RCC				((Rcc_RegDef_t*) RCC_BASE_ADDR)

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

} Gpio_RegDef_t;

#define GPIOD ((Gpio_RegDef_t*) GPIOD_BASEADDRESS)


typedef struct {
	_vo uint32_t CR1;
	_vo uint32_t CR2;
	_vo uint32_t SMCR;
	_vo uint32_t DIER;
	_vo uint32_t SR;
	_vo uint32_t EGR;
	_vo uint32_t CCMR1;
	_vo uint32_t CCMR2;
	_vo uint32_t CCER;
	_vo uint32_t CNT;
	_vo uint32_t PSC;
	_vo uint32_t ARR;
	uint32_t Reserved;
	_vo uint32_t CCR1;
	_vo uint32_t CCR2;
	_vo uint32_t CCR3;
	_vo uint32_t CCR4;
	uint32_t Reserved2;
	_vo uint32_t DCR;
	_vo uint32_t DMAR;
	_vo uint32_t OR;

} Timer2_5_RegDef_t;


typedef struct {
    _vo uint32_t ISER[8];   // 0xE000E100 - 0xE000E11C (Interrupt Set Enable Registers)
    uint32_t RESERVED0[24];  // Dự trữ bộ nhớ (padding)
    _vo uint32_t ICER[8];   // 0xE000E180 - 0xE000E19C (Interrupt Clear Enable Registers)
    uint32_t RESERVED1[24];
    _vo uint32_t ISPR[8];   // 0xE000E200 - 0xE000E21C (Interrupt Set Pending Registers)
    uint32_t RESERVED2[24];
    _vo uint32_t ICPR[8];   // 0xE000E280 - 0xE000E29C (Interrupt Clear Pending Registers)
} NVIC_RegDef_t;



#define TIMER2  ((Timer2_5_RegDef_t*) TIMER2_BASEADDRESS)
#define TIMER3  ((Timer2_5_RegDef_t*) TIMER3_BASEADDRESS)
#define TIMER4  ((Timer2_5_RegDef_t*) TIMER4_BASEADDRESS)
#define TIMER5  ((Timer2_5_RegDef_t*) TIMER5_BASEADDRESS)
#define NVIC  	((NVIC_RegDef_t*)NVIC_BASEADDRESS)


#define GPIOD_PCLOCK_EN() (RCC->RCC_AHB1ENR |= 1 << 3)

#define TIMER2_PLCOCK_EN() (RCC->RCC_APB1ENR |= 1 << 0)
#define TIMER3_PLCOCK_EN() (RCC->RCC_APB1ENR |= 1 << 1)
#define TIMER4_PLCOCK_EN() (RCC->RCC_APB1ENR |= 1 << 2)
#define TIMER5_PLCOCK_EN() (RCC->RCC_APB1ENR |= 1 << 3)

#endif /* INC_STM32F411CE_H_ */
