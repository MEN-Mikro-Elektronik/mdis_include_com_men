/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: typdefs.h
 *
 *      Author: ub 
 *
 *  Description: Standard types, defs and macros (for OS-9)
 *
 *     Switches: External switches, not defined in this file
 *
 *					_ANSI_C			use prototypes via PROTO
 *					_EDITION		add edition-info
 *					_NO_ADDR_MASK	inhibit address masking in HwRegXX()
 *
 *				 Global system switches, must be defined in this file
 *
 *					MSDOS, OS9, LYNX, HPRT	system flags 	(->syscalls)
 *					INTEL, MOTOROLA			processor flags	(->byte order)
 *					PCBUS, VMEBUS			bus flags		(->byte address)
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1992-2019, MEN Mikro Elektronik GmbH
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

#ifndef _TYPEDEFS_H
#define _TYPEDEFS_H

/*-------------------------------------------------------------------------+
|  system switches                                                         |
+-------------------------------------------------------------------------*/
/* operating system (select one) */
#define MSDOS    0    /* MS-DOS */
#define OS9      0    /* OS-9 */
#define LYNX     0    /* LynxOS */
#define HPRT     0    /* HP-RT */
#define VXWORKS  0    /* VxWorks */
#define LINUX    1    /* Linux */

/* processor, byte order (select one) */
#define INTEL    0    /* INTEL    80xxx */
#define MOTOROLA 1    /* MOTOROLA 68xxx */

/* bus architecture (select one) */
#define PCBUS    0    /* PC-Bus: even byte addresses */
#define VMEBUS   1    /* VMEbus: odd  byte addresses */

/*-------------------------------------------------------------------------+
|  integer types                                                           |
+-------------------------------------------------------------------------*/
/* standard integer types */
#if OS9 && defined(_UCC)
# if !defined(_TYPES_H)
#    include <types.h>
# endif
#else
typedef unsigned char   u_int8;
typedef unsigned short  u_int16;
typedef unsigned long   u_int32;
typedef char            int8;
typedef short           int16;
typedef long            int32;
#endif

/* alternate integer types */
#if !(HPRT || LINUX)
#define u_char   	u_int8
#define u_short  	u_int16
#define u_int    	u_int32
#define u_long   	u_int32
#endif

#define UnBit8      u_int8
#define UnBit16     u_int16
#define UnBit32     u_int32
#define Bit8        int8
#define Bit16       int16
#define Bit32       int32

/*-------------------------------------------------------------------------+
|  hardware access types                                                   |
+-------------------------------------------------------------------------*/
#ifndef VOLATILE
#ifdef _ANSI_C
# define VOLATILE volatile		/* use 'volatile' if ANSI-C */
#else
# define VOLATILE
#endif
#endif

#if MSDOS
#define FAR far					/* use 'far' if MSDOS */
#else
#define FAR
#endif

typedef VOLATILE u_int8  FAR Reg8;     /* register access types */
typedef VOLATILE u_int16 FAR Reg16;
typedef VOLATILE u_int32 FAR Reg32;

/*-------------------------------------------------------------------------+
|  hardware access macros                                                  |
+-------------------------------------------------------------------------*/
#define MkReg(type)  VOLATILE type FAR		/* convert other types */

#ifdef _NO_ADDR_MASK
# define HwReg8(addr)  (Reg8* )(addr)			/* byte addr */
# define HwReg16(addr) (Reg16*)(addr)			/* word addr */
# define HwReg32(addr) (Reg32*)(addr)			/* long addr */
#else
# if PCBUS
#  define HwReg8(addr)  (Reg8* )((addr) & ~1)	/* byte addr: make even */
#  define HwReg16(addr) (Reg16*)((addr) & ~1)	/* word addr: make word aligned */
#  define HwReg32(addr) (Reg32*)((addr) & ~3)	/* long addr: make long aligned */
# endif
# if VMEBUS
#  define HwReg8(addr)  (Reg8* )((addr) | 1)	/* byte addr: make odd */
#  define HwReg16(addr) (Reg16*)((addr) & ~1)	/* word addr: make word aligned */
#  define HwReg32(addr) (Reg32*)((addr) & ~3)	/* long addr: make long aligned */
# endif
#endif

/*-------------------------------------------------------------------------+
|  handling _ANSI_C                                                        |
+-------------------------------------------------------------------------*/
#ifndef PROTO
# ifdef _ANSI_C
#  define PROTO(args)	args		/* ansi c: print arguments */
# else
#  define PROTO(args)	()			/* non ansi c: suppress arguments */
# endif
#endif

/*-------------------------------------------------------------------------+
|  useful macros and definitions                                           |
+-------------------------------------------------------------------------*/
/* useful macros */
#define InSet(v,b,e) ((v)>=(b) && (v)<=(e))   /* if v in set [b..e] */

/* useful defs */
#ifndef true
#define true    1
#endif

#ifndef false
#define false   0
#endif

#ifndef TRUE
#define TRUE    1
#endif

#ifndef FALSE
#define FALSE   0
#endif

#ifndef NULL
#define NULL    0
#endif

/* newline character */
#if MSDOS || LYNX || HPRT || LINUX
#define NL 0x0a
#endif

#if OS9
#define NL 0x0d
#endif

/* add edition-info (as a global string), if _EDITION defined */
#ifdef _EDITION
static void _edummy() { char* a=_EDITION; }
#endif

#endif  /* _TYPEDEFS_H  */

