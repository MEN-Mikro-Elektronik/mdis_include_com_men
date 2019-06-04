/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: testutil.h
 *
 *      Author: MRoth 
 *
 *  Description: include file for use with testutil.l
 *
 *     Switches: ANSI_C or _ANSI_EXT
 *
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1995-2019, MEN Mikro Elektronik GmbH
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

#ifndef _TESTUTIL_H
#define _TESTUTIL_H

#ifndef PROTO
# if defined(_ANSI_C) || defined(_ANSI_EXT) || defined(VXWORKS)
#  define PROTO(args)	args		/* ansi c: use arguments */
# else
#  define PROTO(args)	()			/* non ansi c: suppress arguments */
# endif
#endif

/*--- window IDs ---*/
#define WDW_MSG 	1				/* message window */
#define WDW_ERR		2				/* error window */
#define WDW_RESULT	3				/* result window */
#define WDW_KEYS	4				/* user key window */

/*--- cursor keys --*/
#define	OFFS		256
#define CURSOR_UP		OFFS+0
#define CURSOR_DOWN		OFFS+1
#define CURSOR_LEFT		OFFS+2
#define CURSOR_RIGHT	OFFS+3

/*--- prototypes ---*/
void tu_init_screen	PROTO(( char *title, int error_wdw_width,
						   int result_wdw_height, int key_line_flg ));
void tu_init_screen_pos PROTO(( char *title, int error_wdw_width, int result_wdw_height,
						   int key_line_flg, int y ));
int  tu_print 		PROTO((int wdw_id, int x, int y, char *fmt, ... ));
int  tu_print_revers 		PROTO((int wdw_id, int x, int y, char *fmt, ... ));
void tu_clear 		PROTO((int wdw_id, int x, int y, int n ));
void tu_clear_wdw 	PROTO((int wdw_id));
void tu_print_errhead PROTO((char *line));
char *tu_underline_string PROTO(( char *line ));
int  tu_print_error PROTO((int toterr_update, int user_stop, char *fmt, ...));
void tu_key_line    PROTO((char *line));
void tu_save_key_line PROTO((void));
void tu_restore_key_line PROTO((void));
void tu_print_pass  PROTO((int current_pass, int total_pass));
void tu_print_elapsed_time PROTO((void));
int	 tu_keybd_hit   PROTO((void));
int  tu_wait_key	PROTO((void));
void tu_exit		PROTO((void));

u_int32 tu_get_tick PROTO((void));
char *tu_tick2string PROTO(( int fmt, u_int32 tick_diff ));
char *tu_bytes_per_sec PROTO(( u_int32 bytes, u_int32 tick_diff ));


char tu_getc		PROTO((void));

int  tu_getk		PROTO((void));
int	 tu_inputd		PROTO((int wdw, int x, int y, char *sptr, int *vptr ));
int	 tu_inputx		PROTO((int wdw, int x, int y, char *sptr, int *vptr ));

/* getkey.c */
int		tu_init_keys(void);
void	tu_exit_keys(void);

/* OS-9 only */
void tu_usr_intercept PROTO(( void (*routine)(int signal)));

#endif
