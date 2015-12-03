/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: em10a_cfg.h
 *
 *       Author: ts
 *        $Date: 2012/01/11 18:02:12 $
 *    $Revision: 1.2 $
 *
 *  Description: MEN EM10A Configuration and Memory Map
 *
 *     Switches: TGT_HAM to setup the HAMILTON MM FLASH mapping
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: em10a_cfg.h,v $
 * Revision 1.2  2012/01/11 18:02:12  ts
 * R: support for EEPROD data of CPU was missing
 * M: added functionality in SYSPARAM2, added define for I2C address
 *
 * Revision 1.1  2011/10/10 17:40:43  ts
 * Initial Revision
 *
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2005..2005 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ****************************************************************************/

#ifndef _EM01CFG_H
#define _EM01CFG_H


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/* clocks */
#define EM10CFG_MAIN_CLK_64_0MHZ		64000000	/* 64MHz - PCI clk */

#define EM10CFG_IPB_CLK_DIV				2			/* IPB = XLB/2 */
#define EM10CFG_PCI_CLK_DIV				4           /* PCI = XLB/4 */
#define EM10CFG_PCI_CLK_DIV_66MHZ		0           /* PCI = IPB   */

/* SMB devices, ID EEPROM */

#define EM10A_SMB_SROM_EEPROD			0xaa

#define EM10CFG_IIC_ONBOARD				0
#define EM10CFG_IIC_IO					1


/*
 * CS Start/Size
 */

/* SDRAM */
#define EM10CFG_DRAM_128MB			0x08000000
#define EM10CFG_DRAM_256MB			0x10000000

/* MGT5100 internal map */
#define EM10CFG_MBAR_ADDR				0xf0000000 /* must match linker script */

/* SRAM */
#define EM10CFG_SRAM_ADDR				0xF2000000
#define EM10CFG_SRAM_SIZE				0x00200000

/* FRAM */
#define EM10CFG_FRAM_ADDR				0xF1000000
#define EM10CFG_FRAM_SIZE				0x00020000  /* 128 kB */

/* CPLD */
#define EM10CFG_CPLD_ADDR				0xF4000000
#define EM10CFG_CPLD_SIZE				0x00010000

#define EM10_CPLD_RCR	0x0000       /* reset control register address */
#define EM10_CPLD_RCR_WD_TRIG	0x80 /* w: trigger bit */
#define EM10_CPLD_RCR_LM81_INT	0x40 /* r: reset cause LM81 int */
#define EM10_CPLD_RCR_SWRESET 	0x20 /* r: EM10_CPLD_MCR_DO_RESET executed */
#define EM10_CPLD_RCR_POWER_ON 	0x10 /* r: reset cause power on */
#define EM10_CPLD_RCR_TEMP_CRIT	0x08 /* r: reset cause LM81 temperature */
#define EM10_CPLD_RCR_PB_RESET	0x04 /* r: reset cause PB RESET */
#define EM10_CPLD_RCR_HRESET	0x02 /* r: reset cause HRESET */
#define EM10_CPLD_RCR_WD		0x01 /* r: reset cause watchdog */

/* CPLD MCR register defs */
#define EM10_CPLD_MCR					0x1	/* control reg for FPGA */

#define EM10_CPLD_MCR_FPGA_INIT_DONE		0x80 /* r */
#define EM10_CPLD_MCR_FPGA_DATA				0x80 /* w */

#define EM10_CPLD_MCR_FPGA_CLK				0x40 /* w */
#define EM10_CPLD_MCR_FPGA_CONF_STATUS		0x40 /* r */

#define EM10_CPLD_MCR_FPGA_CONFIG			0x20 /* w */

#define EM10_CPLD_MCR_WD_TIME_MASK			0x0c /* r/w */
#define EM10_CPLD_MCR_WD_120S				0x0
#define EM10_CPLD_MCR_WD_50S				0x1
#define EM10_CPLD_MCR_WD_20S				0x2
#define EM10_CPLD_MCR_WD_1S8				0x3

#define EM10_CPLD_MCR_WD_DIS				0x02 /* r/w */

#define EM10_CPLD_MCR_NON_SAFETY_MODE		0x01 /* r */
#define EM10_CPLD_MCR_DO_RESET				0x01 /* w */

/* FPGA */
#define EM10CFG_FPGA_PCI_DEV_NO		0x1D
#define EM10CFG_FPGA_PCI_BUS		0
#define EM10CFG_FPGA_PCI_FUNC		0

/*
 * FLASH
 */
/* boot flash */
#define EM10CFG_FLASH_2MB					0xFFE00000
#define EM10CFG_FLASH_SIZE_2MB				0x00200000
#define EM10CFG_FLASH_4MB					0xFFC00000
#define EM10CFG_FLASH_SIZE_4MB				0x00400000
#define EM10CFG_FLASH_8MB					0xFF800000
#define EM10CFG_FLASH_SIZE_8MB				0x00800000

/* parameter string */
#define EM10CFG_MM_PARA_FPGA_LOC_SAVE		0x40	/* information which FPGA was loaded will be stored here */
#define EM10CFG_MM_PARA_FPGA_LOC_SAVE_SIZE	0x10    /* to hold this over reset */

#define EM10CFG_MM_PARA_STRING_ADDR		0x3000
#define EM10CFG_MM_PARA_STRING_SIZE		0x0400

/* FLASH Mapping */
#ifndef TGT_HAM
	#define EM10CFG_PMM_BASE				0xFFF00000  /* must match linker script */
	#define EM10CFG_SMM_BASE				0xFFF40000  /* must match linker script */
	#define EM10CFG_PMM_SIZE				0x40000		/* 256 kB for PMM */
	#define EM10CFG_SMM_SIZE				0xC0000		/* 768 kB for SMM */
#else
	#define EM10CFG_PMM_BASE				0xFFF00000  /* must match linker script */
	#define EM10CFG_SMM_BASE				0xFFF80000  /* must match linker script */
	#define EM10CFG_PMM_SIZE				0x80000		/* 512 kB for PMM */
	#define EM10CFG_SMM_SIZE				0x80000		/* 512 kB for SMM */
#endif /*TGT_HAM*/


/*
 * PCI - similar to MPC107 map B
 */

/* Entire PCI mem space */
#define EM10CFG_PCI_MEM_START			0x80000000
#define EM10CFG_PCI_MEM_SIZE			0x40000000

/* PCI prefetchable mem space */
#define EM10CFG_PCI_PF_MEM_START		EM10CFG_PCI_MEM_START
#define EM10CFG_PCI_PF_MEM_SIZE			0x10000000

/* PCI non prefetchable mem space */
#define EM10CFG_PCI_NOPF_MEM_START		0x90000000
#define EM10CFG_PCI_NOPF_MEM_SIZE		(EM10CFG_PCI_MEM_SIZE-\
                                         EM10CFG_PCI_PF_MEM_SIZE)

/* Onboard FPGA PCI mem space, prefetchable */
#define EM10CFG_FPGA_PF_MEM_START		0x80000000
#define EM10CFG_FPGA_PF_MEM_SIZE		0x02000000

/* Onboard FPGA PCI mem space, non prefetchable */
#define EM10CFG_FPGA_NOPF_MEM_START		EM10CFG_PCI_NOPF_MEM_START
#define EM10CFG_FPGA_NOPF_MEM_SIZE		0x02000000



/* PCI master window 1 */
#define EM10CFG_PCI_ISA_MEM_START		0xFD000000
#define EM10CFG_PCI_ISA_MEM_SIZE		0x01000000
/* PCI master window 2 - shared between PCI IO and PCI CFG */
#define EM10CFG_PCI_IO_CFG_START    	0xFE000000
#define EM10CFG_PCI_IO_CFG_SIZE			0x00010000

#define EM10CFG_PCI2MEM_1_START			0x00000000 /* PCI to SDRAM */
#define EM10CFG_PCI2MEM_1_SIZE			0x40000000
#define EM10CFG_PCI2MEM_0_SIZE			0x00040000
#define EM10CFG_PCI2MEM_0_START			(EM10CFG_PCI2MEM_1_START \
                                 - (EM10CFG_PCI2MEM_0_SIZE))/* PCI to MBAR */

/* PCI IRQ mapping, FAKE NUMBERS are used */
#define EM10CFG_PCI_IRQ_INTA	0xf0
#define EM10CFG_PCI_IRQ_INTB	0xf1
#define EM10CFG_PCI_IRQ_INTC	0xf2
#define EM10CFG_PCI_IRQ_INTD	0xf3



#endif /* _EM10CFG_H */










