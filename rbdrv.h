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
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: rbdrv.h,v $
 * Revision 2.3  2005/06/23 16:02:52  kp
 * Copyright line changed
 *
 * Revision 2.2  1998/08/12 16:35:58  kp
 * Removed flags defines (now in rbdioctl.h)
 *
 * Revision 2.1  1998/06/18 11:14:08  kp
 * Added by mcvs
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998 by MEN Mikro Elektronik GmbH, Nuremberg, Germany 
 ****************************************************************************/

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

