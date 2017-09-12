/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ataioctl.h
 *
 *       Author: kp
 *        $Date: 2007/01/05 17:33:20 $
 *    $Revision: 2.6 $
 *
 *  Description: IOCTL defines for ATA driver
 *
 *     Switches: -
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: ataioctl.h,v $
 * Revision 2.6  2007/01/05 17:33:20  cs
 * added:
 *   + define ATA_IOCTL_GET_DRV_STAT
 *
 * Revision 2.5  2005/07/26 16:32:38  kp
 * enhanced for ATA6
 *
 * Revision 2.3  2004/02/18 15:15:28  kp
 * added ATA_IOCTL_REGTEST
 *
 * Revision 2.2  2002/06/05 14:51:59  kp
 * some defs for UDMA and LBA added
 *
 * Revision 2.1  1998/06/18 11:13:56  kp
 * Added by mcvs
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

#ifndef _ATAIOCTL_H
#define _ATAIOCTL_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*--- Ioctl function codes ---*/
#define ATA_IOCTL_INFO				0x0201 /* return ATA_PARM structure */
#define ATA_IOCTL_GET_XFER			0x0202 /* get transfer mode */
#define ATA_IOCTL_GET_LBA			0x0203 /* see if ATA uses LBA on drive */
#define ATA_IOCTL_REGTEST			0x0204 /* perform register test */
#define ATA_IOCTL_GET_DRV_STAT		0x0205 /* get state of drive */
/*--------------------------------------+
|   TYPEDEFS                            |
+--------------------------------------*/

/*
 * structure returned during indentify command
 * ATA6:OBS: obsoleted in ATA6 spec
 * ATA6:RET: retired in ATA6 spec
 */
typedef struct {
    u_int16 config;               /* 0 general configuration */
    u_int16 cylinders;            /* 1 ATA6:OBS number of cylinders */
    u_int16 specConfig;           /* 2 specific configuration */
    u_int16 heads;                /* 3 ATA6:OBS number of heads */
    u_int16 bytesTrack;           /* 4 ATA6:RET number of unformatted bytes/track */
    u_int16 bytesSec;             /* 5 ATA6:RET number of unformatted bytes/sector */
    u_int16 sectors;              /* 6 ATA6:OBS number of sectors/track */
    u_int16 cfAssign0;            /* 7 Reserved for assigment by CompactFlash Assoc. */
    u_int16 cfAssign1;            /* 8 Reserved for assigment by CompactFlash Assoc. */
    u_int16 vendstat;             /* 9 ATA6:RET number of words of vendor status */
    char serial[20];              /* 10-19 controller serial number */
    u_int16 type;                 /* 20 ATA6:RET controller type */
    u_int16 size;                 /* 21 ATA6:RET sector buffer size, in sectors */
    u_int16 bytesEcc;             /* 22 ATA6:OBS necc bytes appended */
    char rev[8];				  /* 23-26 firmware revision */
    char model[40];				  /* 27-46 model name */
    u_int16 multiSecs;            /* 47 RW multiple support. bits 7-0 ia max secs */
    u_int16 reserved48;           /* 48 reserved */
    u_int16 capabilities;         /* 49 capabilities */
    u_int16 capabilities1;        /* 50 capabilities */
    u_int16 pioMode;              /* 51 ATA6:OBS PIO data transfer cycle timing mode */
    u_int16 dmaMode;              /* 52 ATA6:OBS single word DMA data transfer cycle timing */
    u_int16 valid;                /* 53 field validity */
    u_int16 currentCylinders;     /* 54 ATA6:OBS number of current logical cylinders */
    u_int16 currentHeads;         /* 55 ATA6:OBS number of current logical heads */
    u_int16 currentSectors;       /* 56 ATA6:OBS number of current logical sectors / track */
    u_int16 capacity0;            /* 57 ATA6:OBS current capacity in sectors */
    u_int16 capacity1;            /* 58 ATA6:OBS current capacity in sectors */
    u_int16 multiSet;             /* 59 multiple sector setting */
    u_int16 sectors0;             /* 60 total number of user addressable sectors */
    u_int16 sectors1;             /* 61 total number of user addressable sectors */
    u_int16 singleDma;            /* 62 ATA6:OBS single word DMA transfer */
    u_int16 multiDma;             /* 63 multi word DMA transfer */
    u_int16 advancedPio;          /* 64 flow control PIO transfer modes supported */
    u_int16 cycletimeDma;         /* 65 minimum multiword DMA transfer cycle time */
    u_int16 cycletimeMulti;       /* 66 recommended multiword DMA cycle time */
    u_int16 cycletimePioNoIordy;  /* 67 min PIO transfer cycle time wo flow ctl */
    u_int16 cycletimePioIordy;    /* 68 min PIO transfer cycle time w IORDY */
    u_int16 reserved69;           /* 69 reserved */
    u_int16 reserved70;           /* 70 reserved */
    u_int16 reserved71;       	  /* 71 reserved */
    u_int16 reserved72;       	  /* 72 reserved */
    u_int16 reserved73;       	  /* 73 reserved */
    u_int16 reserved74;       	  /* 74 reserved */
	u_int16 queueDepth;       	  /* 75 Maximum queue depth - 1 */
    u_int16 reserved76;       	  /* 76 reserved */
    u_int16 reserved77;       	  /* 77 reserved */
    u_int16 reserved78;       	  /* 78 reserved */
    u_int16 reserved79;       	  /* 79 reserved */
	u_int16 majorVersion;		  /* 80 major version number */
	u_int16 minorVersion;		  /* 81 minor version number */
	u_int16 cmdSet0;	 	 	  /* 82 command set supported */
	u_int16 cmdSet1;	 	 	  /* 83 command set supported */
	u_int16 cmdSetExt;	 	 	  /* 84 command set/feature supported ext. */
	u_int16 cmdSetEnabled0;	 	  /* 85 command set/feature enabled */
	u_int16 cmdSetEnabled1;	 	  /* 86 command set/feature enabled */
	u_int16 cmdSetDefault;	 	  /* 87 command set/feature default */
    u_int16 ultradma;             /* 88 ultra DMA transfer mode */
	u_int16 secEraseTime;		  /* 89 time required for security erase compl. */
	u_int16 enhSecEraseTime;	  /* 90 time required for enhanced security erase compl. */
	u_int16 curPwrMngmntVal;	  /* 91 current advanced power management value */
	u_int16 masterPwRevision;	  /* 92 master password revision code */
	u_int16	hwResetResult;		  /* 93 hardware reset result */
	u_int16 acousticMngmnt;		  /* 94 acoustic managment */
	u_int16 reserved95[5];		  /* 95-99 reserved */
	u_int16 maxLba48[4];		  /* 100-103 maximum user LBA for LBA48 */
	u_int16 reserved104[23];	  /* 104-126 reserved */
	u_int16 remStatusNotification; /* 127 removeable status notification feature set support */
	u_int16 securityStatus;		  /* 128 security status */
    u_int16 vendor[31];           /* 129-159 vendor specific */
	u_int16 cfaPowerMode;		  /* 160 CFA power mode 1 */
	u_int16 cfaReserved161[15];	  /* 161-175 CFA reserved */
	u_int16 mediaSerialNumber[30]; /* 176-205 current media serial number */
	u_int16 reserved206[49];      /* 206-254 reserved */
	u_int16 integrity;			  /* 255 integrity word */
} ATA_PARAM;

#define ATA_PARAM49_SUP_UDMA			0x0100			/* support UDMA mode */
#define ATA_PARAM49_SUP_LBA				0x0200			/* support LBA mode */

#define ATA_PARAM83_SUP_LBA48			0x0400			/* support LBA48 mode */
#define ATA_PARAM86_SUP_LBA48			0x0400			/* support LBA48 mode */

/*--- union to hold Ioctl arguments ---*/
typedef union {
	ATA_PARAM info;
} ATA_IOCTL_PARMS;



#ifdef __cplusplus
	}
#endif

#endif	/* _ATAIOCTL_H */
