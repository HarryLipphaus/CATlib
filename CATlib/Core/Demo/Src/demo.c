/*
 * demo.c
 *
 *  Created on: Apr 18, 2021
 *      Author: Harry L. (dd9dr)
 */

#include "CATlib.h"
#include "gpio.h"
#include "max7219.h"

const char TRXName[] = "Yaesu FT-DX10";
uint8_t Radio;

void demo_init(UART_HandleTypeDef *handle)
{
	init_max7219();
	set_brightness_max7219(0x02);
	for (uint8_t i = 0; i < 8; i++)
		set_digit_max7219(i, 0x0f);

	Radio = CAT_Init(RADIO, TRXName, handle);
}

void Freq_Display(uint32_t freq)
{
	if (freq > 99999999)
	{
		freq /= 10;
		set_val_max7219(freq, 0b00100100);
	}
	else
		set_val_max7219(freq, 0b01001000);
}

/*********************************************************
 *
 * Default Task is always generated by CubeMX.
 * Set the Code-generation of this task in CubeMX to weak
 *
 ********************************************************/
void StartDefaultTask(void *argument)
{
	for (;;)
	{
		// send VFO-B Frequency request
//		CAT_SendCmd(Radio, "FB");
		HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
		osDelay(40);
		// send VFO-A Frequency request
//		CAT_SendCmd(Radio, "FA");
		osDelay(40);
	}
}

/*********************************************************
 *
 * Display Task takes care of updating our display if
 * a monitored value has been changed
 *
 ********************************************************/

void StartEventTask(void *argument)
{
	CatEventMsg_t Event;

	for (;;)
	{
		xQueueReceive(CatEventHandle, &Event, portMAX_DELAY);
		switch (Event.Event)
		{
		case FA:	// received VFO-A frequency changed
//			Freq_Display(Event Trx.Vfo_A);
			break;

		case FB:	// received VFO-B frequency changed
//			Freq_Display(Trx.Vfo_B);
			break;

		default:
			break;
		}
	}
}


