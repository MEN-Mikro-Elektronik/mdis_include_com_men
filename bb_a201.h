/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: bb_a201.h
 *
 *      Author: ufranke 
 *
 *  Description: A201/B201/B202 specific set-/getstat codes and BBIS prototypes
 *
 *     Switches:  _ONE_NAMESPACE_PER_DRIVER_
 *                _LL_DRV_
 *				  B201
 *				  B202	
 *---------------------------------------------------------------------------
 * Copyright (c) 1997-2019, MEN Mikro Elektronik GmbH
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

#ifndef _BB_A201_H_
#define _BB_A201_H_

#ifdef __cplusplus
    extern "C" {
#endif


/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/

/*-- A201 specific status codes ( M_BRD_OF / M_BRD_BLK_OF + 0x00...0xff ) --*/
/*                                          S,G: S=setstat, G=getstat code */

#ifndef A201_GLOBNAME
#define _A201_GLOBNAME(var,name) var##_##name
# ifndef _ONE_NAMESPACE_PER_DRIVER_
#  define A201_GLOBNAME(var,name) _A201_GLOBNAME(var,name)
# else
#  define A201_GLOBNAME(var,name) _A201_GLOBNAME(A201,name)
# endif
#endif

/*---------------------------------------------------------------------------+
|    PROTOTYPES                                                              |
+---------------------------------------------------------------------------*/
#define __A201_GetEntry	A201_GLOBNAME(A201_VARIANT,GetEntry)

#ifdef __cplusplus
    }
#endif

#endif /* _BB_A201_H_ */




