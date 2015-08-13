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
 * (c) Copyright 2000 by MEN mikro elektronik GmbH, Nuernberg, Germany 
 ****************************************************************************/

#ifndef _MEN_PCI2VME_H
#define _MEN_PCI2VME_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- PCI vendor/device IDs ---*/
#define MENPCI2VME_DEV_ID		0x5056	/* ASCII 'PV' */
#define MENPCI2VME_VEN_ID		0x1172  

#define MENPCI2VME_DEV_ID_A21       0x4D45  /* ASCII 'PV' */
#define MENPCI2VME_VEN_ID_A21       0x1A88

#define MENPCI2VME_SUB_DEV_ID	0xFF00  /* ???? */
#define MENPCI2VME_SUB_VEN_ID	0xFF00  /* ???? */

/*--- offsets to address found in BAR0 ---*/
#define MENPCI2VME_A24_SPACE	0x00000000	/* VME A24 master access */
#define MENPCI2VME_A16_SPACE	0x01000000	/* VME A16 master access */
#define MENPCI2VME_SRAM_SPACE	0x01400000	/* VME shared RAM */
#define MENPCI2VME_REG_SPACE	0x01800000 	/* registers */
#define MENPCI2VME_IACK_SPACE	0x01c00000 	/* IACK space */

/*--- offsets to register start address (MENPCI2VME_REG_SPACE) ---*/
#define MENPCI2VME_INTR			0x00	/* interrupter control */
#define MENPCI2VME_INTID		0x04	/* interrupter vector */
#define MENPCI2VME_ISTAT		0x08	/* interrupt pending */
#define MENPCI2VME_IMASK		0x0c	/* interrupt handler mask*/
#define MENPCI2VME_MSTR			0x10	/* master control */
#define MENPCI2VME_SLV			0x14	/* slave control */
#define MENPCI2VME_SYSCTL		0x18	/* system control */

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
