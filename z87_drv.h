/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  Z87_drv.h
 *
 *      \author  gvarlet
 *        $Date: 2009/12/10 11:09:00 $
 *    $Revision: 3.2 $
 *
 *  	 \brief  header file for 16Z087_ETH IP cores
 * 				 register defines.
 *
 *     Switches: -
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: z87_drv.h,v $
 * Revision 3.2  2009/12/10 11:09:00  gvarlet
 * R: 1. Support for MM1 I2C bus missing
 *    2. Support for 16Z087_ETH rev. 7 register missing
 *    3. Definition for all 16Z087_ETH interrupts missing.
 *    4. Definitions for outdated 16Z077_ETH
 *    5. OS specific definitions for PHY manipulation.
 * M: 1. Add macro for accessing the 16Z087_ETH I2C bus.
 *    2. Add register definition for 16Z087_ETH rev 7.
 *    3. Add OETH_INT_ALL definition for all OETH_INT_ALL interrupts.
 *    4. Remove outdate definition for 16Z077_ETH
 *    5. Remove OS specific definitions.
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2004 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 *
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

#ifndef _Z87_DRV_H_
#define _Z87_DRV_H_

/**
 * @defgroup _Z087BASES Important basic defines for following Macros
 * These defines are used in all further Macros.
 * The base Address (IP core physical start) is retrieved from
 * the found FPGA IP core 16Z087 through the men_chameleon driver.
 */
/*@{*/
#define Z87_ETHBUF_SIZE		0x1000	/*!< complete size for 1 BD, PAGESZ aligned */
#define Z87_CFGREG_SIZE		0x800	/*!< all from MODER to last Rx BD */
#define MY_TX_TIMEOUT		(5*HZ)  /*!< 5 seconds TX wait timeout */
#define Z087_REG_BASE		(0)	 	/*!< Mode control */
/*@}*/

/* 16P511 specific */
#define Z087_P511_EEPROM_SIZE       256
#define Z087_P511_EEPROM_ADDR       0xAE
#define Z087_P511_SMB_FLAGS         0
#define Z087_P511_SMB_FREQ			149
#define Z087_P511_M24C02_WAIT_MAX   10  /* Twr max in ms*/
#define Z087_P511_NAME              "P511"

/* 15MM01 specific */
#define Z87_I2C_CLK				(1<<0x0)	/* Z87 I2C  register clock mask */
#define Z87_I2C_DATA			(1<<0x1)	/* Z87 I2C  register data mask */

#define Z87_SET_EEPROM_CLK		Z87WRITE_D32( \
									Z087_BASE, \
									Z087_REG_I2C, \
									Z87READ_D32(Z087_BASE, Z087_REG_I2C) \
									| Z87_I2C_CLK )
#define Z87_RESET_EEPROM_CLK	Z87WRITE_D32( \
									Z087_BASE, \
									Z087_REG_I2C, \
									Z87READ_D32(Z087_BASE, Z087_REG_I2C) \
									& ~Z87_I2C_CLK )
#define Z87_GET_EEPROM_CLK		(Z87READ_D32(Z087_BASE, Z087_REG_I2C) & \
									Z87_I2C_CLK)

#define Z87_SET_EEPROM_DATA		Z87WRITE_D32( \
									Z087_BASE, \
									Z087_REG_I2C, \
									Z87READ_D32(Z087_BASE, Z087_REG_I2C) \
									| Z87_I2C_DATA )
#define Z87_RESET_EEPROM_DATA	Z87WRITE_D32( \
									Z087_BASE, \
									Z087_REG_I2C, \
									Z87READ_D32(Z087_BASE, Z087_REG_I2C) \
									& ~Z87_I2C_DATA )
#define Z87_GET_EEPROM_DATA		(Z87READ_D32(Z087_BASE, Z087_REG_I2C) & \
									Z87_I2C_DATA)

#define Z087_MM1_I2C_BUS_FREQ	100
#define Z087_MM1_EEPROM_ADDR	0xA0

/**
 * @defgroup _Z087_REGISTERS 16Z087 Registers
 *
 *@{*/
#define Z087_REG_MODER		(Z087_REG_BASE+0x00) /*!< Mode control */
#define Z087_REG_INT_SRC	(Z087_REG_BASE+0x04) /*!< IRQ source */
#define Z087_REG_INT_MASK	(Z087_REG_BASE+0x08) /*!< IRQ Masking 	*/
#define Z087_REG_IPGT		(Z087_REG_BASE+0x0c) /*!< InterPacket Gap */
#define Z087_REG_IPGR1		(Z087_REG_BASE+0x10) /*!< No InterPacket Gap	*/
#define Z087_REG_IPGR2		(Z087_REG_BASE+0x14) /*!< No InterPacket Gap2	*/
#define Z087_REG_PACKLEN	(Z087_REG_BASE+0x18) /*!< Packet Len (min/max)*/
#define Z087_REG_COLLCONF	(Z087_REG_BASE+0x1c) /*!< Collision/Retry Conf. */
#define Z087_REG_TX_BDNUM	(Z087_REG_BASE+0x20) /*!< Number of TX BDs */
#define Z087_REG_CTRLMODER	(Z087_REG_BASE+0x24) /*!< Control Module Mode */
#define Z087_REG_MIIMODER	(Z087_REG_BASE+0x28) /*!< MII Mode Register	*/
#define Z087_REG_MIICMD		(Z087_REG_BASE+0x2c) /*!< MII command	*/
#define Z087_REG_MIIADR		(Z087_REG_BASE+0x30) /*!< MII Address 	*/
#define Z087_REG_MIITX_DATA (Z087_REG_BASE+0x34) /*!< MII Transmit Data	*/
#define Z087_REG_MIIRX_DATA (Z087_REG_BASE+0x38) /*!< MII Receive Data	*/
#define Z087_REG_MIISTATUS  (Z087_REG_BASE+0x3c) /*!< MII Status 		*/
#define Z087_REG_MAC_ADDR0 	(Z087_REG_BASE+0x40) /*!< MAC Addr[0-3]	*/
#define Z087_REG_MAC_ADDR1  (Z087_REG_BASE+0x44) /*!< MAC Addr[4-5]	*/
#define Z087_REG_HASH_ADDR0 (Z087_REG_BASE+0x48) /*!< Hash Reg 0 */
#define Z087_REG_HASH_ADDR1 (Z087_REG_BASE+0x4c) /*!< Hash Reg 1	*/
#define Z087_REG_TXCTRL    	(Z087_REG_BASE+0x50) /*!< TX control  */
/*@}*/

/**
 * @defgroup _Z087_NEWREGS 16Z087 (MEN) specific Registers
 */
/*@{*/
#define Z087_REG_GLOBALRST 	(Z087_REG_BASE+0x54) /*!< global MAC core reset */
#define Z087_REG_BDSTART 	(Z087_REG_BASE+0x5c) /*!< Startaddr of TxRx BDs	*/
#define Z087_REG_RXEMPTY0 	(Z087_REG_BASE+0x60) /*!< RxBD[31:0] empty Flag	*/
#define Z087_REG_RXEMPTY1 	(Z087_REG_BASE+0x64) /*!< RxBD[63:32]empty Flag	*/
#define Z087_REG_TXEMPTY0 	(Z087_REG_BASE+0x68) /*!< TxBD[31:0] empty Flag	*/
#define Z087_REG_TXEMPTY1 	(Z087_REG_BASE+0x6c) /*!< TxBD[63:32]empty Flag	*/
#define Z087_REG_BD_STATUS	(Z087_REG_BASE+0x70) /*!< BD satus flag			*/
#define Z087_REG_I2C		(Z087_REG_BASE+0x74) /*!< I2C interface reg		*/
#define Z087_REG_REVSION	(Z087_REG_BASE+0x78) /*!< IP core revision		*/
/*@}*/

/**
 * @defgroup _MACRO1 Macros acting on the Rx/Tx Descriptors
 * \verbatim
   Macros to manipulate Rx- and Tx BD Entries

   These provide HW-Independent ways to set/get Address entries and Flag
   settings. Detailled Explanation for Macro construction below:

   New Core: BDs reside in RAM, Address must be 10bit-aligned

   Z087_BDBASE  = pDrvCtrl->bdBase;
   Z087_BD_OFFS = 0

   +--------------+
   |              |
   |--------------|- Tx BD Start
   |              |
   +--------------+- Rx Bd  Start (= Z087_BDBASE + Z087_BD_OFFS )

   \endverbatim
 */
/*@{*/
#define Z087_SET_TBD_ADDR(n,adr) \
		Z87WRITE_D32(Z087_BDBASE, \
        Z087_BD_OFFS+(((n)+TBD_OFF) * Z087_BDSIZE) + Z087_BD_OFFS_ADR, (adr))
/*!< set Tx BD Address for Tx BD nr. (n) */

#define Z087_SET_RBD_ADDR(n,adr) \
		Z87WRITE_D32(Z087_BDBASE, \
        Z087_BD_OFFS+( ((n)+RBD_OFF) * Z087_BDSIZE)+ Z087_BD_OFFS_ADR, adr)
/*!< set Rx BD Address for Rx BD nr. (n) */

#define Z087_GET_RBD_ADDR(n) \
		Z87READ_D32(Z087_BDBASE, Z087_BD_OFFS + \
        ( ((n)+RBD_OFF) * Z087_BDSIZE) + Z087_BD_OFFS_ADR)
/*!< get Rx BD Address for Rx BD nr. (n) */

#define Z087_GET_TBD_ADDR(n) \
		Z87READ_D32(Z087_BDBASE, Z087_BD_OFFS + \
        ( ((n)+TBD_OFF) * Z087_BDSIZE)+Z087_BD_OFFS_ADR)
/*!< get Tx BD Address of ETH Frame of Tx BD nr. (n) */

#define Z087_SET_TBD_FLAG(n,f) \
		Z87WRITE_D16(Z087_BDBASE, Z087_BD_OFFS+( ((n)+TBD_OFF)*Z087_BDSIZE), \
        Z87READ_D16( Z087_BDBASE, Z087_BD_OFFS+( ((n)+TBD_OFF)*Z087_BDSIZE))| \
        (f) )
/*!< set flag f of Tx BD nr. (n) */

#define Z087_SET_RBD_FLAG(n,f) \
	    Z87WRITE_D16(Z087_BDBASE, Z087_BD_OFFS + ((n)+RBD_OFF) * Z087_BDSIZE,\
        Z87READ_D16( Z087_BDBASE, Z087_BD_OFFS + ((n)+RBD_OFF) * Z087_BDSIZE)|\
        (f) )
/*!< set flag f of Rx BD nr. (n) */

#define Z087_CLR_TBD_FLAG(n,f) \
	 Z87WRITE_D16(Z087_BDBASE, Z087_BD_OFFS + (((n)+TBD_OFF) * Z087_BDSIZE),\
     Z87READ_D16( Z087_BDBASE, Z087_BD_OFFS + (((n)+TBD_OFF) * Z087_BDSIZE)) &\
	 ~(f) )
/*!< clear flag f of Tx BD nr. (n) */

#define Z087_CLR_RBD_FLAG(n,f) \
	  Z87WRITE_D16(Z087_BDBASE, Z087_BD_OFFS + ((n)+RBD_OFF) * Z087_BDSIZE,\
      Z87READ_D16( Z087_BDBASE, Z087_BD_OFFS + ((n)+RBD_OFF) * Z087_BDSIZE) &\
      ~(f) )
/*!< clear flag f of Rx BD nr. (n) */

#define Z087_GET_RBD_FLAG(n,f) \
       (Z87READ_D16(Z087_BDBASE, Z087_BD_OFFS+( ((n)+RBD_OFF)*Z087_BDSIZE)) &\
       (f) )
/*!< get flag f of Rx BD nr. (n) */


#define Z087_GET_TBD_FLAG(n,f) \
       (Z87READ_D16(Z087_BDBASE, Z087_BD_OFFS+( ((n)+TBD_OFF)*Z087_BDSIZE)) &\
       (f) )
/*!< get TBD Flag f of Tx BD nr. (n) */


#define Z087_SET_TBD_LEN(n,l) Z87WRITE_D16(Z087_BDBASE, \
        Z087_BD_OFFS + Z087_BD_OFFS_LEN+( ((n)+TBD_OFF) * Z087_BDSIZE), (l));
/*!< set ETH Frame length for Tx BD nr. (n) */


#define Z087_GET_TBD_LEN(n) Z87READ_D16(Z087_BDBASE, \
        Z087_BD_OFFS + Z087_BD_OFFS_LEN+( ((n)+TBD_OFF) * Z087_BDSIZE))
/*!< Get ETH Frame length for Tx BD nr. (n) */


#define Z087_GET_RBD_LEN(n)  Z87READ_D16(Z087_BDBASE, \
	    Z087_BD_OFFS+( ((n)+RBD_OFF) * Z087_BDSIZE) + Z087_BD_OFFS_LEN )
/*!< retrieve the length stored in Rx BD nr. (n) */


#define Z087_CLR_RBD_LEN(n) \
	    Z87WRITE_D16(Z087_BDBASE, \
		Z087_BD_OFFS+( ((n)+RBD_OFF) * Z087_BDSIZE)+Z087_BD_OFFS_LEN, 0 );
/*!< clear a Rx BDs len entry after packet is processed */

#define Z087_GET_RBD_ADDR(n) \
		Z87READ_D32(Z087_BDBASE, Z087_BD_OFFS + \
        ( ((n)+RBD_OFF) * Z087_BDSIZE) + Z087_BD_OFFS_ADR)
/*!< get the address of ETH Frame of Rx BD (n) */

#define Z087_RBD_EMPTY(n) Z087_GET_RBD_FLAG((n), OETH_RX_BD_EMPTY)
/*!< return non-zero if the Rx BD (n) is empty */
/*@}*/

/**
 * @defgroup _Z087_REGBITS Register Bit definitions
 */
/*@{*/
#define OETH_TOTAL_BD       128   	/*!< total number of Buffer descriptors */
#define OETH_MAXBUF_LEN     0x610  	/*!< reserved length of an Eth frame */
/*@}*/


/**
 * @defgroup _ETHT1 message levels for ethtool usage
 */
/*@{*/
#define ETHT_MESSAGE_OFF	0 	/*!< all Messages off */
#define ETHT_MESSAGE_LVL1	1 	/*!< only main debug messages */
#define ETHT_MESSAGE_LVL2	2 	/*!< more verbose messages */
#define ETHT_MESSAGE_LVL3	3 	/*!< maximum verbosity including interrupts */
/*@}*/


/**
 * @defgroup _TXDB Tx Buffer Descriptor Bits
 */
/*@{*/
#define OETH_TX_BD_READY     0x8000   /*!< Tx BD Ready */
#define OETH_TX_BD_IRQ       0x4000   /*!< Tx BD IRQ Enable	*/
#define OETH_TX_BD_WRAP      0x2000   /*!< Tx BD Wrap (last BD)	*/
#define OETH_TX_BD_PAD       0x1000   /*!< Tx BD Pad Enable */
#define OETH_TX_BD_CRC       0x0800   /*!< Tx BD CRC Enable */
#define OETH_TX_BD_UNDERRUN  0x0100   /*!< Tx BD Underrun Status */
#define OETH_TX_BD_RETRY     0x00F0   /*!< Tx BD Retry Status */
#define OETH_TX_BD_RETLIM    0x0008   /*!< Tx BD Retransm Limit Stat */
#define OETH_TX_BD_LATECOL   0x0004   /*!< Tx BD Late Collision Stat */
#define OETH_TX_BD_DEFER     0x0002   /*!< Tx BD Defer Status */
#define OETH_TX_BD_CARRIER   0x0001   /*!< Tx BD Carrier Sense Lost Status */
/*@}*/


/**
 * @defgroup _RXDB Rx Buffer Descriptor Bits
 */
/*@{*/
#define OETH_RX_BD_EMPTY     0x8000	/*!< Rx BD Empty */
#define OETH_RX_BD_IRQ       0x4000	/*!< Rx BD IRQ Enable */
#define OETH_RX_BD_WRAP      0x2000	/*!< Rx BD Wrap (last BD) */
#define OETH_RX_BD_MISS      0x0080	/*!< Rx BD Miss Status 	*/
#define OETH_RX_BD_OVERRUN   0x0040	/*!< Rx BD Overrun Status */
#define OETH_RX_BD_INVSYMB   0x0020	/*!< Rx BD Invalid Symbol Status */
#define OETH_RX_BD_DRIBBLE   0x0010	/*!< Rx BD Dribble Nibble Status */
#define OETH_RX_BD_TOOLONG   0x0008	/*!< Rx BD Too Long Status */
#define OETH_RX_BD_SHORT     0x0004	/*!< Rx BD Too Short Frame Status */
#define OETH_RX_BD_CRCERR    0x0002	/*!< Rx BD CRC Error Status */
#define OETH_RX_BD_LATECOL   0x0001	/*!< Rx BD Late Collision Status */
/*@}*/

#define OETH_ERRFLAGS			OETH_RX_BD_OVERRUN  |\
	                            OETH_RX_BD_INVSYMB  |\
	                            OETH_RX_BD_DRIBBLE  |\
                                OETH_RX_BD_TOOLONG  |\
	                            OETH_RX_BD_SHORT    |\
	                            OETH_RX_BD_CRCERR   |\
	                            OETH_RX_BD_LATECOL


/**
 * @defgroup _MODER MODER Register bits descripton
 */
/*@{*/
#define OETH_MODER_RXEN     (1<<0) 	/*!< Receive Enable 					*/
#define OETH_MODER_TXEN     (1<<1) 	/*!< Transmit Enable					*/
#define OETH_MODER_NOPRE    (1<<2) 	/*!< No Preamb.   		  	REV01:NA	*/
#define OETH_MODER_BRO      (1<<3) 	/*!< 0: Reject Broadcast				*/
#define OETH_MODER_IAM      (1<<4) 	/*!< Use Individual Hash				*/
#define OETH_MODER_PRO      (1<<5) 	/*!< Promisc Mode 						*/
#define OETH_MODER_IFG      (1<<6) 	/*!< Min. IFG not required  REV01:NA 	*/
#define OETH_MODER_LOOPBCK  (1<<7) 	/*!< Loop Back 		  	  	REV01:NA	*/
#define OETH_MODER_NOBCKOF  (1<<8) 	/*!< No Backoff 		  	REV01:NA	*/
#define OETH_MODER_EXDFREN  (1<<9) 	/*!< Excess Defer 		  	REV01:NA	*/
#define OETH_MODER_FULLD    (1<<10) /*!< Full Duplex 						*/
#define OETH_MODER_RST      (1<<11) /*!< Reset MAC 		  	  	REV01:NA 	*/
#define OETH_MODER_DLYCRCEN (1<<12) /*!< Delayed CRC Enable  	REV01:NA 	*/
#define OETH_MODER_CRCEN    (1<<13) /*!< CRC Enable 						*/
#define OETH_MODER_HUGEN    (1<<14) /*!< Huge Enable 		  	REV01:NA	*/
#define OETH_MODER_PAD      (1<<15) /*!< Pad Enable 						*/
#define OETH_MODER_RECSMALL (1<<16) /*!< Receive Small 	  	  	REV01:NA	*/
#define OETH_MODER_HD_AVAL   (1<<19) /*!< Half duplex available              */
#define OETH_MODER_NIOSSHIFT (1<<27) /*!< Ethernetframe shifted at 2 Bytes	 */
/*@}*/


/**
 * @defgroup _INTS Interrupt Source Register bits descripton
 */
/*@{*/
#define OETH_INT_TXB      	0x0001 /*!< Transmit Buffer IRQ	*/
#define OETH_INT_TXE      	0x0002 /*!< Transmit Error IRQ 	*/
#define OETH_INT_RXF      	0x0004 /*!< Receive Frame IRQ 	*/
#define OETH_INT_RXE      	0x0008 /*!< Receive Error IRQ 	*/
#define OETH_INT_BUSY     	0x0010 /*!< Busy IRQ */
#define OETH_INT_TXC      	0x0020 /*!< Tx Control Frame IRQ */
#define OETH_INT_RXC      	0x0040 /*!< Rx Control Frame IRQ */
#define OETH_INT_ALL      	0x007F /*!< All IRQ	*/
/*@}*/

/**
 * @defgroup _INTM Interrupt Mask Register bits descripton
 */
/*@{*/
#define OETH_INT_MASK_TXB       0x0001 /*!< Transmit Buffer IRQ	*/
#define OETH_INT_MASK_TXE       0x0002 /*!< Transmit Error IRQ 	*/
#define OETH_INT_MASK_RXF       0x0004 /*!< Receive Frame IRQ  */
#define OETH_INT_MASK_RXE       0x0008 /*!< Receive Error IRQ  */
#define OETH_INT_MASK_BUSY      0x0010 /*!< Busy IRQ  	*/
#define OETH_INT_MASK_TXC       0x0020 /*!< Tx Control Frame IRQ	*/
#define OETH_INT_MASK_RXC   	0x0040 /*!< Rx Control Frame IRQ */
/*@}*/

/**
 * @defgroup _CTRLMODER Control Module Mode Register
 */
/*@{*/
#define OETH_CTRLMODER_PASSALL  0x0001 /*!< Pass Control Frames */
#define OETH_CTRLMODER_RXFLOW   0x0002 /*!< Rx Control Flow Enable 	*/
#define OETH_CTRLMODER_TXFLOW   0x0004 /*!< Tx Control Flow Enable 	*/
/*@}*/

/**
 * @defgroup _MODERMII MII Mode Register
 */
/*@{*/
#define OETH_MIIMODER_CLKDIV    0x00FF /*!< Clock Divider 	*/
#define OETH_MIIMODER_NOPRE     0x0100 /*!< No Preamble 	*/
#define OETH_MIIMODER_RST       0x0200 /*!< MIIM Reset 	*/
/*@}*/

/**
 * @defgroup _CMDR MII Command Register
 */
/*@{*/
#define OETH_MIICMD_SCANSTAT  	0x0001 /*!< Scan Status		*/
#define OETH_MIICMD_RSTAT     	0x0002 /*!< Read Status	*/
#define OETH_MIICMD_WCTRLDATA 	0x0004 /*!< Write Control Data	*/
/*@}*/

/**
 * @defgroup _MIIA MII Address Register
 */
/*@{*/
#define OETH_MIIADDRESS_FIAD    0x001F /*!< PHY Address	*/
#define OETH_MIIADDRESS_RGAD    0x1F00 /*!< RGAD Address */
/*@}*/

/**
 * @defgroup _MIISR MII Status Register
 */
/*@{*/
#define OETH_MIISTATUS_LINKFAIL 0x0001 /*!< Link Fail */
#define OETH_MIISTATUS_BUSY     0x0002 /*!< MII Busy */
#define OETH_MIISTATUS_NVALID   0x0004 /*!< MIIStatusReg data invalid	*/
/*@}*/

/**
 * @defgroup _MISCR Misc defines
 * The current default KS8721 PHY address (on EM01)
 */
/*@{*/
#define Z087_PHY_ADDRESS 		1
#define MII_100_BASE_TX_PHY		0x1f
#define MII_100BASE_PWR			(1<<10)
#define Z087_WEIGHT             32
/*@}*/

/**
 * @defgroup _BDDEF Buffer Descriptor defines
 * Buffer Descriptor defines. ETH MAC can maintain up to 128 BDs in total.
 * (0x80) BD location = base + 0x400 - base + 0x7ff ( =0x400 )
 */
/*@{*/
#define Z087_BDSIZE			0x8		 /*!< size in byte of one BD */
#define Z087_TBD_NUM		0x40	 /*!< default number of TBDs */
#define Z087_RBD_NUM		0x40  	 /*!< Z087_TBD_NUM make both equal	*/
#define Z087_BDALIGN		(1<<10)  /*!< 10bit adress alignment in RAM */
/*@}*/

/**
 * @defgroup _BDAREA address defines within one Buffer descriptor
 */
/*@{*/
#define Z087_BD_AREA_SIZE ((Z087_TBD_NUM + Z087_RBD_NUM) *	Z087_BDSIZE)
#define Z087_BD_OFFS_STAT	0x0	 /*!< offset of status within  BD 	*/
#define Z087_BD_OFFS_LEN	0x2	 /*!< offset of length within  BD 	*/
#define Z087_BD_OFFS_ADR	0x4	 /*!< offset of Tx/Rx frame within this BD */
/*@}*/

/**
 * @defgroup _TXBDBITS Transmit Buffer Descriptor bit definitions
 */
/*@{*/
#define Z087_TBD_RDY     0x8000	/*!< Tx buffer ready: 1: ready for TX */
#define Z087_TBD_IRQ	 0x4000	/*!< IRQ enable 1: generate. IRQ after send */
#define Z087_TBD_WRAP    0x2000	/*!< Wrap indicate 1: last BD in table */
#define Z087_TBD_PAD     0x1000	/*!< pad enable 1: pad short frames */
#define Z087_TBD_CRC     0x0800 /*!< CRC enable 1: add CRC at packet end */
#define Z087_TBD_UR      0x0100 /*!< underrun 1: underrun while send */
#define Z087_TBD_RETRY   0x00f0	/*!< [7:4]: retry # till frame was sent */
#define Z087_TBD_RTRANS	 0x0008	/*!< retransm.limit reached(collisions etc) */
#define Z087_TBD_LCOLL	 0x0004 /*!< 1: late collision occured */
#define Z087_TBD_DEFER	 0x0002 /*!< Deferred indication */
#define Z087_TBD_CSLOST	 0x0001 /*!< Carrier sense lost while transmit */
/*@}*/

/**
 * @defgroup _RXBDBITS Receive Buffer Descriptors bit definitions
 */
/*@{*/
#define Z087_RBD_EMP    0x8000	/*!< Rx buffer empty */
#define Z087_RBD_IRQ	0x4000	/*!< IRQ enable, generate IRQ after recv */
#define Z087_RBD_WRAP   Z087_TBD_WRAP
#define Z087_RBD_CFRM   0x0100 /*!< 1: received Control Frame 0: normal frame */
#define Z087_RBD_MISS   0x0080 /*!< 1: frame accepted due to promisc mode */
#define Z087_RBD_OV		0x0040 /*!< overrun occured 	*/
#define Z087_RBD_IS		0x0020 /*!< invalid symbol (not in 5B4B table) */
#define Z087_RBD_DN	 	0x0010 /*!< dribble nibble (extra nibble received) */
#define Z087_RBD_TL	 	0x0008 /*!< received Frame longer then PACKETLEN */
#define Z087_RBD_SF	 	0x0004 /*!< short Frame,shorter then MINFL 	*/
#define Z087_RBD_CERR 	0x0002 /*!< CRC error occured */
#define Z087_RBD_LC 	0x0001 /*!< late collision */
/*@}*/

/**
 * @defgroup _PHYDEFS defines related to the PHY device
 */
/*@{*/
#define FEC_END_PHY_PRE_INIT	0x0001	/*!< PHY info initialized */
#define FEC_END_PHY_AUTO		0x0010	/*!< enable auto-negotiation */
#define FEC_END_PHY_TBL			0x0020	/*!< use negotiation table */
#define FEC_END_PHY_100			0x0040	/*!< PHY may use 100Mbit speed */
#define FEC_END_PHY_10			0x0080	/*!< PHY may use 10Mbit speed */
#define FEC_END_PHY_FD			0x0100	/*!< PHY may use full duplex */
#define FEC_END_PHY_HD			0x0200	/*!< PHY may use half duplex */
#define FEC_END_PHY_MAX_WAIT	0x0100	/*!< Autoneg. retries */
#define FEC_END_PHY_NULL		0x00ff	/*!< PHY is not present	*/
#define FEC_END_PHY_DEF			0x0000	/*!< PHY's logical address */
#define FEC_END_100MBS		 100000000  /*!< bits/s */
#define FEC_END_10MBS		  10000000  /*!< bits/s */
/*@}*/

/**
 * @defgroup _PHYDEFS2 MII Register definitions
 */
/*@{*/
#define ETHER_FEC_CRC_LEN		0x4	 	/*!< CRC length in bytes */
#define MII_MAX_PHY_NUM			0x20 	/*!< max number of attached PHYs */
#define MII_CTRL_REG			0x0		/*!< Control Register*/
#define MII_STAT_REG			0x1		/*!< Status Register */
#define MII_PHY_ID1_REG			0x2		/*!< PHY identifier 1 Register */
#define MII_PHY_ID2_REG			0x3		/*!< PHY identifier 2 Register */
#define MII_AN_ADS_REG			0x4		/*!< AutoNeg Advertisement Register */
#define MII_AN_PRTN_REG			0x5		/*!< AutoNeg partner ability Reg. */
#define MII_AN_EXP_REG			0x6		/*!< AutoNeg Expansion Register */
#define MII_AN_NEXT_REG			0x7		/*!< AutoNeg next-page transmit Reg. */
/*@}*/

/**
 * @defgroup _PHYCTRL MII control register bits
 */
/*@{*/
#define MII_CR_COLL_TEST		0x0080	/*!< collision test */
#define MII_CR_FDX				0x0100	/*!< duplexity:  FD:1, HD:0 */
#define MII_CR_RESTART			0x0200	/*!< restart auto negotiation */
#define MII_CR_ISOLATE			0x0400	/*!< isolate PHY from MII */
#define MII_CR_POWER_DOWN		0x0800	/*!< power down */
#define MII_CR_AUTO_EN			0x1000	/*!< auto-negotiation enable */
#define MII_CR_100				0x2000	/*!< 0 = 10mb, 1 = 100mb */
#define MII_CR_LOOPBACK			0x4000	/*!< 0 = normal, 1 = loopback */
#define MII_CR_RESET			0x8000	/*!< 0 = normal, 1 = PHY reset */
#define MII_CR_NORM_EN			0x0000	/*!< just enable the PHY */
/*@}*/

/**
 * @defgroup _MIISTAT MII Status register bit definitions
 */
/*@{*/
#define MII_SR_LINK_STATUS		0x0004  /* link Status -- 1 = link */
#define MII_SR_AUTO_SEL			0x0008  /* auto speed select capable */
#define MII_SR_REMOTE_FAULT     0x0010  /*!< Remote fault detect */
#define MII_SR_AUTO_NEG         0x0020  /*!< auto negotiation complete */
#define MII_SR_10T_HALF_DPX     0x0800  /*!< 10BaseT HD capable	*/
#define MII_SR_10T_FULL_DPX     0x1000  /*!< 10BaseT FD capable	*/
#define MII_SR_TX_HALF_DPX      0x2000  /*!< TX HD capable */
#define MII_SR_TX_FULL_DPX      0x4000  /*!< TX FD capable*/
#define MII_SR_T4               0x8000  /*!< T4 capable	*/
/*@}*/

/**
 * @defgroup MII Link Register bit definitions
 */
/*@{*/
#define MII_BP_FAULT			0x2000  /*!< remote fault */
#define MII_BP_ACK				0x4000  /*!< acknowledge */
#define MII_BP_NP				0x8000  /*!< nexp page is supported */
/*@}*/

/**
 * MII Next Page bit definitions
 */
/*@{*/
#define MII_NP_TOGGLE			0x0800	/*!< toggle bit	*/
#define MII_NP_ACK2				0x1000	/*!< acknowledge two */
#define MII_NP_MSG				0x2000	/*!< message page */
#define MII_NP_ACK1				0x4000	/*!< acknowledge one */
#define MII_NP_NP				0x8000	/*!< nexp page will follow */
/*@}*/

/**
 * MII Expansion Register bit definitions
 */
/*@{*/
#define MII_EXP_FAULT			0x0010  /*!< parallel detection fault */
#define MII_EXP_PRTN_NP			0x0008  /*!< link partner next-page able */
#define MII_EXP_LOC_NP			0x0004  /*!< local PHY next-page able */
#define MII_EXP_PR				0x0002  /*!< full page received */
#define MII_EXP_PRT_AN			0x0001  /*!< link partner autoneg. able */
/*@}*/

/**
 * technology ability field bit definitions
 */
/*@{*/
#define MII_TECH_10BASE_T		0x0020	/*!< 10Base-T */
#define MII_TECH_10BASE_FD		0x0040	/*!< 10Base-T Full Duplex */
#define MII_TECH_100BASE_TX		0x0080	/*!< 100Base-TX */
#define MII_TECH_100BASE_TX_FD	0x0100	/*!< 100Base-TX Full Duplex */
#define MII_TECH_100BASE_T4		0x0200	/*!< 100Base-T4 */
#define MII_TECH_MASK			0x1fe0	/*!< technology abilities mask */
#define MII_AN_FAIL				0x0010	/*!< auto-negotiation fail */
#define MII_STAT_FAIL			0x0020  /*!< errors in the status register */
#define FEC_END_PHY_NO_ABLE		0x0040  /*!< the PHY lacks some abilities */
/*@}*/


/* Cache macros */
# define Z87WRITE_D32(ma,offs,val) 		MWRITE_D32(ma,offs,val)
# define Z87WRITE_D16(ma,offs,val) 		MWRITE_D16(ma,offs,val)
# define Z87READ_D32(ma,offs) 	 		MREAD_D32(ma,offs)
# define Z87READ_D16(ma,offs) 	 		MREAD_D16(ma,offs)
# define Z87READ_D8(ma,offs) 	 		MREAD_D8(ma,offs)

/* Shortcut for polling BUSY until its deasserted after MII accesses */
#define Z087_WAIT_FOR_BUSY \
    while( Z87READ_D32(Z087_BASE, Z087_REG_MIISTATUS ) & OETH_MIISTATUS_BUSY);


/**
 * @defgroup _MACRO0 Macros acting on Registers within the first 0x5c byte
 *  from IP Core start
 */
/*@{*/
#define Z087_DISABLE_IRQ(n)	\
        Z87WRITE_D32(Z087_BASE, Z087_REG_INT_MASK, \
         (Z87READ_D32(Z087_BASE,Z087_REG_INT_MASK)) & ~(n) )
/*!< disable IRQ source n in Interrupt Mask Register */

#define Z087_ENABLE_IRQ(n) \
        Z87WRITE_D32(Z087_BASE, Z087_REG_INT_MASK, \
            Z87READ_D32(Z087_BASE, Z087_REG_INT_MASK)|(n))
/*!< enable IRQ source n in Interrupt Mask Register */

#define Z087_CLR_MODE_FLAG(f) \
		Z87WRITE_D32(Z087_BASE, Z087_REG_MODER, \
        Z87READ_D32(Z087_BASE, Z087_REG_MODER) &~(f))
/*!< clear bit f in MODE Register */

#define Z087_SET_MODE_FLAG(f) \
		Z87WRITE_D32(Z087_BASE, Z087_REG_MODER, \
        Z87READ_D32(Z087_BASE, Z087_REG_MODER)|(f))
/*!< set bit f in MODE Register */
/*@}*/

#endif

