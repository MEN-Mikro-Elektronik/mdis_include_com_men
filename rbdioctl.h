/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: rbdioctl.h
 *
 *       Author: kp
 *        $Date: 2005/06/23 16:03:13 $
 *    $Revision: 2.3 $
 * 
 *  Description: Interface definition to Random Block Driver's IOCTL (ATA/MEM)
 *                      
 *     Switches: 
 *
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

#ifndef _RBDIOCTL_H
#define _RBDIOCTL_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- Standard Ioctl function codes ---*/
#define RBDRV_IOCTL_FORMAT			0x0001 	/* low level format device */
#define RBDRV_IOCTL_INFO			0x0002	/* return info */
/*
 * Further IOCTL codes can be found in ataioctl.h and mtdioctl.h
 */

/*--- RBDRV_IOCTL_PARMS.info.type ---*/
#define RBDRV_IOCTL_TYPE_MEM		1
#define RBDRV_IOCTL_TYPE_ATA		2

/*--- flags to ReadBlocks/WriteBlocks/Ioctl ---*/
#define RBDRV_WRITE_VERIFY			0x0001
#define RBDRV_RAW_ACCESS			0x0100 

/*--- error codes ---*/
#define RBDRV_NOT_SUPPORTED			1
#define RBDRV_READ_ERROR			2
#define RBDRV_WRITE_ERROR			3
#define RBDRV_NOT_READY				4
#define RBDRV_WRITE_PROTECTED		5
#define RBDRV_HW_DAMAGE				6
#define RBDRV_OUT_OF_RESOURCE		7
#define RBDRV_BAD_SUBDEV			8
#define RBDRV_ILLEGAL_SECTOR		9
#define RBDRV_BAD_PARAMETER			10
#define RBDRV_VERIFY_ERROR			11

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/

/*--- union to hold Ioctl arguments ---*/
typedef struct {
	u_int32	subdev;
	u_int32 flags;

	union { 
		struct {
			u_int32	type;			/* device type (MEM/ATA) */

			/*
			 * If device can handle any sector size, it should return
			 * the prefered sector size in <sectorSize> and <log/phySectors>
			 * and <logOffset> should be in units of <sectSize>. 			 
			 */
			u_int32 logSectors;		/* out: logical sectors */
			u_int32 phySectors;		/* out: physical sectors*/
			u_int32 sectSize;		/* out: */
			u_int32 sectSizeAny;	/* out: If <>0, device can handle any
									        sector size (MEM) */
			u_int32 logOffset;		/* out: number of sectors from start of
									        media to begin of usuable area */
			/*
			 * cylinders/heads/sectorsTrack: the geometry info of the drive.
			 * Can be all zero if not applicable
			 */
			u_int32 cylinders;		/* out: phys. cylinders */
			u_int32 heads;			/* out: phys. heads */
			u_int32 sectorsTrack;	/* out: phys. sectors/Track */
		} info;

		u_int8 data[512];			/* generic ioctl data */
	} p;
} RBDRV_IOCTL_PARMS;
		

#ifdef __cplusplus
	}
#endif

#endif	/* _RBDIOCTL_H */

