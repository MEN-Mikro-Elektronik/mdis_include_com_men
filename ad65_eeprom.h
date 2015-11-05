/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ad65_eeprom.h
 *
 *       Author: ub
 *        $Date: 2005/06/23 15:54:54 $
 *    $Revision: 2.3 $
 *
 *  Description: Layout of MEN AD65 carrier board's serial EEPROM
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: ad65_eeprom.h,v $
 * Revision 2.3  2005/06/23 15:54:54  kp
 * Copyright string changed (sbo)
 *
 * Revision 2.2  2002/09/30 13:43:36  ub
 * EEID_PD now in eeprod.h
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2002 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ****************************************************************************/
#ifndef _AD65_EEPROM_H
#define _AD65_EEPROM_H

#include <MEN/eeprod.h>

/* the entire structure covers 0x200 Byte (512 Byte) */

typedef struct {
    /*--- offset 0x0: production data, hardware information (16 byte) ---*/
	EEPROD pd;

    /*--- offset 0x10: MENMON parameters (??? bytes) ---*/
    struct ad65_menm_parms {
        u_int8      mm_id;			/* struct ID (0x5) and parity */
        u_int8		mm_resvd[3];
        struct {					/* touch panel calibration data */
        	u_int32 xoffset;
        	u_int32 xscale;
        	u_int32 yoffset;
        	u_int32 yscale;
        } tcal;

		u_int8		mm_resvd2[12];
    } menm;

	/*--- offset 0x30:  Available to user ---*/
    u_int8 	user[0x200-0x30];

} AD65_EEPROM;

#define AD65_EEID_MENM    0x5

#endif /* _AD65_EEPROM_H */


