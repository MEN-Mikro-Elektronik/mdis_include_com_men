/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  eeprod.h
 *
 *      \author  klaus.popp@men.de/ulrich.bogensperger@men.de
 *        $Date: 2011/09/30 10:42:27 $
 *    $Revision: 2.10 $
 *
 *  	 \brief  Common layout of production data in MEN boards
 *
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * (c) Copyright 2002-2006 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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
#ifndef _EEPROD_H
#define _EEPROD_H

#define EEID_PD      0xd		/**< struct ID for EEPROD */

/** Standard production data section (16 bytes) */
typedef struct {
    u_int8      pd_id;      	/**< struct ID (0xD) and parity */
    u_int8      pd_revision[3];	/**< board HW revision xx.yy.zz */
    u_int32     pd_serial;  	/**< board serial number */
    u_int8      pd_model; 		/**< board model */
	char		pd_hwName[6];	/**< name of HW e.g. "EM04", null term. */
    u_int8      pd_resvd[1];
} EEPROD;

#define EEID_PD2     0xe		/**< struct ID for EEPROD2*/
#define EEPROD2_DATE_YEAR_BIAS 1990 /**< year bias for repdat/prodat  */
	
/** extended EEPROD structure containing production/repair date (24 bytes) */
typedef struct {
    u_int8      pd_id;      	/**< struct ID (0xE) and parity */
    u_int8      pd_revision[3];	/**< board HW revision xx.yy.zz */
    u_int32     pd_serial;  	/**< board serial number */
    u_int8      pd_model; 		/**< board model */
	char		pd_hwName[6];	/**< name of HW e.g. "EM04", null term. */
    u_int8      pd_resvd[1];
	u_int16 	pd_prodat;		/**< production date */
	u_int16 	pd_repdat;		/**< last repair date */
	u_int8		pd_resvd2[4];
} EEPROD2;

/** EEPROM structure for EEPROMs connected directly to 16Z087 */
typedef struct {
    u_int8      pd_id;      	/**< struct ID (0xE) and parity */
    u_int8      pd_mac[6];		/**< 6 byte MAC address */
} EEPROD_MAC;


/** EEPROD structure(32 bytes), with 16-bit CRC*/
#if defined(_RDE_D602_) || defined(_GOLDEN_CODE_)
/**< Inventory Data structure defined for RDE project*/
typedef struct { 
	char 		pd_brd[4]; /**< record ID,4 bytes,  "LRU" or "BRD"*/
	char 		pd_mod[9]; /**< Model ID, 9 bytes. e.g.02D602-00 */
	char 		pd_rev[8]; /**< HW Revision, 8 bytes. e.g.00.00.01 */
	char 		pd_ser[6]; /**< Serial Number, 6 bytes. e.g.000034*/
	char 		pd_pad[3]; /**<reserved, 3 bytes*/
	char 		pd_crc[2]; /**< 16-bit crc, higher 8-bit saved in pd_crc[0]
								* polynominal is 0xA001
								* initial value is 0x0000								
								*/
} EEPROD3;
#else
/**< Inventory Data structure defined for standard products*/
typedef struct {
	char 		pd_brd[6]; /**< record ID, 6ytes. e.g. "A602"*/
	char 		pd_mod[6]; /**< Desgin ID, 6 bytes. e.g."-00" */   
	char 		pd_rev[9]; /**< HW Revision, 9 bytes. e.g.00.00.01 */ 
	char 		pd_ser[6]; /**< Serial Number, 6 bytes. e.g.00034*/  
	char 		pd_pad[3]; /**<reserved, 3 bytes*/                    
	char 		pd_crc[2]; /**< 16-bit crc, higher 8-bit saved in pd_crc[0]
								* CRC algorithm is port-dependant.
								* CRC algorithm should be implemented in 
								* u_int16 PORT_EEPROM_ComputeCRC(u_int8* buf, u_int32 len)
								* where buf is the data source buffer;
								* len is the length of data in byte
								*/
} EEPROD3;
#endif

/***************************************************************************/
/*! \page eeprod2date Definition of EEPROD2 production/repair date fields

  - Stored in BIG ENDIAN format
  - Bits 15..9 (7 bits) contain the year since 1990 in binary format.
               This allows a range from 1990..2117
  - Bits  8..5 (4 bits) contain the month in binary format. (1..12)
  - Bits  4..0 (5 bits) contain the day of month in binary format (1..31)
  - If the field is 0xffff, it means that the field has not been programmed

*/


#endif /* _EEPROD_H */

