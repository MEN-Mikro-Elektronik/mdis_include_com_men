/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  men_typs.h
 *
 *      \author  uf
 *
 *     \project  MEN global
 *       \brief  MEN types and useful definitions
 *    \switches  WINNT
 *               OS9
 *               MSDOS
 *               LYNX
 *               HPRT
 *               HPUX
 *               VXWORKS
 *		 LINUX
 *               __QNX__
 *
 *               OS9 switches
 *               - _UCC
 *               - _TYPES_H
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 1997-2020, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MEN_TYPS_H
#define _MEN_TYPS_H

/*-------------------------------------------------------------------------+
|  OS specifics                                                            |
+-------------------------------------------------------------------------*/
/*
 * Windows: Set WINNT if _WIN32 is set (but not VCIRTX)
 *          Note: _WIN32 is always set from build utility and VC
 *                but WINNT is only set from build.
 */
#if ( defined( _WIN32 ) && !defined(VCIRTX) )
  #ifndef WINNT
    #define WINNT
  #endif
#endif

#ifdef VXWORKS
  #ifndef _VSB_CONFIG_FILE
    #warning _VSB_CONFIG_FILE not defined - using default
    #define _VSB_CONFIG_FILE "../lib/h/config/vsbConfig.h"
  #endif
#endif

/*-------------------------------------------------------------------------+
|  integer types                                                           |
+-------------------------------------------------------------------------*/
#if ((defined(_OSK) || defined(OSK) || defined(OS9) || defined(OS9000)) && defined(_UCC))
# if !defined(_TYPES_H)
#    include <types.h>
# endif
#elif defined(MENMON) && defined(_UCC)
# if !defined(_TYPES_H)
#    include <types.h>
# endif
#else

/* standard integer types */
typedef unsigned char   u_int8;			/**< 8-bit unsigned integer */
typedef signed char     int8;			/**< 8-bit signed integer */

typedef unsigned short  u_int16;		/**< 16-bit unsigned integer */
typedef signed short    int16;			/**< 16-bit signed integer */

#if defined(_LIN64) || defined(_LP64)
 typedef unsigned int   u_int32;		/**< 32-bit unsigned integer */
 typedef signed int		int32;			/**< 32-bit signed integer */
#else
 typedef unsigned long  u_int32;		/**< 32-bit unsigned integer */
 typedef signed long    int32;			/**< 32-bit signed integer */
#endif

#if defined(WINNT) || defined(VCIRTX)
 typedef unsigned __int64	u_int64;	/**< 64-bit unsigned integer */
 typedef __int64			int64;		/**< 64-bit signed integer */
#else
# define u_int64		unsigned long long
# define int64			long long
#endif
#endif

/*-------------------------------------------------------------------------+
|  useful definitions                                                      |
+-------------------------------------------------------------------------*/
#ifndef TRUE
# define TRUE    1			/**< logical TRUE */
#endif

#ifndef FALSE
# define FALSE   0			/**< logical FALSE */
#endif

#ifndef NULL
# define NULL    0			/**< zero pointer */
#endif

#ifndef VOLATILE
# define VOLATILE volatile	/**< volatile keyword */
#endif

/* convert old style men types (don't use in new projects !!!) */
#define UnBit8      u_int8
#define UnBit16     u_int16
#define UnBit32     u_int32
#define Bit8        int8
#define Bit16       int16
#define Bit32       int32

/* MEN API calling convention and 64-bit support */
#if defined(WINNT)
  /* 64-bit compiler */
  #if defined(_WIN64)
#define __MAPILIB						/**< MEN API calling convention */
    #define INT32_OR_64		int64		/**< 32 or 64-bit signed integer */
	#define U_INT32_OR_64	u_int64		/**< 32 or 64-bit unsigned integer */
	#define MENTYPS_64BIT
  /* 32-bit compiler */
  #else
    #define __MAPILIB 		__stdcall	/**< MEN API calling convention */
    #define INT32_OR_64		int32		/**< 32 or 64-bit signed integer */
	#define U_INT32_OR_64	u_int32		/**< 32 or 64-bit unsigned integer */
  #endif /* _WIN64 */
#endif /* WINNT */

#if defined(_LIN64)
    #define __MAPILIB
    #define INT32_OR_64		int64		/**< 32 or 64-bit signed integer */
	#define U_INT32_OR_64	u_int64		/**< 32 or 64-bit unsigned integer */
	#define MENTYPS_64BIT
#endif

#ifndef INT32_OR_64
	#define INT32_OR_64		int32		/**< 32 or 64-bit signed integer */
#endif
#ifndef U_INT32_OR_64
	#define U_INT32_OR_64	u_int32		/**< 32 or 64-bit unsigned integer */
#endif

#ifndef __MAPILIB
#  define __MAPILIB						/**< MEN API calling convention */
#endif

/*-------------------------------------------------------------------------+
|  useful macros                                                           |
+-------------------------------------------------------------------------*/
/** range checking: check if v is in range [b..e] */
#define IN_RANGE(v,b,e) ((v)>=(b) && (v)<=(e))

/** stringize macros */
#define MENT_XSTR_SFX(s,p) MENT_STR(s) " " MENT_STR(p)
#define MENT_XSTR(s) MENT_STR(s)
#define MENT_STR(s) #s

/*-------------------------------------------------------------------------+
|  special character definitions                                           |
+-------------------------------------------------------------------------*/
/** newline */
#if defined(MSDOS) || defined(LYNX) || defined(HPRT) || defined(HPUX) || defined(VXWORKS) || defined(WINNT) || defined(LINUX) || defined(__QNX__)
# define MEN_NL 0x0a
#endif
#if defined(OS9) || defined(OS9000)
# define MEN_NL 0x0d
#endif

/** path separator */
#if defined(OS9) || defined(OS9000) || defined(LYNX) || defined(HPRT) || defined(HPUX) || defined(VXWORKS) || defined(LINUX) || defined(__QNX__)
# define MEN_PATHSEP 0x2f
#endif
#if defined(MSDOS) || defined(WINNT)
# define MEN_PATHSEP 0x5c
#endif

/* Handle intentional statement that falls through to another case label */
#if defined(__GNUC__) && (__GNUC__ >= 7)
# define FALLTHROUGH __attribute__((__fallthrough__))
#else
# define FALLTHROUGH
#endif

#endif  /* _MEN_TYPS_H  */






