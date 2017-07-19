/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: mtdioctl.h
 *
 *       Author: kp
 *        $Date: 2008/11/11 18:21:58 $
 *    $Revision: 2.4 $
 * 
 *  Description: IOCTL interface to Memory Technology drivers
 *                      
 *     Switches: 
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: mtdioctl.h,v $
 * Revision 2.4  2008/11/11 18:21:58  rt
 * R:1. MenMon should always unlock flash blocks before
 *      updating. OS may lock flash blocks, after that
 *      updates in MenMon will fail. MenMon has to
 *      restore old lock entries after update!
 * M:1. Added MTD_IOCTL_FLASH_GET/SET_LOCK...
 *
 * Revision 2.3  2005/06/23 16:03:15  kp
 * Copyright line changed
 *
 * Revision 2.2  1998/08/12 16:35:51  kp
 * added comment to sectorSize.addr
 *
 * Revision 2.1  1998/06/18 11:14:03  kp
 * Added by mcvs
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998 by MEN Mikro Elektronik GmbH, Nuremberg, Germany 
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef _MTDIOCTL_H
#define _MTDIOCTL_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- Ioctl function codes ---*/
#define MTD_IOCTL_FLASH_ERASE		0x0101
#define MTD_IOCTL_FLASH_SECTOR_SIZE	0x0102
#define MTD_IOCTL_INFO				0x0103
#define MTD_IOCTL_FLASH_GET_LOCK	0x0104
#define MTD_IOCTL_FLASH_SET_LOCK	0x0105

/*--- Ioctl parameters ---*/
#define MTD_IOCTL_FLASH_STATE_UNLOCK		0x0
#define MTD_IOCTL_FLASH_STATE_LOCK			0x1
#define MTD_IOCTL_FLASH_STATE_UNLOCK_ALL	0x10
#define MTD_IOCTL_FLASH_STATE_LOCK_ALL		0x20

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/

/*--- Jedec manufacturer / device ID ---*/
typedef struct JEDEC_INFO {
	u_int32 manfId;
	u_int32 deviceId;
} JEDEC_INFO;


/*--- union to hold Ioctl arguments ---*/
typedef union {

	struct {
		u_int32 addr;	/* in:  address within requested sector */
		u_int32 state;	/* out: lock state of sector */
						/* in:  requested lock state */
	} lock;

	struct {
		u_int32 startAddr;		/* in:  address within entire card/array */
		u_int32 nBytes;			/* in:  min. number of bytes to erase */
	} erase;

	struct {
		u_int32	addr;			/* in:  address within requested sector 
								   out: start address of requested sector */
		u_int32 size;			/* out: size of requested sector */
	} sectorSize;

	struct MTD_IOCTL_PARMS_INFO {
		char mtdName[12];		/* out: name of MTD */
		u_int32 busWidth;		/* out: number of parallel bytes to address */
		u_int32 equipFlag;		/* out: Byte equipment flags (1 bit for 
								        each byte */
		JEDEC_INFO jedInfo;		/* out: jedec manufacturer/device ID */
		u_int32 cascDevices;	/* out: number of sequentially cascaded
								        devices */
		u_int32 parDevices;		/* out: number of parallel devices */
		u_int32 size;			/* out: total size within card/array */
		u_int16 vpp, altVpp;	/* out: programming voltages */
	} info;

		
} MTD_IOCTL_PARMS;


/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/


#ifdef __cplusplus
	}
#endif

#endif	/* _MTDIOCTL_H */
