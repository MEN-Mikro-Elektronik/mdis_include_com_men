/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: mem_drv.h
 *
 *       Author: kp
 *        $Date: 2005/06/23 16:03:29 $
 *    $Revision: 1.4 $
 * 
 *  Description: MEM driver export definitions
 *                      
 *     Switches: COMPILE_MEMDRV
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: mem_drv.h,v $
 * Revision 1.4  2005/06/23 16:03:29  kp
 * Copyright line changed
 *
 * Revision 1.3  1998/08/12 16:36:01  kp
 * MEM_Init: Removed maxSize parameter
 *
 * Revision 1.2  1998/07/23 12:08:05  Franke
 * changed  MEM_HANDLE not longer void for extern now RBDRV_HANDLE
 *
 * Revision 1.1  1998/06/18 11:14:43  kp
 * Added by mcvs
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998 by MEN Mikro Elektronik GmbH, Nuremberg, Germany 
 ****************************************************************************/


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
#ifndef COMPILE_MEMDRV
typedef RBDRV_HANDLE MEM_HANDLE;
#endif

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

#ifdef MEM_IS_PCMCIA
int32 MEM_PCMCIA_Init( 
    OSS_HANDLE *osh,
	MTD_INIT mtdInit,
	MTD_ACCDESC *mtdAccDesc,	   			   
	JEDEC_INFO *jedInfo,		   
	u_int32 knownSize,			   
	u_int32 maxPhySearch,
	u_int32 initDbgLevel,
    MEM_HANDLE **handleP);
int32 MEM_CscHandler( 
    PCMCIA_CS_HANDLE *csh, 
    int sock,
    u_int32 event,
    DBG_HANDLE *csDbh,
    u_int32 csDebugLevel,
	void *osCscData);
#else
int32 MEM_Init( 
    OSS_HANDLE *osh,
	MTD_INIT mtdInit,
	MTD_ACCDESC *mtdAccDesc,	   			   
	JEDEC_INFO *jedInfo,		   
	u_int32 knownSize,			   
	u_int32 maxPhySearch,
	u_int32 initDbgLevel,
    MEM_HANDLE **handleP);
#endif





