/*
 * FA_Cmd.c
 *
 *  Created on: 18.04.2021
 *      Author: Harry L. (dd9dr)
 */

#include <stdlib.h>
#include "CAT_Cmds.h"

void CAT_FA_Cmd(char *cmd, char *args)
{
	Event_t Event;
	Event.Event = FA;
	uint32_t freq;

	freq = atol(args);
	if (freq != Trx.Vfo_A)
	{
		Trx.Vfo_A = freq;
		xQueueSend(CatEventHandle, &Event, portMAX_DELAY);
	}
	UNUSED(cmd);
}
