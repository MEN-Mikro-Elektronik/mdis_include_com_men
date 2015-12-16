/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  bb_smbpci.h
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: 2006/08/02 12:25:07 $
 *    $Revision: 3.2 $
 *
 *       \brief  Header file for SMBPCI BBIS driver
 *
 *    \switches  _ONE_NAMESPACE_PER_DRIVER_
 *				  _LL_DRV_
 */
 /*-------------------------------[ History ]--------------------------------
 *
 * $Log: bb_smbpci.h,v $
 * Revision 3.2  2006/08/02 12:25:07  DPfeuffer
 * SMBPCI_VARIANT replaced by VAR_NAME
 *
 * Revision 3.1  2005/11/25 15:08:52  dpfeuffer
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright by MEN Mikro Elektronik GmbH, Nuernberg, Germany
 ****************************************************************************/

#ifndef _BB_SMBPCI_H
#define _BB_SMBPCI_H

#ifdef __cplusplus
	extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/* SMBPCI specific status codes (STD) */		/* S,G: S=setstat, G=getstat */
/*#define SMBPCI_XXX		M_BRD_OF+0x00*/		/* G,S: xxx */
/* none */

/* SMBPCI specific status codes (BLK)*/			/* S,G: S=setstat, G=getstat */
/*#define SMBPCI_XXX		M_BRD_BLK_OF+0x00*/	/* G,S: xxx */
/* none */

/**************************************************
 *** see bb_smb.h for used SMB_XXX status codes ***
 **************************************************/

/* defines for variant support */
# define _SMBPCI_GLOBNAME(var,name) var##_##name

#ifndef _ONE_NAMESPACE_PER_DRIVER_
# define SMBPCI_GLOBNAME(var,name) _SMBPCI_GLOBNAME(var,name)
#else
# define SMBPCI_GLOBNAME(var,name) _SMBPCI_GLOBNAME(SMBPCI,name)
#endif

#define  __SMBPCI_GetEntry	  SMBPCI_GLOBNAME(VAR_NAME,GetEntry)

/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/
#ifndef _ONE_NAMESPACE_PER_DRIVER_
	extern void __SMBPCI_GetEntry( BBIS_ENTRY* bbisP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */


#ifdef __cplusplus
	}
#endif


#endif /* _BB_SMBPCI_H */



