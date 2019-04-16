/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
 *        \file  a203n.h
 *
 *      \author  dieter.pfeuffer@men.de
 *        $Date: 2005/08/03 12:04:03 $
 *    $Revision: 3.1 $
 *
 *       \brief  A203N register definitions
 *
 *    \switches  -
 */
 /*
 *---------------------------------------------------------------------------
 * Copyright (c) 2019, MEN Mikro Elektronik GmbH
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

#ifndef _A203N_H
#define _A203N_H

#ifdef __cplusplus
      extern "C" {
#endif


/*-----------------------------------------+
|  Address Map (VMEbus A16/A24)            |
+-----------------------------------------*/
#define A203N_A16A24_SIZE		0x1000

/*------------ Module Space ------------*/
#define A203N_MMOD(slot)	(0x400 * (slot))
#define A203N_MMOD_SIZE		0x100

/*------------ Module Control Space ------------*/
#define A203N_MCTRL(slot)	A203N_MMOD(slot) + 0x100
#define A203N_MCTRL_SIZE	0x004

/* register offsets and bits */
#define A203N_ICTRL			0x000	/**< Interrupt Control */
#	define A203N_ICTRL_IPEND	0x80		/**< irq pending/clear */
#	define A203N_ICTRL_EXTV		0x20		/**< external vector */
#	define A203N_ICTRL_IRE		0x10		/**< irq enable */
#	define A203N_ICTRL_IRAC		0x08		/**< irq auto clear */
#	define A203N_ICTRL_LEV(l)	((l) & 0x07)/**< irq level */

#define A203N_IVEC			0x002	/**< Interrupt Vector */

/*------------ Trigger Space ------------*/
#define A203N_TRIG			0x180
#define A203N_TRIG_SIZE		0x004

/* register offsets and bits */
#define A203N_TDATA			0x000	/**< Trigger Data */
#	define A203N_TDATA_A		0x01	/**< TRIGA data */
#	define A203N_TDATA_B		0x02	/**< TRIGB data */

#define A203N_TDIR			0x002	/**< Trigger Direction */
#	define A203N_TDIR_A			0x01	/**< TRIGA direction (1=out) */
#	define A203N_TDIR_B			0x02	/**< TRIGB direction (1=out) */

/*------------ Common Control Space ------------*/
#define A203N_CCTRL			0x300
#define A203N_CCTRL_SIZE		0x082

/* register offsets and bits */
#define A203N_A32ADDR		0x002	/**< A32 Slave Address */
#define A203N_I2C			0x080	/**< I2C Temperature Sensor */


/*-----------------------------------------+
|  Address Map (VMEbus A32)                |
+-----------------------------------------*/
#define A203N_A32_SIZE		0x4000000

/*------------ Module Space ------------*/
#define A203N_MMOD_A32(slot)	(0x1000000 * (slot))
#define A203N_MMOD_A32_SIZE		0x1000000


#ifdef __cplusplus
      }
#endif

#endif /* _A203N_H */
