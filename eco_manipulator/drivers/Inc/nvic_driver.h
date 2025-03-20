/*
 * nvic_driver.h
 *
 *  Created on: Mar 14, 2025
 *      Author: tr6r2
 */

#ifndef INC_NVIC_DRIVER_H_
#define INC_NVIC_DRIVER_H_

#include<stm32f411ce.h>


#define IRQn_Timer2 28
#define IRQn_Timer3 29
#define IRQn_Timer4 30
#define IRQn_Timer5 50

typedef struct {
    uint8_t IRQNumber;    // Số hiệu IRQ (Interrupt Request Number)
    uint8_t Enable;       // Bật (1) hoặc Tắt (0) ngắt
    void (*callback)(void);
} NVIC_Config_t;

typedef struct {
    NVIC_Config_t Config; // Cấu hình NVIC
    NVIC_RegDef_t *Instance;
} NVIC_Handle_t;

NVIC_Handle_t Create_NVICHandle(uint8_t IRQNumber,void (*callback)(void));
void NVIC_EnableIRQ(NVIC_Handle_t *pNVICHandle);
void Func_RegisterCallback(void (*callback)(void));


#endif /* INC_NVIC_DRIVER_H_ */
