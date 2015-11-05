/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: esmx_cb_eeprom.h
 *
 *       Author: rt
 *        $Date: 2008/08/04 14:10:16 $
 *    $Revision: 3.1 $
 *
 *  Description: Layout of ESMexpress carrier board's serial EEPROM
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: esmx_cb_eeprom.h,v $
 * Revision 3.1  2008/08/04 14:10:16  rt
 * Initial Revision
 *
 *
 * cloned from esm_cb_eeprom.h (Revision 3.2  2007/07/11 14:37:54)
 *---------------------------------------------------------------------------
 * (c) Copyright 2008 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ****************************************************************************/
#ifndef _ESMX_CB_EEPROM_H
#define _ESMX_CB_EEPROM_H

#include <MEN/eeprod.h>

#define ESMX_CB_EEPROM_SIZE 256

/* the entire structure covers 0x100 Byte (256 Byte) */
typedef struct {
    /*--- offset 0x0: production data, hardware information (24 byte) ---*/
	EEPROD2 pd;

    /*--- offset 0x18: reserved for more parameters ---*/
	u_int8	resvd[0x80-24];

	/*--- offset 0x80:  Available to user ---*/
    u_int8 	user[0x80];

} ESMX_CB_EEPROM;

#endif /* _ESMX_CB_EEPROM_H */


