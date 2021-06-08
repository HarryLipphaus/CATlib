/*
 * CAT_com.c
 *
 *  Created on: Apr 20, 2021
 *      Author: Harry L. (dd9dr)
 */

#include <string.h>
#include "CATlib.h"
#include "CAT_com.h"
#include "serial.h"

//#include "CAT_Cmds.h"
#include "CAT_Cmds.inc"

static uint8_t buffer_p;

//static serial_rx_buf_t EditBuffer;
//static uint8_t tx_buffer[TX_BUFFER_SIZE];
//static serial_rx_buf_t *TargetBuffer;

/* Definitions for RxCmdQueue */
osMessageQueueId_t RxCmdQueueHandle;

osThreadId_t EventTaskHandle;

TRX_t Radios[MAX_SERIAL];
static uint8_t CatNum = 0;

/* Definitions for CmdQueue */
const osMessageQueueAttr_t CmdQueue_attributes[MAX_SERIAL] =
{
{ .name = "Cmd1Queue" },
#if MAX_SERIAL>1
		{ .name = "Cmd2Queue" },
#endif

#if MAX_SERIAL>2
		{ .name = "Cmd3Queue" }
#endif
		};

void StartCatTask(void *argument);
void StartEventTask(void *argument);

const osMessageQueueAttr_t EventQueue_attributes =
{ .name = "Event1Queue" };

const osThreadAttr_t CatTask_attributes[MAX_SERIAL] =
{
{ .name = "Cat1Task", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityNormal, },
#if MAX_SERIAL>1
		{ .name = "Cat2Task", .stack_size = 128 * 4, .priority =
				(osPriority_t) osPriorityNormal, },
#endif
#if MAX_SERIAL>2
		{ .name = "Cat3Task", .stack_size = 128 * 4, .priority =
				(osPriority_t) osPriorityNormal, },
#endif
		};

const osThreadAttr_t EventTask_attributes =
{
		.name = "EventTask", .stack_size = 128 * 4, .priority =
		(osPriority_t) osPriorityNormal,
};



void CAT_init(void)
	{
		uint8_t i;
		for (i = 0; i < MAX_SERIAL; i++)
		{
			Radios[i].iface.CmdBuf[0] = 0;
			Radios[i].iface.Buf_p = 0;
		}
		EventQueueAttr = &EventQueue_attributes;
		EventTaskHandle = osThreadNew(StartEventTask, NULL,
				&EventTask_attributes);
		SerialInit();
	}

	TRX_t* CatAdd(const char *DevName, UART_HandleTypeDef *huart)
	{
		if (CatNum < MAX_SERIAL)
		{
//			Radios[CatNum].msg.Radio = &Radios[CatNum];
//			Radios[CatNum].msg.CatNum = CatNum;
			Radios[CatNum].DeviceName = DevName;

			EventQueueHandle = osMessageQueueNew(2,	RX_BUFFER_SIZE, EventQueueAttr);

			Radios[CatNum].iface.CatTaskHandle = osThreadNew(StartCatTask,
					&Radios[CatNum], &CatTask_attributes[CatNum]);
			Radios[CatNum].iface.com = SerialAdd(huart);
			return &Radios[CatNum++];
		}
		else
			return NULL;
	}

	void StartCatTask(void *argument)
	{
		TRX_t *Radio = argument;
		int i;
		char rxc;
		CatEventMsg_t msg;

		for (;;)
		{
			xQueueReceive(Radio->iface.com->RxQueueHandle, &rxc, portMAX_DELAY);
			if (rxc == ';')
			{
				Radio->iface.Buf_p = 0;

				for (i = 0;
						(CatCmds[i].CmdFunc != NULL)
								&& (memcmp(Radio->iface.CmdBuf, CatCmds[i].cmd, 2));
						i++)
					;
				if (CatCmds[i].CmdFunc != NULL)
				{
					msg.Event = CatCmds[i].Event;
					msg.Radio = Radio;
					strcpy(msg.args, &Radio->iface.CmdBuf[2]);
					CatCmds[i].CmdFunc(&msg);
				}
				else
				{
					// pass thrue
				}

				xQueueSend(EventQueueHandle, &msg, portMAX_DELAY);
			}
			else if (rxc >= ' ')
			{
				if (buffer_p < (CAT_BUFFER_SIZE - 1))
				{
					Radio->iface.CmdBuf[Radio->iface.Buf_p++] = rxc;
					Radio->iface.CmdBuf[Radio->iface.Buf_p] = '\0';
				}
			}
		}
	}

__weak void StartEventTask(void *argument)
	{
		CatEventMsg_t msg;

		for (;;)
		{
			xQueueReceive(EventQueueHandle, &msg, portMAX_DELAY);
		}
	}

