/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: men_pci2vme.h
 *
 *       Author: kp
 *        $Date: 2001/04/04 13:32:19 $
 *    $Revision: 2.2 $
 * 
 *  Description: Register definitions for MEN's PCI2VME bridge
 *				 developed by Klaus Botschnan (used on B11, A12).
 *                      
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: men_pci2vme.h,v $
 * Revision 2.2  2001/04/04 13:32:19  kp
 * adapted: bridge now using only BAR0
 *
 * Revision 2.1  2000/11/21 09:48:33  kp
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2000 by MEN mikro elektronik GmbH, Nuremberg, Germany 
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef _MEN_PCI2VME_H
#define _MEN_PCI2VME_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- PCI vendor/device IDs ---*/
#define MENPCI2VME_DEV_ID_A15	0x5056	/* ASCII 'PV' */
#define MENPCI2VME_VEN_ID_A15	0x1172
#define MENPCI2VME_DEV_ID_A21	0x4D45  /* ASCII 'PV' */
#define MENPCI2VME_VEN_ID_A21	0x1A88
#define MENPCI2VME_VEN_ID_END	0xFFFF
#define MENPCI2VME_DEV_ID_END	0xFFFF

#define MENPCI2VME_SUB_DEV_ID	0xFF00  /* ???? */
#define MENPCI2VME_SUB_VEN_ID	0xFF00  /* ???? */

#define MENPCI2VME_PCI_VENID	0
#define MENPCI2VME_PCI_DEVID	1

/*--- offsets to address found in BAR0 for A15 ---*/
#define MENPCI2VME_A24_SPACE_A15	0x00000000	/* VME A24 master access */
#define MENPCI2VME_A16_SPACE_A15	0x01000000	/* VME A16 master access */
#define MENPCI2VME_SRAM_SPACE_A15	0x01400000	/* VME shared RAM */
#define MENPCI2VME_REG_SPACE_A15	0x01800000	/* registers */
#define MENPCI2VME_IACK_SPACE_A15	0x01c00000	/* IACK space */

/*--- offsets to address found in BAR0 for A21 ---*/
#define MENPCI2VME_A24_D16_SPACE_A21	0x04000000	/* VME A24 D16 master access */
#define MENPCI2VME_A24_D32_SPACE_A21	0x05000000	/* VME A24 D32 master access */
#define MENPCI2VME_A16_D16_SPACE_A21	0x00010000	/* VME A16 D16 master access */
#define MENPCI2VME_A16_D32_SPACE_A21	0x00020000	/* VME A16 D32 master access */
#define MENPCI2VME_SRAM_SPACE_A21		0x00400000	/* VME shared RAM */
#define MENPCI2VME_REG_SPACE_A21		0x00800000	/* registers */
#define MENPCI2VME_IACK_SPACE_A21		0x00c00000	/* IACK space */

/*--- offsets to register start address (MENPCI2VME_REG_SPACE) ---*/
#define MENPCI2VME_INTR			0x00	/* interrupter control */
#define MENPCI2VME_INTID		0x04	/* interrupter vector */
#define MENPCI2VME_ISTAT		0x08	/* interrupt pending */
#define MENPCI2VME_IMASK		0x0c	/* interrupt handler mask*/
#define MENPCI2VME_MSTR			0x10	/* master control */
#define MENPCI2VME_SLV			0x14	/* slave control */
#define MENPCI2VME_SYSCTL		0x18	/* system control */
#define MENPCI2VME_LONGADD		0x1c	/* Upper 3 Address Bits for A32 */

/*--- bit defs of registers above ---*/
#define MENPCI2VME_INTR_INTEN	0x8

#define MENPCI2VME_ISTAT_ACFST	0x1

#define MENPCI2VME_IMASK_ACFEN	0x1

#define MENPCI2VME_MSTR_BERR	0x4
#define MENPCI2VME_MSTR_REQ		0x2
#define MENPCI2VME_MSTR_RMW		0x1

#define MENPCI2VME_SLV_SLEN		0x10

#define MENPCI2VME_SYSCTL_ATO	0x4
#define MENPCI2VME_SYSCTL_SYSRES 0x2
#define MENPCI2VME_SYSCTL_SYSCON 0x1


#ifdef __cplusplus
	}
#endif

#endif	/* _MEN_PCI2VME_H */
