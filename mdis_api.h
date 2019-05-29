/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mdis_api.h
 *
 *       Author: uf
 *        $Date: 2009/05/15 10:53:07 $
 *    $Revision: 1.22 $
 *
 *  Description: MDIS application interface definitions
 *
 *     Switches: __MAPILIB
 *
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 1997-2019, MEN Mikro Elektronik GmbH
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
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MDIS_API_H_
#define _MDIS_API_H_

#ifdef __cplusplus
      extern "C" {
#endif

/*---------------------------------------------------------------------------+
|    DEFINES                                                                 |
+---------------------------------------------------------------------------*/
/*----------------------------------------------+
|  general definitions                          |
+----------------------------------------------*/
#define M_MAX_NAME	32		/* max size of device and driver names [chars] */

/*----------------------------------------------+
|  MDIS status code offsets                     |
|                                               |
|  0x0000..0x0fff  :  prohibited area           |
|  0x1000..0x17ff  :  standard set/getstat      |
|  0x1800..0x1fff  :  (OS special purpose)      |
|  0x2000..0x2fff  :  block set/getstat         |
|  0x2800..0xffff  :  (OS special purpose)      |
+----------------------------------------------*/
/* general type offsets */
#define M_OFFS_STD      0x1000  /* standard codes */
#define M_OFFS_BLK      0x2000  /* block codes */

/* general sub offsets */
#define M_OFFS_MK       0x0000  /* LL common space               */
#define M_OFFS_LL       0x0100  /* LL common space               */
#define M_OFFS_DEV      0x0200  /* LL device space               */
#define M_OFFS_BB       0x0300  /* BBIS common space             */
#define M_OFFS_BRD      0x0400  /* BBIS board space              */
#define M_OFFS_SPEC     0x0800  /* OS special purpose space      */

/* standard code offsets */
#define M_MK_OF       M_OFFS_STD+M_OFFS_MK   /* MK           0x1000..0x10ff */
#define M_LL_OF       M_OFFS_STD+M_OFFS_LL   /* LL common    0x1100..0x11ff */
#define M_DEV_OF      M_OFFS_STD+M_OFFS_DEV  /* LL device    0x1200..0x12ff */
#define M_BB_OF       M_OFFS_STD+M_OFFS_BB   /* BBIS common  0x1300..0x13ff */
#define M_BRD_OF      M_OFFS_STD+M_OFFS_BRD  /* BBIS board   0x1400..0x14ff */

#define M_DEV_NOTEXIST M_DEV_OF+0xff /* LL device  	..0x12ff */
#define M_BRD_NOTEXIST M_BRD_OF+0xff /* BBIS board 	..0x14ff */

/* block code offsets */
#define M_MK_BLK_OF   M_OFFS_BLK+M_OFFS_MK   /* MK         	0x2000..0x20ff */
#define M_LL_BLK_OF   M_OFFS_BLK+M_OFFS_LL   /* LL common  	0x2100..0x21ff */
#define M_DEV_BLK_OF  M_OFFS_BLK+M_OFFS_DEV  /* LL device  	0x2200..0x22ff */
#define M_BB_BLK_OF   M_OFFS_BLK+M_OFFS_BB   /* BBIS common	0x2300..0x23ff */
#define M_BRD_BLK_OF  M_OFFS_BLK+M_OFFS_BRD  /* BBIS board 	0x2400..0x24ff */

#define M_DEV_BLK_NOTEXIST M_DEV_BLK_OF+0xff /* LL device  	..0x22ff */
#define M_BRD_BLK_NOTEXIST M_BRD_BLK_OF+0xff /* BBIS board 	..0x24ff */

/*----------------------------------------------+
|  MDIS status code definitions                 |
|  G=getstat, S=setstat allowed                 |
+----------------------------------------------*/
/* MK */
#define M_MK_NBR_ADDR_SPACE  M_MK_OF+0x01 /* G  : number of dev. addr spaces */
#define M_MK_CH_CURRENT      M_MK_OF+0x02 /* G,S: current channel            */
#define M_MK_CH_CURRENT_OLD  M_MK_OF+0x03 /* G,S: curr. chan.(MDIS3.x compat)*/
#define M_MK_IO_MODE         M_MK_OF+0x04 /* G,S: channel i/o mode           */
#define M_MK_IRQ_ENABLE      M_MK_OF+0x05 /* G,S: device interrupt enable    */
#define M_MK_IRQ_COUNT       M_MK_OF+0x06 /* G,S: global interrupt counter   */
#define M_MK_DEBUG_LEVEL     M_MK_OF+0x07 /* G,S: debug level of mdis kernel */
#define M_MK_API_DEBUG_LEVEL M_MK_OF+0x08 /* G,S: debug level of mdis api    */
#define M_MK_OSS_DEBUG_LEVEL M_MK_OF+0x09 /* G,S: debug level of OSS services*/
#define M_MK_LOCKMODE        M_MK_OF+0x0a /* G  : process lock mode          */
#define M_MK_PATHCNT         M_MK_OF+0x0b /* G  : opened pathes on device    */
#define M_MK_DEV_SLOT        M_MK_OF+0x0c /* G  : device slot at board       */
#define M_MK_DEV_ADDRMODE    M_MK_OF+0x0d /* G  : device addr mode flag(s)   */
#define M_MK_DEV_DATAMODE    M_MK_OF+0x0e /* G  : device data mode flag(s)   */
#define M_MK_BUSTYPE         M_MK_OF+0x0f /* G  : board bus system           */
#define M_MK_IRQ_INFO        M_MK_OF+0x10 /* G  : board irq capabilities     */
#define M_MK_IRQ_MODE        M_MK_OF+0x11 /* G  : board irq mode flag(s)     */
#define M_MK_IRQ_INSTALLED   M_MK_OF+0x12 /* G  : irq service installed      */
#define M_MK_TICKRATE        M_MK_OF+0x13 /* G  : system tickrate [tics/sec] */
#define M_MK_REV_SIZE        M_MK_OF+0x14 /* G  : revision string size       */
#define M_MK_NOTEXIST		 M_MK_OF+0xff /* G,S: (reserved for test)        */

/* MK block set/getstats */
#define M_MK_BLK_PHYSADDR    M_MK_BLK_OF+0x01 /* G  : phys addr and size    */
#define M_MK_BLK_VIRTADDR    M_MK_BLK_OF+0x02 /* G  : virt addr and size    */
#define M_MK_BLK_BB_HANDLER  M_MK_BLK_OF+0x03 /* G  : board handler name    */
#define M_MK_BLK_BRD_NAME    M_MK_BLK_OF+0x04 /* G  : board hardware name   */
#define M_MK_BLK_LL_HANDLER  M_MK_BLK_OF+0x05 /* G  : low level handler name*/
#define M_MK_BLK_DEV_NAME    M_MK_BLK_OF+0x06 /* G  : device name           */
#define M_MK_BLK_REV_ID      M_MK_BLK_OF+0x07 /* G  : revision string       */
#define M_MK_BLK_HW_NAME     M_MK_BLK_OF+0x08 /* G  : device hardware name  */
#define M_MK_BLK_NOTEXIST	 M_MK_BLK_OF+0xff /* G,S: (reserved for test)   */

/* LL common */
#define M_LL_CH_NUMBER     M_LL_OF+0x01 /* G  : number of device channels    */
#define M_LL_CH_DIR        M_LL_OF+0x02 /* G,S: device channel direction     */
#define M_LL_CH_LEN        M_LL_OF+0x03 /* G  : device channel length [bits] */
#define M_LL_CH_TYP        M_LL_OF+0x04 /* G  : device channel type          */
#define M_LL_IRQ_COUNT     M_LL_OF+0x05 /* G,S: device irq counter           */
#define M_LL_ID_CHECK      M_LL_OF+0x06 /* G  : device id-prom check enabled */
#define M_LL_DEBUG_LEVEL   M_LL_OF+0x07 /* G,S: dbg level of LL handler 	 */
#define M_LL_ID_SIZE       M_LL_OF+0x08 /* G  : device id-prom size [bytes]  */
#define M_LL_NOTEXIST	   M_LL_OF+0xff /* G,S: (reserved for test)        	 */

/* LL common MBUF RD */
#define M_RDBUF_OF           M_LL_OF+0x30
#define M_BUF_RD_MODE        M_RDBUF_OF+0x00 /* G,S: block i/o mode          */
#define M_BUF_RD_ERR         M_RDBUF_OF+0x01 /* G,S: overflow error enable   */
#define M_BUF_RD_SIGSET_HIGH M_RDBUF_OF+0x02 /* G,S: hiwater signal activate */
#define M_BUF_RD_SIGCLR_HIGH M_RDBUF_OF+0x03 /*   S: hiwater signal deactivte*/
#define M_BUF_RD_HIGHWATER   M_RDBUF_OF+0x04 /* G,S: highwater mark          */
#define M_BUF_RD_TIMEOUT     M_RDBUF_OF+0x05 /* G,S: read timeout            */
#define M_BUF_RD_BUFSIZE     M_RDBUF_OF+0x06 /* G  : input buffer size       */
#define M_BUF_RD_WIDTH       M_RDBUF_OF+0x07 /* G  : input buffer width      */
#define M_BUF_RD_COUNT       M_RDBUF_OF+0x08 /* G  : input buffer counter    */
#define M_BUF_RD_ERR_COUNT   M_RDBUF_OF+0x09 /* G,S: overflow error counter  */
#define M_BUF_RD_RESET       M_RDBUF_OF+0x0a /*   S: reset input buffer      */
#define M_BUF_RD_CLEAR       M_RDBUF_OF+0x0b /*   S: clear input buffer      */
#define M_BUF_RD_DEBUG_LEVEL M_RDBUF_OF+0x0c /* G,S: debug level of input buf*/
#define M_RDBUF_LAST         M_RDBUF_OF+0x1f /*    : (last valid code) */

/* LL common MBUF WR */
#define M_WRBUF_OF           M_LL_OF+0x50
#define M_BUF_WR_MODE        M_WRBUF_OF+0x00 /* G,S: block i/o mode         */
#define M_BUF_WR_ERR         M_WRBUF_OF+0x01 /* G,S: underrun error enable  */
#define M_BUF_WR_SIGSET_LOW  M_WRBUF_OF+0x02 /* G,S: lowater signal activate*/
#define M_BUF_WR_SIGCLR_LOW  M_WRBUF_OF+0x03 /*   S: lowater signal deactiv.*/
#define M_BUF_WR_LOWWATER    M_WRBUF_OF+0x04 /* G,S: lowwater mark          */
#define M_BUF_WR_TIMEOUT     M_WRBUF_OF+0x05 /* G,S: write timeout          */
#define M_BUF_WR_BUFSIZE     M_WRBUF_OF+0x06 /* G  : output buffer size     */
#define M_BUF_WR_WIDTH       M_WRBUF_OF+0x07 /* G  : output buffer width    */
#define M_BUF_WR_COUNT       M_WRBUF_OF+0x08 /* G  : output buffer counter  */
#define M_BUF_WR_ERR_COUNT   M_WRBUF_OF+0x09 /* G,S: underrun error counter */
#define M_BUF_WR_RESET       M_WRBUF_OF+0x0a /*   S: reset output buffer    */
#define M_BUF_WR_CLEAR       M_WRBUF_OF+0x0b /*   S: clear output buffer    */
#define M_BUF_WR_DEBUG_LEVEL M_WRBUF_OF+0x0c /* G,S: dbg level of output buf.*/
#define M_WRBUF_LAST         M_WRBUF_OF+0x1f /*    : (last valid code) */

/* LL common block set/getstats */
#define M_LL_BLK_ID_DATA     M_LL_BLK_OF+0x01 /* G  : read device id-prom  */
#define M_LL_BLK_CALLBACK  	 M_LL_BLK_OF+0x20 /* G,S: callback control */
#define M_LL_BLK_SHMEM_SET   M_LL_BLK_OF+0x31 /*   S: shared memory control */
#define M_LL_BLK_SHMEM_LINK  M_LL_BLK_OF+0x32 /*   S: shared memory control */
#define M_LL_BLK_SHMEM_CLEAR M_LL_BLK_OF+0x33 /*   S: shared memory control */
#define M_LL_BLK_NOTEXIST	 M_LL_BLK_OF+0xff /* G,S: (reserved for test) */

/* LL common MBUF RD block set/getstats */
#define M_RDBUF_BLK_OF     M_LL_BLK_OF+0x30
#define M_BUF_BLK_RD_DATA  M_RDBUF_BLK_OF+0x00 /* G  : input buffer data  */
#define M_RDBUF_BLK_LAST   M_RDBUF_BLK_OF+0x07 /*    : (last valid code) */

/* LL common MBUF WR block getstats */
#define M_WRBUF_BLK_OF     M_LL_BLK_OF+0x38
#define M_BUF_BLK_WR_DATA  M_WRBUF_BLK_OF+0x00 /* G  : output buffer data 	*/
#define M_WRBUF_BLK_LAST   M_WRBUF_BLK_OF+0x07 /*    : (last valid code) 	*/

/* BBIS common */
#define M_BB_IRQ_VECT      M_BB_OF+0x01 /* G  : device irq vector          	*/
#define M_BB_IRQ_LEVEL     M_BB_OF+0x02 /* G  : device irq level           	*/
#define M_BB_IRQ_PRIORITY  M_BB_OF+0x03 /* G  : device irq priotity        	*/
#define M_BB_IRQ_EXP_COUNT M_BB_OF+0x04 /* G,S: board exception irq counter */
#define M_BB_ID_CHECK      M_BB_OF+0x05 /* G  : board id-prom check enabled */
#define M_BB_DEBUG_LEVEL   M_BB_OF+0x06 /* G,S: debug level of board handler */
#define M_BB_ID_SIZE       M_BB_OF+0x07 /* G  : board id-prom size [bytes] */
#define M_BB_GET_SMBHDL    M_BB_OF+0x08 /* G  : get smb2 hdl (for SMB2 bbis */
#define M_BB_NOTEXIST	   M_BB_OF+0xff /* G,S: (reserved for test)        */

/* BBIS common block set/getstats */
#define M_BB_BLK_ID_DATA       M_BB_BLK_OF+0x01 /* G  : read board id-prom  */
#define M_BB_BLK_NOTEXIST	   M_BB_BLK_OF+0xff /* G,S: (reserved for test) */

/* useful macro: check if MBUF code */
#define M_BUF_CODE(code) \
	((((code) >= M_RDBUF_OF) && ((code) <= M_WRBUF_LAST))  || \
	 (((code) >= M_RDBUF_BLK_OF) && ((code) <= M_WRBUF_BLK_LAST)))

/*----------------------------------------------+
|  mode definitions                             |
+----------------------------------------------*/
/* i/o modes */
#define M_IO_EXEC             0     /* execute i/o */
#define M_IO_EXEC_INC         1     /* execute i/o with channel increment*/

/* block i/o mode */
#define M_BUF_USRCTRL        0    /* USER controlled buffer             */
#define M_BUF_CURRBUF        1    /* MDIS controlled current buffer     */
#define M_BUF_RINGBUF        2    /* MDIS controlled ring buffer        */
#define M_BUF_RINGBUF_OVERWR 3    /* MDIS controlled ring buffer overwrite */

/*----------------------------------------------+
|  type definitions                             |
+----------------------------------------------*/
/* channel direction */
#define M_CH_IN    0x01     /* input  */
#define M_CH_OUT   0x02     /* output */
#define M_CH_INOUT 0x03     /* i/o    */

/* channel type */
#define M_CH_UNKNOWN 0x00   /* unknown     */
#define M_CH_BINARY  0x01   /* binary      */
#define M_CH_ANALOG  0x02   /* analog      */
#define M_CH_SERIAL  0x03   /* serial      */
#define M_CH_COUNTER 0x04   /* counter     */

/*---------------------------------------------------------------------------+
|    TYPEDEFS                                                                |
+---------------------------------------------------------------------------*/

/** block status call structure */
typedef struct {
	int32 size;				/**< number of bytes to exchange with driver */
	void  *data;			/**< data block to exchange with driver */
} M_SG_BLOCK, M_SETGETSTAT_BLOCK;

/** block status call data structure for
   M_MK_BLK_PHYSADDR, M_MK_BLK_VIRTADDR */
typedef struct {
   u_int32 space;		/* in: addr space (index) */
   U_INT32_OR_64 addr;	/* out: start address */
   U_INT32_OR_64 size;	/* out: size of address space */
} M_ADDRSPACE;


typedef INT32_OR_64 MDIS_PATH;

/*---------------------------------------------------------------------------+
|    PROTOTYPES                                                              |
+---------------------------------------------------------------------------*/
#ifndef __MAPILIB
#	define __MAPILIB
#endif

extern MDIS_PATH __MAPILIB M_open(const char *device);
extern int32 __MAPILIB M_close(MDIS_PATH path);
extern int32 __MAPILIB M_getstat(MDIS_PATH path, int32 code, int32 *dataP);
extern int32 __MAPILIB M_setstat(MDIS_PATH path, int32 code, INT32_OR_64 data);
extern int32 __MAPILIB M_read(MDIS_PATH path, int32 *valueP);
extern int32 __MAPILIB M_write(MDIS_PATH path, int32 value);
extern int32 __MAPILIB M_getblock(MDIS_PATH path, u_int8 *buffer, int32 length);
extern int32 __MAPILIB M_setblock(MDIS_PATH path, const u_int8 *buffer, int32 length);
extern char* __MAPILIB M_errstring(int32 errCode);
extern char* __MAPILIB M_errstringTs(int32 errCode, char *strBuf);

/* Windows specific MDIS5 MDIS-API functions */
#ifdef WINNT
extern u_int32 __MAPILIB M_WinEnumDevices( u_int32 idx, char *devName );
#endif

#ifdef __cplusplus
   }
#endif

#endif /*_MDIS_API_H_*/


