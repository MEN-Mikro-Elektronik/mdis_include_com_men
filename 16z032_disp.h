/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: 16z032_disp.h
 *
 *       Author: ub
 *        $Date: 2005/09/09 20:17:54 $
 *    $Revision: 3.1 $
 *
 *  Description: Header file for MEN 16Z032_DISP graphics controller
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: 16z032_disp.h,v $
 * Revision 3.1  2005/09/09 20:17:54  CSchuster
 * Initial Revision
 *
 *
 * cloned from saruman.h
 *
 * Revision 2.2  2005/03/21 16:10:31  ub
 * changed register defines to match hardware spec
 *
 * Revision 2.1  2002/10/28 08:40:29  ub
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2002-2005 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ****************************************************************************/

#ifndef _16Z032_DISP_H
#define _16Z032_DISP_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* registers etc. */
#define Z032_FBSTART			0x0				/* framebuffer start */
#define Z032_CTRL			0x200000		/* control register */

/* #defines for Z032_CTRL */
#define Z032_CTRL_BRIGHTNESS	0x00ff			/* display brightness (mask) */
#define Z032_CTRL_ACTIVE		0x0100			/* display active */
#define Z032_CTRL_TEST		0x0200			/* show test pattern */


/* other parameters */
#define Z032_FBSIZE			0x200000		/* size of framebuffer */

#ifdef __cplusplus
	}
#endif

#endif	/* _16Z032_DISP_H */
