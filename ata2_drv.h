/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ata_drv2.h
 *
 *       Author: kp
 *        $Date: 2008/09/05 11:21:13 $
 *    $Revision: 3.7 $
 *
 *  Description: ATA driver export definitions (for COM/DRIVERS/ATA)
 *
 *     Switches:
 *
 *---------------------------------------------------------------------------
 * Copyright (c) 2005-2019, MEN Mikro Elektronik GmbH
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
#ifndef _ATA2_DRV_H
#define _ATA2_DRV_H


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/
#define ATA2_DRVMASK_MASTER			0x1	/* support master  */
#define ATA2_DRVMASK_SLAVE			0x2	/* support slave  */
#define ATA2_DRVMASK_MASTER_UDMA	0x4	/* support UDMA for master  */
#define ATA2_DRVMASK_SLAVE_UDMA		0x8	/* support UDMA for slave  */

/*--------------------------------------+
|   TYPDEFS                             |
+--------------------------------------*/
typedef void ATA2_HANDLE_T;

/** Channel number.
 * Used only for DMA chipset. Serves as an hint to the chipset
 */
typedef enum {
	ATA2_CHANNEL_PRIMARY=1,
	ATA2_CHANNEL_SECONDARY=2,
	ATA2_CHANNEL_UNSPECIFIC=0
} ATA2_CHANNEL_T;

/** ATA_IOCTL_GET_DRV_STAT parameter.
 *
 */
typedef enum {
	ATA2_DRIVE_ST_OK		= 0,	/* device is OK                      */
	ATA2_DRIVE_ST_NONE		= 1,	/* device absent or does not respond */
	ATA2_DRIVE_ST_DIAG_F	= 2,	/* device diagnostic failed          */
	ATA2_DRIVE_ST_PREAD_F	= 3,	/* read device parameters failed     */
	ATA2_DRIVE_ST_MED_CH	= 4,	/* medium have been changed          */
	ATA2_DRIVE_ST_INIT		= 255	/* uninitialized device              */
} ATA2_DRIVE_STATE_T;

/** ATA2 CHIPSET IrqService status return parameter.
 *
 */
typedef enum {
	ATA2_CHIPS_ISTAT_OK		= 0,	/* IRQ from this controller          */
	ATA2_CHIPS_ISTAT_NOIRQ	= 1,	/* IRQ not from this controllers     */
	ATA2_CHIPS_ISTAT_REMOVE	= 2,	/* device absent or does not respond */
	ATA2_CHIPS_ISTAT_CHANGE	= 3,	/* device inserted/changed           */
	ATA2_CHIPS_ISTAT_ERROR	= 255	/* error while handling irq          */
} ATA2_CHIPSET_INT_STAT_T;

/** Chipset object
 * Must be passed to ATA2_Create()
 */
typedef struct {
	/** Setup handle, especially the register offsets
	 * If required, chipset driver may allocate additional data in
	 * ATA_HANDLE_T.chipsetData
	 */
	int32 (*init)( ATA2_HANDLE_T *ataH );

	/** Late Initialization (e.g. enable interrupts) */
	int32 (*initLate)( ATA2_HANDLE_T *ataH );

	/** terminate chipset driver. can be NULL */
	void (*term)( ATA2_HANDLE_T *ataH );

	/** setup max. possible PIO and UDMA mode
	 * If this function pointer is NULL, PIO default mode and no UDMA is used.
	 *
	 * \param subdev	\IN 0=master, 1=slave
	 * \param pioModeP	\IN requested PIO mode \OUT actualPIO  mode
	 *					ATA_PIO_xxx
	 * \param dmaModeP	\IN requested UDMA mode \OUT actual UDMA mode
	 *					ATA_DMA_ULTRA_xxx or 0 for no DMA
	 */
	int32 (*setMode)( ATA2_HANDLE_T *ataH,
					  int subdev,
					  int *pioModeP,
					  int *dmaModeP );

	/** Do interrupt processing before ATA2 driver does anything
	 *  don't read status register (clears interrupt)
	 */
	int32 (*intPreProc)( ATA2_HANDLE_T *ataH );

	/** Do interrupt processing after ATA2 driver interrupt handling
	 */
	void (*intPostProc)( ATA2_HANDLE_T *ataH );
} ATA2_CHIPSET_T;

/** Chipset data
 *  Can be passed to ATA2_Create()
 */
typedef struct {
	u_int32 hGotSize; 		/**< memory size actually allocated for me */
	u_int8  isRemovable;	/**< flag for controller is hotswappable
	                          *  bit 0 for Primary; bit 1 for Secondary */
} ATA2_CHIPSET_ARG_T;


/** Register offsets */
typedef struct {
	/* offsets to ma[ATA_REG_BLOCK_0] */
	u_int32 data;						/* (RW) data register (16 bits) */
	u_int32 error;						/* (R)  error register          */
	u_int32 feature;					/* (W)  feature/precompensation */
	u_int32 seccnt;						/* (RW) sector count            */
	u_int32 sector;						/* (RW) first sector number     */
	u_int32 cylLo; 						/* (RW) cylinder low byte       */
	u_int32 cylHi; 						/* (RW) cylinder high byte      */
	u_int32 sdh;						/* (RW) sector size/drive/head  */
	u_int32 command;					/* (W)  command register        */
	u_int32 status;						/* (R)  immediate status        */
	/* offsets to ma[ATA_REG_BLOCK_1] */
	u_int32 altStatus;					/* (R)  alternate status        */
	u_int32 devControl;					/* (W)  disk controller control */
	u_int32 drvAdr; 					/* (R)  disk controller address */

	/* offsets to ma[ATA_REG_BLOCK_DMA] */
	u_int32 bmIdeCommand;				/* (RW) Bus Master IDE Command   */
	u_int32 bmIdeStatus;				/* (RW) Bus Master IDE Status    */
	u_int32 bmIdePrdTable;				/* (RW) Bus Master IDE PRD Table */
} ATA2_REG_OFFSETS_T;

/** ATA controller instantiation structure */
typedef struct {
	MACCESS maRegBlock[2];		/**< base to address ATA regs.
								    Idx0: data reg..status reg
									Idx1: altStatus..drvAdr reg  */
	MACCESS maRegBlockDma;		/**< base to address BM DMA regs. */

	/** flags which drives should be supported
	 * See ATA2_DRVMASK_xxx above
	 */
	u_int8 drvMask;
	u_int8 allowSlaveCf;		/**< if TRUE, look for slave when
								     master is CompactFlash  */
	u_int8 useIrq;				/**< if TRUE, use IRQ else polling  */
	u_int32 toutReset;			/**< how long to wait for driver ready (s)  */
	u_int32 retry;				/**< how often to retry 1=no retries  */

	/** the chipset object */
	const ATA2_CHIPSET_T *chipset;

	void *chipsetArg;			/** private information for chipset driver */
} ATA2_DESC_T;

/*--- internal ATA handle ---*/
typedef struct {
	RBDRV_ENTRIES	 ent;					/* RB driver services */
	OSS_HANDLE		 *osh;					/* OSS handle */
	u_int32			 hGotSize;				/* size allocated for handle */
	DBG_HANDLE		 *dbh;					/* debug handle */
	u_int32			 debugLevel; 			/* debug level */
	OSS_SEM_HANDLE	 *lockSem;				/* ATA mutex */
	OSS_SEM_HANDLE	 *irqSem;				/* interrupt sem */

	int				 okRemovable;			/* drive could be removed */

	ATA2_DESC_T		 desc;					/* copy of init descriptor */

#ifdef MEN_ATA2COM_COMPILE
	ATA2_REG_OFFSETS_T regOffs;				/**< register offsets  */


	u_int8			 intStatus;				/* saved interrupt status */
	u_int8			 incompatibleHw; 		/* Regtest failed */
	u_int8			 _pad[2];

	ATA_PRD			 prdTable[ATA_PRD_TABLE_SIZE*2];
	int				 prdStartIndex;			/* first index to use in prdTable
											   (either 0 or 3) */
	ATA_DRIVE		 drive[ATA_MAX_DRIVES];	/* drive structures */
	u_int8 			 buf[512];				/* general buffer */


	void			 *chipsetData; 			/* to be used by chipset driver */
#endif /* MEN_ATA2NATIVE_COMPILE */
} ATA_HANDLE_T;


/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
/* chipset objects */
extern const ATA2_CHIPSET_T ATA2_chipset16Z023Ide;
extern const ATA2_CHIPSET_T ATA2_chipset16Z016Ide;
extern const ATA2_CHIPSET_T ATA2_chipsetCommonIde;
extern const ATA2_CHIPSET_T ATA2_chipsetSiI31xxSata;


/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
int32 ATA2_Create(
    OSS_HANDLE *osh,
	u_int32    initDbgLevel,
	const ATA2_DESC_T *desc,
    ATA2_HANDLE_T **handleP);
int32 ATA2_StartupDrives( ATA2_HANDLE_T *_h );
void ATA2_Irq( ATA2_HANDLE_T *);

#endif /* _ATA2_DRV_H */

