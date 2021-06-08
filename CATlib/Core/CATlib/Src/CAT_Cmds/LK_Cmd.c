/*
 * LK_Cmd.c
 *
 *  Created on: 18.04.2021
 *      Author: Harry L. (dd9dr)
 */

#include "CATlib.h"

void CAT_LK_Cmd(CatEventMsg_t *Source)
{
	Event_t Event;
	Event.Source = Source;
	Event.Event = LK;
	UNUSED(Event);

	/* USER CODE BEGIN */

	/* Event should only be fired if valus/settings has changed! */
	// xQueueSend(CatEventHandle, &Event, portMAX_DELAY);

	/* USER CODE END */

}
