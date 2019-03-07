/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  bb_a203n.h
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: 2005/08/03 12:04:02 $
 *    $Revision: 3.1 $
 *
 *       \brief  Header file for A203N BBIS driver
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

#ifndef _BB_A203N_H
#define _BB_A203N_H

#ifdef __cplusplus
	extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/* A203N specific status codes (STD) */		/* S,G: S=setstat, G=getstat */
/*#define A203N_XXX		M_BRD_OF+0x00*/		/* G,S: xxx */
/* none */

/* A203N specific status codes (BLK)*/			/* S,G: S=setstat, G=getstat */
/*#define A203N_XXX		M_BRD_BLK_OF+0x00*/	/* G,S: xxx */
/* none */

/* defines for variant support */
# define _A203N_GLOBNAME(var,name) var##_##name

#ifndef _ONE_NAMESPACE_PER_DRIVER_
# define A203N_GLOBNAME(var,name) _A203N_GLOBNAME(var,name)
#else
# define A203N_GLOBNAME(var,name) _A203N_GLOBNAME(A203N,name)
#endif

#define  __A203N_GetEntry	  A203N_GLOBNAME(A203N_VARIANT,GetEntry)

/*-----------------------------------------+
|  PROTOTYPES                              |
+-----------------------------------------*/
#ifndef _ONE_NAMESPACE_PER_DRIVER_
	extern void __A203N_GetEntry( BBIS_ENTRY* bbisP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */
#ifdef __cplusplus
	}
#endif


#endif /* _BB_A203N_H */



