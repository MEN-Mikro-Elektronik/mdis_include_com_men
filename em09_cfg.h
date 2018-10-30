/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: em09_cfg.h
 *
 *       Author: rt
 *        $Date: 2009/01/27 14:00:02 $
 *    $Revision: 3.18 $
 *
 *  Description: MEN EM09 Configuration and Memory Map
 *
 *     Switches: -
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2007..2007 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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

#ifndef _EM09CFG_H
#define _EM09CFG_H


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* IIC busses */
#define EM09CFG_IIC_ONBOARD		0					/* onboard I2C bus */
#ifdef MEN_EM09_VARIANT_XM50
 #define EM09CFG_IIC_CBOARD		1					/* I2C bus carrier board */
#else
 #define EM09CFG_IIC_CBOARD		EM09CFG_IIC_ONBOARD	/* I2C bus carrier board */
#endif /*MEN_EM09_VARIANT_XM50*/

#define EM09CFG_IIC_ONBOARD_SPD	0xa0 /* DDR SPD (not used) */

/*
 * CS Start/Size
 */

/* MGT5100 internal map */
#define EM09CFG_CCSR_ADDR			0xf0000000

/* CPLD */
#define EM09CFG_BCSR_ADDR			0xf2000000

/* FRAM */
#define EM09CFG_FRAM_ADDR			0xf3000000
#define EM09CFG_FRAM_SIZE			0x00020000

#ifdef MEN_EM09_VARIANT_XM50
	/* SRAM */
	#define EM09CFG_SRAM_ADDR		0xf4000000
	#define EM09CFG_SRAM_SIZE		0x00200000
#endif /* MEN_EM09_VARIANT_XM50 */

/* FPGA */
#ifdef MEN_EM09_VARIANT_A017
	#define EM09CFG_FPGA_PCI_BUS		0
	#define EM09CFG_FPGA_PCI_DEV_NO		0x1c
#elif defined(MEN_EM09_VARIANT_XM50)
	/* FPGA available for F50 */
	#define EM09CFG_FPGA_PCI_BUS		5
	#define EM09CFG_FPGA_PCI_BUS_R00	6
	#define EM09CFG_FPGA_PCI_DEV_NO		0x0
#else
	#define EM09CFG_FPGA_PCI_BUS		0
	#define EM09CFG_FPGA_PCI_DEV_NO		0x13
#endif
#define EM09CFG_FPGA_PCI_FUNC		0

/*
 * FLASH
 */
/* boot flash */
#define EM09CFG_FLASH_ADDR			0xff000000
#define EM09CFG_FLASH_USR_SIZE		0x00A00000	/* 10 MB usable by user */
#define EM09CFG_FLASH_SIZE			0x01000000	/* 16 MB devices  	*/

/* parameter string */
#define EM09CFG_MM_PARA_FPGA_LOC_SAVE		0x40	/* information which FPGA was loaded will be stored here */
#define EM09CFG_MM_PARA_FPGA_LOC_SAVE_SIZE	0x10    /* to hold this over reset */

/* MENMON parameter string */
#define EM09CFG_MM_PARA_STRING_ADDR		0x3000
#define EM09CFG_MM_PARA_STRING_SIZE		0x0400

/* VxBL string */
#define EM09CFG_MM_VXBL_STRING_ADDR		0x4200
#define EM09CFG_MM_VXBL_STRING_SIZE		0x0200

/* FLASH Mapping */
#define EM09CFG_PMM_BASE			0xFFF00000  /* must match linker script */
#define EM09CFG_SMM_BASE			0xFFE00000  /* must match linker script */
#define EM09CFG_XMM_SIZE			0x100000

#define EM09CFG_BFLASH_SYSP_BASE	0xFFDE0000 /* system parameter sector */
#define EM09CFG_BFLASH_SYSP_SIZE	0x00020000

#define EM09CFG_FPGA_NO_OF_SEC		4
#define EM09CFG_FP0_BASE			0xFFD00000
#define EM09CFG_FP0_SIZE			(0x100000-EM09CFG_BFLASH_SYSP_SIZE)
#define EM09CFG_FP1_BASE			0xFFC00000
#define EM09CFG_FP1_SIZE			0x100000
#define EM09CFG_FP2_BASE			0xFFB00000 /* 66 MHz */
#define EM09CFG_FP2_SIZE			0x100000
#define EM09CFG_FP3_BASE			0xFFA00000 /* 66 MHz fallback */
#define EM09CFG_FP3_SIZE			0x100000

/*
 * PCI - similar to MPC107 map B
 */

/* A017 */
#ifdef MEN_EM09_VARIANT_A017

	#define EM09CFG_PCI_INTERFACE_NO		0
	#define EM09CFG_PCIE_INTERFACE_NO		1

	/* Entire PCI mem space */
	#define EM09CFG_PCI_MEM_START			0x80000000
	#define EM09CFG_PCI_MEM_SIZE			0x50000000

	/* PCI prefetchable mem space */
	#define EM09CFG_PCI_PF_MEM_START		EM09CFG_PCI_MEM_START
	#define EM09CFG_PCI_PF_MEM_SIZE			0x10000000

	/* PCI non prefetchable mem space */
	#define EM09CFG_PCI_NOPF_MEM_START		0x90000000
	#define EM09CFG_PCI_NOPF_MEM_SIZE		(EM09CFG_PCI_MEM_SIZE-\
	                                         EM09CFG_PCI_PF_MEM_SIZE)

	#define EM09CFG_PCI_ISA_MEM_START		0xFB000000
	#define EM09CFG_PCI_ISA_MEM_SIZE		0x01000000

	#define EM09CFG_PCI_IO_START    		0xFBFF8000
	#define EM09CFG_PCI_IO_SIZE				0x00008000

	/* Entire PCIe mem space */
	#define EM09CFG_PCIE_MEM_START			0xD0000000
	#define EM09CFG_PCIE_MEM_SIZE			0x20000000

	/* PCIe prefetchable mem space */
	#define EM09CFG_PCIE_PF_MEM_START		EM09CFG_PCIE_MEM_START
	#define EM09CFG_PCIE_PF_MEM_SIZE		0x10000000

	/* PCIe non prefetchable mem space */
	#define EM09CFG_PCIE_NOPF_MEM_START		0xE0000000
	#define EM09CFG_PCIE_NOPF_MEM_SIZE		(EM09CFG_PCIE_MEM_SIZE-\
	                                         EM09CFG_PCIE_PF_MEM_SIZE)

	#define EM09CFG_PCIE_ISA_MEM_START		0xFD000000
	#define EM09CFG_PCIE_ISA_MEM_SIZE		0x01000000

	#define EM09CFG_PCIE_IO_START    		0xFC000000
	#define EM09CFG_PCIE_IO_SIZE			0x00008000

	/* Onboard FPGA PCI mem space, non prefetchable */
	#define EM09CFG_FPGA_NOPF_MEM_START		EM09CFG_PCI_NOPF_MEM_START
	#define EM09CFG_FPGA_NOPF_MEM_SIZE		0x04000000

/* XM50 */
#elif defined( MEN_EM09_VARIANT_XM50 )

	#define EM09CFG_PCI_INTERFACE_NO		0
	#define EM09CFG_PCI2_INTERFACE_NO		1
	#define EM09CFG_PCIE_INTERFACE_NO		2

	/* Entire PCI1 mem space */
	#define EM09CFG_PCI_MEM_START			0xE0000000
	#define EM09CFG_PCI_MEM_SIZE			0x08000000

	/* PCI1 prefetchable mem space */
	#define EM09CFG_PCI_PF_MEM_START		EM09CFG_PCI_MEM_START+0x04000000
	#define EM09CFG_PCI_PF_MEM_SIZE			0x04000000

	/* PCI1 non prefetchable mem space */
	#define EM09CFG_PCI_NOPF_MEM_START		EM09CFG_PCI_MEM_START
	#define EM09CFG_PCI_NOPF_MEM_SIZE		(EM09CFG_PCI_MEM_SIZE-\
	                                         EM09CFG_PCI_PF_MEM_SIZE)

	#define EM09CFG_PCI_IO_START    		0xFC000000
	#define EM09CFG_PCI_IO_SIZE				0x00008000

	/* Entire PCI2 mem space */
	#define EM09CFG_PCI2_MEM_START			0xE8000000
	#define EM09CFG_PCI2_MEM_SIZE			0x08000000

	/* PCI2 prefetchable mem space */
	#define EM09CFG_PCI2_PF_MEM_START		EM09CFG_PCI2_MEM_START+0x04000000
	#define EM09CFG_PCI2_PF_MEM_SIZE		0x04000000

	/* PCI2 non prefetchable mem space */
	#define EM09CFG_PCI2_NOPF_MEM_START		EM09CFG_PCI2_MEM_START
	#define EM09CFG_PCI2_NOPF_MEM_SIZE		(EM09CFG_PCI2_MEM_SIZE-\
	                                         EM09CFG_PCI2_PF_MEM_SIZE)

	/* Entire PCIe mem space */
	#define EM09CFG_PCIE_MEM_START			0x80000000
	#define EM09CFG_PCIE_MEM_SIZE			0x60000000

	/* PCIe prefetchable mem space */
	#define EM09CFG_PCIE_PF_MEM_START		EM09CFG_PCIE_MEM_START
	#define EM09CFG_PCIE_PF_MEM_SIZE		0x20000000

	/* PCIe non prefetchable mem space */
	#define EM09CFG_PCIE_NOPF_MEM_START		(EM09CFG_PCIE_MEM_START+\
											 EM09CFG_PCIE_PF_MEM_SIZE)
	#define EM09CFG_PCIE_NOPF_MEM_SIZE		(EM09CFG_PCIE_MEM_SIZE-\
	                                         EM09CFG_PCIE_PF_MEM_SIZE)

	#define EM09CFG_PCIE_ISA_MEM_START		0xFB000000
	#define EM09CFG_PCIE_ISA_MEM_SIZE		0x01000000

	#define EM09CFG_PCIE_IO_START    		0xFBFF8000
	#define EM09CFG_PCIE_IO_SIZE			0x00008000

/* Standard */
#else /* !XM50 && ! A17 */

	#define EM09CFG_PCI_INTERFACE_NO		0

	/* Entire PCI mem space */
	#define EM09CFG_PCI_MEM_START			0x80000000
	#define EM09CFG_PCI_MEM_SIZE			0x70000000

	/* PCI prefetchable mem space */
	#define EM09CFG_PCI_PF_MEM_START		EM09CFG_PCI_MEM_START
	#define EM09CFG_PCI_PF_MEM_SIZE			0x10000000

	/* PCI non prefetchable mem space */
	#define EM09CFG_PCI_NOPF_MEM_START		0x90000000
	#define EM09CFG_PCI_NOPF_MEM_SIZE		(EM09CFG_PCI_MEM_SIZE-\
                                         EM09CFG_PCI_PF_MEM_SIZE)

	#define EM09CFG_PCI_ISA_MEM_START		0xFB000000
	#define EM09CFG_PCI_ISA_MEM_SIZE		0x01000000

	#define EM09CFG_PCI_IO_START    		0xFBFF0000
	#define EM09CFG_PCI_IO_SIZE				0x00010000

	/* Onboard FPGA PCI mem space, non prefetchable */
	#define EM09CFG_FPGA_NOPF_MEM_START		EM09CFG_PCI_NOPF_MEM_START
	#define EM09CFG_FPGA_NOPF_MEM_SIZE		0x04000000

#endif /* MEN_EM09_VARIANT_A017 */

/* Onboard FPGA PCI mem space, prefetchable */
#define EM09CFG_FPGA_SAURER_PF_MEM_START	0x80800000
#define EM09CFG_FPGA_SAURER_PF_MEM_SIZE		0x03800000
#define EM09CFG_FPGA_PF_MEM_START			0x80000000
#define EM09CFG_FPGA_PF_MEM_SIZE			0x04000000

#define EM09CFG_FPGA_SAURER_SRAM_START		EM09CFG_FPGA_SAURER_PF_MEM_START
#define EM09CFG_FPGA_SAURER_SRAM_SIZE		0x00800000

#define EM09CFG_PCI2MEM_START			0x00000000 /* PCI to SDRAM */
#define EM09CFG_PCI2MEM_SIZE			0x40000000


/* PCI IRQ mapping */
#define EM09CFG_PCI_IRQ_INTA	0x8
#define EM09CFG_PCI_IRQ_INTB	0x9
#define EM09CFG_PCI_IRQ_INTC	0xa
#define EM09CFG_PCI_IRQ_INTD	0xb

#if defined( MEN_EM09_VARIANT_A017 ) || defined( MEN_EM09_VARIANT_XM50 )
	/* PCIE IRQ mapping */
	#define EM09CFG_PCIE_IRQ_INTA	0xf0
	#define EM09CFG_PCIE_IRQ_INTB	0xf1
	#define EM09CFG_PCIE_IRQ_INTC	0xf2
	#define EM09CFG_PCIE_IRQ_INTD	0xf3
#endif /* MEN_EM09_VARIANT_A017 || MEN_EM09_VARIANT_XM50 */

#if defined( MEN_EM09_VARIANT_A017 )
	/* VME outbound mapping */
	#define A017CFG_VME_A64_D64_START	0xB0000000
	#define A017CFG_VME_A64_D64_SIZE	0x20000000
	#define A017CFG_VME_A32_D32_START	0xA8000000
	#define A017CFG_VME_A32_D32_SIZE	0x08000000
	#define A017CFG_VME_A24_D32_START	0xA7000000
	#define A017CFG_VME_A24_D32_SIZE	0x01000000
	#define A017CFG_VME_A24_D16_START	0xA6000000
	#define A017CFG_VME_A24_D16_SIZE	0x01000000
	#define A017CFG_VME_A16_D32_START	0xA5FF0000
	#define A017CFG_VME_A16_D32_SIZE	0x00010000
	#define A017CFG_VME_A16_D16_START	0xA5FE0000
	#define A017CFG_VME_A16_D16_SIZE	0x00010000

	#define A017CFG_VME_PCI_SPACE_START	A017CFG_VME_A16_D16_START

	/* defines for TSI148 VME-PCI bridge */
	#define A017CFG_TSI148_PCI_BUS		0x00
	#define A017CFG_TSI148_PCI_DEV_NO	0x1d
	#define A017CFG_TSI148_PCI_FUNC		0x00

#endif /* MEN_EM09_VARIANT_A017 */

#define EM09CFG_Z125_UART_CLK	(2*66000000)

#endif /* _EM09CFG_H */


