/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: esm_cb_eeprom.h
 *
 *       Author: cs
 *        $Date: 2007/07/11 14:37:54 $
 *    $Revision: 3.2 $
 *
 *  Description: Layout of ESM carrier board's serial EEPROM
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
#ifndef _ESM_CB_EEPROM_H
#define _ESM_CB_EEPROM_H

#include <MEN/eeprod.h>

/* defines to be used with esm_cb_info_parms.ci_hw_flag */
#define	ESM_CB_HW_FLAG_HAS_TOUCH		0x00000001
#define ESM_CB_HW_FLAG_TOUCH_NO_ID		0x00000002 /*bits 2,3 should be reserved
													 for other touch controllers
													*/

/* the entire structure covers 0x200 Byte (512 Byte) */
typedef struct {
    /*--- offset 0x0: production data, hardware information (24 byte) ---*/
	EEPROD2 pd;

	struct esm_cb_info_parms {
        u_int8      ci_id;				/* struct ID (0x6) and parity 		*/
        u_int8		ci_resvd[3];
		u_int32		ci_hw_flag;			/* bit 0: CB has Touch controller
        								 * bit 1: touch controller without ID
        								 * bit 24-31: reserved for 
        								 * 			  board specific things */
		u_int8		ci_custPNum[16]; 	/* partnumber for use by customer
										 * string, null term. 				*/
	} cbinfo;

    /*--- offset 0x30: MENMON parameters (??? bytes) ---*/
    struct esm_cb_menm_parms {
        u_int8      mm_id;			/* struct ID (0x7) and parity */
        u_int8		mm_resvd[3];
        struct {					/* touch panel calibration data */
        	u_int32 xoffset;
        	u_int32 xscale;
        	u_int32 yoffset;
        	u_int32 yscale;
        } tcal;
		u_int8		mm_mode_com1[4];	/* COM1x mode (RS232,RS422,RS485) */

		u_int8		mm_resvd2[27];
    } menm;



	/*--- offset 0x60:  Available to user ---*/
    u_int8 	user[0x200-0x60];

} ESM_CB_EEPROM;

#define ESM_CB_EEID_CBINFO  0x6
#define ESM_CB_EEID_MENM    0x7

#endif /* _ESM_CB_EEPROM_H */


