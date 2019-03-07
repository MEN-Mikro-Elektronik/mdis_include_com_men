/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: uti.h
 *
 *      $Author: ww $
 *        $Date: 2001/08/07 18:34:15 $
 *    $Revision: 1.10 $
 * 
 *  Description: Header File for uti.l
 *                      
 *     Switches: _ANSI_EXT or __STDC__: include prototypes
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1993-2019, MEN Mikro Elektronik GmbH
 ****************************************************************************/
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


#if !defined(__STDC__) && !defined(_ANSI_EXT)
extern char *tstopt();
void	illiopt();
#else
/*--- ANSI C prototypes ---*/

int 	_f_permit( void *, int );
int 	_f_protect( void *, int);
int 	ask( char *, char *, int, char *);
void 	clearmem( char *, int );
int 	cntarg( int, char **);
int 	cntopt( int, char **);
void	dump(const char *, const char *, int);
void	echo(int,int);
int		p_echo(int,int);
void	fdump( FILE *, char *, char *, int);
char	*filename( char *);
int		ftw( const char *, int (*)(), int, long int, long int, long int);
int		getint(const char *,int,int,int,char *) ;
int 	get_screen_xsize(void);
int 	get_screen_ysize(void);
char 	*getshorterrmsg( int, char *);
char	*getstr( const char *, char *, const char *, int, const char *);
int		installnam( char * );
int		line_args( char *, char **, int, const char *, const char *);
void	free_args( const char **);
int		look_string( const char *, const char **, int );
int		macro_def(void *, const char *, const char *, int );
char 	*macro_expand(void *, const char *, char *buf, int );
char 	*make_path(char *, const char *, const char *, int);
/*int		os9stat(const char *file, struct fildes *buff);*/
void	panic( const char *, const char *);
int		parent_id(void);
#ifndef _SIGNAL_H
/* declaration/function incompatible with signal.h! */
void	pause(void);
#endif
void	rest_pause(void);
void	printos9err(FILE *, int);
void	printtime(void);
int		raw_open(const char *, short);
int		smatch(const char *, const char *);
char 	*str_to_lower(char *, char *);
char 	*str_to_upper(char *, char *);
char	*strsave(const char *);
int 	system_devs(char **, int);
int 	system_mods(char **, int, short);
void	init_screen(void);
void	clear_screen(void);
void	clear_eol(int,int);
void	clear_to_eol(void);
void	move_cursor(int,int);
void	standout(int);
void	exit_screen(void);
/*int		topt(int, char**, char *, struct option *);*/
char 	*tstopt(int, char **, const char *, const char *);
void	illiopt(int, char **, const char *);
void	ofdump( FILE *, char *, char *, int, int);
#endif

#define TSTOPT(opt) 		tstopt(argc,argv,(opt),0)
#define TSTOPT_D(opt,dft)	tstopt(argc,argv,(opt),(dft))
#define CNTOPT				cntopt(argc,argv)
#define CNTARG				cntarg(argc,argv)
#define ILLIOPT(opts)		illiopt(argc,argv,(opts))

