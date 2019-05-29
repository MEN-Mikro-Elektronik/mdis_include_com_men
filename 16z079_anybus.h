/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: 16z079_anybus.h
 *
 *       Author: rla
 *        $Date: 2017/12/04 16:19:57CET $
 *    $Revision: 1.2 $
 *
 *  Description: Header file for MEN Z079_ANYBUS
 *
 *     Switches: -
 *
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2006-2019, MEN Mikro Elektronik GmbH
 ****************************************************************************/

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

#ifndef _Z079_ANYB_H
#define _Z079_ANYB_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* registers etc. */
#define Z079_ANYBUS_SWRST_REG	0x00	/**< Software Reset */
#define Z079_ANYBUS_GIP_REG		0x04	/**< GIP register */
#define Z079_ANYBUS_GOP_REG     0x08    /**< GOP register */
#define Z079_ANYBUS_OPM_REG		0x0C	/**< Operation Mode register */
#define Z079_ANYBUS_MID_REG		0x10	/**< Module ID register */
#define Z079_ANYBUS_MDET_REG	0x14	/**< Module Detection register */

#define Z079_ANYBUS_SWRST_MSK	0x01

#define Z079_ANYBUS_OPMOD_PARALLEL	0x00
#define Z079_ANYBUS_OPMOD_SER_19_2	0x01
#define Z079_ANYBUS_OPMOD_SER_57_6	0x02
#define Z079_ANYBUS_OPMOD_SER_115	0x03
#define Z079_ANYBUS_OPMOD_SER_625	0x04

#define Z079_ANYBUS_GIP_DATAEN		0x01
#define Z079_ANYBUS_GOP_NETRDY		0x01
#define Z079_ANYBUS_MODID_PASSIV	0x01

#define Z079_ANYBUS_MODID_MSK		0x03

#define ANYBUS_SRAM_TYPE_OFFS		0x3800

#define ANYBUS_TYPE_RS232			0x1
#define ANYBUS_TYPE_RS422			0x2
#define ANYBUS_TYPE_USB				0x3
#define ANYBUS_TYPE_ETH				0x4
#define ANYBUS_TYPE_BLUTO			0x5
#define ANYBUS_TYPE_ZIGBEE			0x6
#define ANYBUS_TYPE_RS485			0xA

typedef struct {
	u_int8 swrst;
	u_int8 rsvd1[3];
	u_int8 gip;
	u_int8 rsvd2[3];
	u_int8 gop;
	u_int8 rsvd3[3];
	u_int8 opmod;
	u_int8 rsvd4[3];
	u_int8 modid;
	u_int8 rsvd5[3];
	u_int8 modetect;
} Z079_ANYBUS_MAP;

typedef struct {
	unsigned char swrst;		/* SW Reset register */
	unsigned char gip;			/* GIP register */
	unsigned char gop;			/* GOP register */
	unsigned char opmod;		/* Operation mode register */
	unsigned char modid;		/* Module Identification register */
	unsigned char modetect;		/* Module Detection register */
	unsigned char type;			/* Passive type */
} Z079_ANYBUS_REGS;

#ifdef __cplusplus
	}
#endif

#endif	/* _Z079_ANYB_H */

