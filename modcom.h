/*********************  P r o g r a m  -  M o d u l e ***********************
 *
 *         Name: modcom.c
 *      Project: common lib for m-modules
 *
 *       Author: kp
 *
 *  Description: Handling Module-Identification (EEPROM)
 *
 *     Required: -
 *     Switches: ID_SW - swapped access
 *
 *---------------------------[ Public Functions ]----------------------------
 *
 * int m_mread(addr,buff)            multiple read i=0..15
 * int m_mwrite(addr,buff)           multiple write i=0..15
 * int m_read(addr,index)            single read i
 * int m_write(addr,index,data)      single write i
 * int usm_mread(addr,buff)          multiple read i=0..128
 * int usm_mwrite(addr,buff)         multiple write i=0..128
 * int usm_read(addr,index)          single read i
 * int usm_write(addr,index,data)    single write i
 *
 *---------------------------------------------------------------------------
 * Copyright 1993-2019, MEN Mikro Elektronik GmbH
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

#if !defined(_MODCOM_H)
#  define _MODCOM_H

#ifdef __cplusplus
   extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
/* swapped access */
#ifdef ID_SW
#	define m_mread	ID_SW_m_mread
#	define m_mwrite	ID_SW_m_mwrite
#	define m_write	ID_SW_m_write
#	define m_read	ID_SW_m_read
#	define m_getmodinfo ID_SW_usm_getmodinfo
#	define usm_mread	ID_SW_usm_mread
#	define usm_mwrite	ID_SW_usm_mwrite
#	define usm_write	ID_SW_usm_write
#	define usm_read		ID_SW_usm_read
#endif

/* for m_getmodinfo */
#define MODCOM_MOD_MEN		1
#define MODCOM_MOD_THIRD	2

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
int m_mread( u_int8 *addr, u_int16 *buff );
int m_mwrite( u_int8 *addr, u_int16 *buff );
int m_write( u_int8 *addr, u_int8 index, u_int16 data );
int m_read( U_INT32_OR_64 base, u_int8 index );
int m_getmodinfo(
	U_INT32_OR_64 base,
	u_int32 *modtype,
	u_int32 *devid,
	u_int32 *devrev,
	char    *devname );
int usm_mread( u_int8 *addr, u_int16 *buff );
int usm_mwrite( u_int8 *addr, u_int16 *buff );
int usm_write( u_int8 *addr, u_int8 index, u_int16 data );
int usm_read( U_INT32_OR_64 base, u_int8 index );

#ifdef __cplusplus
   }
#endif

#endif  /*_MODCOM_H*/



