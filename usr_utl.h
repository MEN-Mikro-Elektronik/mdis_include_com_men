/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: usr_utl.h
 *
 *       Author: see
 *        $Date: 2000/08/03 15:43:47 $
 *    $Revision: 2.6 $
 *
 *  Description: Defines and prototypes for the UTL library.
 *
 *     Switches:  __MAPILIB
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: usr_utl.h,v $
 * Revision 2.6  2000/08/03 15:43:47  Schmidt
 * __MAPILIB added to all prototypes to enable OS specific calling convention
 *
 * Revision 2.5  1998/08/13 10:55:46  see
 * UTL_Ident prototype added
 *
 * Revision 2.4  1998/08/11 16:12:56  Schmidt
 * include <MEN/utl_os.h> added, cosmetics
 *
 * Revision 2.3  1998/08/10 10:58:38  see
 * prototypes changed
 *
 * Revision 2.2  1998/08/10 10:44:39  see
 * prototypes changed
 *
 * Revision 2.1  1998/07/02 15:29:20  see
 * Added by mcvs
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998-2000 by MEN mikro elektronik GmbH, Nuremberg, Germany
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



