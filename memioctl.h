/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: memioctl.h
 *
 *       Author: kp
 *        $Date: 2008/11/11 18:20:35 $
 *    $Revision: 2.3 $
 * 
 *  Description: IOCTL interface MEMory driver (RBFLASH, MEN_PCMCIA)
 *                      
 *     Switches: 
 *---------------------------------------------------------------------------
 * Copyright (c) 1998-2019, MEN Mikro Elektronik GmbH
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

#ifndef _MEMIOCTL_H
#define _MEMIOCTL_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- Ioctl function codes ---*/
#define MEM_IOCTL_FLASH_ERASE		0x0301
#define MEM_IOCTL_FLASH_SECTOR_SIZE	0x0302
#define MEM_IOCTL_CONFIG_PARTITION	0x0303
#define MEM_IOCTL_FLASH_GET_LOCK	0x0304
#define MEM_IOCTL_FLASH_SET_LOCK	0x0305

/*--- Ioctl parameters ---*/
#define MEM_IOCTL_FLASH_STATE_UNLOCK		0x0
#define MEM_IOCTL_FLASH_STATE_LOCK			0x1
#define MEM_IOCTL_FLASH_STATE_UNLOCK_ALL	0x10
#define MEM_IOCTL_FLASH_STATE_LOCK_ALL		0x20

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/



/*
 * union to hold Ioctl arguments 
 * 
 * When used with an RBDRV ioctl interface, this structure overlays
 * the RBDRV_IOCTL_PARMS.p area
 */
typedef union {

	/*--- for MEM_IOCTL_FLASH_GET/SET_LOCK ---*/
	struct {
		u_int32 addr;	/* in:  address within requested sector */
		u_int32 state;	/* out: lock state of sector (0=unlocked) */
						/* in:  requested lock state (0=unlock) */
	} lock;

	/*--- for MEM_IOCTL_FLASH_ERASE ---*/
	struct {
		u_int32 startAddr;		/* in:  address within entire card/array */
		u_int32 nBytes;			/* in:  min. number of bytes to erase */
	} erase;

	/*--- for MEM_IOCTL_FLASH_SECTOR_SIZE ---*/
	struct {
		u_int32	addr;			/* in:  address within requested sector 
								   out: start address of sector */
		u_int32 size;			/* out: size of requested sector */
	} sectorSize;

	/*--- for MEM_IOCTL_CONFIG_PARTITION ---*/
	struct MEM_IOCTL_PARMS_CONFIG_PARTITION {
		u_int32	startAddr;		/* in:  start address of partition */
		u_int32	size;			/* in:  size of partition in bytes */
	} configPartition;

} MEM_IOCTL_PARMS;


/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/


#ifdef __cplusplus
	}
#endif

#endif	/* _MEMIOCTL_H */
