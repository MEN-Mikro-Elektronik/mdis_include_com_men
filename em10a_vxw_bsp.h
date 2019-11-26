/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: em10a_vxw.h
 *
 *       Author: ts
 *
 *  Description: globally visible Prototypes for EM10A VxWorks BSP 
 *     Switches: -
 *
 *---------------------------------------------------------------------------
 * Copyright 2005-2019, MEN Mikro Elektronik GmbH
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

#ifndef	_SYSLIB_MEN_H
#define	_SYSLIB_MEN_H

#ifdef __cplusplus
	extern "C" {
#endif

/* sysLib.c */
extern void 	sysIdent( void );
extern u_int32 	sysMbarAddrGet( void );

extern void 	sysLedUser( int on );
extern void 	sysLedError( int on );
extern void 	sysPciIrqFixup( int bus );

extern int 		sysSwitchGet( void );
extern int 		sysMvbAddrGet( void );
extern int 		sysCanBaudGet( void );
extern void 	sysPrepareMpc5200Mscan( void );

extern int	  	sysClkIpb;


/* sysSmb.c */
extern STATUS 	sysSmbInit( void );
extern int32 	sysSmbWriteByte( u_int8 smbNum, u_int8 smbAddr, u_int8 data );
extern int32 	sysSmbWriteTwoByte( u_int8 smbNum, u_int8 smbAddr, u_int8 data1,
									u_int8 data2);
extern int32 	sysSmbReadByte( u_int8 smbNum, u_int8 smbAddr, u_int8 *dataP );
extern int32 	sysSmbWriteReadTwoByte( u_int8 smbNum, u_int8 smbAddr,
										u_int8 inData,
										u_int8 *outData1P, u_int8 *outData2P);

/* sysChameleon.c */
STATUS 	sysChameleonInit( void );
STATUS 	sysChameleonTerm( void );
int32 	sysChameleonGlobalIdent(char *variantP, int *revisionP );
int32 	sysChameleonTableIdent( CHAMELEONV2_TABLE *chamTable,	u_int32 buffSize );

int 	sysChameleonIntNumForUnitIrq( int unitIrq );
int 	sysChameleonIntDisable( u_int32 intvec );
int 	sysChameleonIntEnable( u_int32 intvec );

int32 	sysChameleonV2UnitFind(  CHAMELEONV2_FIND find,
								 int idx,
								 CHAMELEONV2_UNIT *unit );

int32 	sysChameleonV2UnitIdent( int idx, CHAMELEONV2_UNIT *unit );
int32 	sysChameleonV2Info( CHAMELEONV2_INFO *info );
void 	sysChameleonShow( void );

/* Processor and CPU Version */
int 	sysGetSvr(void);
int 	sysGetPvr(void);

/* Memon Version */
int sysGetMmVersion(
	int mm, 			/* 0 for secondary, 1 for primary MenMon */
	char* verStr		/* version string buffer,
						   should be at least 0x80 bytes long */
);

/* LM81 */
int sysGetTemp( void );
int sysGetVoltage( int which );

/* LEDs on carrier board */
void sysLedUser( int on );
void sysHBLSpawn( void );

/* FPGA PLL error supervision when available in FPGA */
int sysGetPllError( void ); /* returns 0: OK; 1: FPGA PLL lock lost */

#ifdef __cplusplus
	}
#endif

#endif /* _SYSLIB_MEN_H */
