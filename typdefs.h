/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: typdefs.h
 *
 *      $Author: ub $
 *        $Date: 2003/05/26 11:45:18 $
 *    $Revision: 2.1 $
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
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: typdefs.h,v $
 * Revision 2.1  2003/05/26 11:45:18  ub
 * Initial Revision
 *
 * Revision 1.26  1998/06/24 17:45:41  see
 * ifndef VOLATILE added since problems when including men_typs.h
 *
 * Revision 1.25  1998/01/21 11:20:01  kp
 * inhibit alternate u_char.. types for HPRT
 *
 * Revision 1.24  1997/06/02 17:18:01  see
 * _NO_ADDR_MASK switch added to inhibit address masking
 * (this allows accessing odd and even byte addresses via HwReg8)
 *
 * Revision 1.23  1997/04/11 09:51:25  see
 * VXWORKS switch added
 *
 * Revision 1.22  1997/04/08 11:42:23  kp
 * MkReg: VOLATILE added
 * HwReg8 (VMEBUS): make odd
 * HwReg16: make word aligned
 * HwReg32: make long aligned
 *
 * Revision 1.21  1996/11/29 09:19:34  kp
 * Added volatile macros (kp)
 *
 * Revision 1.20  1995/08/07 13:59:35  see
 * OS9: include types.h only if _UCC (to allow compiling with non-UCC)
 *
 * Revision 1.19  95/03/28  16:23:41  see
 * NL definitions for MSDOS and HPRT added
 *
 * Revision 1.18  95/02/15  09:46:56  kp
 * added PROTO macro (ifdef _ANSI_C)
 *
 * Revision 1.17  94/11/23  10:04:35  kp
 * changed include algorithm for types.h slightly
 *
 * Revision 1.16  94/08/15  11:01:55  see
 * OS9: include types.h if _TYPES_H not defined
 *
 * Revision 1.15  94/04/13  15:38:17  Seeberger
 * check _TYPES_H identifiers also for alternate integer types
 *
 * Revision 1.14  94/03/02  11:31:47  Seeberger
 * _TYPEDEFS_H identifier added
 * check _TYPES_H identifiers for OS-9 integer types
 * old style integers are now converted
 * alternate integers are now typedef's
 *
 * Revision 1.13  93/10/13  14:51:51  Seeberger
 * HPRT switch added
 *
 * Revision 1.12  93/09/28  11:04:33  Seeberger
 * Reg8 (PCBUS): make even by &~1 instead -1
 *
 * Revision 1.11  93/09/10  11:44:44  Seeberger
 * int8..int32, u_int8..u_int32 types now macros
 * u_char..u_long macros added
 *
 * Revision 1.10  93/09/08  16:49:20  Seeberger
 * HwReg32 macro added
 *
 * Revision 1.9  93/08/19  15:25:42  Seeberger
 * bug fixed, NL character define
 *
 * Revision 1.8  93/05/07  11:14:59  Seeberger
 * #ifndef true/false,TRUE/FALSE added
 *
 * Revision 1.7  93/03/01  12:59:17  Seeberger
 * switches OS9, MOTOROLA, VMEBUS set
 * INTEL, MOTOROLA changed
 * PCBUS, VMEBUS added
 * HwReg() types added
 * InSet() macro added
 * macro MSDOS added
 * macro NL added
 *
 * Revision 1.2  92/11/23  09:24:48  Seeberger
 * alternate int types added
 *
 * Revision 1.1  92/10/22  09:18:52  Seeberger
 * Initial revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1992-1994 by MEN mikro elektronik GmbH, Nuernberg, Germany
 ****************************************************************************/

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

