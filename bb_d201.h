/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: bb_d201.h
 *
 *       Author: ds
 * 
 *  Description: Header file for D201 BBIS driver
 *               - D201 specific status codes
 *               - D201 function prototypes
 *                      
 *     Switches:  _ONE_NAMESPACE_PER_DRIVER_
 *				  _LL_DRV_
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

#ifndef _BB_D201_H_
#define _BB_D201_H_

#ifdef __cplusplus
	extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/*-- D201 specific status codes ( M_BRD_OF / M_BRD_BLK_OF + 0x00...0xff ) --*/
/*											 S,G: S=setstat, G=getstat code */
#define D201_BLK_EEPROM_DATA M_BRD_BLK_OF+0x01	/* G:  read eeprom data     */	

/*---------------------------------------------------------------------------+
|    PROTOTYPES                                                              |
+---------------------------------------------------------------------------*/
#ifndef _ONE_NAMESPACE_PER_DRIVER_
	extern void D201_GetEntry( BBIS_ENTRY* bbisP );
	extern void C203_GetEntry( BBIS_ENTRY* bbisP );
	extern void C204_GetEntry( BBIS_ENTRY* bbisP );
	extern void F201_GetEntry( BBIS_ENTRY* bbisP );
	extern void F202_GetEntry( BBIS_ENTRY* bbisP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */

#ifdef __cplusplus
	}
#endif


#endif /* _BB_D201_H_ */



