/*
 * CAT_com.h
 *
 *  Created on: Apr 20, 2021
 *      Author: Harry L. (dd9dr)
 */

#ifndef CATLIB_INC_CAT_COM_H_
#define CATLIB_INC_CAT_COM_H_

#define CAT_BUFFER_SIZE		64

#include "serial.h"
#include "Radio.h"

typedef enum {
#include "CAT_Events.inc"

	NOP
}CatEvent_t;


typedef struct
{
	CatEvent_t Event;
	void *Radio;
	char args[CAT_BUFFER_SIZE];
} CatEventMsg_t;

typedef struct
{
// General

// Tasks
	osThreadId_t CatTaskHandle;
	const osThreadAttr_t CatTaskAttributes;

// internal
	Serial_t *com;
	char CmdBuf[CAT_BUFFER_SIZE];
	uint8_t Buf_p;
} CatCom_t;

typedef struct
{
	const char *DeviceName;
	Radio_t settings;
	CatCom_t iface;
} TRX_t;

typedef struct
{
	CatEvent_t Event;
	char cmd[3];
	void (*CmdFunc)(CatEventMsg_t *);
}CatCmd_t;

// Queues
	osMessageQueueId_t EventQueueHandle;
	const osMessageQueueAttr_t *EventQueueAttr;

extern const CatCmd_t CatCmds[];


extern TRX_t Radios[MAX_SERIAL];

void CAT_init(void);
TRX_t* CatAdd(const char *DevName, UART_HandleTypeDef *huart);

#endif /* CATLIB_INC_CAT_COM_H_ */
