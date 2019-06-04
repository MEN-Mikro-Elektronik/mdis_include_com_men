/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: em01_eeprom.h
 *
 *       Author: kp
 *
 *  Description: Layout of EM01 EEPROM
 *
 *     Switches: -
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2005-2019, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _EM01_EEPROM_H
#define _EM01_EEPROM_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

#define EM01_SMB_SROM_SIZE	(0x400)
#define EM01_SMB_SROM_MM	0xa8
#define EM01_SMB_SROM_VX	0xae /* at 0x300 in EEPROM (0x100 bytes) */

/* get address of structure component */
#ifndef offsetof
	#define offsetof(type, part)	((int)((char*)&((type*)0)->part-(char*)0))
#endif

#define EM01_EEPROM_STARTUP_LEN		(0x180-0x70)
#define EM01_KERPAR_LEN				0x180
#define EM01_VXBLINE_LEN			0x100

/* structure holding LM81 calibration parameters ( 7 byte ) */
typedef	struct _LM81_PARMS
{
    u_int8      lm81_id;        	/* struct ID (0xA) and parity */
    u_int8      lm81_2V5;
    u_int8      lm81_3V3;
    u_int8      lm81_5V0;
    u_int8      lm81_vcore;
    u_int8      lm81_1V2;
    u_int8      lm81_res;			/* currently not used */
} LM81_PARMS;


/*
 * EEPROM structure
 * The entire structure covers 0x400 Byte (1KByte) (24C08)
 */
typedef struct {
    /*--- offset 0x00: production data, hardware information (24 byte) ---*/
	EEPROD2 pd;

    /*--- offset 0x18: MENMON parameters (68 bytes) ---*/
    struct menm_parms
    {
        u_int8      mm_id;        	/* struct ID (0x5) and parity */
		u_int8      mm_misc;      	/* misc flags */
		u_int8      mm_selftest;  	/* selftest options */
		u_int8		mm_tto;			/* network timeout */

        u_int32     mm_cbaud;     	/* console baudrate */
        u_int32     mm_bsadr;     	/* address of bootstrapper */

		u_int16		mm_vmode;		/* gfx video mode */
		int16	   	mm_tdp;			/* telnet daemon port */
		int16	   	mm_hdp;			/* HTTP daemon port */
		int16		mm_wdt;			/* watchdog timer setting ???*/

		u_int8		mm_stwait;		/* selftest wait time */
		u_int8	   	mm_gcon;		/* gfx console select */
		u_int8	   	mm_con[4];		/* console selectors  */
		u_int8	   	mm_ecl;			/* ethernet I/F select */
		int8		mm_tries; 		/* network retries
									   -1 default = 20, 0 forever or 1..127 */
		u_int8		mm_nspeed[3];	/* ethernet speed */

		u_int16		mm_usr[16];		/* user defined */
		u_int8		mm_powerReset; 	/* power supervision reset flags  */
		u_int8		_resvd[3];		/* reserved */
    } menm;

	/*--- offset 0x5C: LM81 calibration parameters ( 7 byte ) ---*/
	LM81_PARMS lm81;

	/*--- offset 0x63: reserved ( 13 byte ) ---*/
	char _rsvd[13];

	/*--- offset 0x70: MENMON startup string (0x180-(pd+menm)) ---*/
	char	startup[EM01_EEPROM_STARTUP_LEN];

	/*--- offset 0x180: Linux kernel parameters (used by MENMON and Linux)*/
	char	kerpar[EM01_KERPAR_LEN];

	/*--- offset 0x300: vxWorks Bootline string (used by MENMON and VxWorks)*/
	char	vxBline[EM01_VXBLINE_LEN];

} EM01_EEPROM;

/*
 * Struct Ids
 */
#define EEID_PD      		0xd
#define EM01_EEID_MENM    	0x5
#define EM01_EEID_LM81    	0xA   /* LM81 calibration values */


#ifdef __cplusplus
	}
#endif

#endif /* _EM01_EEPROM_H */








