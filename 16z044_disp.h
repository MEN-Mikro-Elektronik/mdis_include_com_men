/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: 16z044_disp.h
 *
 *       Author: cs/kp
 *        $Date: 2011/12/19 14:39:02 $
 *    $Revision: 3.9 $
 *
 *  Description: Header file for MEN Z044_DISP graphics controller
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: 16z044_disp.h,v $
 * Revision 3.9  2011/12/19 14:39:02  ts
 * R: customer uses both LVDS ports on EM10A
 * M: added define for BOTH_PORTS bit
 *
 * Revision 3.8  2011/05/23 15:23:50  ts
 * R: additional display type to be supported with 1280 x 800 pixel
 * M: new define Z044_DISP_RES_1280X800 added
 *
 * Revision 3.7  2007/07/11 14:36:52  rt
 * added:
 * -LVDS support
 *
 * Revision 3.6  2006/07/11 10:00:19  rla
 * Added Resolution 320x200, adapted for Z044 controller revision 1
 *
 * Revision 3.5  2005/06/23 16:03:23  kp
 * Copyright line changed
 *
 * Revision 3.4  2005/05/10 13:19:06  ub
 * added Z044_DISP_FOFFS register
 *
 * Revision 3.3  2005/04/29 15:54:56  dpfeuffer
 * Z044_LVDS_XXX defines added
 *
 * Revision 3.2  2005/02/10 09:59:52  kp
 * + Z044_DISP_CTRL_BYTESWAP
 *
 * Revision 3.1  2005/02/02 16:36:15  kp
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2005 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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

#ifndef _Z044_DISP_H
#define _Z044_DISP_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* registers etc. */
#define Z044_DISP_FBSTART			0x00		/**< framebuffer start */
#define Z044_DISP_CTRL				0x00		/**< control register */
#define Z044_DISP_FOFFS             0x04        /**< frame offset */
#define Z044_LVDS_CTRL				0x08		/**< lvds control register */


/* Z044_DISP_CTRL bit definitions */
#define Z044_DISP_CTRL_CHANGE	0x80000000
							/**< bit enabling change of this register */
							/**< 0: disable that changes of register settings
							 *      affect mode of display controller \n
							 *   1: changes to register also change mode of
							 *      display controller
							 */
#define Z044_DISP_CTRL_ONOFF	0x40000000
							/**< bit setting power on/off status of display */
							/**< 0: display (and controller) enabled \n
							 *   1: display (and controller) disabled
							 */
#define Z044_DISP_CTRL_DEBUG	0x20000000
							/**< bit setting debug mode of display controller*/
							/**< 0: disable debug mode \n
							 *   1: enable debug mode
							 *      a colored rectangular the size of the
							 *      actual resolution is drawn
							 */
#define Z044_DISP_CTRL_BYTESWAP	0x00000008 /**< perform FB byte swapping */
#define Z044_DISP_CTRL_REFRESH	0x00000004
							/**< bit setting refresh frequency of display */
							/**< 0: 60 Hz \n
							 *   1: 75 Hz
							 */
#define Z044_DISP_CTRL_RES_MASK	0x00000033
							/**< mask for all bits setting the resolution */
#define Z044_DISP_CTRL_RES_320X240		0x00000010
							/**< setting VGA resolution (  320 x  240 ) */
#define Z044_DISP_CTRL_RES_640X480		0x00000000
							/**< setting VGA resolution (  640 x  480 ) */
#define Z044_DISP_CTRL_RES_800X600		0x00000001
							/**< setting VGA resolution (  800 x  600 ) */
#define Z044_DISP_CTRL_RES_1024X768	0x00000002
							/**< setting VGA resolution ( 1024 x  768 ) */
#define Z044_DISP_CTRL_RES_1280X1024	0x00000003
							/**< setting VGA resolution ( 1280 x 1024 ) */
#define Z044_DISP_CTRL_RES_1280X800		0x00000011
							/**< setting VGA resolution ( 1280 x 800 ) */

#define Z044_DISP_RES_MASK			0x000000FF
#define Z044_DISP_RES_320X240		4
#define Z044_DISP_RES_640X480		0
#define Z044_DISP_RES_800X600		1
#define Z044_DISP_RES_1024X768		2
#define Z044_DISP_RES_1280X1024		3
#define Z044_DISP_RES_1280X800		5

#define Z044_DISP_LVDS_MASK			0xF0000000
#define Z044_DISP_LVDS				(1<<28)

/* Z044_LVDS_CTRL bit definitions */
#define Z044_LVDS_WIDTH_24_BIT	0x00000001
							/**< Panel Type (determines number of used
                             *   LVDS channels) */
#define Z044_LVDS_HITACHI		0x00000002
							/**< Panel Mode (used when WIDTH_24_BIT = 1) */
#define Z044_LVDS_TWO_PORTS		0x00000004
							/**< Select number of used FPD Link ports */
#define Z044_LVDS_SEL_PORT		0x00000008
							/**< Select FPD Link Port
                             *   (used when TWO_PORTS = 0) */
#define Z044_LVDS_INV_TX_CLK	0x00000010
							/**< Invert TX_CLK (= LVDS pixel clock) */
#define Z044_LVDS_DISABLE_LVDS	0x00000020
							/**< Disable LVDS */
#define Z044_LVDS_BOTH_PORTS	0x00000040
							/**< enable one or both LVDS ports */


#ifdef __cplusplus
	}
#endif

#endif	/* _Z044_DISP_H */

