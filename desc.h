/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: desc.h
 *
 *       Author: uf
 *
 *  Description: interface to desc module
 *
 *     Switches: -
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

#ifndef _DESC_H
#  define _DESC_H

#include <MEN/dbg.h>

#  ifdef __cplusplus
      extern "C" {
#  endif

/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
/* descriptor data ptr */
typedef void* DESC_SPEC;

/* descriptor handle */
typedef void* DESC_HANDLE;

/* internal descriptor handle */
typedef struct {
   u_int32     OwnMemSize;
   OSS_HANDLE  *osHdl;				/* oss handle */
   DBG_HANDLE  *dbgHdl;				/* debug handle */
   u_int32     dbgLev;				/* debug level */
   void        *descStructP;		/* ptr to descr data */
} DESC_INT_HDL;

/*-----------------------------------------+
|  DEFINES                                 |
+------------------------------------------*/
/* limits */
#define DESC_MAX_KEYLEN     256		/* max key string length */

/* descriptor types */
#define DESC_TYPE_DEVICE	0x1
#define DESC_TYPE_BOARD		0x2

/* check return value for fatal errors */
#define DESC_FATAL(error)	((error) && (error) != ERR_DESC_KEY_NOTFOUND)

/*-----------------------------------------+
|  GLOBALS                                 |
+------------------------------------------*/

/*-----------------------------------------+
|  PROTOTYPES                              |
+------------------------------------------*/
extern char* DESC_Ident( void );
extern int32 DESC_Init( DESC_SPEC   *descSpec,
                        OSS_HANDLE  *osHdl,
                        DESC_HANDLE **descHandleP );

extern int32 DESC_GetUInt32( DESC_HANDLE *descHandle,
                             u_int32      defVal,
                             u_int32     *valueP,
                             char        *keyFmt,
                             ...);

extern int32 DESC_GetBinary( DESC_HANDLE *descHandle,
                             u_int8      *defVal,
                             u_int32     defValLen,
                             u_int8      *bufP,
                             u_int32     *lenP,
                             char        *keyFmt,
                             ...);

extern int32 DESC_GetString( DESC_HANDLE *descHandle,
                             char        *defVal,
                             char        *bufP,
                             u_int32     *lenP,
                             char        *keyFmt,
                             ...);

extern void DESC_DbgLevelSet( DESC_HANDLE *descHandle,
							  u_int32 dbgLevel);

extern void DESC_DbgLevelGet( DESC_HANDLE *descHandle,
							  u_int32 *dbgLevelP);

extern int32 DESC_Exit( DESC_HANDLE **descHandleP );

#  ifdef __cplusplus
   }
#  endif

#endif/*_DESC_H*/


