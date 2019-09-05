/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: usr_ers.h
 *
 *       Author: ds
 *
 *  Description: UOS_OSS error code string table
 *
 *     Switches: -
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

#ifndef _USR_ERS_H_
#  define _USR_ERS_H_

#  ifdef __cplusplus
      extern "C" {
#  endif

/*------------------------------+
|  table of error code strings  |
+------------------------------*/
struct _UOS_ERR_STR {
    int32  errCode;
    char*  errString;
} UOS_ErrStrTable[] =
{	/* no error */
	{ ERR_UOS_SUCCESS		  ,"UOS: (no error)" },
	/* UOS error codes */
	{ ERR_UOS_BUSY            ,"UOS: function is locked" },
	{ ERR_UOS_NOT_INIZED      ,"UOS: function not initialized" },
	{ ERR_UOS_NOT_INSTALLED   ,"UOS: function not installed" },
	{ ERR_UOS_ABORTED         ,"UOS: function aborted" },
	{ ERR_UOS_TIMEOUT         ,"UOS: timeout occurred" },
	{ ERR_UOS_OVERRUN         ,"UOS: queue overrun" },
	{ ERR_UOS_ILL_SIG         ,"UOS: illegal signal code" },
	{ ERR_UOS_NO_TIMER        ,"UOS: no timer available" },
	{ ERR_UOS_NO_MIKRODELAY   ,"UOS: no mikro delay available" },
	{ ERR_UOS_ILL_PARAM       ,"UOS: illegal parameter" },
	{ ERR_UOS_MEM_ALLOC       ,"UOS: can't alloc memory" },
	{ ERR_UOS_GETSTAT         ,"UOS: driver getstat failed" },
	{ ERR_UOS_SETSTAT         ,"UOS: driver setstat failed" },
	{ ERR_UOS_NO_PERM         ,"UOS: no permission accessing memory" },
};

#define UOS_NBR_OF_ERR sizeof(UOS_ErrStrTable)/sizeof(struct _UOS_ERR_STR)

#  ifdef __cplusplus
       }
#  endif

#endif/*_USR_ERS_H_*/




