#include <stm32f411ce.h>
#include <timer2_5_driver.h>


Timer2_5_Handle_t Timer2_5_CreateHandle(Timer2_5_RegDef_t* timerx,uint8_t timer_number, uint32_t prc, uint32_t arr)
{
	Timer2_5_Handle_t TimerX;
	TimerX.Timer = timerx;
	TimerX.Config.prc = prc;
	TimerX.Config.timer_number = timer_number;
	TimerX.Config.arr = arr;

	return TimerX;
}
void Init_Timer2_5(Timer2_5_Handle_t *timerx)
{
	if (timerx->Config.timer_number == Timer_no2) {
		TIMER2_PLCOCK_EN();
	}
	else
	{
		TIMER3_PLCOCK_EN();
	}
	timerx->Timer->PSC = timerx->Config.prc;
	timerx->Timer->ARR = timerx->Config.arr;

	timerx->Timer->DIER |= 1 << 0;

	timerx->Timer->CNT = 0;

	timerx->Timer->CR1 |= 1<< 0;
}

void Delay(Timer2_5_Handle_t* timerx)
{
	timerx->Timer->CNT = 0;
	timerx->Timer->SR &= ~(1 << 0);

	while (!(timerx->Timer->SR & 0b01));
}
