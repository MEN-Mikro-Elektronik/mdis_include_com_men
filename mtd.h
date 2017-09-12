/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: mtd.h
 *
 *       Author: kp
 *        $Date: 2005/06/23 16:02:59 $
 *    $Revision: 2.4 $
 * 
 *  Description: Interface to PCMCIA/RAW Memory technology Drivers (FLASH/SRAM)
 *                      
 *     Switches: COMPILE_MTD - when compiling a MTD driver
 *				 MTD_IS_PCMCIA - when used for PCMCIA devices
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: mtd.h,v $
 * Revision 2.4  2005/06/23 16:02:59  kp
 * Copyright line changed
 *
 * Revision 2.3  1998/10/07 12:21:59  Franke
 * added MTD_ACCDESC writeEnableData, WriteEnable()
 *
 * Revision 2.2  1998/08/03 16:14:47  kp
 * added typedef MTD_TRY_F
 *
 * Revision 2.1  1998/06/18 11:14:01  kp
 * Added by mcvs
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998 by MEN Mikro Elektronik GmbH, Nuremberg, Germany 
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

#ifndef _MTD_H
#define _MTD_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- error codes (note: same numbering as RBDRV interface!) ---*/
#define MTD_NOT_SUPPORTED			1
#define MTD_READ_ERROR				2
#define MTD_WRITE_ERROR				3
#define MTD_NOT_READY				4
#define MTD_WRITE_PROTECTED			5
#define MTD_HW_DAMAGE				6
#define MTD_OUT_OF_RESOURCE			7
#define MTD_BAD_SUBDEV				8
#define MTD_ILLEGAL_SECTOR			9
#define MTD_BAD_PARAMETER			10
#define MTD_VERIFY_ERROR			11

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
#ifndef COMPILE_MTD
typedef struct MTD_ENTRIES MTD_HANDLE;
#endif


/*--- MTD access descriptor ---*/
#ifdef MTD_IS_PCMCIA
typedef struct {
	struct PCMCIA_CS_HANDLE *csh;
	int sock;
	PCMCIA_SS_HANDLE *ssh;
	PCMCIA_SS_MEM_MAP memMap[4];
	PCMCIA_SS_MEMWIN_HANDLE *memWin[4];
} MTD_ACCDESC;
#else
typedef struct {
	MACCESS ma;
	void *vppData;
	int32 (*SetVpp)(void *vppData, u_int16 vpp);
	void *writeEnableData;
	int32 (*WriteEnable)(void *writeEnableData, u_int16 enable);
} MTD_ACCDESC;
#endif /* MTD_IS_PCMCIA */


typedef int32 (*MTD_INIT)(OSS_HANDLE *, MTD_ACCDESC *, JEDEC_INFO *jedInfo, 
						  u_int32 knownSize, u_int32 maxSize, 
						  u_int32 initDbgLevel, MTD_HANDLE **);

typedef int32 (*MTD_EXIT)( MTD_HANDLE *h);
typedef int32 (*MTD_IDENT)(MTD_HANDLE *h, char *, u_int32 );
typedef void  (*MTD_DBGLEVELSET)(MTD_HANDLE *h, u_int32 dbgLevel);

typedef int32 (*MTD_TRY)(OSS_HANDLE *osh, DBG_HANDLE *dbh, u_int32 dbgLevel, 
						 MTD_ACCDESC *mtdAccDesc, JEDEC_INFO *jedInfo, 
						 MTD_INIT *);

typedef int32 (*MTD_READBLOCKS)( MTD_HANDLE *h,u_int32 lsn,u_int32 nblks,
								u_int8  *buf, u_int32 blksz);

typedef int32 (*MTD_WRITEBLOCKS)( MTD_HANDLE *h,u_int32 lsn,u_int32 nblks,
								u_int8  *buf, u_int32 blksz);

typedef int32 (*MTD_IOCTL)(MTD_HANDLE *h,u_int32 function,	
						   MTD_IOCTL_PARMS *arg);

typedef int32 MTD_TRY_F(OSS_HANDLE *osh, DBG_HANDLE *dbh, u_int32 dbgLevel, 
						 MTD_ACCDESC *mtdAccDesc, JEDEC_INFO *jedInfo, 
						 MTD_INIT *);

		

/*--- MTD services function table ---*/
typedef struct MTD_ENTRIES {
	MTD_EXIT		Exit;
	MTD_IDENT		Ident;
	MTD_DBGLEVELSET	DbgLevelSet;
	MTD_READBLOCKS	ReadBlocks;
	MTD_WRITEBLOCKS	WriteBlocks;
	MTD_IOCTL		Ioctl;
} MTD_ENTRIES;

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/


#ifdef __cplusplus
	}
#endif

#endif	/* _MTD_H */

