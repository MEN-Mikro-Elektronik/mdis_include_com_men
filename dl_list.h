/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: dl_list.h
 *
 *      Author: kp 
 * 
 *  Description: Include when using the double linked list functions
 *               of the uti.l library       
 *     Switches: 
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1994-2019, MEN Mikro Elektronik GmbH
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

typedef struct node {
	struct node *next;
	struct node *prev;
} node;

typedef struct list {
	struct node *head;
	struct node *tail;
	struct node *tailpred;
} list;

extern list *dl_newlist();
extern node *dl_remove(), *dl_remhead(), *dl_addtail();


