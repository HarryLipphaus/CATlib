/*
 * serial.h
 * for use with FreeRTOS
 *
 *  Created on: 19.04.2021
 *      Author: harry
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "cmsis_os.h"

#include "usart.h"

#include "config.h"

#ifndef FALSE
#define FALSE	0
#define TRUE	(!FALSE)
#endif

#ifndef MAX_SERIAL
#define MAX_SERIAL			2
#endif

typedef enum
{
	/*
	RADIO,
	CONTROLER,
	CONSOLE,
*/
	OTHER
}SerialDevice_t;

typedef enum
{
	CAT,
	CON,
	RAW
}SerialMode_t;

typedef struct
{
	// General
	SerialMode_t		DeviceType;
	UART_HandleTypeDef 	*Handle;

	// Queues
	osMessageQueueId_t	TxQueueHandle;
	const osMessageQueueAttr_t *TxQueueAttr;

	osMessageQueueId_t	RxQueueHandle;
	const osMessageQueueAttr_t *RxQueueAttr;

	// API
	void (*putc)(void *SerIf, char c);

	// internal
	uint8_t busy;
	uint8_t rxbuf;
	uint8_t txbuf;
}Serial_t;

extern Serial_t	Serial_IF[MAX_SERIAL];

void SerialInit(void);

//uint8_t SerialInit(SerialDevice_t dev, const char *DevName, UART_HandleTypeDef *huart);
void serial_putc(Serial_t *iface, char c);
Serial_t* SerialAdd(UART_HandleTypeDef *huart);

#endif /* SERIAL_H_ */
