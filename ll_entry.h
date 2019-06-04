/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ll_entry.h
 *
 *      Author: CKauntz 
 *
 *  Description: MDIS LL-driver jump table definitions
 *
 *     Switches: -
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

#ifndef _LL_ENTRY_H
#define _LL_ENTRY_H

#ifdef __cplusplus
    extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
/* jump table structure */
typedef struct {
        int32 (*init)(DESC_SPEC*, OSS_HANDLE*, MACCESS*,
					  OSS_SEM_HANDLE*, OSS_IRQ_HANDLE*, LL_HANDLE**);
        int32 (*exit)(LL_HANDLE**);
        int32 (*read)(LL_HANDLE*, int32, int32*);
        int32 (*write)(LL_HANDLE*,int32, int32);
        int32 (*blockRead)( LL_HANDLE*, int32, void*, int32, int32* );
        int32 (*blockWrite)(LL_HANDLE*, int32, void*, int32, int32* );
        int32 (*setStat)(LL_HANDLE*, int32, int32, INT32_OR_64);
        int32 (*getStat)(LL_HANDLE*, int32, int32, INT32_OR_64* );
        int32 (*irq)(LL_HANDLE*);
        int32 (*info)(int32, ...);
} LL_ENTRY;

/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
#ifdef _ONE_NAMESPACE_PER_DRIVER_
    extern void LL_GetEntry( LL_ENTRY* drvP );
#else
    extern int32 LL_FindEntry( char* name, LL_ENTRY* drvP );
#endif /* _ONE_NAMESPACE_PER_DRIVER_ */

#ifdef __cplusplus
    }
#endif

#endif /* _LL_ENTRY_H */




