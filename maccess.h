/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: maccess.h
 *
 *       Author: uf
 *
 *  Description: including os specific access macros
 *
 *     Switches: MAC_MEM_MAPPED		memory mapped access
 *               MAC_IO_MAPPED		i/o mapped access
 *               MAC_SHARC_TB		access with SHARC toolbox
 *
 *---------------------------------------------------------------------------
 * Copyright 1998-2019, MEN Mikro Elektronik GmbH
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

#ifndef _MACCESS_H
#define _MACCESS_H


/*-----------------------------------------+
|  DEFINES                                 |
+------------------------------------------*/
/* macros for PCI-parameter <--> maccess-handle conversion */
#define MAC_PCI2MAHDL(bus, dev, func)						\
	(MACCESS)(U_INT32_OR_64) ( ( (bus)  & 0xff ) << 16 |	\
				( (dev)  & 0x1f ) << 11 |					\
				( (func) & 0x07 ) <<  8 )

#define MAC_PCI2MAHDL2(domain, bus, dev, func)				\
	(MACCESS)(U_INT32_OR_64) ( ( (domain) & 0xff ) << 24 |	\
				( (bus)  & 0xff ) << 16 |					\
				( (dev)  & 0x1f ) << 11 |					\
				( (func) & 0x07 ) <<  8 )

#define MAC_MAHDL2PCI_DOM(ma)	 ( (u_int32)(((U_INT32_OR_64)(ma)>>24) & 0xff) )
#define MAC_MAHDL2PCI_BUS(ma)	 ( (u_int32)(((U_INT32_OR_64)(ma)>>16) & 0xff) )
#define MAC_MAHDL2PCI_DEV(ma)	 ( (u_int32)(((U_INT32_OR_64)(ma)>>11) & 0x1f) )
#define MAC_MAHDL2PCI_FUNC(ma) ( (u_int32)(((U_INT32_OR_64)(ma)>> 8) & 0x07) )

/* swap macros */
#ifdef MAC_BYTESWAP
#	define RSWAP8(a)	(a)
#	define RSWAP16(a)	OSS_Swap16(a)
#	define RSWAP32(a)	OSS_Swap32(a)
#	define WSWAP8(a)	(a)
#	define WSWAP16(a)	OSS_SWAP16(a)
#	define WSWAP32(a)	OSS_SWAP32(a)
#else
#	define RSWAP8(a)	(a)
#	define RSWAP16(a)	(a)
#	define RSWAP32(a)	(a)
#	define WSWAP8(a)	(a)
#	define WSWAP16(a)	(a)
#	define WSWAP32(a)	(a)
#endif


/* sanity check */
#ifdef MAC_MEM_MAPPED
#	ifdef MAC_IO_MAPPED
#		error "Do not define MAC_MEM_MAPPED and MAC_IO_MAPPED together"
#	endif /* MAC_IO_MAPPED */
#endif /* MAC_MEM_MAPPED */
#ifndef MAC_MEM_MAPPED
#	ifndef MAC_IO_MAPPED
#		error "Define MAC_MEM_MAPPED or MAC_IO_MAPPED must be defined"
#	endif /* MAC_IO_MAPPED */
#endif /* MAC_MEM_MAPPED */


/* include files for memory mapped access */
#ifdef MAC_MEM_MAPPED

#	ifdef WINNT
#	define MAC_OS_SPECIFIC
#   	include <MEN/MACCESS/nt_func.h>
#	endif

#	ifdef LINUX
#	define MAC_OS_SPECIFIC
#   	include <MEN/MACCESS/maccess_linux.h>
#	endif

#   ifdef NIOS_II_ALTERA_IDE
#   define MAC_OS_SPECIFIC
#       include <MEN/MACCESS/maccess_nios2.h>
#   endif


#	ifndef MAC_OS_SPECIFIC
#		include <MEN/MACCESS/mac_mem.h>
#	endif

#endif
 /* MAC_MEM_MAPPED */


/* include files for i/o mapped access */
#ifdef MAC_IO_MAPPED

#	ifdef WINNT
#   	include <MEN/MACCESS/nt_func.h>
#	endif

#	ifdef VXWORKS
#   	include <MEN/MACCESS/mac_io_vxworks.h>
#	endif

#	ifdef LINUX
#   	include <MEN/MACCESS/maccess_linux.h>
#	endif

#	ifdef __QNX__
#   	include <MEN/MACCESS/maccess_qnx.h>
#	endif

#	ifdef VCIRTX
#   	include <MEN/MACCESS/mac_io_vcirtx.h>
#	endif

#   ifdef NIOS_II_ALTERA_IDE
#     include <MEN/MACCESS/maccess_nios2.h>
# endif


#endif /* MAC_IO_MAPPED */


/* others */
#ifdef MAC_SHARC_TB
#	include <MEN/MACCESS/mac_sharc.h>
#endif


#endif /* _MACCESS_H */






