/*
 * FB_Cmd.c
 *
 *  Created on: 18.04.2021
 *      Author: Harry L. (dd9dr)
 */

#include <stdlib.h>
#include "CAT_Cmds.h"

void CAT_FB_Cmd(char *cmd, char *args)
{
	Event_t Event;
	Event.Event = FB;
	uint32_t freq;

	freq = atol(args);
	if (freq != Trx.Vfo_B)
	{
		Trx.Vfo_B = freq;
		xQueueSend(CatEventHandle, &Event, portMAX_DELAY);
	}
	UNUSED(cmd);
}
