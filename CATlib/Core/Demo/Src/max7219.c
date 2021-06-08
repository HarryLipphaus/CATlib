/*
 * max7219.c
 *
 *  Created on: 30.04.2016
 *      Author: harry
 */

#include "gpio.h"

#include <stdlib.h>

#include "max7219.h"

// define Hardware
#define MAXCLK(a)   HAL_GPIO_WritePin(MAX_CLK_GPIO_Port, MAX_CLK_Pin, a)
#define MAXCS(a)    HAL_GPIO_WritePin(MAX_CS_GPIO_Port, MAX_CS_Pin, a)
#define MAXDTA(a)  	HAL_GPIO_WritePin(MAX_DIN_GPIO_Port, MAX_DIN_Pin, a)


#define MAX7219_NOP		0x00
#define MAX7219_DIGIT0	0x01
#define MAX7219_DIGIT1	0x02
#define MAX7219_DIGIT2	0x03
#define MAX7219_DIGIT3	0x04
#define MAX7219_DIGIT4	0x05
#define MAX7219_DIGIT5	0x06
#define MAX7219_DIGIT6	0x07
#define MAX7219_DIGIT7	0x08
#define MAX7219_DECMOD	0x09
#define MAX7219_INTENS	0x0a
#define MAX7219_SCANL	0x0b
#define MAX7219_SHUTDWN	0x0c
#define MAX7219_TEST	0x0f

void send_max7219(uint8_t Register, uint8_t Value)
{
	uint8_t i;
	uint16_t vv = (Register <<8) + Value;

	MAXCS(RESET);
	for (i = 0; i < 16; i++)
	{
		if (vv & 0x8000)
			MAXDTA(SET);
		else
			MAXDTA(RESET);
		vv <<= 1;
		MAXCLK(SET);
//		HAL_Delay(1);
		MAXCLK(RESET);
//		HAL_Delay(1);
	}
	MAXCS(SET);
}

void init_max7219(void)
{
	MAXCS(SET);
	send_max7219(MAX7219_SHUTDWN, 0x01);
	send_max7219(MAX7219_DECMOD, 0xff);
	send_max7219(MAX7219_SCANL, 0x07);
	set_brightness_max7219(7);
}

void set_brightness_max7219(uint8_t brightness)
{
	send_max7219(MAX7219_INTENS, brightness);
}

void set_digit_max7219(uint8_t digit, uint8_t val)
{
	send_max7219(digit + 1, val);
}

void set_val_max7219(int32_t val, uint8_t dpoint)
{
	int32_t v;
	uint8_t i, j;
	uint8_t dpoint_mask = 0x01;
	j = 0;
	v = abs(val);
	for (i = 0; i < 8; i++)
	{
		if (v > 0)
		{
			if (dpoint_mask & dpoint)
//			if ((dpoint == i) && (dpoint != 0))
				set_digit_max7219(i, (v % 10) | 0x80);
			else
				set_digit_max7219(i, v % 10);

			v /= 10;
		}
		else
		{
			if (i <= dpoint)
			{
				set_digit_max7219(i, 0x0f);
				if (i == dpoint)
				{
					set_digit_max7219(i, 0x0f | 0x80);
				}
			}
			else
			{
				if ((val < 0) && (j == 0))
				{
					set_digit_max7219(i, 0x0a);
					j = 1;
				}
				else
				{
					set_digit_max7219(i, 0xf);
				}
			}
		}
		dpoint_mask <<= 1;
	}
}
