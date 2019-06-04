/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  bb_smbpci.h
 *
 *      \author  dieter.pfeuffer@men.de
 *
 *       \brief  Header file for SMBPCI BBIS driver
 *
 *    \switches  _ONE_NAMESPACE_PER_DRIVER_
 *				  _LL_DRV_
 */
 /*
 *---------------------------------------------------------------------------
 * Copyright (c) 2019, MEN Mikro Elektronik GmbH
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



