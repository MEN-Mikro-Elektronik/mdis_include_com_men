/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: bb_chameleon.h
 *
 *       Author: kp
 * 
 *  Description: Header file for CHAMELEON BBIS driver
 *               - CHAMELEON function prototypes
 *
 *     Switches: _ONE_NAMESPACE_PER_DRIVER_
 *               _LL_DRV_
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2003-2019, MEN Mikro Elektronik GmbH
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

#ifndef _BB_CHAMELEON_H_
#define _BB_CHAMELEON_H_

#ifdef __cplusplus
	extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/* defines for variant support */
#ifndef  BB_CHAMELEON_VARIANT
# define BB_CHAMELEON_VARIANT CHAMELEON
#endif

# define _BB_CHAMELEON_GLOBNAME(var,name) var##_##name

#ifndef _ONE_NAMESPACE_PER_DRIVER_
# define BB_CHAMELEON_GLOBNAME(var,name) _BB_CHAMELEON_GLOBNAME(var,name)
#else
# define BB_CHAMELEON_GLOBNAME(var,name) _BB_CHAMELEON_GLOBNAME(BBIS,name)
#endif

#define __BB_CHAMELEON_GetEntry			BB_CHAMELEON_GLOBNAME(BB_CHAMELEON_VARIANT,GetEntry)
#define __BB_CHAMELEON_IoReadD32		BB_CHAMELEON_GLOBNAME(BB_CHAMELEON_VARIANT,IoReadD32)
#define __BB_CHAMELEON_IoWriteD32		BB_CHAMELEON_GLOBNAME(BB_CHAMELEON_VARIANT,IoWriteD32)

/*---------------------------------------------------------------------------+
|    PROTOTYPES                                                              |
+---------------------------------------------------------------------------*/

extern u_int32 __BB_CHAMELEON_IoReadD32( MACCESS ma, u_int32 offs );
extern void __BB_CHAMELEON_IoWriteD32( MACCESS ma, u_int32 offs, u_int32 val );

#ifndef _ONE_NAMESPACE_PER_DRIVER_
	extern void __BB_CHAMELEON_GetEntry( BBIS_ENTRY* bbisP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */

#ifdef __cplusplus
	}
#endif

#endif /* _BB_CHAMELEON_H_ */

