/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: ata_regs.h
 *
 *       Author: kp
 *        $Date: 2008/05/05 10:27:22 $
 *    $Revision: 2.6 $
 *
 *  Description: Register definitions for ATA drives
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

#ifndef _ATA_REGS_H
#define _ATA_REGS_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* diagnostic code */

#define ATA_DIAG_OK             0x01

/* control register */

#define ATA_CTL_4BIT            0x8     /* use 4 head bits (wd1003) */
#define ATA_CTL_RST             0x4     /* reset controller */
#define ATA_CTL_IDS             0x2     /* disable interrupts */

/* status register */

#define ATA_STAT_BUSY           0x80    /* controller busy */
#define ATA_STAT_READY          0x40    /* selected drive ready */
#define ATA_STAT_WRTFLT         0x20    /* write fault */
#define ATA_STAT_SEEKCMPLT      0x10    /* seek complete */
#define ATA_STAT_DRQ            0x08    /* data request */
#define ATA_STAT_ECCCOR         0x04    /* ECC correction made in data */
#define ATA_STAT_INDEX          0x02    /* index pulse from selected drive */
#define ATA_STAT_ERR            0x01    /* error detect */

/* size/drive/head register: addressing mode CHS or LBA */

#define ATA_SDH_IBM             0xa0    /* chs, 512 bytes sector, ecc */
#define ATA_SDH_LBA             0xe0    /* lba, 512 bytes sector, ecc */

/* commands */

#define ATA_CMD_RECALIB         0x10    /* recalibrate */
#define ATA_CMD_SEEK            0x70    /* seek */
#define ATA_CMD_READ            0x20    /* read sectors with retries */
#define ATA_CMD_WRITE           0x30    /* write sectors with retries */
#define ATA_CMD_READ_EXT        0x24    /* read sectors EXT */
#define ATA_CMD_READ_DMA_EXT    0x25    /* read DMA EXT */
#define ATA_CMD_WRITE_EXT       0x34    /* write sectors EXT */
#define ATA_CMD_WRITE_DMA_EXT   0x35    /* write DMA EXT */
#define ATA_CMD_FORMAT          0x50    /* format track */
#define ATA_CMD_DIAGNOSE        0x90    /* execute controller diagnostic */
#define ATA_CMD_INITP           0x91    /* initialize drive parameters */
#define ATA_CMD_IDENTIFY        0xEC    /* identify device */
#define ATA_CMD_IDENTIFY_PK		0xA1	/* identify packet device */
#define ATA_CMD_SET_FEATURE     0xEF    /* set features */
#define ATA_CMD_SET_MULTI       0xC6    /* set multi */
#define ATA_CMD_READ_MULTI      0xC4    /* read multi */
#define ATA_CMD_WRITE_MULTI     0xC5    /* write multi */
#define ATA_CMD_READ_DMA        0xC8    /* read dma */
#define ATA_CMD_WRITE_DMA       0xCA    /* write dma */

/* sub command of ATA_CMD_SET_FEATURE */

#define ATA_SUB_ENABLE_8BIT     0x01    /* enable 8bit data transfer */
#define ATA_SUB_ENABLE_WCACHE   0x02    /* enable write cache */
#define ATA_SUB_SET_RWMODE      0x03    /* set transfer mode */
#define ATA_SUB_DISABLE_RETRY   0x33    /* disable retry */
#define ATA_SUB_SET_LENGTH      0x44    /* length of vendor specific bytes */
#define ATA_SUB_SET_CACHE       0x54    /* set cache segments */
#define ATA_SUB_DISABLE_LOOK    0x55    /* disable read look-ahead feature */
#define ATA_SUB_DISABLE_REVE    0x66    /* disable reverting to power on def */
#define ATA_SUB_DISABLE_ECC     0x77    /* disable ECC */
#define ATA_SUB_DISABLE_8BIT    0x81    /* disable 8bit data transfer */
#define ATA_SUB_DISABLE_WCACHE  0x82    /* disable write cache */
#define ATA_SUB_ENABLE_ECC      0x88    /* enable ECC */
#define ATA_SUB_ENABLE_RETRY    0x99    /* enable retries */
#define ATA_SUB_ENABLE_LOOK     0xaa    /* enable read look-ahead feature */
#define ATA_SUB_SET_PREFETCH    0xab    /* set maximum prefetch */
#define ATA_SUB_SET_4BYTES      0xbb    /* 4 bytes of vendor specific bytes */
#define ATA_SUB_ENABLE_REVE     0xcc    /* enable reverting to power on def */

/* transfer modes of ATA_SUB_SET_RWMODE */

#define ATA_PIO_DEF_W           0x00    /* PIO default trans. mode */
#define ATA_PIO_DEF_WO          0x01    /* PIO default trans. mode, no IORDY */
#define ATA_PIO_W_0             0x08    /* PIO flow control trans. mode 0 */
#define ATA_PIO_W_1             0x09    /* PIO flow control trans. mode 1 */
#define ATA_PIO_W_2             0x0a    /* PIO flow control trans. mode 2 */
#define ATA_PIO_W_3             0x0b    /* PIO flow control trans. mode 3 */
#define ATA_PIO_W_4             0x0c    /* PIO flow control trans. mode 4 */
#define ATA_DMA_SINGLE_0        0x10    /* singleword DMA mode 0 */
#define ATA_DMA_SINGLE_1        0x11    /* singleword DMA mode 1 */
#define ATA_DMA_SINGLE_2        0x12    /* singleword DMA mode 2 */
#define ATA_DMA_MULTI_0         0x20    /* multiword DMA mode 0 */
#define ATA_DMA_MULTI_1         0x21    /* multiword DMA mode 1 */
#define ATA_DMA_MULTI_2         0x22    /* multiword DMA mode 2 */
#define ATA_DMA_ULTRA_0         0x40    /* ultra DMA mode 0 */
#define ATA_DMA_ULTRA_1         0x41    /* ultra DMA mode 1 */
#define ATA_DMA_ULTRA_2         0x42    /* ultra DMA mode 2 */
#define ATA_DMA_ULTRA_3         0x43    /* ultra DMA mode 3 */
#define ATA_DMA_ULTRA_4         0x44    /* ultra DMA mode 4 */
#define ATA_DMA_ULTRA_5         0x45    /* ultra DMA mode 5 */
#define ATA_DMA_ULTRA_6         0x46    /* ultra DMA mode 6 */
#define ATA_MAX_RW_SECTORS      0x100   /* max sectors per transfer */

/* configuration flags: transfer mode, bits, unit, geometry */

#define ATA_PIO_DEF_0           ATA_PIO_DEF_W   /* PIO default mode */
#define ATA_PIO_DEF_1           ATA_PIO_DEF_WO  /* PIO default mode, no IORDY */
#define ATA_PIO_0               ATA_PIO_W_0     /* PIO mode 0 */
#define ATA_PIO_1               ATA_PIO_W_1     /* PIO mode 1 */
#define ATA_PIO_2               ATA_PIO_W_2     /* PIO mode 2 */
#define ATA_PIO_3               ATA_PIO_W_3     /* PIO mode 3 */
#define ATA_PIO_4               ATA_PIO_W_4     /* PIO mode 4 */
#define ATA_PIO_AUTO            0x000d          /* PIO max supported mode */
#define ATA_DMA_0               0x0002          /* DMA mode 0 */
#define ATA_DMA_1               0x0003          /* DMA mode 1 */
#define ATA_DMA_2               0x0004          /* DMA mode 2 */
#define ATA_DMA_AUTO            0x0005          /* DMA max supported mode */
#define ATA_MODE_MASK           0x000F          /* transfer mode mask */

#define ATA_BITS_16             0x0040          /* RW bits size, 16 bits */
#define ATA_BITS_32             0x0080          /* RW bits size, 32 bits */
#define ATA_BITS_MASK           0x00c0          /* RW bits size mask */

#define ATA_PIO_SINGLE          0x0010          /* RW PIO single sector */
#define ATA_PIO_MULTI           0x0020          /* RW PIO multi sector */
#define ATA_PIO_MASK            0x0030          /* RW PIO mask */

#define ATA_DMA_SINGLE          0x0400          /* RW DMA single word */
#define ATA_DMA_MULTI           0x0800          /* RW DMA multi word */
#define ATA_DMA_MASK            0x0c00          /* RW DMA mask */

#define ATA_GEO_FORCE           0x0100          /* set geometry in the table */
#define ATA_GEO_PHYSICAL        0x0200          /* set physical geometry */
#define ATA_GEO_CURRENT         0x0300          /* set current geometry */
#define ATA_GEO_MASK            0x0300          /* geometry mask */

#define ATA_SUP_UDMA			0x0100			/* support UDMA mode */
#define ATA_SUP_LBA				0x0200			/* support LBA mode */

#ifdef __cplusplus
	}
#endif

#endif	/* _ATA_REGS_H */
