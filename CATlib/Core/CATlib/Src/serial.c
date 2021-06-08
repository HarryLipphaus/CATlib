/*
 * serial.c
 * for use with FreeRTOS
 *
 *  Created on: 20.04.2021
 *      Author: harry
 */

#include "usart.h"

//#include "gpio.h"

#include "config.h"
#include "serial.h"

static uint8_t IFNum = 0;

Serial_t Serial_IF[MAX_SERIAL];

/* Definitions for Tx1Queue */
//osMessageQueueId_t Tx1QueueHandle;
const osMessageQueueAttr_t TxQueue_attributes[MAX_SERIAL] =
{
{ .name = "Tx1Queue" },
#if MAX_SERIAL>1
		{ .name = "Tx2Queue" },
#endif
#if MAX_SERIAL>2
		{ .name = "Tx3Queue" }
#endif
#if MAX_SERIAL>3
		{ .name = "Tx4Queue" }
#endif
#if MAX_SERIAL>4
		{ .name = "Tx5Queue" }
#endif
#if MAX_SERIAL>5
		{ .name = "Tx6Queue" }
#endif
		};

/* Definitions for Rx1Queue */
//osMessageQueueId_t Rx1QueueHandle;
const osMessageQueueAttr_t RxQueue_attributes[MAX_SERIAL] =
{
{ .name = "Rx1Queue" },
#if MAX_SERIAL>1
		{ .name = "Rx2Queue" },
#endif
#if MAX_SERIAL>2
		{ .name = "Rx3Queue" }
#endif
#if MAX_SERIAL>3
		{ .name = "Rx4Queue" }
#endif
#if MAX_SERIAL>4
		{ .name = "Rx5Queue" }
#endif
#if MAX_SERIAL>5
		{ .name = "Rx6Queue" }
#endif
		};

// static char EditBuffer[RX_BUFFER_SIZE];

void StartRx1Task(void *argument);

/********************************************************************
 * Uart API-Fuctions
 ********************************************************************/

void SerialInit(void)
{
	uint8_t i;
	for (i = 0; i < MAX_SERIAL; i++)
	{
		Serial_IF[i].TxQueueHandle = osMessageQueueNew(TX_BUFFER_SIZE,
				sizeof(char), &TxQueue_attributes[i]);
		Serial_IF[i].RxQueueHandle = osMessageQueueNew(RX_BUFFER_SIZE,
				sizeof(char), &RxQueue_attributes[i]);
		Serial_IF[i].busy = FALSE;
	}
}

Serial_t* SerialAdd(UART_HandleTypeDef *huart)
{
	if (IFNum < MAX_SERIAL)
	{
		Serial_IF[IFNum].Handle = huart;

		// create Queues
		Serial_IF[IFNum].TxQueueHandle = osMessageQueueNew(TX_BUFFER_SIZE,
				sizeof(char), &TxQueue_attributes[IFNum]);
		Serial_IF[IFNum].RxQueueHandle = osMessageQueueNew(RX_BUFFER_SIZE,
				sizeof(char), &RxQueue_attributes[IFNum]);

		HAL_UART_Receive_IT(Serial_IF[IFNum].Handle, &Serial_IF[IFNum].rxbuf,
				1);
		return &Serial_IF[IFNum++];
	}
	else
		return NULL;
}

void serial_putc(Serial_t *iface, char c)
{
	if (iface->busy == FALSE)
	{
		iface->txbuf = c;
		iface->busy = TRUE;
		HAL_UART_Transmit_IT(iface->Handle, (uint8_t*) &iface->txbuf, 1);
	}
	else
	{
		while (xQueueSend(iface->TxQueueHandle, &iface->txbuf, portMAX_DELAY)
				!= pdPASS)
			;
	}
}

/********************************************************************
 * Uart Iterrupt-Handler
 ********************************************************************/

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	int i;
	for (i = 0; (Serial_IF[i].Handle != huart) && (i < IFNum); i++)
		;
	if (Serial_IF[i].Handle == huart)
	{
		xQueueSendFromISR(Serial_IF[i].RxQueueHandle, &Serial_IF[i].rxbuf,
				NULL);
		HAL_UART_Receive_IT(Serial_IF[i].Handle, &Serial_IF[i].rxbuf, 1);

	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	int i;
	for (i = 0; (Serial_IF[i].Handle != huart) && (i < IFNum); i++)
		;
	if (Serial_IF[i].Handle == huart)
	{
		if (xQueueReceiveFromISR(Serial_IF[IFNum].TxQueueHandle,
				&Serial_IF[i].txbuf,
				NULL) == pdPASS)
		{
			HAL_UART_Transmit_IT(Serial_IF[i].Handle,
					(uint8_t*) &Serial_IF[i].txbuf, 1);
		}
		else
			Serial_IF[i].busy = FALSE;
	}

}

