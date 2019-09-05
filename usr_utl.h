/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: usr_utl.h
 *
 *       Author: see
 *
 *  Description: Defines and prototypes for the UTL library.
 *
 *     Switches:  __MAPILIB
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1998-2019, MEN Mikro Elektronik GmbH
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

#ifndef _USR_UTL_H
#define _USR_UTL_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <MEN/utl_os.h>

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
#define UTL_TSTOPT(opt) 			UTL_Tstopt(argc,argv,(opt))
#define UTL_ILLIOPT(opts,errstr)	UTL_Illiopt(argc,argv,(opts),(errstr))

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
#ifndef __MAPILIB
#	define __MAPILIB
#endif

extern char*   __MAPILIB UTL_Ident(void);
extern u_int32 __MAPILIB UTL_Atox(char *str);
extern char*   __MAPILIB UTL_Bindump(u_int32 data, u_int32 bits, char *buf);
extern void    __MAPILIB UTL_Memdump(char *info, char *buf, u_int32 n, u_int32 fmt);
extern char*   __MAPILIB UTL_Tstopt(int argc, char **argv, char *option);
extern char*   __MAPILIB UTL_Illiopt(int argc, char **argv, char *opts, char *errstr);

#ifdef __cplusplus
	}
#endif

#endif	/* _USR_UTL_H */



