/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mdis_ers.h
 *
 *       Author: ds
 *        $Date: 2010/10/14 10:11:27 $
 *    $Revision: 1.29 $
 *
 *  Description: MDIS error code string table
 *
 *     Switches: -
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1998 by MEN mikro elektronik GmbH, Nuremberg, Germany
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

#ifndef MDIS_ERS_H
#  define MDIS_ERS_H

#  ifdef __cplusplus
      extern "C" {
#  endif

/* NOTE: for Windows event logging:								*/
/* length of error code description is limit to 50 characters	*/

/*------------------------------+
|  table of error code strings  |
+------------------------------*/
struct _MDIS_ERR_STR
{
    int32  errCode;
    char*   errString;
} errStrTable[] =
{
	/* max string size indicator  |1---------------------------------------------50| */
	/* no error */
	{ ERR_SUCCESS				,"(no error)" },
	/* OS specific errors */
	{ ERR_BAD_PATH				,"OS: bad path number" },
	{ ERR_PATH_FULL				,"OS: path table full" },
	{ ERR_BUSERR				,"OS: bus error occurred" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* MK error codes */
	{ ERR_MK					,"MK: general error" },
	{ ERR_MK_USERBUF			,"MK: user buffer too small" },
	{ ERR_MK_UNK_CODE			,"MK: unknown status code" },
	{ ERR_MK_ILL_PARAM			,"MK: illegal parameter" },	
	{ ERR_MK_DESC_PARAM			,"MK: descriptor values out of range" },	
	{ ERR_MK_NO_LLDESC			,"MK: device descriptor not found" },
    { ERR_MK_NO_BBISDESC        ,"MK: board descriptor not found" },
	{ ERR_MK_NO_LLDRV			,"MK: device driver not found" },
	{ ERR_MK_IRQ_INSTALL		,"MK: can't install interrupt" },
	{ ERR_MK_IRQ_REMOVE			,"MK: can't remove interrupt" },
	{ ERR_MK_IRQ_ENABLE			,"MK: can't enable/disable interrupt" },
	{ ERR_MK_ILL_DESC			,"MK: illegal descriptor type" },
	{ ERR_MK_ILL_MSIZE			,"MK: address space size conflict" },
	{ ERR_MK_NO_IRQ				,"MK: board doesn't support interrupts" },
	{ ERR_MK_SLEEP_ILLHDL		,"MK: sleep closed low-level drv-hdl" },
	{ ERR_MK_SLEEP_LOCKED		,"MK: sleep locked driver usage" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* MIPIOS error codes */
	{ ERR_MIPIOS				,"MIPIOS: general error" },
	{ ERR_MIPIOS_ILL_PARAM		,"MIPIOS: illegal parameter" },	
	{ ERR_MIPIOS_NOT_SUPPORTED 	,"MIPIOS: not supported" },	
	{ ERR_MIPIOS_NO_DEV     	,"MIPIOS: no device" },	
	{ ERR_MIPIOS_NOT_INITIALIZED,"MIPIOS: not initialized" },	
	{ ERR_MIPIOS_ALREADY_INIT	,"MIPIOS: already initialized" },	
	{ ERR_MIPIOS_NO_SPACE		,"MIPIOS: no space" },	
	{ ERR_MIPIOS_TGT_CALL    	,"MIPIOS: target call" },	
	{ ERR_MIPIOS_TIMEOUT		,"MIPIOS: timeout" },	
	{ ERR_MIPIOS_CRC			,"MIPIOS: crc error" },	
	{ ERR_MIPIOS_NO_BUF			,"MIPIOS: no buffer" },	
	{ ERR_MIPIOS_SOCKET			,"MIPIOS: socket error" },	
	/* max string size indicator  |1---------------------------------------------50| */
	/* LL error codes */
	{ ERR_LL					,"LL: general error" },
	{ ERR_LL_USERBUF			,"LL: user buffer too small" },
	{ ERR_LL_UNK_CODE			,"LL: unknown status code" },
	{ ERR_LL_ILL_PARAM			,"LL: illegal parameter" },
	{ ERR_LL_DESC_PARAM			,"LL: descriptor values out of range" },	
	{ ERR_LL_ILL_ID				,"LL: wrong device id detected" },
	{ ERR_LL_ILL_DIR			,"LL: illegal i/o direction" },
	{ ERR_LL_DEV_BUSY			,"LL: device is busy" },
	{ ERR_LL_READ				,"LL: device read error" },
	{ ERR_LL_WRITE				,"LL: device write error" },
	{ ERR_LL_ILL_FUNC			,"LL: driver function not supported" },
	{ ERR_LL_DEV_NOTRDY			,"LL: device not ready error" },
	{ ERR_LL_ILL_CHAN			,"LL: illegal channel" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* MBUF error codes */
	{ ERR_MBUF					,"MBUF: general error" },
	{ ERR_MBUF_USERBUF			,"MBUF: user buffer too small" },
	{ ERR_MBUF_UNK_CODE			,"MBUF: unknown status code" },
	{ ERR_MBUF_ILL_PARAM		,"MBUF: illegal parameter" },
	{ ERR_MBUF_OVERFLOW			,"MBUF: buffer overflow occurred" },
	{ ERR_MBUF_UNDERRUN			,"MBUF: buffer underrun occurred" },
	{ ERR_MBUF_NO_BUF			,"MBUF: no buffer installed" },
	{ ERR_MBUF_ILL_SIZE			,"MBUF: illegal buffer size" },
	{ ERR_MBUF_ILL_DIR			,"MBUF: illegal buffer direction" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* BBIS error codes */
	{ ERR_BBIS					,"BBIS: general error" },
	{ ERR_BBIS_USERBUF			,"BBIS: user buffer too small" },
	{ ERR_BBIS_UNK_CODE			,"BBIS: unknown status code" },
	{ ERR_BBIS_ILL_PARAM		,"BBIS: illegal parameter" },
	{ ERR_BBIS_DESC_PARAM		,"BBIS: descriptor values out of range" },	
	{ ERR_BBIS_ILL_ID			,"BBIS: wrong board id detected" },
	{ ERR_BBIS_NO_IRQ			,"BBIS: can't determine interrupt parameters" },
	{ ERR_BBIS_ILL_IRQPARAM		,"BBIS: illegal interrupt parameter" },
	{ ERR_BBIS_EEPROM			,"BBIS: eeprom access error" },
	{ ERR_BBIS_ILL_SLOT			,"BBIS: illegal board slot" },
	{ ERR_BBIS_ILL_DATAMODE		,"BBIS: illegal address space (data mode)" },
	{ ERR_BBIS_ILL_ADDRMODE		,"BBIS: illegal address space (addr mode)" },
	{ ERR_BBIS_ILL_FUNC			,"BBIS: board handler function not supported" },
	{ ERR_BBIS_NO_CHECKLOC		,"BBIS: can't check board location" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* OSS error codes */
	{ ERR_OSS					,"OSS: general error" },
	{ ERR_OSS_UNK_BUSTYPE		,"OSS: unknown bus type" },
	{ ERR_OSS_TIMEOUT			,"OSS: timeout occurred" },
	{ ERR_OSS_NO_PERM			,"OSS: no permission accessing memory" },
	{ ERR_OSS_ILL_PARAM			,"OSS: illegal parameter" },
	{ ERR_OSS_ILL_HANDLE		,"OSS: illegal handle" },
	{ ERR_OSS_SIG_OCCURED		,"OSS: signal occurred" },
	{ ERR_OSS_SIG_SEND			,"OSS: can't send signal" },
	{ ERR_OSS_SIG_SET			,"OSS: can't install signal" },
	{ ERR_OSS_SIG_CLR			,"OSS: can't remove signal" },
	{ ERR_OSS_MEM_ALLOC			,"OSS: can't allocate memory" },
	{ ERR_OSS_MEM_FREE			,"OSS: can't free memory" },
	{ ERR_OSS_SEM_CREATE		,"OSS: can't create semaphore" },
	{ ERR_OSS_SEM_REMOVE		,"OSS: can't remove semaphore" },
	{ ERR_OSS_UNK_RESOURCE		,"OSS: unknown resource" },
	{ ERR_OSS_BUSY_RESOURCE		,"OSS: busy resource" },
	{ ERR_OSS_MAP_FAILED		,"OSS: can't map address space" },
	{ ERR_OSS_NO_MIKRODELAY		,"OSS: microdelay not available" },
	{ ERR_OSS_NO_BUSTOPHYS		,"OSS: can't map bus address" },
	{ ERR_OSS_NO_SYSCLOCK		,"OSS: no system ticker available" },
	{ ERR_OSS_ALARM_CREATE		,"OSS: can't create alarm" },
	{ ERR_OSS_ALARM_REMOVE		,"OSS: can't remove alarm" },
	{ ERR_OSS_ALARM_SET			,"OSS: can't install alarm routine" },
	{ ERR_OSS_ALARM_CLR			,"OSS: can't remove alarm routine" },
	{ ERR_OSS_CALLBACK_SET		,"OSS: can't install callback routine" },
	{ ERR_OSS_CALLBACK_CLR		,"OSS: can't remove callback routine" },
	{ ERR_OSS_CALLBACK_EMPTY	,"OSS: callback queue empty" },
	{ ERR_OSS_CALLBACK_OVER		,"OSS: callback queue overflow" },
	{ ERR_OSS_SHMEM_CREATE		,"OSS: can't init shared memory" },
	{ ERR_OSS_SHMEM_REMOVE		,"OSS: can't exit shared memory" },
	{ ERR_OSS_SHMEM_SET  		,"OSS: can't create shared memory area" },
	{ ERR_OSS_SHMEM_LINK		,"OSS: can't link to shared memory area" },
	{ ERR_OSS_SHMEM_CLR  		,"OSS: can't remove shared memory area" },
	{ ERR_OSS_UNK_ADDRSPACE		,"OSS: unknown address space type " },
	{ ERR_OSS_BUF_TOOSMALL		,"OSS: buffer too small " },
	/* max string size indicator  |1---------------------------------------------50| */
	/* (PCI specific) */
	{ ERR_OSS_PCI				,"OSS: general PCI error" },
	{ ERR_OSS_PCI_ILL_DEV		,"OSS: illegal PCI device" },
	{ ERR_OSS_PCI_ILL_DEVNBR	,"OSS: illegal PCI device number" },
	{ ERR_OSS_PCI_ILL_ADDRNBR	,"OSS: illegal PCI address number" },
	{ ERR_OSS_PCI_NO_DEVINSLOT	,"OSS: no PCI device found in slot" },
	{ ERR_OSS_PCI_UNK_REG		,"OSS: unknown PCI register" },
	{ ERR_OSS_PCI_SLOT_TO_DEV	,"OSS: can't map PCI slot to device" },
	{ ERR_OSS_PCI_NO_DEV_FOUND	,"OSS: no PCI dev found" },
	{ ERR_OSS_PCI_SET_CONFIG	,"OSS: PCI set config failed" },
	{ ERR_OSS_PCI_BUS_NOTFOUND  ,"OSS: PCI bus nr not found in system" },	
	{ ERR_OSS_PCIE_ILL_MSI      ,"OSS: unknown/illegal PCI MSI vector" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* (VME specific) */
	{ ERR_OSS_VME				,"OSS: general VME error" },
	{ ERR_OSS_VME_ILL_SPACE		,"OSS: illegal VME address space" },
	{ ERR_OSS_VME_ILL_SIZE		,"OSS: illegal VME address space size" },
	{ ERR_OSS_VME_NO_ADDRWIN	,"OSS: can't map VME address window" },
	/* max string size indicator  |1---------------------------------------------50| */
	/* (ISA specific) */
	{ ERR_OSS_ISA				,"OSS: general ISA error" },
	{ ERR_OSS_ISA_NO_PNPDATA	,"OSS: no ISAPNP cfg-data available" },
	{ ERR_OSS_ISA_NO_SUCH_DEV	,"OSS: no such ISA device" },
	{ ERR_OSS_ISA_UNK_RES		,"OSS: unknown ISA resource" },
	{ ERR_OSS_ISA_UNAVAIL_RES	,"OSS: unavailable ISA resource" },
	/* USER MODE */
	{ ERR_OSSU					,"OSSU: offset for OSSU error codes" },
	{ ERR_OSSU_PCI_ACC_INIT		,"OSSU: initialize PCI access failed" },
	/* DESC error codes */
	{ ERR_DESC					,"DESC: general error" },
	{ ERR_DESC_CORRUPTED		,"DESC: descriptor data corrupted" },
	{ ERR_DESC_KEY_NOTFOUND		,"DESC: descriptor key not found" },
	{ ERR_DESC_BUF_TOOSMALL		,"DESC: descriptor buffer too small" },
	/* ID error codes */
	{ ERR_ID					,"ID: general error" },
	{ ERR_ID_NOTFOUND			,"ID: id prom not found" },
	{ ERR_ID_CORRUPTED			,"ID: id prom data corrupted" },
	{ ERR_ID_ILL_PARAM			,"ID: id prom illegal parameter" },
	/* PLD error codes */
	{ ERR_PLD					,"PLD: general error" },
	{ ERR_PLD_NOTFOUND			,"PLD: no response from PLD" },
	{ ERR_PLD_INIT				,"PLD: error initializing PLD" },
	{ ERR_PLD_LOAD				,"PLD: error loading PLD" },
	{ ERR_PLD_TERM				,"PLD: error terminating PLD" },
	/* CBIS error codes */
	{ ERR_CBIS					,"CBIS: general error" },
	{ ERR_CBIS_UNK_CODE			,"CBIS: unknown status code" },
	{ ERR_CBIS_ILL_PARAM		,"CBIS: illegal parameter" },
	{ ERR_CBIS_ILL_FUNC			,"CBIS: cpu handler function not supported" },
	/* BK error codes */
	{ ERR_BK 					,"BK: general error" },
	{ ERR_BK_USERBUF			,"BK: user buffer too small" },
	{ ERR_BK_UNK_CODE			,"BK: unknown status code" },
	{ ERR_BK_ILL_PARAM			,"BK: illegal parameter" },	
	{ ERR_BK_DESC_PARAM			,"BK: descriptor values out of range" },	
	{ ERR_BK_NO_LLDESC			,"BK: board descriptor not found" },
	{ ERR_BK_NO_LLDRV			,"BK: board handler not found" },
	{ ERR_BK_ILL_DESC			,"BK: illegal descriptor type" },
	/* max string size indicator  |1---------------------------------------------50| */
};

#define MDIS_NBR_OF_ERR sizeof(errStrTable)/sizeof(struct _MDIS_ERR_STR)

#  ifdef __cplusplus
       }
#  endif

#endif /* MDIS_ERS_H */











