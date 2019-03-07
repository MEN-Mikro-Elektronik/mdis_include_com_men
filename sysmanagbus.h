/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: sysmanagbus.h
 *
 *       Author: uf
 *        $Date: 2007/09/20 16:57:21 $
 *    $Revision: 2.18 $
 *
 *  Description: system managment bus routines interface
 *     Switches: SMB_COMPILE - for module compilation
 *				 MAC_IO_MAPPED - only valid for SMB_PORT_xxx
 *               MEN_EP02      - to provide additional routines for the EP02
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
#ifndef _SMB_H
#  define _SMB_H

#  ifdef __cplusplus
      extern "C" {
#  endif

/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
/* descriptor for the ALI1543 internal SMB controller */
typedef struct
{
	void       *baseAddr;
}SMB_DESC_ALI1543;


/* descriptor for the ICH internal SMB controller */
typedef struct
{
	void       *baseAddr;
}SMB_DESC_ICH;

/* descriptor for the PORT emulated SMB controller */
typedef struct
{
	u_int8     busClock;    /* 0  -   max - no internal delay
							 * 1  -  1kHz - OSS_Delay() call
							 * 10 - 10kHz - OSS_MikroDelay() call
							 */

	void       *addrDataIn;
	u_int8     flagsDataIn; /* access size, polarity */
	u_int32    maskDataIn;

	void       *addrDataOut;
	u_int8     flagsDataOut; /* access size, polarity, readable register */
	u_int32    maskDataOut;
	u_int32    notReadBackDefaultsDataOut;
	u_int32    notReadBackMaskDataOut;

	void       *addrClockIn;
	u_int8     flagsClockIn; /* access size, polarity */
	u_int32    maskClockIn;

	void       *addrClockOut;
	u_int8     flagsClockOut; /* access size, polarity, readable register */
	u_int32    maskClockOut;
	u_int32    notReadBackDefaultsClockOut;
	u_int32    notReadBackMaskClockOut;
}SMB_DESC_PORT;

/* descriptor for the MGT5100 internal I2C controller */
typedef struct
{
	void	   *i2cBase;		   /* base address of MGT5100 I2C controller */
	u_int32    divReg;    		   /* see MGT5100 UM, Frequency divider reg. */
	u_int32    dbgLevel;		   /* see dbg.h */
	u_int32	   timeOut;			   /* ms - 20 is a good value */
	u_int32	   mikroDelay;		   /* default 0 - OSS_Delay, 1 - OSS_MikroDelay */
}SMB_DESC_MGT5100;

/* descriptor for the MGT5200 internal I2C controller */
typedef struct
{
	void	   *i2cBase;		   /* base address of MGT5200 I2C controller */
	u_int32    divReg;    		   /* see MGT5200 UM, Frequency divider reg. */
	u_int32    dbgLevel;		   /* see dbg.h */
	u_int32	   timeOut;			   /* ms - 20 is a good value */
	u_int32	   mikroDelay;		   /* default 0 - OSS_Delay, 1 - OSS_MikroDelay */
	u_int32    filterReg;    	   /* see MPC5200 UM, digital filter sampling reg. */
}SMB_DESC_MGT5200;

/* descriptor for the MGT5200 internal I2C controller */
typedef struct
{
	void	   *i2cBase;		   /* base address of MGT5200 I2C controller */
	u_int32    sclFreq;			/**< SCL frequency [kHz](37/55/74/111/149/223)*/
	u_int32    dbgLevel;		   /* see dbg.h */
	u_int32	   timeOut;			   /* ms - 20 is a good value */
	u_int32	   mikroDelay;		   /* default 0 - OSS_Delay, 1 - OSS_MikroDelay */

}SMB_DESC_MENZ001;


/*
 * descriptor for the MPC85XX internal I2C controller, to be passed
 * to SMB_MPC85XX_Init
 */
typedef struct
{
	void	   *i2cBase;		   /* base address of MPC85XX I2C controller */
	u_int32    divReg;    		   /* see MPC85XX UM, Frequency divider reg. */
	u_int32    filterReg;    	   /* see MPC85XX UM, digital filter sampling reg. */
	u_int32    dbgLevel;		   /* see dbg.h */
	u_int32	   timeOut;			   /* ms - 20 is a good value */
	u_int32	   mikroDelay;		   /* default 0 - OSS_Delay, 1 - OSS_MikroDelay */
}SMB_DESC_MPC85XX;


/* descriptor for the MPC8240 internal SMB controller */
typedef struct
{
	u_int8     busClockDivider;    /* 0x00..0x3f => see doc. table - e.g. 3F=32768 100MHz/32768= 3kHz */

	u_int32	   pollTimeUs;		   /* 0..100  -   OSS_MikroDelay() call
							 		* >100 OSS_Delay(pollTimeUs/1000) call
							 		*/
	u_int32    dbgLevel;		   /* see dbg.h */
	void       *baseAddr;		   /* see MPC8240 documentation EUMB base address + 0x3000 */
}SMB_DESC_MPC8240;

/* descriptor for the PORT emulated SMB controller using callbacks */
typedef struct
{
	u_int8     busClock;    /* 0  -   max - no internal delay
							 * 1  -  1kHz - OSS_Delay() call
							 * 10 - 10kHz - OSS_MikroDelay() call
							 */
	void	   *cbArg;	    /* argument that is passed to callbacks */
	int 	   (*sclIn)(void *);			/* read SCL pin */
	int		   (*sclSet)(void *, int val);	/* set/verify SCL */
	int		   (*sdaIn)(void *); 			/* read SDA pin */
	int		   (*sdaSet)(void *, int val);	/* set/verify SDA */

} SMB_DESC_PORTCB;


typedef struct
{
    char* (*Ident)       ( void );
    int32 (*Exit)        ( void **smbHdlP );
    int32 (*WriteByte)   ( void *smbHdl, u_int8 addr, u_int8 data );
    int32 (*ReadByte)    ( void *smbHdl, u_int8 addr, u_int8 *dataP );
    int32 (*WriteTwoByte)( void *smbHdl, u_int8 addr, u_int8 cmdAddr, u_int8 data );
    int32 (*WriteReadTwoByte)( void *smbHdl, u_int8 addr, u_int8 cmdAddr, u_int8 *data1P, u_int8 *data2P );
#ifdef MEN_EP02
    int32 (*ReadAddrByte)( void *smbHdl, u_int8 addr, u_int8 byteAddrH, u_int8 byteAddrL, u_int8 *dataP );
    int32 (*WriteAddrByte)( void *smbHdl, u_int8 smbaddr, u_int16 addr, u_int8 data );
    int32 (*WritePageByte)( void *smbHdl, u_int8 smbaddr, u_int16 addr, unsigned int n, u_int8 *dataP );
#endif /*MEN_EP02*/
}SMB_ENTRIES;

#ifndef SMB_COMPILE
	typedef SMB_ENTRIES SMB_HANDLE;
#endif /*SMB_COMPILE*/

/*-----------------------------------------+
|  DEFINES & CONST                         |
+------------------------------------------*/
#define SMB_ERR_NO           		0
#define SMB_ERR_DESCRIPTOR   		1
#define SMB_ERR_NO_MEM       		2
#define SMB_ERR_ADDR    	 		3
#define SMB_ERR_BUSY    	 		4
#define SMB_ERR_COLL    	 		5
#define SMB_ERR_NO_DEVICE	 		6
#define SMB_ERR_PARAM		 		7

#define SMB_DESC_PORT_FLAG_SIZE_MASK		0x07
#define SMB_DESC_PORT_FLAG_SIZE_8			0x01
#define SMB_DESC_PORT_FLAG_SIZE_16			0x02
#define SMB_DESC_PORT_FLAG_SIZE_32			0x04

#define SMB_DESC_PORT_FLAG_POLARITY_HIGH	0x10
#define SMB_DESC_PORT_FLAG_READABLE_REG		0x20

/*-----------------------------------------+
|  GLOBALS                                 |
+------------------------------------------*/
/*-----------------------------------------+
|  PROTOTYPES                              |
+------------------------------------------*/
u_int32 SMB_ALI1543_Init( SMB_DESC_ALI1543 *descP, OSS_HANDLE *osHdl, void **smbHdlP );

u_int32 SMB_ICH_Init( SMB_DESC_ICH *descP, OSS_HANDLE *osHdl, void **smbHdlP );

#ifdef MAC_IO_MAPPED
u_int32 SMB_PORT_IO_Init(    SMB_DESC_PORT    *descP, OSS_HANDLE *osHdl, void **smbHdlP );
#else
u_int32 SMB_PORT_Init(    SMB_DESC_PORT    *descP, OSS_HANDLE *osHdl, void **smbHdlP );
#endif

u_int32 SMB_PORTCB_Init(  SMB_DESC_PORTCB    *descP, OSS_HANDLE *osHdl, void **smbHdlP );
u_int32 SMB_PORTCB_HandleSize(void);

u_int32 SMB_MPC8240_Init( SMB_DESC_MPC8240 *descP, OSS_HANDLE *osHdl, void **smbHdlP );

u_int32 SMB_MGT5100_Init( SMB_DESC_MGT5100 *desc, OSS_HANDLE *osHdl, void **smbHdlP );
u_int32 SMB_MGT5100_HandleSize(void);

u_int32 SMB_MGT5200_Init( SMB_DESC_MGT5200 *desc, OSS_HANDLE *osHdl, void **smbHdlP );
u_int32 SMB_MGT5200_HandleSize(void);

u_int32 SMB_16Z001_Init( SMB_DESC_MENZ001 *desc, OSS_HANDLE *osHdl, void **smbHdlP );

/* exported by sysmanagbus_mgt5200.c: */
u_int32 SMB_MPC85XX_Init( SMB_DESC_MPC85XX *desc, OSS_HANDLE *osHdl, void **smbHdlP);
u_int32 SMB_MPC85XX_HandleSize(void);


#  ifdef __cplusplus
      }
#  endif

#endif/*_SMB_H*/






