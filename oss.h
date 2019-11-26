/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  oss.h
 *
 *      \author  uf
 *
 *	   \project  MDISforLinux
 *	     \brief  Operating System Services module interface
 *
 *     \switches (set in oss_os.h):
 *		- NO_SHARED_MEM	:				shared memory not supported
 *      - NO_CALLBACK	:				callback not supported
 *		- OSS_HAS_UNASSIGN_RESOURCES:	OSS_UnAssignResources available
 *      - MAC_USERSPACE:                compile OSS_library for user space
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 1997-2019, MEN Mikro Elektronik GmbH
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
 * You should have received a copy of the GNU Lesser General License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _OSS_H_
#define _OSS_H_

#ifndef MAC_USERSPACE
#	include <MEN/oss_os.h>  /* os specific types and header */
#else
#	include <MEN/ossu_os.h>  /* os specific types and header for user space */
#endif /* MAC_USERSPACE */

#ifdef __cplusplus
   extern "C" {
#endif

/*-----------------------------------------+
|  TYPEDEFS                                |
+------------------------------------------*/
/* for easy casting function pointers (callback) */
typedef void (*OSS_FKT_VOIDP1)(void*);
typedef void (*OSS_FKT_VOIDP2)(void*, void*);

/* for OSS_AssignResources */
typedef struct {
    int32   type;           /* resource type */
        union {
            struct {
                void    *physAddr;  /* physical address */
                u_int32 size;       /* size of address space */
            }mem;

            struct {
                int32   level;      /* interrupt level */
                int32   vector;     /* interrupt vector */
            }irq;

            int32   spare[32];      /* size of union */
        } u;
} OSS_RESOURCES;

typedef struct {                /* OSS_CallbackSet: */
    u_int32    callNr;          /* callback function index (0..n) */
    void       (*funct)(        /* callback function pointer */
                   void *appArg,
                   void *drvArg);
    void       *appArg;         /* function argument from application */
} OSS_CALLBACK_SET;

/*--- SHMEM block status ---*/
typedef struct {				/* M_LL_BLK_SHMEM_SET: */
    u_int32    smNr;			/* IN:  shared memory area index (0..n) */
	u_int32    size;			/* IN:  shared memory size [bytes] */
	void       *drvAddr;		/* OUT: shared memory address (driver) */
} OSS_SHMEM_SET;

typedef struct {				/* M_LL_BLK_SHMEM_LINK: */
    u_int32    smNr;			/* IN:  shared memory area index (0..n) */
	u_int32    size;			/* OUT: shared memory size [bytes] */
	void       *drvAddr;		/* OUT: shared memory address (driver) */
} OSS_SHMEM_LINK;

typedef struct {				/* M_LL_BLK_SHMEM_CLEAR: */
    u_int32    smNr;			/* IN:  shared memory area index (0..n) */
    u_int32    linkCnt;			/* OUT: shared memory link counter */
} OSS_SHMEM_CLEAR;

typedef struct OSS_DL_NODE {	/* Double linked list node */
	struct OSS_DL_NODE *next;
	struct OSS_DL_NODE *prev;
} OSS_DL_NODE;

typedef struct OSS_DL_LIST {	/* Double linked list header */
	OSS_DL_NODE *head;
	OSS_DL_NODE *tail;
	OSS_DL_NODE *tailpred;
} OSS_DL_LIST;

#ifdef MAC_USERSPACE
/* VME interface */
/** address-window type */
typedef enum {
	OSS_VME_WinT_master = 0, /**< master */
    OSS_VME_WinT_slave = 1,	 /**< slave */
} OSS_VME_WINTYPE;

/** Structure that describes address-window list nodes */
typedef struct {
	OSS_DL_NODE		n;
	int32			fd;			/**< handle to opened device */
	OSS_VME_WINTYPE winType;			/**< address-window type */
	long			vmeAddr;		/**< VMEbus addresses to map (from user) */
	long			locAddr;		/**< local address (translated) */
	long			size;			/**< number of bytes to map (from user) */
	/* master exclusive usage */
	u_int32			addrMode;		/**< OSS_VME_AM_X address mode (from user) */
	u_int32			maxDataMode;		/**< OSS_VME_DM_max data mode (from user) */
	u_int32			flags;			/**< flags (from user) */
	u_int32			useNbr;			/**< number of usage */
	/* slave exclusive usage */
	u_int32			slvSpc;			/**< number of VME slave space */
	u_int32			slvSpcSize;		/**< slave space size */
	u_int32			mapNbr;			/**< number of mappings */
} OSS_VME_ADDRWIN_NODE;

#endif /* MAC_USERSPACE */

/*-----------------------------------------+
|  DEFINES & CONST                         |
+------------------------------------------*/
/* semaphores */
#define OSS_SEM_BIN    0
#define OSS_SEM_COUNT  1
#define OSS_SEM_NOWAIT 0
#define OSS_SEM_WAITFOREVER  -1

/* for mem permission check */
#define OSS_READ     0
#define OSS_WRITE    1

/* for OSS_AssignResources */
#define OSS_RES_MEM      1
#define OSS_RES_IRQ      2
#define OSS_RES_IO       3

/* for OSS_BusToPhysAddr and BBIS BrdInfo */
#define OSS_BUSTYPE_NONE        0   /* device is local */
#define OSS_BUSTYPE_VME         1
#define OSS_BUSTYPE_PCI         2
#define OSS_BUSTYPE_ISA         3
#define OSS_BUSTYPE_ISAPNP      4
#define OSS_BUSTYPE_MMODULE     5
#define OSS_BUSTYPE_SMB		    6
#define OSS_BUSTYPE_CHAM		7
#define OSS_BUSTYPE_MSI			8
#define OSS_BUSTYPE_UNKNOWN   255

/* for OSS_MapPhysToVirtAddr */
#define OSS_ADDRSPACE_MEM         0
#define OSS_ADDRSPACE_IO          1
#define OSS_ADDRSPACE_PCICFG      2

/* VMEbus addr range */
#define OSS_VME_AXX          0x00ff	/* (mask) */
#define OSS_VME_A16          0x0001	/* short i/o */
#define OSS_VME_A24          0x0002	/* standard i/o */
#define OSS_VME_A32          0x0003	/* extended i/o */

/* VMEbus data width */
#define OSS_VME_DXX          0xff00	/* (mask) */
#define OSS_VME_D16          0x0100
#define OSS_VME_D24          0x0200
#define OSS_VME_D32          0x0300

/* OSS_MapVmeAddr - Data Modes */
#define OSS_VME_DM_8		0x01	/**<  8-bit data access */
#define OSS_VME_DM_16		0x02	/**< 16-bit data access */
#define OSS_VME_DM_32		0x04	/**< 32-bit data access */
#define OSS_VME_DM_64		0x08	/**< 64-bit data access */

/* OSS_MapVmeAddr - Address Modes (VMEbus address modifiers) */
/* VME_AM_<16:short/24:std/32:ext/64:long><U:user/S:superv><D:data/P:prgr/B:BLT/B64:D64-MBLT> */
#define OSS_VME_AM_16UD		0x29	/**< Short non-privileged access		 */
#define OSS_VME_AM_24UD		0x39	/**< Standard non-privileged data access */
#define OSS_VME_AM_24UB		0x3B	/**< Standard non-privileged BLT		 */
#define OSS_VME_AM_32UD		0x09	/**< Extended non-privileged data access */
#define OSS_VME_AM_32UB		0x0B	/**< Extended non-privileged BLT		 */
#define OSS_VME_AM_32UB64	0x08	/**< Extended non-privileged D64-MBLT	 */

/* for OSS_PciGetConfig */
#define OSS_PCI_INVALID	             0
#define OSS_PCI_VENDOR_ID            1
#define OSS_PCI_DEVICE_ID            2
#define OSS_PCI_COMMAND              3
#define OSS_PCI_STATUS               4
#define OSS_PCI_REVISION_ID          5
#define OSS_PCI_CLASS                6
#define OSS_PCI_SUB_CLASS            7
#define OSS_PCI_PROG_IF              8
#define OSS_PCI_CACHE_LINE_SIZE      9
#define OSS_PCI_PCI_LATENCY_TIMER   10
#define OSS_PCI_HEADER_TYPE         11     /* 0=device; 1=bridge */
#define OSS_PCI_BIST                12
#define OSS_PCI_ADDR_0              13
#define OSS_PCI_ADDR_1              14
#define OSS_PCI_ADDR_2              15
#define OSS_PCI_ADDR_3              16
#define OSS_PCI_ADDR_4              17
#define OSS_PCI_ADDR_5              18
#define OSS_PCI_CIS                 19
#define OSS_PCI_SUBSYS_VENDOR_ID    20
#define OSS_PCI_SUBSYS_ID           21
#define OSS_PCI_EXPROM_ADDR         22
#define OSS_PCI_INTERRUPT_PIN       23
#define OSS_PCI_INTERRUPT_LINE      24
/* additional offsets for PCI type 1 devices (bridges) */
#define OSS_PCI_PRIMARY_BUS     	25
#define OSS_PCI_SECONDARY_BUS   	26
#define OSS_PCI_SUBORDINATE_BUS 	27
#define OSS_PCI_SEC_LATENCY     	28
#define OSS_PCI_IO_BASE         	29
#define OSS_PCI_IO_LIMIT        	30
#define OSS_PCI_SEC_STATUS      	31
#define OSS_PCI_MEM_BASE        	32
#define OSS_PCI_MEM_LIMIT       	33
#define OSS_PCI_PRE_MEM_BASE    	34
#define OSS_PCI_PRE_MEM_LIMIT   	35
#define OSS_PCI_PRE_MEM_BASE_U  	36
#define OSS_PCI_PRE_MEM_LIMIT_U 	37
#define OSS_PCI_IO_BASE_U       	38
#define OSS_PCI_IO_LIMIT_U      	39
#define OSS_PCI_ROM_BASE        	40
#define OSS_PCI_BRG_INT_LINE    	41
#define OSS_PCI_BRG_INT_PIN     	42
#define OSS_PCI_BRIDGE_CONTROL  	43

#define OSS_PCI_ACCESS_8			0x01000000
#define OSS_PCI_ACCESS_16			0x02000000
#define OSS_PCI_ACCESS_32			0x04000000
#define OSS_PCI_ACCESS				0x07000000

/* Bit encodings for  PCI_COMMON_CONFIG.HeaderType */
#define OSS_PCI_HEADERTYPE_MULTIFUNCTION	0x80
#define OSS_PCI_HEADERTYPE_DEVICE_TYPE		0x00
#define OSS_PCI_HEADERTYPE_BRIDGE_TYPE		0x01

/* Bit encodings for PCI_COMMON_CONFIG.Command */
#define OSS_PCI_COMMAND_ENABLE_IO_SPACE					0x0001
#define OSS_PCI_COMMAND_ENABLE_MEM_SPACE				0x0002
#define OSS_PCI_COMMAND_ENABLE_BUS_MASTER				0x0004
#define OSS_PCI_COMMAND_ENABLE_SPECIAL_CYCLES			0x0008
#define OSS_PCI_COMMAND_ENABLE_WRITE_AND_INVALIDATE		0x0010
#define OSS_PCI_COMMAND_ENABLE_VGA_COMPATIBLE_PALETTE	0x0020
#define OSS_PCI_COMMAND_ENABLE_PARITY					0x0040  /* (ro+) */
#define OSS_PCI_COMMAND_ENABLE_WAIT_CYCLE				0x0080  /* (ro+) */
#define OSS_PCI_COMMAND_ENABLE_SERR						0x0100  /* (ro+) */
#define OSS_PCI_COMMAND_ENABLE_FAST_BACK_TO_BACK		0x0200  /* (ro)  */

/* Bit encodings for PCI_COMMON_CONFIG.Status */
#define OSS_PCI_STATUS_FAST_BACK_TO_BACK        0x0080  /* (ro) */
#define OSS_PCI_STATUS_DATA_PARITY_DETECTED     0x0100
#define OSS_PCI_STATUS_DEVSEL                   0x0600  /* 2 bits wide */
#define OSS_PCI_STATUS_SIGNALED_TARGET_ABORT    0x0800
#define OSS_PCI_STATUS_RECEIVED_TARGET_ABORT    0x1000
#define OSS_PCI_STATUS_RECEIVED_MASTER_ABORT    0x2000
#define OSS_PCI_STATUS_SIGNALED_SYSTEM_ERROR    0x4000
#define OSS_PCI_STATUS_DETECTED_PARITY_ERROR    0x8000

/* Bit encodings for PCI_COMMON_CONFIG.Status.Devsel bits */
#define PCI_STATUS_DEVSEL_SPEED_FAST               0x0000
#define PCI_STATUS_DEVSEL_SPEED_MEDIUM             0x0200
#define PCI_STATUS_DEVSEL_SPEED_SLOW               0x0400

/* for OSS_IsaGetConfig */
#define OSS_ISA_MEM_ADDR			0x10
#define OSS_ISA_IO_ADDR				0x20
#define OSS_ISA_IRQ_LEVEL			0x30

/* swap macros */
#define OSS_SWAP16(word)	( (((word)>>8) & 0xff) | (((word)<<8)&0xff00) )

#define OSS_SWAP32(dword)	( (((dword)>>24)& 0x000000ff)   | \
							  (((dword)<<24)& 0xff000000)   | \
							  (((dword)>>8) & 0x0000ff00)   | \
							  (((dword)<<8) & 0x00ff0000)     )

#define OSS_SWAP64(qword)  (  ((qword>>56) & 0x00000000000000ffLL) | \
							  ((qword<<56) & 0xff00000000000000LL) | \
							  ((qword>>40) & 0x000000000000ff00LL) | \
							  ((qword<<40) & 0x00ff000000000000LL) | \
							  ((qword>>24) & 0x0000000000ff0000LL) | \
							  ((qword<<24) & 0x0000ff0000000000LL) | \
							  ((qword>>8)  & 0x00000000ff000000LL) | \
							  ((qword<<8)  & 0x000000ff00000000LL)   )

/* merge the pci domain number into the pci bus number */
#define OSS_MERGE_BUS_DOMAIN(bus, domain) \
		(( bus & 0xff ) | ( ( domain & 0xff ) << 16 ))

#define OSS_BUS_NBR( merged_bus ) 		( merged_bus & 0xff )
#define OSS_DOMAIN_NBR( merged_bus )	( ( merged_bus >> 16 ) & 0xff )


/*-----------------------------------------+
|  PROTOTYPES                              |
+------------------------------------------*/
extern char* OSS_Ident( void );

extern void *OSS_MemGet(
    OSS_HANDLE *osHdl,
    u_int32    size,
    u_int32    *gotsizeP);

extern int32 OSS_MemFree(
    OSS_HANDLE *osHdl,
    void       *addr,
    u_int32    size);

extern int32 OSS_MemChk(
    OSS_HANDLE *osHdl,
    void       *addr,
    u_int32    size,
    int32      mode);

extern void OSS_MemCopy(
   OSS_HANDLE    *osHdl,
   u_int32       size,
   char          *src,
   char          *dest);

extern void OSS_MemFill(
    OSS_HANDLE *osHdl,
    u_int32    size,
    char       *adr,
    int8       value);

extern void OSS_StrCpy(
    OSS_HANDLE  *oss,
    char        *from,
	char        *to);

extern u_int32 OSS_StrLen(
    OSS_HANDLE *osHdl,
    char *string);

extern int32 OSS_StrCmp(
    OSS_HANDLE *osHdl,
    char *str1,
    char *str2);

extern int32 OSS_StrNcmp(
    OSS_HANDLE *osHdl,
    char    *str1,
    char    *str2,
    u_int32 nbrOfBytes);

extern char* OSS_StrTok(
    OSS_HANDLE *osHdl,
    char *string,
    char *separator,
    char **lastP);

#ifndef MAC_USERSPACE

#ifdef OSS_HAS_IRQMASKR
extern OSS_IRQ_STATE OSS_IrqMaskR(
	OSS_HANDLE *oss,
	OSS_IRQ_HANDLE* irqHandle );

extern void OSS_IrqRestore(
	OSS_HANDLE *oss,
	OSS_IRQ_HANDLE* irqHandle,
	OSS_IRQ_STATE oldState );
#endif /* OSS_HAS_IRQMASKR */

extern void OSS_IrqMask(
    OSS_HANDLE *osHdl,
    OSS_IRQ_HANDLE* irqHandle);

extern void OSS_IrqUnMask(
    OSS_HANDLE *osHdl,
    OSS_IRQ_HANDLE *irqHandle);

extern int32 OSS_IrqLevelToVector(
    OSS_HANDLE *osHdl,
    int32      busType,
	int32      level,
	int32      *vector);

extern int32 OSS_SpinLockCreate(
	OSS_HANDLE			*oss,
	OSS_SPINL_HANDLE	**spinlP );

extern int32 OSS_SpinLockRemove(
	OSS_HANDLE			*oss,
	OSS_SPINL_HANDLE	**spinlP );

extern int32 OSS_SpinLockAcquire(
	OSS_HANDLE			*oss,
	OSS_SPINL_HANDLE	*spinl );

extern int32 OSS_SpinLockRelease(
	OSS_HANDLE			*oss,
	OSS_SPINL_HANDLE	*spinl );

extern int32 OSS_SigCreate(
    OSS_HANDLE*       osHdl,
    int32            value,
    OSS_SIG_HANDLE** sigHandleP);

extern int32 OSS_SigSend(
    OSS_HANDLE *osHdl,
    OSS_SIG_HANDLE* sigHandle);

extern int32 OSS_SigRemove(
    OSS_HANDLE *osHdl,
    OSS_SIG_HANDLE** sigHandleP);

extern int32 OSS_SigInfo(
    OSS_HANDLE     *osHdl,
    OSS_SIG_HANDLE *sigHdl,
    int32          *signalNbrP,
    int32          *processIdP);

#endif /* MAC_USERSPACE */

extern int32 OSS_SemCreate(
    OSS_HANDLE *osHdl,
    int32          semType,
    int32          initVal,
    OSS_SEM_HANDLE** semHandleP);

extern int32 OSS_SemRemove(
    OSS_HANDLE *osHdl,
    OSS_SEM_HANDLE** semHandleP);

extern int32 OSS_SemWait(
    OSS_HANDLE *osHdl,
    OSS_SEM_HANDLE*   semHandle,
    int32           msec);

extern int32 OSS_SemSignal(
    OSS_HANDLE *osHdl,
    OSS_SEM_HANDLE* semHandle);

extern void OSS_DbgLevelSet(
    OSS_HANDLE *osHdl,
    u_int32 newLevel);

extern u_int32 OSS_DbgLevelGet(
    OSS_HANDLE *osHdl);

extern int32 OSS_Delay(
    OSS_HANDLE *osHdl,
    int32      msec);

extern int32 OSS_TickRateGet(
    OSS_HANDLE *osHdl);

extern u_int32 OSS_TickGet(
    OSS_HANDLE *osHdl);

extern u_int32 OSS_GetPid(
	OSS_HANDLE *osHdl);

extern int32 OSS_MikroDelayInit(
    OSS_HANDLE *osHdl);

extern int32 OSS_MikroDelay(
    OSS_HANDLE *osHdl,
    u_int32 mikroSec);

extern int32 OSS_BusToPhysAddr(
    OSS_HANDLE *osHdl,
    int32       busType,
    void       **physicalAddrP,
    ...);

#ifdef OSS_HAS_MAP_VME_ADDR
extern int32 OSS_MapVmeAddr(
	OSS_HANDLE	*osHdl,
	u_int64 	vmeBusAddr,
	u_int32		addrMode,
	u_int32		maxDataMode,
	u_int32		size,
	u_int32		flags,
	void		**locAddrP,
	void		**addrWinHdlP);
extern int32 OSS_UnMapVmeAddr(
	OSS_HANDLE	*osHdl,
	void		*addrWinHdl );
#endif /* OSS_HAS_MAP_VME_ADDR */

extern int32 OSS_PciGetConfig(
    OSS_HANDLE *osHdl,
    int32       busNbr,
    int32       pciDevNbr,
    int32       pciFunction,
    int32       which,
    int32      *valueP);

extern int32 OSS_PciSetConfig(
    OSS_HANDLE *osHdl,
    int32       busNbr,
    int32       pciDevNbr,
    int32       pciFunction,
    int32       which,
    int32       value);

#ifndef MAC_USERSPACE

extern int32 OSS_PciSlotToPciDevice(
    OSS_HANDLE *osHdl,
    int32      busNbr,
    int32      mechSlot,
    int32      *pciDevNbrP);

extern int32 OSS_IsaGetConfig(
	OSS_HANDLE	*osHdl,
	int8		*cardVendId,
	int16		cardProdId,
	int8		*devVendId,
	int16		devProdId,
	int32       devNbr,
	int32       resType,
	int32       resNbr,
	u_int32		*valueP);

#endif /* MAC_USERSPACE */

extern int32 OSS_AssignResources(
    OSS_HANDLE      *osHdl,
    int32           busType,
    int32           busNbr,
    int32           resNbr,
    OSS_RESOURCES   res[]);

#ifdef OSS_HAS_UNASSIGN_RESOURCES
extern int32 OSS_UnAssignResources(
    OSS_HANDLE      *osHdl,
    int32           busType,
    int32           busNbr,
    int32           resNbr,
    OSS_RESOURCES   res[]);
#endif

extern int32 OSS_MapPhysToVirtAddr(
    OSS_HANDLE *osHdl,
    void       *physAddr,
    u_int32    size,
	int32      addrSpace,
    int32      busType,
    int32      busNbr,
    void       **virtAddrP);

extern int32 OSS_UnMapVirtAddr(
    OSS_HANDLE *osHdl,
    void       **virtAddrP,
    u_int32    size,
	int32      addrSpace);

extern int32 OSS_Sprintf(
    OSS_HANDLE  *oss,
    char *str,
    const char *fmt,
    ...);

extern int32 OSS_Vsprintf(
    OSS_HANDLE  *oss,
    char *str,
    const char *fmt,
    va_list arg);

#ifndef MAC_USERSPACE

/* alarm prototypes */
extern int32 OSS_AlarmCreate(
    OSS_HANDLE       *oss,
    void             (*funct)(void *arg),
	void             *arg,
    OSS_ALARM_HANDLE **alarmP);

extern int32 OSS_AlarmRemove(
    OSS_HANDLE       *oss,
    OSS_ALARM_HANDLE **alarmP);

extern int32 OSS_AlarmSet(
    OSS_HANDLE       *oss,
    OSS_ALARM_HANDLE *alarm,
    u_int32          msec,
    u_int32          cyclic,
    u_int32          *realMsec);

extern int32 OSS_AlarmClear(
    OSS_HANDLE       *oss,
    OSS_ALARM_HANDLE *alarm);

#ifdef OSS_HAS_ALARMMASK
OSS_ALARM_STATE OSS_AlarmMask( OSS_HANDLE *oss );
void OSS_AlarmRestore( OSS_HANDLE *oss, OSS_ALARM_STATE oldState );
#endif /* OSS_HAS_ALARMMASK */

#endif /* MAC_USERSPACE */

/* callback prototypes */
#ifndef NO_CALLBACK
extern int32 OSS_CallbackCreate(
    OSS_HANDLE           *oss,
    u_int32	             maxQueue,
    OSS_CALLBACK_HANDLE  **cbHdlP);

extern int32 OSS_CallbackRemove(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE **cbHdlP);

extern int32 OSS_CallbackExec(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
    u_int32             callNr,
    void                *drvArg);

extern int32 OSS_CallbackExec2(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
    u_int32             callNr,
    void                *appArg,
    void                *drvArg);

extern int32 OSS_CallbackSetStat(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
	OSS_CALLBACK_SETSTAT *arg);

extern int32 OSS_CallbackGetStat(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
	OSS_CALLBACK_GETSTAT *arg);

extern int32 OSS_CallbackSet(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
    OSS_CALLBACK_SET    *cbSet);

extern int32 OSS_CallbackClear(
    OSS_HANDLE          *oss,
    OSS_CALLBACK_HANDLE *cbHdl,
    u_int32             callNr);
#endif

/* shared memory prototypes */
#ifndef NO_SHARED_MEM
extern int32 OSS_SharedMemCreate(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE **smHdlP);

extern int32 OSS_SharedMemRemove(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE **smHdlP);

extern int32 OSS_SharedMemCheckNr(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE *smHdl,
    OSS_SHMEM_SET    *smSet,
	u_int32          minNr,
	u_int32          maxNr,
	u_int32          *smNr);

extern int32 OSS_SharedMemCheckSize(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE *smHdl,
    OSS_SHMEM_SET    *smSet,
	u_int32          minSize,
	u_int32          maxSize,
	u_int32          *smSize);

extern int32 OSS_SharedMemSet(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE *smHdl,
    OSS_SHMEM_SET    *smSet);

extern int32 OSS_SharedMemLink(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE *smHdl,
    OSS_SHMEM_SET    *smLink);

extern int32 OSS_SharedMemClear(
    OSS_HANDLE       *oss,
    OSS_SHMEM_HANDLE *smHdl,
    OSS_SHMEM_CLEAR  *smClear);
#endif

/* SMBus specific OSS function prototypes */
extern int32 OSS_GetSmbHdl(
    OSS_HANDLE  *oss,
    u_int32		busNbr,
	void		**smbHdlP);

extern int32 OSS_SetSmbHdl(
    OSS_HANDLE  *oss,
    u_int32		busNbr,
	void		*smbHdl);

/* swapping prototypes */
extern u_int16 OSS_Swap16( u_int16 word );
extern u_int32 OSS_Swap32( u_int32 dword );

#if !defined(OS9000) && !defined(OS9)
extern u_int64 OSS_Swap64( u_int64 qword );
#endif

/* double linked list prototypes */
extern OSS_DL_LIST *OSS_DL_NewList( OSS_DL_LIST *l );
extern OSS_DL_NODE *OSS_DL_Remove( OSS_DL_NODE *n );
extern OSS_DL_NODE *OSS_DL_RemHead( OSS_DL_LIST *l );
extern OSS_DL_NODE *OSS_DL_AddTail( OSS_DL_LIST *l, OSS_DL_NODE *n );
#ifdef OSS_HAS_DL_INSERT_AFTER
extern OSS_DL_NODE *OSS_DL_InsertAfter( OSS_DL_NODE *n1, OSS_DL_NODE *n2 );
#endif

#ifdef __cplusplus
   }
#endif
#endif /*_OSS_H_*/

































