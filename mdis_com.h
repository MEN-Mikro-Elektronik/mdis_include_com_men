/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mdis_com.h
 *
 *       Author: ds
 *
 *  Description: MDIS common driver definitions
 *
 *     Switches:
 *
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

#ifndef _MDIS_COM_H
#define _MDIS_COM_H

#ifdef __cplusplus
      extern "C" {
#endif

/*-----------------------------------------+
|  DEFINES                                 |
+------------------------------------------*/
/* m-module address modes */
#define MDIS_MA_NONE        0x0000
#define MDIS_MA08           0x0001
#define MDIS_MA24           0x0002
#define MDIS_MA_PCICFG      0x0100

/* chameleon address mode */
#define MDIS_MA_CHAMELEON   0x0200

/* special bbis info address mode */
#define MDIS_MA_BB_INFO_PTR 0x0400

/* flag to distinguish address modes which need 
   physical to virtual address mapping and which do not */
#define MDIS_MA_FLAG_NOMAP	0x0400

/* m-module data access modes */
#define MDIS_MD_NONE        0x0000
#define MDIS_MD08           0x0004
#define MDIS_MD16           0x0008
#define MDIS_MD32           0x0010

/* chameleon address space index */
#define MDIS_MD_CHAM_0      0x0000
#define MDIS_MD_CHAM_1      0x0001
#define MDIS_MD_CHAM_2      0x0002
#define MDIS_MD_CHAM_3      0x0003
#define MDIS_MD_CHAM_4      0x0004
#define MDIS_MD_CHAM_5      0x0005
#define MDIS_MD_CHAM_6      0x0006
#define MDIS_MD_CHAM_7      0x0007
#define MDIS_MD_CHAM_MAX    MDIS_MD_CHAM_7

/* max address spaces */
#define MDIS_MAX_MSPACE     8

/* ident call table size */
#define MDIS_MAX_IDCALLS 	16

#if defined(VXWORKS) &&  (_WRS_VXWORKS_MAJOR == 6) && (_WRS_VXWORKS_MINOR >=6)
# define VXW_PCI_DOMAIN_SUPPORT 
#endif


/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
/* ident call data struct */
typedef struct {
    char* (*identCall) (void);
} ID_CALL;

/* ident call table struct */
typedef struct {
    ID_CALL idCall[MDIS_MAX_IDCALLS];
} MDIS_IDENT_FUNCT_TBL;

/*-----------------------------------------+
|  GLOBALS                                 |
+------------------------------------------*/
/* none */

/*-----------------------------------------+
|  PROTOTYPES                              |
+------------------------------------------*/
/* none */

#ifdef __cplusplus
   }
#endif

#endif  /* _MDIS_COM_H  */


