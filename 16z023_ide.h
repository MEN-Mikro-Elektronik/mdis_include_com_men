/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: 16z023_ide.h
 *
 *       Author: kp
 *        $Date: 2005/06/23 16:03:21 $
 *    $Revision: 2.5 $
 * 
 *  Description: Header file for 16z023_Ide IDE controller in Chameleon FPGA
 *                      
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: 16z023_ide.h,v $
 * Revision 2.5  2005/06/23 16:03:21  kp
 * Copyright line changed
 *
 * Revision 2.4  2005/03/24 12:42:29  kp
 * + Z023_IDE_CTRL_NC define
 *
 * Revision 2.3  2005/02/02 16:36:13  kp
 * use official IP core naming
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2002-2005 by MEN Mikro Elektronik GmbH, Nuremberg, Germany 
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

#ifndef _Z023_IDE_H
#define _Z023_IDE_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* register offsets */

/* distance between standard IDE regs: 4 bytes */

#define Z023_IDE_BLOCK			0x80 		/* pri: 0x00, sec: 0x80 */

/* Z023_IDE specific registers: (relative to pri/sec block start) */
#define Z023_IDE_CONTROL		0x40 	/* power/CD status/irq enable */
#define Z023_IDE_IRQ_PENDING	0x44 	/* interrupt pending/clear */

/* bits in IRQ_ENABLE/IRQ_PENDING */
#define Z023_IDE_IRQ_ATA		0x01		/* IRQ from ATA card */
#define Z023_IDE_IRQ_CD_CHG		0x02 		/* Card detect change interrupt */

/* bits only in CONTROL */
#define Z023_IDE_CTRL_POW		0x04		/* power supply control (w) */
#define Z023_IDE_CTRL_CD		0x08		/* Card detect status (r) */
#define Z023_IDE_CTRL_NC		0x10 		/* port not connected */


/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/

#ifdef __cplusplus
	}
#endif

#endif	/* _Z023_IDE_H */

