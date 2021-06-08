/*
 * CATlib.h
 *
 *  Created on: Apr 20, 2021
 *      Author: Harry L. (dd9dr)
 */

#ifndef CATLIB_INC_CATLIB_H_
#define CATLIB_INC_CATLIB_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "cmsis_os.h"

#include "config.h"
#include "usart.h"

#include "CAT_com.h"

#ifndef FALSE
#define FALSE	0
#define TRUE	(!FALSE)
#endif

typedef enum
{
	RADIO,
	ROTOR,
	CONTROLER
}CatType_t;

typedef enum
{
	SYS,
	RADIO_1,
	RADIO_2,
	CONTROL_1,
	CONTROL_2
}EventSource_t;

typedef struct
{
	CatEvent_t	Event;
	void 		*Dta;
	void 		*Source;
}Event_t;

extern osMessageQueueId_t CatEventHandle;

uint8_t CAT_Init(CatType_t dev, const char * DevName, UART_HandleTypeDef *huart);
void CAT_SendCmd(uint8_t ifnum, char *Cmd);


#endif /* CATLIB_INC_CATLIB_H_ */
