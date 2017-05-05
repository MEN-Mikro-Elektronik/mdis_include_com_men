/***********************  I n c l u d e  -  F i l e  ************************/
/*!  
 *        \file  mipios.h
 *
 *      \author  men
 *        $Date: 2009/01/30 09:23:59 $
 *    $Revision: 3.1 $
 * 
 *  	 \brief  MIPIOS - MEN Internet Protocol Input Output System
 *               MIPIOS delivers the IP coupled I/O for MDIS.
 *               Finally local I/O and IP coupled I/O will be accessed
 *               via MDIS API.
 *                      
 *     Switches: -
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: mipios.h,v $
 * Revision 3.1  2009/01/30 09:23:59  ufranke
 * checkin at project freeze
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2008-2009 by MEN Mikro Elektronik GmbH, Nueremberg, Germany 
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef _MIPIOS_H
#define _MIPIOS_H

#ifdef __cplusplus
	extern "C" {
#endif

/* states */
#define MIPIOS_STATE_CONFIGURATION		1
#define MIPIOS_STATE_OPERATIONAL		2
#define MIPIOS_STATE_STOP				3


/* guarding modes */
#define MIPIOS_GUARDING_MODE_SYSTEM		1
#define MIPIOS_GUARDING_MODE_LINE		2
#define MIPIOS_GUARDING_MODE_NODE		3

#define MIPIOS_GUARDING_TIMEOUT_DEFAULT_MS		5000  /* 5000ms */
#define MIPIOS_SIGNAL_POLL_TIMEOUT_DEFAULT_MS	  10  /*   10ms */

/* connect modes */
#define MIPIOS_HOST_FIX_CONNECT							1
#define MIPIOS_HOST_AUTO_CONNECT						2  /* default for each line */
#define MIPIOS_TARGET_AUTO_CONNECT						3
#define MIPIOS_HOST_MULTICAST_TARGET_AUTO_CONNECT		4

/* default ports */
#define MIPIOS_TARGET_RX_PORT_DEFAULT		52317
#define MIPIOS_HOST_RX_PORT_DEFAULT			62317

/* some usefull defines  */
#define MIPIOS_IP_TYPE_V4			0x04
#define MIPIOS_IP_TYPE_V6			0x06  /* prepared but not implemented */

/* device link states */
#define MIPIOS_LINK_QUIET			0
#define MIPIOS_LINK_CONNECT			1
#define MIPIOS_LINK_ESTABLISHED		2


#define MIPIOS_MAX_LINE_NAME			50
#define MIPIOS_MAX_DEV_NAME				40  	/* must matches OS2M_MaxDevName for VxWorks - do not touch */
#define MIPIOS_MAX_DATA_SIZE  			1000	/* + MIPIOS header less than MTU: so we should be able to transmit a MIPIOS frame in one ethernet frame */

#define MIPIOS_DATA_SIZE_0					0		/* fix size for command */
#define MIPIOS_DATA_SIZE_1					1		/* fix size for command */
#define MIPIOS_DATA_SIZE_2					2		/* fix size for command */
#define MIPIOS_DATA_SIZE_4					4		/* fix size for command */
#define MIPIOS_DATA_SIZE_8					8		/* fix size for command */
#define MIPIOS_DATA_SIZE_12					12		/* fix size for command */
#define MIPIOS_DATA_SIZE_16					16		/* fix size for command */
#define MIPIOS_DATA_SIZE_NOT_FIX			0x7FFF  /* size is not fix for this command can be 0..MIPIOS_MAX_DATA_SIZE */
#define MIPIOS_DATA_SIZE_NOT_FIX_GTZERO		0x6FFF  /* size is not fix for this command can be 1..MIPIOS_MAX_DATA_SIZE */
#define MIPIOS_DATA_SIZE_ILLEGAL			0xFFFF  /* illegal data size */


#ifndef MIPIOS_MAX_LINES
	#define MIPIOS_MAX_LINES			5	/* how much MIPIOS lines */
#endif

#ifndef MIPIOS_MAX_DEVS_PER_LINE
	#define MIPIOS_MAX_DEVS_PER_LINE	10  /* how much MIPIOS devices per line */
#endif

#ifndef MIPIOS_MAX_DEVS
	#define MIPIOS_MAX_DEVS				50  /* how much MIPIOS devices */
#endif

#ifndef MIPIOS_NUM_FILES
	#define MIPIOS_NUM_FILES			100	/* how much open files/pathes */
#endif


typedef struct
{
    u_int32  crc32;       	/* over link nbr ... data[end] */
    u_int32  linkNumber;   	/* link number for a host/target connection, counting up for a new link */
    u_int32  devFrameNbr; 	/* frame number per device      */
    u_int8   retryCnt;    	/* 0..2 */
    u_int8   type;			/* frame type */
    u_int8   command;		/* command */
    u_int8   signalCnt;   	/* current signal + signals in target queue */
    u_int32  singleSignal;	/* current signal */
    int32	 returnCode;	/* 0 or error code */
    u_int32  errorNo;		/* target errno */
    u_int16  dataSize;		/* number of bytes in frame data field */
    u_int8   magic; 		/* MIPIOS magic */
    u_int8   version; 		/* MIPIOS protocolversion */
    u_int32  resv1;
}MIPIOS_FRAME_HEADER;


typedef struct
{
	MIPIOS_FRAME_HEADER hdr;
	u_int8				data[MIPIOS_MAX_DATA_SIZE];
}MIPIOS_FRAME;

#define MIPIOS_MAX_FRAME_SIZE  (sizeof(MIPIOS_FRAME))

/* TYPE */
#define MIPIOS_TYPE_RESPONSE_REQ_MASK			0x80	/* the sender expects a response from receiver */
#define MIPIOS_TYPE_ACKNOWLEDGE_DELAYED_MASK	0x40
#define MIPIOS_TYPE_DEV_NAME					0x01
#define MIPIOS_TYPE_CONFIGURATION				0x02
#define MIPIOS_TYPE_GUARDING					0x03
#define MIPIOS_TYPE_DATA						0x10
#define MIPIOS_TYPE_DATA_FRAG_BEGIN				0x11
#define MIPIOS_TYPE_DATA_FRAG_END				0x12
#define MIPIOS_TYPE_DATA_FRAG_RX				0x13
#define MIPIOS_TYPE_DATA_FRAG_RX_END			0x14

/* COMMAND */
#define MIPIOS_CMD_REQUEST_DEV_NAME		0x01	/* MIPIOS_TYPE_DEV_NAME */
#define MIPIOS_CMD_ANNOUNCE_DEV_NAME	0x02	/* MIPIOS_TYPE_DEV_NAME 			this is the only one initiated by target */

#define MIPIOS_CMD_ESTABLISH_LINK		0x03	/* MIPIOS_TYPE_CONFIGURATION */


#define MIPIOS_CMD_DISCONNECT			0x04	/* MIPIOS_TYPE_CONFIGURATION */
#define MIPIOS_CMD_OPERATIONAL			0x05	/* MIPIOS_TYPE_CONFIGURATION */
#define MIPIOS_CMD_STOP					0x06	/* MIPIOS_TYPE_CONFIGURATION */


#define MIPIOS_CMD_GUARDING				0x10	/* MIPIOS_TYPE_GUARDING */
#define MIPIOS_CMD_SIGNAL_POLL			0x11
#define MIPIOS_CMD_DBG_GET    			0x12
#define MIPIOS_CMD_DBG_GET_NEXT			0x13

#define MIPIOS_CMD_POST_GET    				0x14
#define MIPIOS_CMD_RESET_CAUSE_GET    		0x15
#define MIPIOS_CMD_RESET_CAUSE_COUNT_GET	0x16

#define MIPIOS_CMD_SET_LL_DESC					0x20	/* MIPIOS_TYPE_DATA */
#define MIPIOS_CMD_M_OPEN						0x21	/* MIPIOS_TYPE_DATA */
#define MIPIOS_CMD_M_READ						0x22	/* MIPIOS_TYPE_DATA */
#define MIPIOS_CMD_M_WRITE						0x23	/* MIPIOS_TYPE_DATA */

#define MIPIOS_CMD_M_SETSTAT					0x24	/* MIPIOS_TYPE_DATA */
#define MIPIOS_CMD_M_SETSTAT_SIG_INSTALLED		0x25	/* MIPIOS_TYPE_DATA - special answer of setstat */
#define MIPIOS_CMD_M_SETSTAT_SIG_REMOVED		0x26	/* MIPIOS_TYPE_DATA - special answer of setstat  */
#define MIPIOS_CMD_M_SETSTAT_BLK				0x27	/* MIPIOS_TYPE_DATA _FRAG_BEGIN _FRAG_END*/

#define MIPIOS_CMD_M_GETSTAT					0x28	/* MIPIOS_TYPE_DATA */
#define MIPIOS_CMD_M_GETSTAT_BLK				0x29	/* MIPIOS_TYPE_DATA _FRAG_BEGIN _FRAG_END*/

#define MIPIOS_CMD_M_SET_BLK					0x2a	/* MIPIOS_TYPE_DATA _FRAG_BEGIN _FRAG_END*/
#define MIPIOS_CMD_M_GET_BLK					0x2b	/* MIPIOS_TYPE_DATA _FRAG_BEGIN _FRAG_END*/
#define MIPIOS_CMD_M_CLOSE						0x2c	/* MIPIOS_TYPE_DATA */

#define MIPIOS_MAGIC					0xC5
#define MIPIOS_VERSION_1				0x01


#define MIPIOS_CRC32_INITAL				0xabcdef07

#define MIPIOS_HOST_IS_LITTLE_ENDIAN	0x00
#define MIPIOS_HOST_IS_BIG_ENDIAN		0x01


/* data structure of special commands */
typedef struct
{
	u_int8 ipType;     /* MIPIOS_IP_TYPE_V4 - IPV4 implemented only */
	char   ipAddr[16]; /* from LSB [0] ... [15] MSB - enough space for IPV6 extenstion */
	char   port[2];	   /* from LSB [0] ... [1] MSB */
}MIPIOS_IP_PORT_DATA;

typedef struct
{
	MIPIOS_IP_PORT_DATA ipPort;
	char				devName[MIPIOS_MAX_DEV_NAME];	/* dev name including ending 0 */
}MIPIOS_CMD_ANNOUNCE_DEV_NAME_STRUCT;





#endif /*_MIPIOS_H*/ 
