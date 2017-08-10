/***********************  I n c l u d e  -  F i l e  ************************
 *  
 *         Name: dl_list.h
 *
 *      $Author: kp $
 *        $Date: 1994/04/22 11:42:43 $
 *    $Revision: 1.1 $
 * 
 *  Description: Include when using the double linked list functions
 *               of the uti.l library       
 *     Switches: 
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: dl_list.h,v $
 * Revision 1.1  1994/04/22 11:42:43  kp
 * Initial revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1994 by MEN mikro elektronik GmbH, Nuernberg, Germany 
 ****************************************************************************/

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


