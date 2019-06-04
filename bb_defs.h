/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: bb_defs.h
 *
 *       Author: ds
 *
 *  Description: BBIS board handler common definitions
 *
 *     Switches: _NO_BBIS_HANDLE	exclude BBIS_HANDLE declaration
 *
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

#ifndef _BB_DEFS_H_
#define _BB_DEFS_H_

#ifdef __cplusplus
    extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR BrdInfo()                                               |
+---------------------------------------------------------------------------*/

/*------------- bus type ---------------*/
#define BBIS_BRDINFO_BUSTYPE        0x0100

/*----------- function info ------------*/
#define BBIS_BRDINFO_FUNCTION       0x0200
#define BBIS_FUNC_IRQENABLE         0x0201
#define BBIS_FUNC_IRQSRVINIT        0x0202
#define BBIS_FUNC_IRQSRVEXIT        0x0203
#define BBIS_FUNC_EXPENABLE         0x0204
#define BBIS_FUNC_EXPSRV            0x0205

/*------------ slot number -------------*/
#define BBIS_BRDINFO_NUM_SLOTS      0x0300

/*-------- interrupt capability --------*/
#define BBIS_BRDINFO_INTERRUPTS		0x0400
#define BBIS_IRQ_DEVIRQ				0x0001	/* device IRQ supported */
#define BBIS_IRQ_EXPIRQ				0x0002	/* exception IRQ supp.  */

/*---- type of device address space ----*/
#define BBIS_BRDINFO_ADDRSPACE      0x0500

/*-------- type of device bus ----------*/
#define BBIS_BRDINFO_DEVBUSTYPE     0x0600

/*------------ board name --------------*/
#define BBIS_BRDINFO_BRDNAME		 0x0700
#define BBIS_BRDINFO_BRDNAME_MAXSIZE 80 

/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR CfgInfo()                                               |
+---------------------------------------------------------------------------*/

/*------------- bus number -------------*/
#define BBIS_CFGINFO_BUSNBR         0x1100

/*----------- interrupt info -----------*/
#define BBIS_CFGINFO_IRQ            0x1200
#define BBIS_CFGINFO_EXP            0x1300

/*------ flags for interrupt info ------*/
#define BBIS_IRQ_NONE               0x0000
#define BBIS_IRQ_EXCEPTION          0x0002
#define BBIS_IRQ_EXCLUSIVE          0x0004
#define BBIS_IRQ_SHARED             0x0008

/*-------- PCI dev/func number ---------*/
#define BBIS_CFGINFO_PCI_DEVNBR     0x1400
#define BBIS_CFGINFO_PCI_FUNCNBR    0x1410
#define BBIS_CFGINFO_PCI_DOMAIN	    0x1420

/*-------- slot information ------------*/
#define BBIS_CFGINFO_SLOT			0x1500

/*---- flags for slot information ------*/
/* for BK/MK usage */ 
#define BBIS_SLOT_PLGAB_DEV		0x1000		/* pluggable device */
#define BBIS_SLOT_ONBRD_DEV		0x2000		/* onboard device */
#define BBIS_SLOT_EXIST_YES		0x0001		/* device exist */
#define BBIS_SLOT_EXIST_NO		0x0002		/* device doesn't exist */

/* BBIS usage for pluggable devices */
#define BBIS_SLOT_OCCUP_YES		(BBIS_SLOT_PLGAB_DEV | BBIS_SLOT_EXIST_YES)
#define BBIS_SLOT_OCCUP_NO		(BBIS_SLOT_PLGAB_DEV | BBIS_SLOT_EXIST_NO)

/* BBIS usage for onboard devices */
#define BBIS_SLOT_OCCUP_ALW		(BBIS_SLOT_ONBRD_DEV | BBIS_SLOT_EXIST_YES)
#define BBIS_SLOT_OCCUP_DIS		(BBIS_SLOT_ONBRD_DEV | BBIS_SLOT_EXIST_NO)

#define BBIS_SLOT_NBR_UNK		0xffffffff	/* indicates an unknown number */
#define BBIS_SLOT_STR_UNK		"" 			/* indicates an unknown string 	*/
#define BBIS_SLOT_STR_MAXSIZE	80			/* max size for strings 		*/ 

/*---- type of mSlot address space -----*/
#define BBIS_CFGINFO_ADDRSPACE      0x1600

/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR IRQ-FKT.                                                |
+---------------------------------------------------------------------------*/
#define BBIS_IRQ_NO     0x0001      /* no module interrupt */
#define BBIS_IRQ_UNK    0x0002      /* perhaps module interrupt */
#define BBIS_IRQ_YES    0x0004      /* module interrupt */
#define BBIS_IRQ_EXP    0x0008      /* exception interrupt */


/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR GetMAddr()  / SetMIface()                               |
+---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR BUS TO LOCAL CONVERSION                                 |
+---------------------------------------------------------------------------*/
#define BBIS_BUS_TO_LOCAL_NO    0       /* no bus to local conversion */
#define BBIS_BUS_TO_LOCAL       1       /* bus to local conversion */

/*---------------------------------------------------------------------------+
|    DEFINITIONS FOR MISCELLANOUS                                            |
+---------------------------------------------------------------------------*/
#define BBIS_SLOTS_ONBOARDDEVICE_START      0x1000

/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
#ifndef _NO_BBIS_HANDLE
   typedef void *BBIS_HANDLE;
#endif


#ifdef __cplusplus
    }
#endif

#endif /* _BB_DEFS_H_ */











