/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: uboot_param_parse.h
 *
 *       Author: cs
 *        $Date: 2011/11/08 18:21:24 $
 *    $Revision: 3.2 $
 *
 *  Description: Header file for UBOOT parameter parsing lib
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: uboot_param_parse.h,v $
 * Revision 3.2  2011/11/08 18:21:24  ts
 * R: U-Boot version should be displayable under VxWorks 6.8 on EM10A
 * M: added define UBOOT_PARAM_VER
 *
 * Revision 3.1  2010/03/27 00:27:58  cs
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2010 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ****************************************************************************/

#ifndef _UBOOT_PARAM_PARSE_H_
#define _UBOOT_PARAM_PARSE_H_

#ifdef __cplusplus
	extern "C" {
#endif


extern void sysUbootParamInit(const char* ubootParamStart, unsigned int ubootParamSize);
extern const char* sysUbootParamParse( const char*parseStr );
extern int   sysUbootParamToRawEth(void *dest, const char *src );


#define UBOOT_PARAM_MAC_ADDR        "ethaddr"
#define UBOOT_PARAM_MAC_ADDR_FORMAT	"%x:%x:%x:%x:%x:%x"
#define UBOOT_PARAM_VERSION        	"ver"

#define UBOOT_PARAM_SER_BAUD        "baudrate"

#ifdef __cplusplus
	}
#endif

#endif /* _UBOOT_PARAM_PARSE_H_ */
