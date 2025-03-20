/*
 * nvic_driver.c
 *
 *  Created on: Mar 14, 2025
 *      Author: tr6r2
 */

#include<stm32f411ce.h>

#include<nvic_driver.h>

static void (*Func_Callback[100])(void) = {NULL}; // Mảng callback

void NVIC_EnableIRQ(NVIC_Handle_t *pNVICHandle) {
	pNVICHandle->Instance->ISER[pNVICHandle->Config.IRQNumber / 32] |= (1 << (pNVICHandle->Config.IRQNumber % 32));
	Func_Callback[pNVICHandle->Config.IRQNumber] = pNVICHandle->Config.callback;
}
void Func_RegisterCallback(void (*callback)(void)) {
}
void TIM2_IRQHandler(void) {
    if (TIMER2->SR & (1 << 0)) {
    	TIMER2->SR &= ~(1 << 0);  // Xóa cờ ngắt
        if (Func_Callback[IRQn_Timer2]) {
        	Func_Callback[IRQn_Timer2]();  // Gọi callback nếu tồn tại
        }
    }
}
void TIM3_IRQHandler(void) {
    if (TIMER3->SR & (1 << 0)) {
    	TIMER3->SR &= ~(1 << 0);  // Xóa cờ ngắt
        if (Func_Callback[IRQn_Timer3]) {
        	Func_Callback[IRQn_Timer3]();  // Gọi callback nếu tồn tại
        }
    }
}
NVIC_Handle_t Create_NVICHandle(uint8_t IRQNumber,void (*callback)(void))
{
	NVIC_Handle_t pNVICHandle;
	pNVICHandle.Instance = NVIC;
	pNVICHandle.Config.IRQNumber = IRQNumber;
	pNVICHandle.Config.callback = callback;

	return pNVICHandle;

}

