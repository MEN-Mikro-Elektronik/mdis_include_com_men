/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: em09_eeprom.h
 *
 *       Author: aw
 *
 *  Description: Layout of MEN EM09's serial EEPROM/FLASH
 *               cloned from EM03
 *
 *     Switches: SYSP_EM09_VARIANT_A017 - A017 specific eeprom layout
 *               SYSP_EM09_VARIANT_XM50 - XM50 specific eeprom layout
 *
 *---------------------------------------------------------------------------
 * Copyright 2007-2019, MEN Mikro Elektronik GmbH
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
#ifndef _EM09_EEPROM_H
#define _EM09_EEPROM_H

#if defined( SYSP_EM09_VARIANT_A017 ) || defined( SYSP_EM09_VARIANT_XM50 )
 #define EM09_EEPROM_STARTUP_LEN		0x100
#else
 #define EM09_EEPROM_STARTUP_LEN		0x90
#endif /*if defined( SYSP_EM09_VARIANT_A017 )...*/
#define EM09_VXBLINE_LEN			0x100

#define EM09_FLASH_STARTUP_LEN		512
#define EM09_FLASH_KERPAR_LEN		400

#define EM09_SMB_SROM_SIZE	(0x100)
#define EM09_SMB_SROM_MM	0xa8
#if defined( SYSP_EM09_VARIANT_A017 ) || defined( SYSP_EM09_VARIANT_XM50 )
	#define EM09_SMB_SROM_VX	0xae /* at 0x300 in EEPROM (0x100 bytes) */
#else /* SYSP_EM09_VARIANT_A017 || SYSP_EM09_VARIANT_XM50 */
	#define EM09_SMB_SROM_VX	0xaa /* at 0x100 in EEPROM (0x100 bytes) */
#endif /* SYSP_EM09_VARIANT_A017 || SYSP_EM09_VARIANT_XM50 */

/* get address of structure component */
#ifndef offsetof
	#define offsetof(type, part)	((int)((char*)&((type*)0)->part-(char*)0))
#endif

/* the entire structure covers 0x200 byte for EM9 */
/*                            (0x400 byte for A17 and XM50 hw model) */

typedef struct {
    /*--- offset 0x0: production data, hardware information (24 byte) ---*/
	EEPROD2 pd;

    /*--- offset 0x18: MENMON parameters
     *                  88 bytes on EM9
     *                 344 bytes on A17, XM50 ---*/
    struct menm_parms {
        u_int8      mm_id;        /* struct ID (0x5) and parity */
		u_int8      mm_misc;      /* misc flags */
		u_int8      mm_selftest;  /* selftest options */
		u_int8	   	mm_selftest2; /* more selftest options */
        u_int32     mm_cbaud;     /* console baudrate */
        u_int32     mm_bsadr;     /* address of bootstrapper */
        u_int16		mm_usr[16];   /* user parameters */

		u_int8	   	mm_con[4];		/* console selectors  */
		u_int16		mm_vmode;		/* gfx video mode */
		u_int8	   	mm_gcon;		/* gfx console select */
		u_int8	   	mm_ecl;			/* ethernet I/F select */
		u_int8	   	mm_tto;			/* network timeout */
		u_int8	   	mm_tries;		/* network tries */

		u_int8		mm_stwait;		/* selftest wait time */
		u_int8		mm_eccSingleTh;	/* ECC single bit error MC threshold */

		int16	   	mm_tdp;			/* telnet daemon port */
		int16	   	mm_hdp;			/* HTTP daemon port */
		int16		mm_wdt;			/* watchdog timer setting */

		u_int8		mm_nspeed[3];	/* ethernet speed */

		u_int8		mm_powerReset; 	/* power supervision reset flags  */
		u_int8		mm_pci_opts;  /* various PCI option flags */

#ifdef SYSP_EM09_VARIANT_A017
		u_int8		mm_vme_in[17];	/* VME inbound windows */
		u_int8		mm_resvd_1[0x7F];
		u_int8		mm_vme_irq;		/* VME irq levels */
		u_int8		mm_nspeed_3;	/* ethernet speed for eth3 */
		u_int8	   	mm_resvd_2[0x83];
#elif defined( SYSP_EM09_VARIANT_XM50 )
		u_int8		mm_resvd_1[277];
#else
		u_int8		mm_nspeed_3; 	/* ethernet speed for eth3 at EM09A */
		u_int8	   	mm_resvd_1[20];
#endif /*SYSP_EM09_VARIANT_A017*/
    } menm;

	/*--- offset 0x070 for EM9
	 *           0x170 for A17 and XM50: MENMON startup string ---*/
	char	startup[EM09_EEPROM_STARTUP_LEN];

#if defined( SYSP_EM09_VARIANT_A017 ) || defined( SYSP_EM09_VARIANT_XM50 )
	u_int8	resvd[0x90];
#endif

	/*--- offset 0x100 for EM9
	 *           0x300 for A17 and XM50: vxWorks Bootline string
	 *    (used by MENMON and VxWorks) ---*/
	char	vxBline[EM09_VXBLINE_LEN];
} EM09_EEPROM;

/* Placed in last flash sector within secondary MENMON */
typedef struct {
	struct flstr_parms {
		u_int8	   	fl_id;		/* struct ID (0x7) and parity */
		u_int8 		fl_pad;
		char		fl_startup[EM09_FLASH_STARTUP_LEN];
		char		fl_kerpar[EM09_FLASH_KERPAR_LEN];
	} flstr;

} EM09_BFLASH_PARMS;

#define EM09_EEID_MENM    0x5
#define EM09_FLID_STR     0x7


#endif /* _EM09_EEPROM_H */



