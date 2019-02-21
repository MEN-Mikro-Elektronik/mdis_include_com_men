/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: rbdrv.h
 *
 *       Author: kp
 *        $Date: 2005/06/23 16:02:52 $
 *    $Revision: 2.3 $
 * 
 *  Description: Interface definition to Random Block Drivers (ATA/MEM)
 *                      
 *     Switches: COMPILE_RBDRV - when compiling a RB driver
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

#ifndef _RBDRV_H
#define _RBDRV_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
#ifndef COMPILE_RBDRV
typedef struct RBDRV_ENTRIES RBDRV_HANDLE;
#endif


/*--- RB driver services function table ---*/
typedef struct RBDRV_ENTRIES {
	int32 (*Exit)(
	   RBDRV_HANDLE *h);

 	int32 (*Ident)(RBDRV_HANDLE *h, char *, u_int32 );

	void (*DbgLevelSet)(
	    RBDRV_HANDLE *h,
        u_int32 dbgLevel);

	int32 (*ReadBlocks)(
	    RBDRV_HANDLE *h,
		u_int32 subdev,				
		u_int32 lsn,
        u_int32 nblks,
        u_int8  *buf,
        u_int32 blksz,
        u_int32 flags);

	int32 (*WriteBlocks)(
	    RBDRV_HANDLE *h,
		u_int32 subdev,				
		u_int32 lsn,
        u_int32 nblks,
        u_int8  *buf,
        u_int32 blksz,
        u_int32 flags);

	int32 (*Ioctl)(
	    RBDRV_HANDLE *h,
		u_int32 function,
		RBDRV_IOCTL_PARMS *arg);

	int32 (*reserved1)();
	int32 (*reserved2)();
	int32 (*reserved3)();
	int32 (*reserved4)();

} RBDRV_ENTRIES;

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/


#ifdef __cplusplus
	}
#endif

#endif	/* _RBDRV_H */

