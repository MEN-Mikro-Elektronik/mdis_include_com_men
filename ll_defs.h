/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ll_defs.h
 *
 *      $Author: see $
 *        $Date: 1998/06/02 11:00:14 $
 *    $Revision: 1.2 $
 *
 *  Description: LL-Drv. defines
 *
 *     Switches: _NO_LL_HANDLE	exclude LL_HANDLE declaration
 *
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

#ifndef _LL_DEFS_H
#define _LL_DEFS_H

#ifdef __cplusplus
    extern "C" {
#endif

/*-----------------------------------------+
|  DEFINES & CONST                         |
+------------------------------------------*/
/* ll-drv info function codes */
#define LL_INFO_ADDRSPACE_COUNT         0x01
#define LL_INFO_ADDRSPACE               0x02
#define LL_INFO_HW_CHARACTER            0x03
#define LL_INFO_IRQ                     0x04
#define LL_INFO_LOCKMODE                0x05

/* LL_INFO_LOCKMODE values */
#define LL_LOCK_NONE	0x01
#define LL_LOCK_CALL	0x02
#define LL_LOCK_CHAN	0x03

/* ll-drv irq return codes */
#define LL_IRQ_DEV_NOT  0
#define LL_IRQ_DEVICE   1
#define LL_IRQ_UNKNOWN  2

/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
#ifndef _NO_LL_HANDLE
   typedef void *LL_HANDLE;
#endif

#ifdef __cplusplus
    }
#endif

#endif /* _LL_DEFS_H */

