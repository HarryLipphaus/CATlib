#!/bin/bash
#
# create new module from template
#

# TARGET_DIR=test/
TARGET_DIR=../Src/CAT_Cmds
DEF_FILE=../Src/CAT_Cmds.inc
EVT_FILE=../Inc/CAT_Events.inc



function create_command()
{
	UNAME=`echo "$1" | awk '{print toupper($0)}'`
	cat template/xyz_Cmd.c|sed -e s/xyz/$1/g | \
		sed -e s/XYZ/$UNAME/g > ${TARGET_DIR}/$1_Cmd.c
}

function create_enums()
{
# cat template/CAT_Events.1 > $1
cat template/CAT_Events.inc > $1
while read cmd; do
echo -e "\t${cmd}," >>$1
done < DX10_CAT.txt
echo -e "" >> $1;

# echo -e "\tCAT_NONE" >>$1
# echo "}CatEvent_t;" >>$1
# cat template/CAT_Events.2 >> $1
}

function create_protos()
{
while read cmd; do
echo -e "\tvoid CAT_${cmd}_Cmd(CatEventMsg_t *Source);" >>$1
done < DX10_CAT.txt
}

function create_table()
{
while read cmd; do
echo -en '\t{ '${cmd}', "' >>$1
echo -en ${cmd} >>$1
echo -en '", &CAT_' >>$1
echo -en ${cmd} >>$1
echo '_Cmd },' >>$1
done < DX10_CAT.txt
}

function create_handler()
{
while read cmd; do

    create_command $cmd		
done < DX10_CAT.txt
}

cat template/CAT_Cmds.1 > $DEF_FILE

create_enums $EVT_FILE
create_protos $DEF_FILE

cat template/CAT_Cmds.2 >> $DEF_FILE

create_table $DEF_FILE

cat template/CAT_Cmds.3 >> $DEF_FILE

create_handler
    
