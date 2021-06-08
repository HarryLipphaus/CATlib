/*
 * CAT_Cmds.inc
 *
 *  Created on: 18.04.2021
 *      Author: Harry L. (dd9dr)
 */

#ifndef CAT_SRC_CAT_CMDS_INC_
#define CAT_SRC_CAT_CMDS_INC_

void Cat_Fx_Cmd(char *cmd, char *args);

const CatCmd_t CatCmds[] =
{
{ "FA", &Cat_Fx_Cmd },
{ "FB", &Cat_Fx_Cmd },
{ "  ", NULL } };


#endif /* CAT_SRC_CAT_CMDS_INC_ */
