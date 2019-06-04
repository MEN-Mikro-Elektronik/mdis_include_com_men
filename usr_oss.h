/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: usr_oss.h
 *
 *       Author: uf
 *
 *  Description: User mode system services
 *
 *     Switches: NO_CALLBACK, NO_SHARED_MEM, __MAPILIB
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1997-2019, MEN Mikro Elektronik GmbH
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
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _USR_OSS_H_
#	define _USR_OSS_H_

#include <MEN/usr_os.h>

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
/* limits */
#define UOS_MAX_USEC	1000000		/* max mikrodelay */

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
/* for easy casting function pointers (callback) */
typedef void (*UOS_FKT_VOIDP1)(void*);
typedef void (*UOS_FKT_VOIDP2)(void*, void*);

typedef struct UOS_DL_NODE {	/* Double linked list node */
	struct UOS_DL_NODE *next;
	struct UOS_DL_NODE *prev;
} UOS_DL_NODE;

typedef struct {		/* Double linked list header */
	UOS_DL_NODE *head;
	UOS_DL_NODE *tail;
	UOS_DL_NODE *tailpred;
} UOS_DL_LIST;

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
#ifndef __MAPILIB
#	define __MAPILIB
#endif

/* general */
extern char*   __MAPILIB UOS_Ident(void);
extern u_int32 __MAPILIB UOS_ErrnoGet(void);
extern u_int32 __MAPILIB UOS_ErrnoSet(u_int32 errCode);
extern char*   __MAPILIB UOS_ErrString(int32 errCode);
extern char*   __MAPILIB UOS_ErrStringTs(int32 errCode, char *strBuf);
extern int32   __MAPILIB UOS_KeyPressed(void);
extern int32   __MAPILIB UOS_KeyWait(void);
extern u_int32 __MAPILIB UOS_Random(u_int32 old);
extern u_int32 __MAPILIB UOS_RandomMap(u_int32 val, u_int32 ra, u_int32 re);
extern u_int32 __MAPILIB UOS_MsecTimerGet(void);
extern u_int32 __MAPILIB UOS_MsecTimerResolution(void);
extern int32   __MAPILIB UOS_Delay(u_int32 msec);
extern int32   __MAPILIB UOS_MikroDelayInit(void);
extern int32   __MAPILIB UOS_MikroDelay(u_int32 usec);

/* signal handling */
extern int32 __MAPILIB UOS_SigInit(void (__MAPILIB *sigHandler)(u_int32 sigCode));
extern int32 __MAPILIB UOS_SigExit(void);
extern int32 __MAPILIB UOS_SigInstall(u_int32 sigCode);
extern int32 __MAPILIB UOS_SigRemove(u_int32 sigCode);
extern int32 __MAPILIB UOS_SigMask(void);
extern int32 __MAPILIB UOS_SigUnMask(void);
extern int32 __MAPILIB UOS_SigWait(u_int32 msec, u_int32 *sigCodeP);

/* callback */
#ifndef NO_CALLBACK
extern int32 __MAPILIB UOS_CallbackInit(INT32_OR_64 path,UOS_CALLBACK_HANDLE **cbHdlP);
extern int32 __MAPILIB UOS_CallbackExit(UOS_CALLBACK_HANDLE **cbHdlP);
extern int32 __MAPILIB UOS_CallbackSet(UOS_CALLBACK_HANDLE *cbHdl,u_int32 callNr,
                                       void (*funct)(void *appArg, void *drvArg),
                                       void *appArg);
extern int32 __MAPILIB UOS_CallbackClear(UOS_CALLBACK_HANDLE *cbHdl,u_int32 callNr);
extern int32 __MAPILIB UOS_CallbackMask(UOS_CALLBACK_HANDLE *cbHdl);
extern int32 __MAPILIB UOS_CallbackUnMask(UOS_CALLBACK_HANDLE *cbHdl);
#endif

/* shared memory */
#ifndef NO_SHARED_MEM
extern int32 __MAPILIB UOS_SharedMemInit(INT32_OR_64 path,UOS_SHMEM_HANDLE **smHdlP);
extern int32 __MAPILIB UOS_SharedMemExit(UOS_SHMEM_HANDLE **smHdlP);
extern int32 __MAPILIB UOS_SharedMemSet(UOS_SHMEM_HANDLE *smHdl,u_int32 smNr,
										u_int32 size,void **appAddrP);
extern int32 __MAPILIB UOS_SharedMemLink(UOS_SHMEM_HANDLE *smHdl,u_int32 smNr,
										 u_int32 *sizeP,void **appAddrP);
extern int32 __MAPILIB UOS_SharedMemClear(UOS_SHMEM_HANDLE *smHdl,u_int32 smNr);
#endif

/* double linked list */
extern UOS_DL_LIST* __MAPILIB UOS_DL_NewList(UOS_DL_LIST *l);
extern UOS_DL_NODE* __MAPILIB UOS_DL_Remove(UOS_DL_NODE *n);
extern UOS_DL_NODE* __MAPILIB UOS_DL_RemHead(UOS_DL_LIST *l);
extern UOS_DL_NODE* __MAPILIB UOS_DL_AddTail(UOS_DL_LIST *l,UOS_DL_NODE *n);

#ifdef __cplusplus
	}
#endif

#endif /*_USR_OSS_H_*/
















