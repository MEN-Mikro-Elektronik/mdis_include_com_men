/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  serflash.h
 *
 *      \author  Adam Wujek
 *
 *  	 \brief Defines for Serial flash indirect interface
 *
 */
/*---------------------------------------------------------------------------
 * (c) Copyright 2017 by CERN
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

#ifndef _SERFLASH_H
#define _SERFLASH_H

#  ifdef __cplusplus
      extern "C" {
#  endif

/*--------------------------------------+
|   DEFINES & CONSTS                    |
+--------------------------------------*/

#define SFII_SPACE		0x00000000	/**< Serial flash indirect interface - offset	*/
#define SFII_SIZE		0x00000010	/**< Serial flash indirect interface - size (16 Bytes) */

#define SFII_CR			0x00		/**< Serial flash indirect interface - Control Register */
#define SFII_DR			0x04		/**< Serial flash indirect interface - Data Register */
#define SFII_BSR		0x08		/**< Serial flash indirect interface - Board Status Register, status of the remote update controller */
#define SFII_BAR		0x0C		/**< Serial flash indirect interface - Boot-Address Register, FPGA image boot byte address */

/* SFII_BSR, Board Status Register, status of the remote update controller */
#define SFII_BSR_BS_MASK	0x03		/**< Serial flash indirect interface - Board Status Register, Mask gives the current status of the FPGA and which image is loaded */
#define SFII_BSR_LRTC_MASK	0x7c		/**< Serial flash indirect interface - Board Status Register, last_reconf_trigger_con Mask,
							     Reflects the reason of the last reconfiguration. These bits are only valid in FPGA Fallback Image.
							     In FPGA Image they are always '0'. */
#define SFII_BSR_LRTC_SHIFT	2

/* SFII_BSR_BS_MASK */
#define SFII_BSR_BS_FALLBACK	0x00		/**< Serial flash indirect interface - Board Status Register,
							     FPGA is programmed with the FPGA Fallback Image and no configuration error has occurred. */
#define SFII_BSR_BS_IMG_OK	0x01		/**< Serial flash indirect interface - Board Status Register,
							     FPGA is programmed with the FPGA Image */
#define SFII_BSR_BS_IMG_ERR	0x02		/**< Serial flash indirect interface - Board Status Register,
							     FPGA has returned to FPGA Fallback Image after a configuration error. */
#define SFII_BSR_BS_INV		0x03		/**< Serial flash indirect interface - Board Status Register, Invalid */


#  ifdef __cplusplus
       }
#  endif

#endif /* _SERFLASH_H */
