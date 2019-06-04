/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: bb_d302.h
 *
 *       Author: ds
 * 
 *  Description: Header file for D302 BBIS driver
 *               - D302 specific status codes
 *               - D302 function prototypes
 *
 *     Switches: _ONE_NAMESPACE_PER_DRIVER_
 *               _LL_DRV_
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2001-2019, MEN Mikro Elektronik GmbH
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

#ifndef _BB_D302_H_
#define _BB_D302_H_

#ifdef __cplusplus
	extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/* D302 specific status codes (STD) */		/* S,G: S=setstat, G=getstat */
/*#define D302_XXX		M_BRD_OF+0x00*/		/* G,S: xxx */
/* none */

/* D302 specific status codes (BLK)*/			/* S,G: S=setstat, G=getstat */
/*#define D302_XXX		M_BRD_BLK_OF+0x00*/	/* G,S: xxx */
/* none */

/* defines for variant support */
# define _D302_GLOBNAME(var,name) var##_##name

#ifndef _ONE_NAMESPACE_PER_DRIVER_
# define D302_GLOBNAME(var,name) _D302_GLOBNAME(var,name)
#else
# define D302_GLOBNAME(var,name) _D302_GLOBNAME(D302,name)
#endif

#define  __D302_GetEntry	  D302_GLOBNAME(D302_VARIANT,GetEntry)

/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/
#ifndef _ONE_NAMESPACE_PER_DRIVER_
	extern void __D302_GetEntry( BBIS_ENTRY* bbisP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */


#ifdef __cplusplus
	}
#endif

#endif /* _BB_D302_H_ */
