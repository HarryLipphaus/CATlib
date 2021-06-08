/*
 * CAT_Cmds.inc
 *
 *  Created on: 18.04.2021
 *      Author: Harry L. (dd9dr)
 */

#ifndef CAT_SRC_CAT_CMDS_INC_
#define CAT_SRC_CAT_CMDS_INC_

	void Cat_AB_Cmd(char *cmd, char *args);
	void Cat_AC_Cmd(char *cmd, char *args);
	void Cat_AG_Cmd(char *cmd, char *args);
	void Cat_AI_Cmd(char *cmd, char *args);
	void Cat_AM_Cmd(char *cmd, char *args);
	void Cat_AO_Cmd(char *cmd, char *args);
	void Cat_AV_Cmd(char *cmd, char *args);
	void Cat_BA_Cmd(char *cmd, char *args);
	void Cat_BC_Cmd(char *cmd, char *args);
	void Cat_BD_Cmd(char *cmd, char *args);
	void Cat_BI_Cmd(char *cmd, char *args);
	void Cat_BM_Cmd(char *cmd, char *args);
	void Cat_BP_Cmd(char *cmd, char *args);
	void Cat_BS_Cmd(char *cmd, char *args);
	void Cat_BU_Cmd(char *cmd, char *args);
	void Cat_BY_Cmd(char *cmd, char *args);
	void Cat_CF_Cmd(char *cmd, char *args);
	void Cat_CH_Cmd(char *cmd, char *args);
	void Cat_CN_Cmd(char *cmd, char *args);
	void Cat_CO_Cmd(char *cmd, char *args);
	void Cat_CS_Cmd(char *cmd, char *args);
	void Cat_CT_Cmd(char *cmd, char *args);
	void Cat_DA_Cmd(char *cmd, char *args);
	void Cat_DN_Cmd(char *cmd, char *args);
	void Cat_DT_Cmd(char *cmd, char *args);
	void Cat_ED_Cmd(char *cmd, char *args);
	void Cat_EM_Cmd(char *cmd, char *args);
	void Cat_EN_Cmd(char *cmd, char *args);
	void Cat_EU_Cmd(char *cmd, char *args);
	void Cat_EX_Cmd(char *cmd, char *args);
	void Cat_FA_Cmd(char *cmd, char *args);
	void Cat_FB_Cmd(char *cmd, char *args);
	void Cat_FN_Cmd(char *cmd, char *args);
	void Cat_GT_Cmd(char *cmd, char *args);
	void Cat_ID_Cmd(char *cmd, char *args);
	void Cat_IF_Cmd(char *cmd, char *args);
	void Cat_IS_Cmd(char *cmd, char *args);
	void Cat_KM_Cmd(char *cmd, char *args);
	void Cat_KP_Cmd(char *cmd, char *args);
	void Cat_KR_Cmd(char *cmd, char *args);
	void Cat_KS_Cmd(char *cmd, char *args);
	void Cat_KY_Cmd(char *cmd, char *args);
	void Cat_LK_Cmd(char *cmd, char *args);
	void Cat_LM_Cmd(char *cmd, char *args);
	void Cat_MA_Cmd(char *cmd, char *args);
	void Cat_MB_Cmd(char *cmd, char *args);
	void Cat_MC_Cmd(char *cmd, char *args);
	void Cat_MD_Cmd(char *cmd, char *args);
	void Cat_MG_Cmd(char *cmd, char *args);
	void Cat_ML_Cmd(char *cmd, char *args);
	void Cat_MR_Cmd(char *cmd, char *args);
	void Cat_MS_Cmd(char *cmd, char *args);
	void Cat_MT_Cmd(char *cmd, char *args);
	void Cat_MW_Cmd(char *cmd, char *args);
	void Cat_MX_Cmd(char *cmd, char *args);
	void Cat_NA_Cmd(char *cmd, char *args);
	void Cat_NB_Cmd(char *cmd, char *args);
	void Cat_NL_Cmd(char *cmd, char *args);
	void Cat_NR_Cmd(char *cmd, char *args);
	void Cat_OL_Cmd(char *cmd, char *args);
	void Cat_OS_Cmd(char *cmd, char *args);
	void Cat_PA_Cmd(char *cmd, char *args);
	void Cat_PB_Cmd(char *cmd, char *args);
	void Cat_PC_Cmd(char *cmd, char *args);
	void Cat_PL_Cmd(char *cmd, char *args);
	void Cat_PR_Cmd(char *cmd, char *args);
	void Cat_PS_Cmd(char *cmd, char *args);
	void Cat_QI_Cmd(char *cmd, char *args);
	void Cat_QR_Cmd(char *cmd, char *args);
	void Cat_QS_Cmd(char *cmd, char *args);
	void Cat_RA_Cmd(char *cmd, char *args);
	void Cat_RC_Cmd(char *cmd, char *args);
	void Cat_RD_Cmd(char *cmd, char *args);
	void Cat_RF_Cmd(char *cmd, char *args);
	void Cat_RG_Cmd(char *cmd, char *args);
	void Cat_RI_Cmd(char *cmd, char *args);
	void Cat_RL_Cmd(char *cmd, char *args);
	void Cat_RM_Cmd(char *cmd, char *args);
	void Cat_RS_Cmd(char *cmd, char *args);
	void Cat_RT_Cmd(char *cmd, char *args);
	void Cat_RU_Cmd(char *cmd, char *args);
	void Cat_SC_Cmd(char *cmd, char *args);
	void Cat_SD_Cmd(char *cmd, char *args);
	void Cat_SF_Cmd(char *cmd, char *args);
	void Cat_SH_Cmd(char *cmd, char *args);
	void Cat_SM_Cmd(char *cmd, char *args);
	void Cat_SQ_Cmd(char *cmd, char *args);
	void Cat_SS_Cmd(char *cmd, char *args);
	void Cat_ST_Cmd(char *cmd, char *args);
	void Cat_SV_Cmd(char *cmd, char *args);
	void Cat_TS_Cmd(char *cmd, char *args);
	void Cat_TX_Cmd(char *cmd, char *args);
	void Cat_UL_Cmd(char *cmd, char *args);
	void Cat_UP_Cmd(char *cmd, char *args);
	void Cat_VD_Cmd(char *cmd, char *args);
	void Cat_VG_Cmd(char *cmd, char *args);
	void Cat_VM_Cmd(char *cmd, char *args);
	void Cat_VS_Cmd(char *cmd, char *args);
	void Cat_VX_Cmd(char *cmd, char *args);
	void Cat_XT_Cmd(char *cmd, char *args);
	void Cat_ZI_Cmd(char *cmd, char *args);

const CatCmd_t CatCmds[] =
{
	{ "AB", &Cat_AB_Cmd },
	{ "AC", &Cat_AC_Cmd },
	{ "AG", &Cat_AG_Cmd },
	{ "AI", &Cat_AI_Cmd },
	{ "AM", &Cat_AM_Cmd },
	{ "AO", &Cat_AO_Cmd },
	{ "AV", &Cat_AV_Cmd },
	{ "BA", &Cat_BA_Cmd },
	{ "BC", &Cat_BC_Cmd },
	{ "BD", &Cat_BD_Cmd },
	{ "BI", &Cat_BI_Cmd },
	{ "BM", &Cat_BM_Cmd },
	{ "BP", &Cat_BP_Cmd },
	{ "BS", &Cat_BS_Cmd },
	{ "BU", &Cat_BU_Cmd },
	{ "BY", &Cat_BY_Cmd },
	{ "CF", &Cat_CF_Cmd },
	{ "CH", &Cat_CH_Cmd },
	{ "CN", &Cat_CN_Cmd },
	{ "CO", &Cat_CO_Cmd },
	{ "CS", &Cat_CS_Cmd },
	{ "CT", &Cat_CT_Cmd },
	{ "DA", &Cat_DA_Cmd },
	{ "DN", &Cat_DN_Cmd },
	{ "DT", &Cat_DT_Cmd },
	{ "ED", &Cat_ED_Cmd },
	{ "EM", &Cat_EM_Cmd },
	{ "EN", &Cat_EN_Cmd },
	{ "EU", &Cat_EU_Cmd },
	{ "EX", &Cat_EX_Cmd },
	{ "FA", &Cat_FA_Cmd },
	{ "FB", &Cat_FB_Cmd },
	{ "FN", &Cat_FN_Cmd },
	{ "GT", &Cat_GT_Cmd },
	{ "ID", &Cat_ID_Cmd },
	{ "IF", &Cat_IF_Cmd },
	{ "IS", &Cat_IS_Cmd },
	{ "KM", &Cat_KM_Cmd },
	{ "KP", &Cat_KP_Cmd },
	{ "KR", &Cat_KR_Cmd },
	{ "KS", &Cat_KS_Cmd },
	{ "KY", &Cat_KY_Cmd },
	{ "LK", &Cat_LK_Cmd },
	{ "LM", &Cat_LM_Cmd },
	{ "MA", &Cat_MA_Cmd },
	{ "MB", &Cat_MB_Cmd },
	{ "MC", &Cat_MC_Cmd },
	{ "MD", &Cat_MD_Cmd },
	{ "MG", &Cat_MG_Cmd },
	{ "ML", &Cat_ML_Cmd },
	{ "MR", &Cat_MR_Cmd },
	{ "MS", &Cat_MS_Cmd },
	{ "MT", &Cat_MT_Cmd },
	{ "MW", &Cat_MW_Cmd },
	{ "MX", &Cat_MX_Cmd },
	{ "NA", &Cat_NA_Cmd },
	{ "NB", &Cat_NB_Cmd },
	{ "NL", &Cat_NL_Cmd },
	{ "NR", &Cat_NR_Cmd },
	{ "OL", &Cat_OL_Cmd },
	{ "OS", &Cat_OS_Cmd },
	{ "PA", &Cat_PA_Cmd },
	{ "PB", &Cat_PB_Cmd },
	{ "PC", &Cat_PC_Cmd },
	{ "PL", &Cat_PL_Cmd },
	{ "PR", &Cat_PR_Cmd },
	{ "PS", &Cat_PS_Cmd },
	{ "QI", &Cat_QI_Cmd },
	{ "QR", &Cat_QR_Cmd },
	{ "QS", &Cat_QS_Cmd },
	{ "RA", &Cat_RA_Cmd },
	{ "RC", &Cat_RC_Cmd },
	{ "RD", &Cat_RD_Cmd },
	{ "RF", &Cat_RF_Cmd },
	{ "RG", &Cat_RG_Cmd },
	{ "RI", &Cat_RI_Cmd },
	{ "RL", &Cat_RL_Cmd },
	{ "RM", &Cat_RM_Cmd },
	{ "RS", &Cat_RS_Cmd },
	{ "RT", &Cat_RT_Cmd },
	{ "RU", &Cat_RU_Cmd },
	{ "SC", &Cat_SC_Cmd },
	{ "SD", &Cat_SD_Cmd },
	{ "SF", &Cat_SF_Cmd },
	{ "SH", &Cat_SH_Cmd },
	{ "SM", &Cat_SM_Cmd },
	{ "SQ", &Cat_SQ_Cmd },
	{ "SS", &Cat_SS_Cmd },
	{ "ST", &Cat_ST_Cmd },
	{ "SV", &Cat_SV_Cmd },
	{ "TS", &Cat_TS_Cmd },
	{ "TX", &Cat_TX_Cmd },
	{ "UL", &Cat_UL_Cmd },
	{ "UP", &Cat_UP_Cmd },
	{ "VD", &Cat_VD_Cmd },
	{ "VG", &Cat_VG_Cmd },
	{ "VM", &Cat_VM_Cmd },
	{ "VS", &Cat_VS_Cmd },
	{ "VX", &Cat_VX_Cmd },
	{ "XT", &Cat_XT_Cmd },
	{ "ZI", &Cat_ZI_Cmd },
    { "  ", NULL } };


#endif /* CAT_SRC_CAT_CMDS_INC_ */
