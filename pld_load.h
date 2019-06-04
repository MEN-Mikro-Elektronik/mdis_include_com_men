/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: pld_load.h
 *
 *       Author: see
 * 
 *  Description: PLD loader library defs
 *                      
 *     Switches: PLD_SW - swapped access
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1998-2019, MEN Mikro Elektronik GmbH
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

#ifndef _PLD_LOAD_H
#define _PLD_LOAD_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
/* swapped access */
#ifdef PLD_SW
#	define PLD_ErrorMsg		PLD_SW_ErrorMsg
#	define PLD_FLEX10K_Identify	PLD_SW_FLEX10K_Identify
#	define PLD_FLEX10K_LoadCallBk	PLD_SW_FLEX10K_LoadCallBk
#	define PLD_FLEX10K_LoadDirect	PLD_SW_FLEX10K_LoadDirect
#endif

/* PLD execution flags */
#define PLD_FIRSTBLOCK		0x1		/* init PLD before loading block */
#define PLD_LASTBLOCK		0x2		/* terminate PLD after loading block */

/* PLD error codes */
#define PLD_ERR_NOTFOUND	0x1		/* no response from PLD */
#define PLD_ERR_INIT		0x2		/* error when initializing PLD */
#define PLD_ERR_LOAD		0x3		/* error when loading PLD */
#define PLD_ERR_TERM		0x4		/* error when terminating PLD */

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
/* none */

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
/* Common */
extern char *PLD_ErrorMsg(int32 error);

/* FLEX10K */
extern char *PLD_FLEX10K_Identify(void);
extern int32 PLD_FLEX10K_LoadCallBk(u_int8	*buf,
							 u_int32 size,
							 u_int32 flags,
							 void *arg,
							 void (*msec_delay)(void *arg, u_int32 msec),
							 u_int8 (*get_status)(void *arg),
							 u_int8 (*get_cfgdone)(void *arg),
							 void (*set_data)(void *arg, u_int8 state),
							 void (*set_dclk)(void *arg, u_int8 state),
							 void (*set_config)(void *arg, u_int8 state));
extern int32 PLD_FLEX10K_LoadDirect(MACCESS *ma, 
							 u_int8	*buf,
							 u_int32 size,
							 u_int32 flags,
							 void *arg,
							 void (*msec_delay)(void *arg, u_int32 msec),
							 u_int16 nonpld_bits,
							 u_int8 data, 
							 u_int8 dclk, 
							 u_int8 config, 
							 u_int8 status, 
							 u_int8 cfgdone);


#ifdef __cplusplus
	}
#endif

#endif	/* _PLD_LOAD_H */


