/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  mpc85xx.h
 *
 *      \author  Xianghua Xiao (x.xiao@motorola.com), klaus.popp@men.de
 *        $Date: 2014/08/20 10:17:54 $
 *    $Revision: 2.9 $
 *
 *  	 \brief  Header file for MPC 85xx internal registers
 *
 * From u-boot immap_85xx.h
 *
 *    \switches MPC85XX_FOR_8540 - turn on register layout for 8540,
 *									  otherwise it's 8560
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 2004-2019, MEN Mikro Elektronik GmbH
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

/*
 * MPC85xx Internal Memory Map
 *
 * Copyright(c) 2002,2003 Motorola Inc.
 * Xianghua Xiao (x.xiao@motorola.com)
 *
 */

#ifndef _MPC85XX_H
#define _MPC85XX_H

typedef volatile u_int32 __85xx_r32;
typedef volatile u_int16 __85xx_r16;
typedef volatile u_int8 __85xx_r8;

/* Local-Access Registers and ECM Registers(0x0000-0x2000) */

typedef struct MPC85XX_LOCAL_ECM {
	__85xx_r32	ccsrbar;	/* 0x0 - Control Configuration Status Registers Base Address Register */
	__85xx_r8	res1[4];
	__85xx_r32	altcbar;	/* 0x8 - Alternate Configuration Base Address Register */
	__85xx_r8	res2[4];
	__85xx_r32	altcar;		/* 0x10 - Alternate Configuration Attribute Register */
	__85xx_r8	res3[12];
	__85xx_r32	bptr;		/* 0x20 - Boot Page Translation Register */
	__85xx_r8	res4[3044];
	__85xx_r32	lawbar0;	/* 0xc08 - Local Access Window 0 Base Address Register */
	__85xx_r8	res5[4];
	__85xx_r32	lawar0;		/* 0xc10 - Local Access Window 0 Attributes Register */
	__85xx_r8	res6[20];
	__85xx_r32	lawbar1;	/* 0xc28 - Local Access Window 1 Base Address Register */
	__85xx_r8	res7[4];
	__85xx_r32	lawar1;		/* 0xc30 - Local Access Window 1 Attributes Register */
	__85xx_r8	res8[20];
	__85xx_r32	lawbar2;	/* 0xc48 - Local Access Window 2 Base Address Register */
	__85xx_r8	res9[4];
	__85xx_r32	lawar2;		/* 0xc50 - Local Access Window 2 Attributes Register */
	__85xx_r8	res10[20];
	__85xx_r32	lawbar3;	/* 0xc68 - Local Access Window 3 Base Address Register */
	__85xx_r8	res11[4];
	__85xx_r32	lawar3;		/* 0xc70 - Local Access Window 3 Attributes Register */
	__85xx_r8	res12[20];
	__85xx_r32	lawbar4;	/* 0xc88 - Local Access Window 4 Base Address Register */
	__85xx_r8	res13[4];
	__85xx_r32	lawar4;		/* 0xc90 - Local Access Window 4 Attributes Register */
	__85xx_r8	res14[20];
	__85xx_r32	lawbar5;	/* 0xca8 - Local Access Window 5 Base Address Register */
	__85xx_r8	res15[4];
	__85xx_r32	lawar5;		/* 0xcb0 - Local Access Window 5 Attributes Register */
	__85xx_r8	res16[20];
	__85xx_r32	lawbar6;	/* 0xcc8 - Local Access Window 6 Base Address Register */
	__85xx_r8	res17[4];
	__85xx_r32	lawar6;		/* 0xcd0 - Local Access Window 6 Attributes Register */
	__85xx_r8	res18[20];
	__85xx_r32	lawbar7;	/* 0xce8 - Local Access Window 7 Base Address Register */
	__85xx_r8	res19[4];
	__85xx_r32	lawar7;		/* 0xcf0 - Local Access Window 7 Attributes Register */
	__85xx_r8	res20[780];
	__85xx_r32	eebacr;		/* 0x1000 - ECM CCB Address Configuration Register */
	__85xx_r8	res21[12];
	__85xx_r32	eebpcr;		/* 0x1010 - ECM CCB Port Configuration Register */
	__85xx_r8	res22[3564];
	__85xx_r32	eedr;		/* 0x1e00 - ECM Error Detect Register */
	__85xx_r8	res23[4];
	__85xx_r32	eeer;		/* 0x1e08 - ECM Error Enable Register */
	__85xx_r32	eeatr;		/* 0x1e0c - ECM Error Attributes Capture Register */
	__85xx_r32	eeadr;		/* 0x1e10 - ECM Error Address Capture Register */
	__85xx_r8	res24[492];
} MPC85XX_LOCAL_ECM_T;


/* DDR memory controller registers(0x2000-0x3000) */

typedef struct MPC85XX_DDR {
	__85xx_r32	cs0_bnds;		/* 0x2000 - DDR Chip Select 0 Memory Bounds */
	__85xx_r8	res1[4];
	__85xx_r32	cs1_bnds;		/* 0x2008 - DDR Chip Select 1 Memory Bounds */
	__85xx_r8	res2[4];
	__85xx_r32	cs2_bnds;		/* 0x2010 - DDR Chip Select 2 Memory Bounds */
	__85xx_r8	res3[4];
	__85xx_r32	cs3_bnds;		/* 0x2018 - DDR Chip Select 3 Memory Bounds */
	__85xx_r8	res4[100];
	__85xx_r32	cs0_config;		/* 0x2080 - DDR Chip Select Configuration */
	__85xx_r32	cs1_config;		/* 0x2084 - DDR Chip Select Configuration */
	__85xx_r32	cs2_config;		/* 0x2088 - DDR Chip Select Configuration */
	__85xx_r32	cs3_config;		/* 0x208c - DDR Chip Select Configuration */
	__85xx_r8	res5[112];
	__85xx_r32	timing_cfg_3;	/* 0x2100 - DDR SDRAM Timing Configuration Register 3 */
	__85xx_r32	timing_cfg_0;	/* 0x2104 - DDR SDRAM Timing Configuration Register 0 */
	__85xx_r32	timing_cfg_1;	/* 0x2108 - DDR SDRAM Timing Configuration Register 1 */
	__85xx_r32	timing_cfg_2;	/* 0x210c - DDR SDRAM Timing Configuration Register 2 */
	__85xx_r32	sdram_cfg;		/* 0x2110 - DDR SDRAM Control Configuration */
	__85xx_r32	sdram_cfg_2;	/* 0x2114 - DDR SDRAM Control Configuration 2 */
	__85xx_r32	sdram_mode;		/* 0x2118 - DDR SDRAM Mode Configuration */
	__85xx_r8	res7[8];
	__85xx_r32	sdram_interval;		/* 0x2124 - DDR SDRAM Interval Configuration */
	__85xx_r8	res8a[8];
	__85xx_r32	sdram_clk_cntl;		/* 0x2130 - DDR SDRAM Clock Control */
	__85xx_r8	res8b[3276];
	__85xx_r32	data_err_inject_hi;	/* 0x2e00 - DDR Memory Data Path Error Injection Mask High */
	__85xx_r32	data_err_inject_lo;	/* 0x2e04 - DDR Memory Data Path Error Injection Mask Low */
	__85xx_r32	ecc_err_inject;		/* 0x2e08 - DDR Memory Data Path Error Injection Mask ECC */
	__85xx_r8	res9[20];
	__85xx_r32	capture_data_hi;	/* 0x2e20 - DDR Memory Data Path Read Capture High */
	__85xx_r32	capture_data_lo;	/* 0x2e24 - DDR Memory Data Path Read Capture Low */
	__85xx_r32	capture_ecc;		/* 0x2e28 - DDR Memory Data Path Read Capture ECC */
	__85xx_r8	res10[20];
	__85xx_r32	err_detect;		/* 0x2e40 - DDR Memory Error Detect */
	__85xx_r32	err_disable;		/* 0x2e44 - DDR Memory Error Disable */
	__85xx_r32	err_int_en;		/* 0x2e48 - DDR  */
	__85xx_r32	capture_attributes;	/* 0x2e4c - DDR Memory Error Attributes Capture */
	__85xx_r32	capture_address;	/* 0x2e50 - DDR Memory Error Address Capture */
	__85xx_r32	capture_ext_address;	/* 0x2e54 - DDR Memory Error Extended Address Capture */
	__85xx_r32	err_sbe;		/* 0x2e58 - DDR Memory Single-Bit ECC Error Management */
	__85xx_r8	res11[164];
	__85xx_r32	debug_1;		/* 0x2f00 */
	__85xx_r32	debug_2;
	__85xx_r32	debug_3;
	__85xx_r32	debug_4;
	__85xx_r8	res12[240];
} MPC85XX_DDR_T;


/* I2C Registers(0x3000-0x4000) */

typedef struct MPC85XX_I2C {
	__85xx_r8	i2cadr;		/* 0x3000 - I2C Address Register */
#define MPC85xx_I2CADR_MASK	0xFE
	__85xx_r8	res1[3];
	__85xx_r8	i2cfdr;		/* 0x3004 - I2C Frequency Divider Register */
#define MPC85xx_I2CFDR_MASK	0x3F
	__85xx_r8	res2[3];
	__85xx_r8	i2ccr;		/* 0x3008 - I2C Control Register */
#define MPC85xx_I2CCR_MEN	0x80
#define MPC85xx_I2CCR_MIEN	0x40
#define MPC85xx_I2CCR_MSTA      0x20
#define MPC85xx_I2CCR_MTX       0x10
#define MPC85xx_I2CCR_TXAK      0x08
#define MPC85xx_I2CCR_RSTA      0x04
#define MPC85xx_I2CCR_BCST      0x01
	__85xx_r8	res3[3];
	__85xx_r8	i2csr;		/* 0x300c - I2C Status Register */
#define MPC85xx_I2CSR_MCF	0x80
#define MPC85xx_I2CSR_MAAS      0x40
#define MPC85xx_I2CSR_MBB       0x20
#define MPC85xx_I2CSR_MAL       0x10
#define MPC85xx_I2CSR_BCSTM     0x08
#define MPC85xx_I2CSR_SRW       0x04
#define MPC85xx_I2CSR_MIF       0x02
#define MPC85xx_I2CSR_RXAK      0x01
	__85xx_r8	res4[3];
	__85xx_r8	i2cdr;		/* 0x3010 - I2C Data Register */
#define MPC85xx_I2CDR_DATA	0xFF
	__85xx_r8	res5[3];
	__85xx_r8	i2cdfsrr;	/* 0x3014 - I2C Digital Filtering Sampling Rate Register */
#define MPC85xx_I2CDFSRR	0x3F
	__85xx_r8	res6[4075];
} MPC85XX_I2C_T;

#define MPC85XX_I2C_REG_BLK_SIZE 0x100


#ifdef MPC85XX_FOR_8540
/* DUART Registers(0x4000-0x5000) */
typedef struct MPC85XX_DUART {
	__85xx_r8	res1[1280];
	__85xx_r8	urbr1_uthr1_udlb1;/* 0x4500 - URBR1, UTHR1, UDLB1 with the same address offset of 0x04500 */
	__85xx_r8	uier1_udmb1;	/* 0x4501 - UIER1, UDMB1 with the same address offset of 0x04501 */
	__85xx_r8	uiir1_ufcr1_uafr1;/* 0x4502 - UIIR1, UFCR1, UAFR1 with the same address offset of 0x04502 */
	__85xx_r8	ulcr1;		/* 0x4503 - UART1 Line Control Register */
	__85xx_r8	umcr1;		/* 0x4504 - UART1 Modem Control Register */
	__85xx_r8	ulsr1;		/* 0x4505 - UART1 Line Status Register */
	__85xx_r8	umsr1;		/* 0x4506 - UART1 Modem Status Register */
	__85xx_r8	uscr1;		/* 0x4507 - UART1 Scratch Register */
	__85xx_r8	res2[8];
	__85xx_r8	udsr1;		/* 0x4510 - UART1 DMA Status Register */
	__85xx_r8	res3[239];
	__85xx_r8	urbr2_uthr2_udlb2;/* 0x4600 - URBR2, UTHR2, UDLB2 with the same address offset of 0x04600 */
	__85xx_r8	uier2_udmb2;	/* 0x4601 - UIER2, UDMB2 with the same address offset of 0x04601 */
	__85xx_r8	uiir2_ufcr2_uafr2;/* 0x4602 - UIIR2, UFCR2, UAFR2 with the same address offset of 0x04602 */
	__85xx_r8	ulcr2;		/* 0x4603 - UART2 Line Control Register */
	__85xx_r8	umcr2;		/* 0x4604 - UART2 Modem Control Register */
	__85xx_r8	ulsr2;		/* 0x4605 - UART2 Line Status Register */
	__85xx_r8	umsr2;		/* 0x4606 - UART2 Modem Status Register */
	__85xx_r8	uscr2;		/* 0x4607 - UART2 Scratch Register */
	__85xx_r8	res4[8];
	__85xx_r8	udsr2;		/* 0x4610 - UART2 DMA Status Register */
	__85xx_r8	res5[2543];
} MPC85XX_DUART_T;
#else /* MPC8560 uses UART on its CPM */
typedef struct MPC85XX_DUART {
	__85xx_r8 res[4096];
} MPC85XX_DUART_T;
#endif

/* Local Bus Controller Registers(0x5000-0x6000) */
/* Omitting OCeaN(0x6000) and Reserved(0x7000) block */

typedef struct MPC85XX_LBC {
	__85xx_r32	br0;		/* 0x5000 - LBC Base Register 0 */
	__85xx_r32	or0;		/* 0x5004 - LBC Options Register 0 */
	__85xx_r32	br1;		/* 0x5008 - LBC Base Register 1 */
	__85xx_r32	or1;		/* 0x500c - LBC Options Register 1 */
	__85xx_r32	br2;		/* 0x5010 - LBC Base Register 2 */
	__85xx_r32	or2;		/* 0x5014 - LBC Options Register 2 */
	__85xx_r32	br3;		/* 0x5018 - LBC Base Register 3 */
	__85xx_r32	or3;		/* 0x501c - LBC Options Register 3 */
	__85xx_r32	br4;		/* 0x5020 - LBC Base Register 4 */
	__85xx_r32	or4;		/* 0x5024 - LBC Options Register 4 */
	__85xx_r32	br5;		/* 0x5028 - LBC Base Register 5 */
	__85xx_r32	or5;		/* 0x502c - LBC Options Register 5 */
	__85xx_r32	br6;		/* 0x5030 - LBC Base Register 6 */
	__85xx_r32	or6;		/* 0x5034 - LBC Options Register 6 */
	__85xx_r32	br7;		/* 0x5038 - LBC Base Register 7 */
	__85xx_r32	or7;		/* 0x503c - LBC Options Register 7 */
	__85xx_r8	res1[40];
	__85xx_r32	mar;		/* 0x5068 - LBC UPM Address Register */
	__85xx_r8	res2[4];
	__85xx_r32	mamr;		/* 0x5070 - LBC UPMA Mode Register */
	__85xx_r32	mbmr;		/* 0x5074 - LBC UPMB Mode Register */
	__85xx_r32	mcmr;		/* 0x5078 - LBC UPMC Mode Register */
	__85xx_r8	res3[8];
	__85xx_r32	mrtpr;		/* 0x5084 - LBC Memory Refresh Timer Prescaler Register */
	__85xx_r32	mdr;		/* 0x5088 - LBC UPM Data Register */
	__85xx_r8	res4[8];
	__85xx_r32	lsdmr;		/* 0x5094 - LBC SDRAM Mode Register */
	__85xx_r8	res5[8];
	__85xx_r32	lurt;		/* 0x50a0 - LBC UPM Refresh Timer */
	__85xx_r32	lsrt;		/* 0x50a4 - LBC SDRAM Refresh Timer */
	__85xx_r8	res6[8];
	__85xx_r32	ltesr;		/* 0x50b0 - LBC Transfer Error Status Register */
	__85xx_r32	ltedr;		/* 0x50b4 - LBC Transfer Error Disable Register */
	__85xx_r32	lteir;		/* 0x50b8 - LBC Transfer Error Interrupt Register */
	__85xx_r32	lteatr;		/* 0x50bc - LBC Transfer Error Attributes Register */
	__85xx_r32	ltear;		/* 0x50c0 - LBC Transfer Error Address Register */
	__85xx_r8	res7[12];
	__85xx_r32	lbcr;		/* 0x50d0 - LBC Configuration Register */
	__85xx_r32	lcrr;		/* 0x50d4 - LBC Clock Ratio Register */
	__85xx_r8	res8[12072];
} MPC85XX_LBC_T;


/* PCIX/PCI1 Registers(0x8000-0x9000) */

typedef struct MPC85XX_PCIX {
	__85xx_r32	cfg_addr;	/* 0x8000 - PCIX Configuration Address Register */
	__85xx_r32	cfg_data;	/* 0x8004 - PCIX Configuration Data Register */
	__85xx_r32	int_ack;	/* 0x8008 - PCIX Interrupt Acknowledge Register */
	__85xx_r8	res1[3060];
	__85xx_r32	potar0;		/* 0x8c00 - PCIX Outbound Transaction Address Register 0 */
	__85xx_r32	potear0;	/* 0x8c04 - PCIX Outbound Translation Extended Address Register 0 */
	__85xx_r32	powbar0;	/* 0x8c08 - PCIX Outbound Window Base Address Register 0 */
	__85xx_r32	powbear0;	/* 0x8c0c - PCIX Outbound Window Base Extended Address Register 0 */
	__85xx_r32	powar0;		/* 0x8c10 - PCIX Outbound Window Attributes Register 0 */
	__85xx_r8	res2[12];
	__85xx_r32	potar1;		/* 0x8c20 - PCIX Outbound Transaction Address Register 1 */
	__85xx_r32	potear1;	/* 0x8c24 - PCIX Outbound Translation Extended Address Register 1 */
	__85xx_r32	powbar1;	/* 0x8c28 - PCIX Outbound Window Base Address Register 1 */
	__85xx_r32	powbear1;	/* 0x8c2c - PCIX Outbound Window Base Extended Address Register 1 */
	__85xx_r32	powar1;		/* 0x8c30 - PCIX Outbound Window Attributes Register 1 */
	__85xx_r8	res3[12];
	__85xx_r32	potar2;		/* 0x8c40 - PCIX Outbound Transaction Address Register 2 */
	__85xx_r32	potear2;	/* 0x8c44 - PCIX Outbound Translation Extended Address Register 2 */
	__85xx_r32	powbar2;	/* 0x8c48 - PCIX Outbound Window Base Address Register 2 */
	__85xx_r32	powbear2;	/* 0x8c4c - PCIX Outbound Window Base Extended Address Register 2 */
	__85xx_r32	powar2;		/* 0x8c50 - PCIX Outbound Window Attributes Register 2 */
	__85xx_r8	res4[12];
	__85xx_r32	potar3;		/* 0x8c60 - PCIX Outbound Transaction Address Register 3 */
	__85xx_r32	potear3;	/* 0x8c64 - PCIX Outbound Translation Extended Address Register 3 */
	__85xx_r32	powbar3;	/* 0x8c68 - PCIX Outbound Window Base Address Register 3 */
	__85xx_r32	powbear3;	/* 0x8c6c - PCIX Outbound Window Base Extended Address Register 3 */
	__85xx_r32	powar3;		/* 0x8c70 - PCIX Outbound Window Attributes Register 3 */
	__85xx_r8	res5[12];
	__85xx_r32	potar4;		/* 0x8c80 - PCIX Outbound Transaction Address Register 4 */
	__85xx_r32	potear4;	/* 0x8c84 - PCIX Outbound Translation Extended Address Register 4 */
	__85xx_r32	powbar4;	/* 0x8c88 - PCIX Outbound Window Base Address Register 4 */
	__85xx_r32	powbear4;	/* 0x8c8c - PCIX Outbound Window Base Extended Address Register 4 */
	__85xx_r32	powar4;		/* 0x8c90 - PCIX Outbound Window Attributes Register 4 */
	__85xx_r8	res6[268];
	__85xx_r32	pitar3;		/* 0x8da0 - PCIX Inbound Translation Address Register 3  */
	__85xx_r32	pitear3;	/* 0x8da4 - PCIX Inbound Translation Extended Address Register 3 */
	__85xx_r32	piwbar3;	/* 0x8da8 - PCIX Inbound Window Base Address Register 3 */
	__85xx_r32	piwbear3;	/* 0x8dac - PCIX Inbound Window Base Extended Address Register 3 */
	__85xx_r32	piwar3;		/* 0x8db0 - PCIX Inbound Window Attributes Register 3 */
	__85xx_r8	res7[12];
	__85xx_r32	pitar2;		/* 0x8dc0 - PCIX Inbound Translation Address Register 2  */
	__85xx_r32	pitear2;	/* 0x8dc4 - PCIX Inbound Translation Extended Address Register 2 */
	__85xx_r32	piwbar2;	/* 0x8dc8 - PCIX Inbound Window Base Address Register 2 */
	__85xx_r32	piwbear2;	/* 0x8dcc - PCIX Inbound Window Base Extended Address Register 2 */
	__85xx_r32	piwar2;		/* 0x8dd0 - PCIX Inbound Window Attributes Register 2 */
	__85xx_r8	res8[12];
	__85xx_r32	pitar1;		/* 0x8de0 - PCIX Inbound Translation Address Register 1  */
	__85xx_r32	pitear1;	/* 0x8de4 - PCIX Inbound Translation Extended Address Register 1 */
	__85xx_r32	piwbar1;	/* 0x8de8 - PCIX Inbound Window Base Address Register 1 */
	__85xx_r8	res9[4];
	__85xx_r32	piwar1;		/* 0x8df0 - PCIX Inbound Window Attributes Register 1 */
	__85xx_r8	res10[12];
	__85xx_r32	pedr;		/* 0x8e00 - PCIX Error Detect Register */
#define MPC85XX_PEDR_MULTERR	0x80000000		/* multiple errors */
#define MPC85XX_PEDR_ADDRPAR	0x00000400		/* address parity error */
#define MPC85XX_PEDR_RCVSERR	0x00000200		/* received SERR */
#define MPC85XX_PEDR_MSTPERR	0x00000100		/* master PERR */
#define MPC85XX_PEDR_TGTPERR	0x00000080		/* target PERR */
#define MPC85XX_PEDR_MSTAB		0x00000040		/* master abort */
#define MPC85XX_PEDR_TGTAB		0x00000020		/* target abort */
#define MPC85XX_PEDR_OWMSV		0x00000010		/* OWMSV error */
#define MPC85XX_PEDR_ORMSV		0x00000008		/* ORMSV error */
#define MPC85XX_PEDR_IRMSV		0x00000004		/* IRMSV error */
#define MPC85XX_PEDR_SCM		0x00000002		/* split completion message error */
#define MPC85XX_PEDR_TOE		0x00000001		/* time-out error */
	__85xx_r32	pecdr;		/* 0x8e04 - PCIX Error Capture Disable Register */
	__85xx_r32	peer;		/* 0x8e08 - PCIX Error Enable Register */
	__85xx_r32	peattrcr;	/* 0x8e0c - PCIX Error Attributes Capture Register */
	__85xx_r32	peaddrcr;	/* 0x8e10 - PCIX Error Address Capture Register */
	__85xx_r32	peextaddrcr;	/* 0x8e14 - PCIX  Error Extended Address Capture Register */
	__85xx_r32	pedlcr;		/* 0x8e18 - PCIX Error Data Low Capture Register */
	__85xx_r32	pedhcr;		/* 0x8e1c - PCIX Error Error Data High Capture Register */
	__85xx_r8	res11[480];
} MPC85XX_PCIX_T;


/* PCI2 Registers(0x9000-0xA000) */
/* Omitting Reserved(0xA000-0x2_0000) */

typedef struct MPC85XX_PCI2 {
	__85xx_r32	cfg_addr;	/* 0x9000 - PCI2 Configuration Address Register */
	__85xx_r32	cfg_data;	/* 0x9004 - PCI2 Configuration Data Register */
	__85xx_r32	int_ack;	/* 0x9008 - PCI2 Interrupt Acknowledge Register */
	__85xx_r8	res1[3060];
	__85xx_r32	potar0;		/* 0x9c00 - PCI2 Outbound Transaction Address Register 0 */
	__85xx_r32	potear0;	/* 0x9c04 - PCI2 Outbound Translation Extended Address Register 0 */
	__85xx_r32	powbar0;	/* 0x9c08 - PCI2 Outbound Window Base Address Register 0 */
	__85xx_r32	powbear0;	/* 0x9c0c - PCI2 Outbound Window Base Extended Address Register 0 */
	__85xx_r32	powar0;		/* 0x9c10 - PCI2 Outbound Window Attributes Register 0 */
	__85xx_r8	res2[12];
	__85xx_r32	potar1;		/* 0x9c20 - PCI2 Outbound Transaction Address Register 1 */
	__85xx_r32	potear1;	/* 0x9c24 - PCI2 Outbound Translation Extended Address Register 1 */
	__85xx_r32	powbar1;	/* 0x9c28 - PCI2 Outbound Window Base Address Register 1 */
	__85xx_r32	powbear1;	/* 0x9c2c - PCI2 Outbound Window Base Extended Address Register 1 */
	__85xx_r32	powar1;		/* 0x9c30 - PCI2 Outbound Window Attributes Register 1 */
	__85xx_r8	res3[12];
	__85xx_r32	potar2;		/* 0x9c40 - PCI2 Outbound Transaction Address Register 2 */
	__85xx_r32	potear2;	/* 0x9c44 - PCI2 Outbound Translation Extended Address Register 2 */
	__85xx_r32	powbar2;	/* 0x9c48 - PCI2 Outbound Window Base Address Register 2 */
	__85xx_r32	powbear2;	/* 0x9c4c - PCI2 Outbound Window Base Extended Address Register 2 */
	__85xx_r32	powar2;		/* 0x9c50 - PCI2 Outbound Window Attributes Register 2 */
	__85xx_r8	res4[12];
	__85xx_r32	potar3;		/* 0x9c60 - PCI2 Outbound Transaction Address Register 3 */
	__85xx_r32	potear3;	/* 0x9c64 - PCI2 Outbound Translation Extended Address Register 3 */
	__85xx_r32	powbar3;	/* 0x9c68 - PCI2 Outbound Window Base Address Register 3 */
	__85xx_r32	powbear3;	/* 0x9c6c - PCI2 Outbound Window Base Extended Address Register 3 */
	__85xx_r32	powar3;		/* 0x9c70 - PCI2 Outbound Window Attributes Register 3 */
	__85xx_r8	res5[12];
	__85xx_r32	potar4;		/* 0x9c80 - PCI2 Outbound Transaction Address Register 4 */
	__85xx_r32	potear4;	/* 0x9c84 - PCI2 Outbound Translation Extended Address Register 4 */
	__85xx_r32	powbar4;	/* 0x9c88 - PCI2 Outbound Window Base Address Register 4 */
	__85xx_r32	powbear4;	/* 0x9c8c - PCI2 Outbound Window Base Extended Address Register 4 */
	__85xx_r32	powar4;		/* 0x9c90 - PCI2 Outbound Window Attributes Register 4 */
	__85xx_r8	res6[268];
	__85xx_r32	pitar3;		/* 0x9da0 - PCI2 Inbound Translation Address Register 3  */
	__85xx_r32	pitear3;	/* 0x9da4 - PCI2 Inbound Translation Extended Address Register 3 */
	__85xx_r32	piwbar3;	/* 0x9da8 - PCI2 Inbound Window Base Address Register 3 */
	__85xx_r32	piwbear3;	/* 0x9dac - PCI2 Inbound Window Base Extended Address Register 3 */
	__85xx_r32	piwar3;		/* 0x9db0 - PCI2 Inbound Window Attributes Register 3 */
	__85xx_r8	res7[12];
	__85xx_r32	pitar2;		/* 0x9dc0 - PCI2 Inbound Translation Address Register 2  */
	__85xx_r32	pitear2;	/* 0x9dc4 - PCI2 Inbound Translation Extended Address Register 2 */
	__85xx_r32	piwbar2;	/* 0x9dc8 - PCI2 Inbound Window Base Address Register 2 */
	__85xx_r32	piwbear2;	/* 0x9dcc - PCI2 Inbound Window Base Extended Address Register 2 */
	__85xx_r32	piwar2;		/* 0x9dd0 - PCI2 Inbound Window Attributes Register 2 */
	__85xx_r8	res8[12];
	__85xx_r32	pitar1;		/* 0x9de0 - PCI2 Inbound Translation Address Register 1  */
	__85xx_r32	pitear1;	/* 0x9de4 - PCI2 Inbound Translation Extended Address Register 1 */
	__85xx_r32	piwbar1;	/* 0x9de8 - PCI2 Inbound Window Base Address Register 1 */
	__85xx_r8	res9[4];
	__85xx_r32	piwar1;		/* 0x9df0 - PCI2 Inbound Window Attributes Register 1 */
	__85xx_r8	res10[12];
	__85xx_r32	pedr;		/* 0x9e00 - PCI2 Error Detect Register */
	__85xx_r32	pecdr;		/* 0x9e04 - PCI2 Error Capture Disable Register */
	__85xx_r32	peer;		/* 0x9e08 - PCI2 Error Enable Register */
	__85xx_r32	peattrcr;	/* 0x9e0c - PCI2 Error Attributes Capture Register */
	__85xx_r32	peaddrcr;	/* 0x9e10 - PCI2 Error Address Capture Register */
	__85xx_r32	peextaddrcr;	/* 0x9e14 - PCI2  Error Extended Address Capture Register */
	__85xx_r32	pedlcr;		/* 0x9e18 - PCI2 Error Data Low Capture Register */
	__85xx_r32	pedhcr;		/* 0x9e1c - PCI2 Error Error Data High Capture Register */
	__85xx_r8	res11[90592];
} MPC85XX_PCI2_T;

/* L2 Cache Registers(0x2_0000-0x2_1000) */

typedef struct MPC85XX_L2CACHE {
	__85xx_r32	l2ctl;		/* 0x20000 - L2 configuration register 0 */
	__85xx_r8	res1[12];
	__85xx_r32	l2cewar0;	/* 0x20010 - L2 cache external write address register 0 */
	__85xx_r8	res2[4];
	__85xx_r32	l2cewcr0;	/* 0x20018 - L2 cache external write control register 0 */
	__85xx_r8	res3[4];
	__85xx_r32	l2cewar1;	/* 0x20020 - L2 cache external write address register 1 */
	__85xx_r8	res4[4];
	__85xx_r32	l2cewcr1;	/* 0x20028 - L2 cache external write control register 1 */
	__85xx_r8	res5[4];
	__85xx_r32	l2cewar2;	/* 0x20030 - L2 cache external write address register 2 */
	__85xx_r8	res6[4];
	__85xx_r32	l2cewcr2;	/* 0x20038 - L2 cache external write control register 2 */
	__85xx_r8	res7[4];
	__85xx_r32	l2cewar3;	/* 0x20040 - L2 cache external write address register 3 */
	__85xx_r8	res8[4];
	__85xx_r32	l2cewcr3;	/* 0x20048 - L2 cache external write control register 3 */
	__85xx_r8	res9[180];
	__85xx_r32	l2srbar0;	/* 0x20100 - L2 memory-mapped SRAM base address register 0 */
	__85xx_r8	res10[4];
	__85xx_r32	l2srbar1;	/* 0x20108 - L2 memory-mapped SRAM base address register 1 */
	__85xx_r8	res11[3316];
	__85xx_r32	l2errinjhi;	/* 0x20e00 - L2 error injection mask high register */
	__85xx_r32	l2errinjlo;	/* 0x20e04 - L2 error injection mask low register */
	__85xx_r32	l2errinjctl;	/* 0x20e08 - L2 error injection tag/ECC control register */
	__85xx_r8	res12[20];
	__85xx_r32	l2captdatahi;	/* 0x20e20 - L2 error data high capture register */
	__85xx_r32	l2captdatalo;	/* 0x20e24 - L2 error data low capture register */
	__85xx_r32	l2captecc;	/* 0x20e28 - L2 error ECC capture register */
	__85xx_r8	res13[20];
	__85xx_r32	l2errdet;	/* 0x20e40 - L2 error detect register */
	__85xx_r32	l2errdis;	/* 0x20e44 - L2 error disable register */
	__85xx_r32	l2errinten;	/* 0x20e48 - L2 error interrupt enable register */
	__85xx_r32	l2errattr;	/* 0x20e4c - L2 error attributes capture register */
	__85xx_r32	l2erraddr;	/* 0x20e50 - L2 error address capture register */
	__85xx_r8	res14[4];
	__85xx_r32	l2errctl;	/* 0x20e58 - L2 error control register */
	__85xx_r8	res15[420];
} MPC85XX_L2CACHE_T;


/* DMA Registers(0x2_1000-0x2_2000) */

typedef struct MPC85XX_DMA {
	__85xx_r8	res1[256];
	__85xx_r32	mr0;		/* 0x21100 - DMA 0 Mode Register */
	__85xx_r32	sr0;		/* 0x21104 - DMA 0 Status Register */
	__85xx_r8	res2[4];
	__85xx_r32	clndar0;	/* 0x2110c - DMA 0 Current Link Descriptor Address Register */
	__85xx_r32	satr0;		/* 0x21110 - DMA 0 Source Attributes Register */
	__85xx_r32	sar0;		/* 0x21114 - DMA 0 Source Address Register */
	__85xx_r32	datr0;		/* 0x21118 - DMA 0 Destination Attributes Register */
	__85xx_r32	dar0;		/* 0x2111c - DMA 0 Destination Address Register */
	__85xx_r32	bcr0;		/* 0x21120 - DMA 0 Byte Count Register */
	__85xx_r8	res3[4];
	__85xx_r32	nlndar0;	/* 0x21128 - DMA 0 Next Link Descriptor Address Register */
	__85xx_r8	res4[8];
	__85xx_r32	clabdar0;	/* 0x21134 - DMA 0 Current List - Alternate Base Descriptor Address Register */
	__85xx_r8	res5[4];
	__85xx_r32	nlsdar0;	/* 0x2113c - DMA 0 Next List Descriptor Address Register */
	__85xx_r32	ssr0;		/* 0x21140 - DMA 0 Source Stride Register */
	__85xx_r32	dsr0;		/* 0x21144 - DMA 0 Destination Stride Register */
	__85xx_r8	res6[56];
	__85xx_r32	mr1;		/* 0x21180 - DMA 1 Mode Register */
	__85xx_r32	sr1;		/* 0x21184 - DMA 1 Status Register */
	__85xx_r8	res7[4];
	__85xx_r32	clndar1;	/* 0x2118c - DMA 1 Current Link Descriptor Address Register */
	__85xx_r32	satr1;		/* 0x21190 - DMA 1 Source Attributes Register */
	__85xx_r32	sar1;		/* 0x21194 - DMA 1 Source Address Register */
	__85xx_r32	datr1;		/* 0x21198 - DMA 1 Destination Attributes Register */
	__85xx_r32	dar1;		/* 0x2119c - DMA 1 Destination Address Register */
	__85xx_r32	bcr1;		/* 0x211a0 - DMA 1 Byte Count Register */
	__85xx_r8	res8[4];
	__85xx_r32	nlndar1;	/* 0x211a8 - DMA 1 Next Link Descriptor Address Register */
	__85xx_r8	res9[8];
	__85xx_r32	clabdar1;	/* 0x211b4 - DMA 1 Current List - Alternate Base Descriptor Address Register */
	__85xx_r8	res10[4];
	__85xx_r32	nlsdar1;	/* 0x211bc - DMA 1 Next List Descriptor Address Register */
	__85xx_r32	ssr1;		/* 0x211c0 - DMA 1 Source Stride Register */
	__85xx_r32	dsr1;		/* 0x211c4 - DMA 1 Destination Stride Register */
	__85xx_r8	res11[56];
	__85xx_r32	mr2;		/* 0x21200 - DMA 2 Mode Register */
	__85xx_r32	sr2;		/* 0x21204 - DMA 2 Status Register */
	__85xx_r8	res12[4];
	__85xx_r32	clndar2;	/* 0x2120c - DMA 2 Current Link Descriptor Address Register */
	__85xx_r32	satr2;		/* 0x21210 - DMA 2 Source Attributes Register */
	__85xx_r32	sar2;		/* 0x21214 - DMA 2 Source Address Register */
	__85xx_r32	datr2;		/* 0x21218 - DMA 2 Destination Attributes Register */
	__85xx_r32	dar2;		/* 0x2121c - DMA 2 Destination Address Register */
	__85xx_r32	bcr2;		/* 0x21220 - DMA 2 Byte Count Register */
	__85xx_r8	res13[4];
	__85xx_r32	nlndar2;	/* 0x21228 - DMA 2 Next Link Descriptor Address Register */
	__85xx_r8	res14[8];
	__85xx_r32	clabdar2;	/* 0x21234 - DMA 2 Current List - Alternate Base Descriptor Address Register */
	__85xx_r8	res15[4];
	__85xx_r32	nlsdar2;	/* 0x2123c - DMA 2 Next List Descriptor Address Register */
	__85xx_r32	ssr2;		/* 0x21240 - DMA 2 Source Stride Register */
	__85xx_r32	dsr2;		/* 0x21244 - DMA 2 Destination Stride Register */
	__85xx_r8	res16[56];
	__85xx_r32	mr3;		/* 0x21280 - DMA 3 Mode Register */
	__85xx_r32	sr3;		/* 0x21284 - DMA 3 Status Register */
	__85xx_r8	res17[4];
	__85xx_r32	clndar3;	/* 0x2128c - DMA 3 Current Link Descriptor Address Register */
	__85xx_r32	satr3;		/* 0x21290 - DMA 3 Source Attributes Register */
	__85xx_r32	sar3;		/* 0x21294 - DMA 3 Source Address Register */
	__85xx_r32	datr3;		/* 0x21298 - DMA 3 Destination Attributes Register */
	__85xx_r32	dar3;		/* 0x2129c - DMA 3 Destination Address Register */
	__85xx_r32	bcr3;		/* 0x212a0 - DMA 3 Byte Count Register */
	__85xx_r8	res18[4];
	__85xx_r32	nlndar3;	/* 0x212a8 - DMA 3 Next Link Descriptor Address Register */
	__85xx_r8	res19[8];
	__85xx_r32	clabdar3;	/* 0x212b4 - DMA 3 Current List - Alternate Base Descriptor Address Register */
	__85xx_r8	res20[4];
	__85xx_r32	nlsdar3;	/* 0x212bc - DMA 3 Next List Descriptor Address Register */
	__85xx_r32	ssr3;		/* 0x212c0 - DMA 3 Source Stride Register */
	__85xx_r32	dsr3;		/* 0x212c4 - DMA 3 Destination Stride Register */
	__85xx_r8	res21[56];
	__85xx_r32	dgsr;		/* 0x21300 - DMA General Status Register */
	__85xx_r8	res22[11516];
} MPC85XX_DMA_T;

/* tsec1 tsec2: 24000-26000 */
typedef struct MPC85XX_TSEC {
	__85xx_r8	res1[16];
	__85xx_r32	ievent;		/* 0x24010 - Interrupt Event Register */
	__85xx_r32	imask;		/* 0x24014 - Interrupt Mask Register */
	__85xx_r32	edis;		/* 0x24018 - Error Disabled Register */
	__85xx_r8	res2[4];
	__85xx_r32	ecntrl;		/* 0x24020 - Ethernet Control Register */
	__85xx_r32	minflr;		/* 0x24024 - Minimum Frame Length Register */
	__85xx_r32	ptv;		/* 0x24028 - Pause Time Value Register */
	__85xx_r32	dmactrl;	/* 0x2402c - DMA Control Register */
	__85xx_r32	tbipa;		/* 0x24030 - TBI PHY Address Register */
	__85xx_r8	res3[88];
	__85xx_r32	fifo_tx_thr;		/* 0x2408c - FIFO transmit threshold register */
	__85xx_r8	res4[4];
	__85xx_r32	fifo_tx_thold_dbg;	/* 0x24094 - TSEC18 workaround register */
	__85xx_r32	fifo_tx_starve;		/* 0x24098 - FIFO transmit starve register */
	__85xx_r32	fifo_tx_starve_shutoff;		/* 0x2409c - FIFO transmit starve shutoff register */
	__85xx_r8	res5[96];
	__85xx_r32	tctrl;		/* 0x24100 - Transmit Control Register */
	__85xx_r32	tstat;		/* 0x24104 - Transmit Status Register */
	__85xx_r8	res6[4];
	__85xx_r32	tbdlen;		/* 0x2410c - Transmit Buffer Descriptor Data Length Register */
	__85xx_r8	res7[16];
	__85xx_r32	ctbptrh;	/* 0x24120 - Current Transmit Buffer Descriptor Pointer High Register */
	__85xx_r32	ctbptr;		/* 0x24124 - Current Transmit Buffer Descriptor Pointer Register */
	__85xx_r8	res8[88];
	__85xx_r32	tbptrh;		/* 0x24180 - Transmit Buffer Descriptor Pointer High Register */
	__85xx_r32	tbptr;		/* 0x24184 - Transmit Buffer Descriptor Pointer Low Register */
	__85xx_r8	res9[120];
	__85xx_r32	tbaseh;		/* 0x24200 - Transmit Descriptor Base Address High Register */
	__85xx_r32	tbase;		/* 0x24204 - Transmit Descriptor Base Address Register */
	__85xx_r8	res10[168];
	__85xx_r32	ostbd;		/* 0x242b0 - Out-of-Sequence Transmit Buffer Descriptor Register */
	__85xx_r32	ostbdp;		/* 0x242b4 - Out-of-Sequence Transmit Data Buffer Pointer Register */
	__85xx_r32	os32tbdp;	/* 0x242b8 - Out-of-Sequence 32 Bytes Transmit Data Buffer Pointer Low Register */
	__85xx_r32	os32iptrh;	/* 0x242bc - Out-of-Sequence 32 Bytes Transmit Insert Pointer High Register */
	__85xx_r32	os32iptrl;	/* 0x242c0 - Out-of-Sequence 32 Bytes Transmit Insert Pointer Low Register */
	__85xx_r32	os32tbdr;	/* 0x242c4 - Out-of-Sequence 32 Bytes Transmit Reserved Register */
	__85xx_r32	os32iil;	/* 0x242c8 - Out-of-Sequence 32 Bytes Transmit Insert Index/Length Register */
	__85xx_r8	res11[52];
	__85xx_r32	rctrl;		/* 0x24300 - Receive Control Register */
	__85xx_r32	rstat;		/* 0x24304 - Receive Status Register */
	__85xx_r8	res12[4];
	__85xx_r32	rbdlen;		/* 0x2430c - RxBD Data Length Register */
	__85xx_r8	res13[16];
	__85xx_r32	crbptrh;	/* 0x24320 - Current Receive Buffer Descriptor Pointer High */
	__85xx_r32	crbptr;		/* 0x24324 - Current Receive Buffer Descriptor Pointer */
	__85xx_r8	res14[24];
	__85xx_r32	mrblr;		/* 0x24340 - Maximum Receive Buffer Length Register */
	__85xx_r32	mrblr2r3;	/* 0x24344 - Maximum Receive Buffer Length R2R3 Register */
	__85xx_r8	res15[56];
	__85xx_r32	rbptrh;		/* 0x24380 - Receive Buffer Descriptor Pointer High 0 */
	__85xx_r32	rbptr;		/* 0x24384 - Receive Buffer Descriptor Pointer */
	__85xx_r32	rbptrh1;	/* 0x24388 - Receive Buffer Descriptor Pointer High 1 */
	__85xx_r32	rbptrl1;	/* 0x2438c - Receive Buffer Descriptor Pointer Low 1 */
	__85xx_r32	rbptrh2;	/* 0x24390 - Receive Buffer Descriptor Pointer High 2 */
	__85xx_r32	rbptrl2;	/* 0x24394 - Receive Buffer Descriptor Pointer Low 2 */
	__85xx_r32	rbptrh3;	/* 0x24398 - Receive Buffer Descriptor Pointer High 3 */
	__85xx_r32	rbptrl3;	/* 0x2439c - Receive Buffer Descriptor Pointer Low 3 */
	__85xx_r8	res16[96];
	__85xx_r32	rbaseh;		/* 0x24400 - Receive Descriptor Base Address High 0 */
	__85xx_r32	rbase;		/* 0x24404 - Receive Descriptor Base Address */
	__85xx_r32	rbaseh1;	/* 0x24408 - Receive Descriptor Base Address High 1 */
	__85xx_r32	rbasel1;	/* 0x2440c - Receive Descriptor Base Address Low 1 */
	__85xx_r32	rbaseh2;	/* 0x24410 - Receive Descriptor Base Address High 2 */
	__85xx_r32	rbasel2;	/* 0x24414 - Receive Descriptor Base Address Low 2 */
	__85xx_r32	rbaseh3;	/* 0x24418 - Receive Descriptor Base Address High 3 */
	__85xx_r32	rbasel3;	/* 0x2441c - Receive Descriptor Base Address Low 3 */
	__85xx_r8	res17[224];
	__85xx_r32	maccfg1;	/* 0x24500 - MAC Configuration 1 Register */
	__85xx_r32	maccfg2;	/* 0x24504 - MAC Configuration 2 Register */
	__85xx_r32	ipgifg;		/* 0x24508 - Inter Packet Gap/Inter Frame Gap Register */
	__85xx_r32	hafdup;		/* 0x2450c - Half Duplex Register */
	__85xx_r32	maxfrm;		/* 0x24510 - Maximum Frame Length Register */
	__85xx_r8	res18[12];
	__85xx_r32	miimcfg;	/* 0x24520 - MII Management Configuration Register */
	__85xx_r32	miimcom;	/* 0x24524 - MII Management Command Register */
	__85xx_r32	miimadd;	/* 0x24528 - MII Management Address Register */
	__85xx_r32	miimcon;	/* 0x2452c - MII Management Control Register */
	__85xx_r32	miimstat;	/* 0x24530 - MII Management Status Register */
	__85xx_r32	miimind;	/* 0x24534 - MII Management Indicator Register */
	__85xx_r8	res19[4];
	__85xx_r32	ifstat;		/* 0x2453c - Interface Status Register */
	__85xx_r32	macstnaddr1;	/* 0x24540 - Station Address Part 1 Register */
	__85xx_r32	macstnaddr2;	/* 0x24544 - Station Address Part 2 Register */
	__85xx_r8	res20[312];
	__85xx_r32	tr64;		/* 0x24680 - Transmit and Receive 64-byte Frame Counter */
	__85xx_r32	tr127;		/* 0x24684 - Transmit and Receive 65-127 byte Frame Counter */
	__85xx_r32	tr255;		/* 0x24688 - Transmit and Receive 128-255 byte Frame Counter */
	__85xx_r32	tr511;		/* 0x2468c - Transmit and Receive 256-511 byte Frame Counter */
	__85xx_r32	tr1k;		/* 0x24690 - Transmit and Receive 512-1023 byte Frame Counter */
	__85xx_r32	trmax;		/* 0x24694 - Transmit and Receive 1024-1518 byte Frame Counter */
	__85xx_r32	trmgv;		/* 0x24698 - Transmit and Receive 1519-1522 byte Good VLAN Frame */
	__85xx_r32	rbyt;		/* 0x2469c - Receive Byte Counter */
	__85xx_r32	rpkt;		/* 0x246a0 - Receive Packet Counter */
	__85xx_r32	rfcs;		/* 0x246a4 - Receive FCS Error Counter */
	__85xx_r32	rmca;		/* 0x246a8 - Receive Multicast Packet Counter */
	__85xx_r32	rbca;		/* 0x246ac - Receive Broadcast Packet Counter */
	__85xx_r32	rxcf;		/* 0x246b0 - Receive Control Frame Packet Counter */
	__85xx_r32	rxpf;		/* 0x246b4 - Receive Pause Frame Packet Counter */
	__85xx_r32	rxuo;		/* 0x246b8 - Receive Unknown OP Code Counter */
	__85xx_r32	raln;		/* 0x246bc - Receive Alignment Error Counter */
	__85xx_r32	rflr;		/* 0x246c0 - Receive Frame Length Error Counter */
	__85xx_r32	rcde;		/* 0x246c4 - Receive Code Error Counter */
	__85xx_r32	rcse;		/* 0x246c8 - Receive Carrier Sense Error Counter */
	__85xx_r32	rund;		/* 0x246cc - Receive Undersize Packet Counter */
	__85xx_r32	rovr;		/* 0x246d0 - Receive Oversize Packet Counter */
	__85xx_r32	rfrg;		/* 0x246d4 - Receive Fragments Counter */
	__85xx_r32	rjbr;		/* 0x246d8 - Receive Jabber Counter */
	__85xx_r32	rdrp;		/* 0x246dc - Receive Drop Counter */
	__85xx_r32	tbyt;		/* 0x246e0 - Transmit Byte Counter Counter */
	__85xx_r32	tpkt;		/* 0x246e4 - Transmit Packet Counter */
	__85xx_r32	tmca;		/* 0x246e8 - Transmit Multicast Packet Counter */
	__85xx_r32	tbca;		/* 0x246ec - Transmit Broadcast Packet Counter */
	__85xx_r32	txpf;		/* 0x246f0 - Transmit Pause Control Frame Counter */
	__85xx_r32	tdfr;		/* 0x246f4 - Transmit Deferral Packet Counter */
	__85xx_r32	tedf;		/* 0x246f8 - Transmit Excessive Deferral Packet Counter */
	__85xx_r32	tscl;		/* 0x246fc - Transmit Single Collision Packet Counter */
	__85xx_r32	tmcl;		/* 0x24700 - Transmit Multiple Collision Packet Counter */
	__85xx_r32	tlcl;		/* 0x24704 - Transmit Late Collision Packet Counter */
	__85xx_r32	txcl;		/* 0x24708 - Transmit Excessive Collision Packet Counter */
	__85xx_r32	tncl;		/* 0x2470c - Transmit Total Collision Counter */
	__85xx_r8	res21[4];
	__85xx_r32	tdrp;		/* 0x24714 - Transmit Drop Frame Counter */
	__85xx_r32	tjbr;		/* 0x24718 - Transmit Jabber Frame Counter */
	__85xx_r32	tfcs;		/* 0x2471c - Transmit FCS Error Counter */
	__85xx_r32	txcf;		/* 0x24720 - Transmit Control Frame Counter */
	__85xx_r32	tovr;		/* 0x24724 - Transmit Oversize Frame Counter */
	__85xx_r32	tund;		/* 0x24728 - Transmit Undersize Frame Counter */
	__85xx_r32	tfrg;		/* 0x2472c - Transmit Fragments Frame Counter */
	__85xx_r32	car1;		/* 0x24730 - Carry Register One */
	__85xx_r32	car2;		/* 0x24734 - Carry Register Two */
	__85xx_r32	cam1;		/* 0x24738 - Carry Mask Register One */
	__85xx_r32	cam2;		/* 0x2473c - Carry Mask Register Two */
	__85xx_r8	res22[192];
	__85xx_r32	iaddr0;		/* 0x24800 - Indivdual address register 0 */
	__85xx_r32	iaddr1;		/* 0x24804 - Indivdual address register 1 */
	__85xx_r32	iaddr2;		/* 0x24808 - Indivdual address register 2 */
	__85xx_r32	iaddr3;		/* 0x2480c - Indivdual address register 3 */
	__85xx_r32	iaddr4;		/* 0x24810 - Indivdual address register 4 */
	__85xx_r32	iaddr5;		/* 0x24814 - Indivdual address register 5 */
	__85xx_r32	iaddr6;		/* 0x24818 - Indivdual address register 6 */
	__85xx_r32	iaddr7;		/* 0x2481c - Indivdual address register 7 */
	__85xx_r8	res23[96];
	__85xx_r32	gaddr0;		/* 0x24880 - Global address register 0 */
	__85xx_r32	gaddr1;		/* 0x24884 - Global address register 1 */
	__85xx_r32	gaddr2;		/* 0x24888 - Global address register 2 */
	__85xx_r32	gaddr3;		/* 0x2488c - Global address register 3 */
	__85xx_r32	gaddr4;		/* 0x24890 - Global address register 4 */
	__85xx_r32	gaddr5;		/* 0x24894 - Global address register 5 */
	__85xx_r32	gaddr6;		/* 0x24898 - Global address register 6 */
	__85xx_r32	gaddr7;		/* 0x2489c - Global address register 7 */
	__85xx_r8	res24[96];
	__85xx_r32	pmd0;		/* 0x24900 - Pattern Match Data Register */
	__85xx_r8	res25[4];
	__85xx_r32	pmask0;		/* 0x24908 - Pattern Mask Register */
	__85xx_r8	res26[4];
	__85xx_r32	pcntrl0;	/* 0x24910 - Pattern Match Control Register */
	__85xx_r8	res27[4];
	__85xx_r32	pattrb0;	/* 0x24918 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli0;	/* 0x2491c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd1;		/* 0x24920 - Pattern Match Data Register */
	__85xx_r8	res28[4];
	__85xx_r32	pmask1;		/* 0x24928 - Pattern Mask Register */
	__85xx_r8	res29[4];
	__85xx_r32	pcntrl1;	/* 0x24930 - Pattern Match Control Register */
	__85xx_r8	res30[4];
	__85xx_r32	pattrb1;	/* 0x24938 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli1;	/* 0x2493c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd2;		/* 0x24940 - Pattern Match Data Register */
	__85xx_r8	res31[4];
	__85xx_r32	pmask2;		/* 0x24948 - Pattern Mask Register */
	__85xx_r8	res32[4];
	__85xx_r32	pcntrl2;	/* 0x24950 - Pattern Match Control Register */
	__85xx_r8	res33[4];
	__85xx_r32	pattrb2;	/* 0x24958 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli2;	/* 0x2495c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd3;		/* 0x24960 - Pattern Match Data Register */
	__85xx_r8	res34[4];
	__85xx_r32	pmask3;		/* 0x24968 - Pattern Mask Register */
	__85xx_r8	res35[4];
	__85xx_r32	pcntrl3;	/* 0x24970 - Pattern Match Control Register */
	__85xx_r8	res36[4];
	__85xx_r32	pattrb3;	/* 0x24978 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli3;	/* 0x2497c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd4;		/* 0x24980 - Pattern Match Data Register */
	__85xx_r8	res37[4];
	__85xx_r32	pmask4;		/* 0x24988 - Pattern Mask Register */
	__85xx_r8	res38[4];
	__85xx_r32	pcntrl4;	/* 0x24990 - Pattern Match Control Register */
	__85xx_r8	res39[4];
	__85xx_r32	pattrb4;	/* 0x24998 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli4;	/* 0x2499c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd5;		/* 0x249a0 - Pattern Match Data Register */
	__85xx_r8	res40[4];
	__85xx_r32	pmask5;		/* 0x249a8 - Pattern Mask Register */
	__85xx_r8	res41[4];
	__85xx_r32	pcntrl5;	/* 0x249b0 - Pattern Match Control Register */
	__85xx_r8	res42[4];
	__85xx_r32	pattrb5;	/* 0x249b8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli5;	/* 0x249bc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd6;		/* 0x249c0 - Pattern Match Data Register */
	__85xx_r8	res43[4];
	__85xx_r32	pmask6;		/* 0x249c8 - Pattern Mask Register */
	__85xx_r8	res44[4];
	__85xx_r32	pcntrl6;	/* 0x249d0 - Pattern Match Control Register */
	__85xx_r8	res45[4];
	__85xx_r32	pattrb6;	/* 0x249d8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli6;	/* 0x249dc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd7;		/* 0x249e0 - Pattern Match Data Register */
	__85xx_r8	res46[4];
	__85xx_r32	pmask7;		/* 0x249e8 - Pattern Mask Register */
	__85xx_r8	res47[4];
	__85xx_r32	pcntrl7;	/* 0x249f0 - Pattern Match Control Register */
	__85xx_r8	res48[4];
	__85xx_r32	pattrb7;	/* 0x249f8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli7;	/* 0x249fc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd8;		/* 0x24a00 - Pattern Match Data Register */
	__85xx_r8	res49[4];
	__85xx_r32	pmask8;		/* 0x24a08 - Pattern Mask Register */
	__85xx_r8	res50[4];
	__85xx_r32	pcntrl8;	/* 0x24a10 - Pattern Match Control Register */
	__85xx_r8	res51[4];
	__85xx_r32	pattrb8;	/* 0x24a18 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli8;	/* 0x24a1c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd9;		/* 0x24a20 - Pattern Match Data Register */
	__85xx_r8	res52[4];
	__85xx_r32	pmask9;		/* 0x24a28 - Pattern Mask Register */
	__85xx_r8	res53[4];
	__85xx_r32	pcntrl9;	/* 0x24a30 - Pattern Match Control Register */
	__85xx_r8	res54[4];
	__85xx_r32	pattrb9;	/* 0x24a38 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli9;	/* 0x24a3c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd10;		/* 0x24a40 - Pattern Match Data Register */
	__85xx_r8	res55[4];
	__85xx_r32	pmask10;	/* 0x24a48 - Pattern Mask Register */
	__85xx_r8	res56[4];
	__85xx_r32	pcntrl10;	/* 0x24a50 - Pattern Match Control Register */
	__85xx_r8	res57[4];
	__85xx_r32	pattrb10;	/* 0x24a58 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli10;	/* 0x24a5c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd11;		/* 0x24a60 - Pattern Match Data Register */
	__85xx_r8	res58[4];
	__85xx_r32	pmask11;	/* 0x24a68 - Pattern Mask Register */
	__85xx_r8	res59[4];
	__85xx_r32	pcntrl11;	/* 0x24a70 - Pattern Match Control Register */
	__85xx_r8	res60[4];
	__85xx_r32	pattrb11;	/* 0x24a78 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli11;	/* 0x24a7c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd12;		/* 0x24a80 - Pattern Match Data Register */
	__85xx_r8	res61[4];
	__85xx_r32	pmask12;	/* 0x24a88 - Pattern Mask Register */
	__85xx_r8	res62[4];
	__85xx_r32	pcntrl12;	/* 0x24a90 - Pattern Match Control Register */
	__85xx_r8	res63[4];
	__85xx_r32	pattrb12;	/* 0x24a98 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli12;	/* 0x24a9c - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd13;		/* 0x24aa0 - Pattern Match Data Register */
	__85xx_r8	res64[4];
	__85xx_r32	pmask13;	/* 0x24aa8 - Pattern Mask Register */
	__85xx_r8	res65[4];
	__85xx_r32	pcntrl13;	/* 0x24ab0 - Pattern Match Control Register */
	__85xx_r8	res66[4];
	__85xx_r32	pattrb13;	/* 0x24ab8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli13;	/* 0x24abc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd14;		/* 0x24ac0 - Pattern Match Data Register */
	__85xx_r8	res67[4];
	__85xx_r32	pmask14;	/* 0x24ac8 - Pattern Mask Register */
	__85xx_r8	res68[4];
	__85xx_r32	pcntrl14;	/* 0x24ad0 - Pattern Match Control Register */
	__85xx_r8	res69[4];
	__85xx_r32	pattrb14;	/* 0x24ad8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli14;	/* 0x24adc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r32	pmd15;		/* 0x24ae0 - Pattern Match Data Register */
	__85xx_r8	res70[4];
	__85xx_r32	pmask15;	/* 0x24ae8 - Pattern Mask Register */
	__85xx_r8	res71[4];
	__85xx_r32	pcntrl15;	/* 0x24af0 - Pattern Match Control Register */
	__85xx_r8	res72[4];
	__85xx_r32	pattrb15;	/* 0x24af8 - Pattern Match Attributes Register */
	__85xx_r32	pattrbeli15;	/* 0x24afc - Pattern Match Attributes Extract Length and Extract Index Register */
	__85xx_r8	res73[248];
	__85xx_r32	attr;		/* 0x24bf8 - Attributes Register */
	__85xx_r32	attreli;	/* 0x24bfc - Attributes Extract Length and Extract Index Register */
	__85xx_r8	res74[1024];
} MPC85XX_TSEC_T;

/* PIC Registers(0x2_6000-0x4_0000-0x8_0000) */

typedef struct MPC85XX_PIC {
	__85xx_r8 	res0[106496];	/* 0x26000-0x40000 */
	__85xx_r8	res1[64];
	__85xx_r32	ipidr0;		/* 0x40040 - Interprocessor Interrupt Dispatch Register 0 */
	__85xx_r8	res2[12];
	__85xx_r32	ipidr1;		/* 0x40050 - Interprocessor Interrupt Dispatch Register 1 */
	__85xx_r8	res3[12];
	__85xx_r32	ipidr2;		/* 0x40060 - Interprocessor Interrupt Dispatch Register 2 */
	__85xx_r8	res4[12];
	__85xx_r32	ipidr3;		/* 0x40070 - Interprocessor Interrupt Dispatch Register 3 */
	__85xx_r8	res5[12];
	__85xx_r32	ctpr;		/* 0x40080 - Current Task Priority Register */
	__85xx_r8	res6[12];
	__85xx_r32	whoami;		/* 0x40090 - Who Am I Register */
	__85xx_r8	res7[12];
	__85xx_r32	iack;		/* 0x400a0 - Interrupt Acknowledge Register */
	__85xx_r8	res8[12];
	__85xx_r32	eoi;		/* 0x400b0 - End Of Interrupt Register */
	__85xx_r8	res9[3916];
	__85xx_r32	frr;		/* 0x41000 - Feature Reporting Register */
	__85xx_r8	res10[28];
	__85xx_r32	gcr;		/* 0x41020 - Global Configuration Register */
	__85xx_r8	res11[92];
	__85xx_r32	vir;		/* 0x41080 - Vendor Identification Register */
	__85xx_r8	res12[12];
	__85xx_r32	pir;		/* 0x41090 - Processor Initialization Register */
	__85xx_r8	res13[12];
	__85xx_r32	ipivpr0;	/* 0x410a0 - IPI Vector/Priority Register 0 */
	__85xx_r8	res14[12];
	__85xx_r32	ipivpr1;	/* 0x410b0 - IPI Vector/Priority Register 1 */
	__85xx_r8	res15[12];
	__85xx_r32	ipivpr2;	/* 0x410c0 - IPI Vector/Priority Register 2 */
	__85xx_r8	res16[12];
	__85xx_r32	ipivpr3;	/* 0x410d0 - IPI Vector/Priority Register 3 */
	__85xx_r8	res17[12];
	__85xx_r32	svr;		/* 0x410e0 - Spurious Vector Register */
	__85xx_r8	res18[12];
	__85xx_r32	tfrr;		/* 0x410f0 - Timer Frequency Reporting Register */
	__85xx_r8	res19[12];
	__85xx_r32	gtccr0;		/* 0x41100 - Global Timer Current Count Register 0 */
	__85xx_r8	res20[12];
	__85xx_r32	gtbcr0;		/* 0x41110 - Global Timer Base Count Register 0 */
	__85xx_r8	res21[12];
	__85xx_r32	gtvpr0;		/* 0x41120 - Global Timer Vector/Priority Register 0 */
	__85xx_r8	res22[12];
	__85xx_r32	gtdr0;		/* 0x41130 - Global Timer Destination Register 0 */
	__85xx_r8	res23[12];
	__85xx_r32	gtccr1;		/* 0x41140 - Global Timer Current Count Register 1 */
	__85xx_r8	res24[12];
	__85xx_r32	gtbcr1;		/* 0x41150 - Global Timer Base Count Register 1 */
	__85xx_r8	res25[12];
	__85xx_r32	gtvpr1;		/* 0x41160 - Global Timer Vector/Priority Register 1 */
	__85xx_r8	res26[12];
	__85xx_r32	gtdr1;		/* 0x41170 - Global Timer Destination Register 1 */
	__85xx_r8	res27[12];
	__85xx_r32	gtccr2;		/* 0x41180 - Global Timer Current Count Register 2 */
	__85xx_r8	res28[12];
	__85xx_r32	gtbcr2;		/* 0x41190 - Global Timer Base Count Register 2 */
	__85xx_r8	res29[12];
	__85xx_r32	gtvpr2;		/* 0x411a0 - Global Timer Vector/Priority Register 2 */
	__85xx_r8	res30[12];
	__85xx_r32	gtdr2;		/* 0x411b0 - Global Timer Destination Register 2 */
	__85xx_r8	res31[12];
	__85xx_r32	gtccr3;		/* 0x411c0 - Global Timer Current Count Register 3 */
	__85xx_r8	res32[12];
	__85xx_r32	gtbcr3;		/* 0x411d0 - Global Timer Base Count Register 3 */
	__85xx_r8	res33[12];
	__85xx_r32	gtvpr3;		/* 0x411e0 - Global Timer Vector/Priority Register 3 */
	__85xx_r8	res34[12];
	__85xx_r32	gtdr3;		/* 0x411f0 - Global Timer Destination Register 3 */
	__85xx_r8	res35[268];
	__85xx_r32	tcr;		/* 0x41300 - Timer Control Register */
	__85xx_r8	res36[12];
	__85xx_r32	irqsr0;		/* 0x41310 - IRQ_OUT Summary Register 0 */
	__85xx_r8	res37[12];
	__85xx_r32	irqsr1;		/* 0x41320 - IRQ_OUT Summary Register 1 */
	__85xx_r8	res38[12];
	__85xx_r32	cisr0;		/* 0x41330 - Critical Interrupt Summary Register 0 */
	__85xx_r8	res39[12];
	__85xx_r32	cisr1;		/* 0x41340 - Critical Interrupt Summary Register 1 */
	__85xx_r8	res40[188];
	__85xx_r32	msgr0;		/* 0x41400 - Message Register 0 */
	__85xx_r8	res41[12];
	__85xx_r32	msgr1;		/* 0x41410 - Message Register 1 */
	__85xx_r8	res42[12];
	__85xx_r32	msgr2;		/* 0x41420 - Message Register 2 */
	__85xx_r8	res43[12];
	__85xx_r32	msgr3;		/* 0x41430 - Message Register 3 */
	__85xx_r8	res44[204];
	__85xx_r32	mer;		/* 0x41500 - Message Enable Register */
	__85xx_r8	res45[12];
	__85xx_r32	msr;		/* 0x41510 - Message Status Register */
	__85xx_r8	res46[60140];
	__85xx_r32	eivpr0;		/* 0x50000 - External Interrupt Vector/Priority Register 0 */
	__85xx_r8	res47[12];
	__85xx_r32	eidr0;		/* 0x50010 - External Interrupt Destination Register 0 */
	__85xx_r8	res48[12];
	__85xx_r32	eivpr1;		/* 0x50020 - External Interrupt Vector/Priority Register 1 */
	__85xx_r8	res49[12];
	__85xx_r32	eidr1;		/* 0x50030 - External Interrupt Destination Register 1 */
	__85xx_r8	res50[12];
	__85xx_r32	eivpr2;		/* 0x50040 - External Interrupt Vector/Priority Register 2 */
	__85xx_r8	res51[12];
	__85xx_r32	eidr2;		/* 0x50050 - External Interrupt Destination Register 2 */
	__85xx_r8	res52[12];
	__85xx_r32	eivpr3;		/* 0x50060 - External Interrupt Vector/Priority Register 3 */
	__85xx_r8	res53[12];
	__85xx_r32	eidr3;		/* 0x50070 - External Interrupt Destination Register 3 */
	__85xx_r8	res54[12];
	__85xx_r32	eivpr4;		/* 0x50080 - External Interrupt Vector/Priority Register 4 */
	__85xx_r8	res55[12];
	__85xx_r32	eidr4;		/* 0x50090 - External Interrupt Destination Register 4 */
	__85xx_r8	res56[12];
	__85xx_r32	eivpr5;		/* 0x500a0 - External Interrupt Vector/Priority Register 5 */
	__85xx_r8	res57[12];
	__85xx_r32	eidr5;		/* 0x500b0 - External Interrupt Destination Register 5 */
	__85xx_r8	res58[12];
	__85xx_r32	eivpr6;		/* 0x500c0 - External Interrupt Vector/Priority Register 6 */
	__85xx_r8	res59[12];
	__85xx_r32	eidr6;		/* 0x500d0 - External Interrupt Destination Register 6 */
	__85xx_r8	res60[12];
	__85xx_r32	eivpr7;		/* 0x500e0 - External Interrupt Vector/Priority Register 7 */
	__85xx_r8	res61[12];
	__85xx_r32	eidr7;		/* 0x500f0 - External Interrupt Destination Register 7 */
	__85xx_r8	res62[12];
	__85xx_r32	eivpr8;		/* 0x50100 - External Interrupt Vector/Priority Register 8 */
	__85xx_r8	res63[12];
	__85xx_r32	eidr8;		/* 0x50110 - External Interrupt Destination Register 8 */
	__85xx_r8	res64[12];
	__85xx_r32	eivpr9;		/* 0x50120 - External Interrupt Vector/Priority Register 9 */
	__85xx_r8	res65[12];
	__85xx_r32	eidr9;		/* 0x50130 - External Interrupt Destination Register 9 */
	__85xx_r8	res66[12];
	__85xx_r32	eivpr10;	/* 0x50140 - External Interrupt Vector/Priority Register 10 */
	__85xx_r8	res67[12];
	__85xx_r32	eidr10;		/* 0x50150 - External Interrupt Destination Register 10 */
	__85xx_r8	res68[12];
	__85xx_r32	eivpr11;	/* 0x50160 - External Interrupt Vector/Priority Register 11 */
	__85xx_r8	res69[12];
	__85xx_r32	eidr11;		/* 0x50170 - External Interrupt Destination Register 11 */
	__85xx_r8	res70[140];
	__85xx_r32	iivpr0;		/* 0x50200 - Internal Interrupt Vector/Priority Register 0 */
	__85xx_r8	res71[12];
	__85xx_r32	iidr0;		/* 0x50210 - Internal Interrupt Destination Register 0 */
	__85xx_r8	res72[12];
	__85xx_r32	iivpr1;		/* 0x50220 - Internal Interrupt Vector/Priority Register 1 */
	__85xx_r8	res73[12];
	__85xx_r32	iidr1;		/* 0x50230 - Internal Interrupt Destination Register 1 */
	__85xx_r8	res74[12];
	__85xx_r32	iivpr2;		/* 0x50240 - Internal Interrupt Vector/Priority Register 2 */
	__85xx_r8	res75[12];
	__85xx_r32	iidr2;		/* 0x50250 - Internal Interrupt Destination Register 2 */
	__85xx_r8	res76[12];
	__85xx_r32	iivpr3;		/* 0x50260 - Internal Interrupt Vector/Priority Register 3 */
	__85xx_r8	res77[12];
	__85xx_r32	iidr3;		/* 0x50270 - Internal Interrupt Destination Register 3 */
	__85xx_r8	res78[12];
	__85xx_r32	iivpr4;		/* 0x50280 - Internal Interrupt Vector/Priority Register 4 */
	__85xx_r8	res79[12];
	__85xx_r32	iidr4;		/* 0x50290 - Internal Interrupt Destination Register 4 */
	__85xx_r8	res80[12];
	__85xx_r32	iivpr5;		/* 0x502a0 - Internal Interrupt Vector/Priority Register 5 */
	__85xx_r8	res81[12];
	__85xx_r32	iidr5;		/* 0x502b0 - Internal Interrupt Destination Register 5 */
	__85xx_r8	res82[12];
	__85xx_r32	iivpr6;		/* 0x502c0 - Internal Interrupt Vector/Priority Register 6 */
	__85xx_r8	res83[12];
	__85xx_r32	iidr6;		/* 0x502d0 - Internal Interrupt Destination Register 6 */
	__85xx_r8	res84[12];
	__85xx_r32	iivpr7;		/* 0x502e0 - Internal Interrupt Vector/Priority Register 7 */
	__85xx_r8	res85[12];
	__85xx_r32	iidr7;		/* 0x502f0 - Internal Interrupt Destination Register 7 */
	__85xx_r8	res86[12];
	__85xx_r32	iivpr8;		/* 0x50300 - Internal Interrupt Vector/Priority Register 8 */
	__85xx_r8	res87[12];
	__85xx_r32	iidr8;		/* 0x50310 - Internal Interrupt Destination Register 8 */
	__85xx_r8	res88[12];
	__85xx_r32	iivpr9;		/* 0x50320 - Internal Interrupt Vector/Priority Register 9 */
	__85xx_r8	res89[12];
	__85xx_r32	iidr9;		/* 0x50330 - Internal Interrupt Destination Register 9 */
	__85xx_r8	res90[12];
	__85xx_r32	iivpr10;	/* 0x50340 - Internal Interrupt Vector/Priority Register 10 */
	__85xx_r8	res91[12];
	__85xx_r32	iidr10;		/* 0x50350 - Internal Interrupt Destination Register 10 */
	__85xx_r8	res92[12];
	__85xx_r32	iivpr11;	/* 0x50360 - Internal Interrupt Vector/Priority Register 11 */
	__85xx_r8	res93[12];
	__85xx_r32	iidr11;		/* 0x50370 - Internal Interrupt Destination Register 11 */
	__85xx_r8	res94[12];
	__85xx_r32	iivpr12;	/* 0x50380 - Internal Interrupt Vector/Priority Register 12 */
	__85xx_r8	res95[12];
	__85xx_r32	iidr12;		/* 0x50390 - Internal Interrupt Destination Register 12 */
	__85xx_r8	res96[12];
	__85xx_r32	iivpr13;	/* 0x503a0 - Internal Interrupt Vector/Priority Register 13 */
	__85xx_r8	res97[12];
	__85xx_r32	iidr13;		/* 0x503b0 - Internal Interrupt Destination Register 13 */
	__85xx_r8	res98[12];
	__85xx_r32	iivpr14;	/* 0x503c0 - Internal Interrupt Vector/Priority Register 14 */
	__85xx_r8	res99[12];
	__85xx_r32	iidr14;		/* 0x503d0 - Internal Interrupt Destination Register 14 */
	__85xx_r8	res100[12];
	__85xx_r32	iivpr15;	/* 0x503e0 - Internal Interrupt Vector/Priority Register 15 */
	__85xx_r8	res101[12];
	__85xx_r32	iidr15;		/* 0x503f0 - Internal Interrupt Destination Register 15 */
	__85xx_r8	res102[12];
	__85xx_r32	iivpr16;	/* 0x50400 - Internal Interrupt Vector/Priority Register 16 */
	__85xx_r8	res103[12];
	__85xx_r32	iidr16;		/* 0x50410 - Internal Interrupt Destination Register 16 */
	__85xx_r8	res104[12];
	__85xx_r32	iivpr17;	/* 0x50420 - Internal Interrupt Vector/Priority Register 17 */
	__85xx_r8	res105[12];
	__85xx_r32	iidr17;		/* 0x50430 - Internal Interrupt Destination Register 17 */
	__85xx_r8	res106[12];
	__85xx_r32	iivpr18;	/* 0x50440 - Internal Interrupt Vector/Priority Register 18 */
	__85xx_r8	res107[12];
	__85xx_r32	iidr18;		/* 0x50450 - Internal Interrupt Destination Register 18 */
	__85xx_r8	res108[12];
	__85xx_r32	iivpr19;	/* 0x50460 - Internal Interrupt Vector/Priority Register 19 */
	__85xx_r8	res109[12];
	__85xx_r32	iidr19;		/* 0x50470 - Internal Interrupt Destination Register 19 */
	__85xx_r8	res110[12];
	__85xx_r32	iivpr20;	/* 0x50480 - Internal Interrupt Vector/Priority Register 20 */
	__85xx_r8	res111[12];
	__85xx_r32	iidr20;		/* 0x50490 - Internal Interrupt Destination Register 20 */
	__85xx_r8	res112[12];
	__85xx_r32	iivpr21;	/* 0x504a0 - Internal Interrupt Vector/Priority Register 21 */
	__85xx_r8	res113[12];
	__85xx_r32	iidr21;		/* 0x504b0 - Internal Interrupt Destination Register 21 */
	__85xx_r8	res114[12];
	__85xx_r32	iivpr22;	/* 0x504c0 - Internal Interrupt Vector/Priority Register 22 */
	__85xx_r8	res115[12];
	__85xx_r32	iidr22;		/* 0x504d0 - Internal Interrupt Destination Register 22 */
	__85xx_r8	res116[12];
	__85xx_r32	iivpr23;	/* 0x504e0 - Internal Interrupt Vector/Priority Register 23 */
	__85xx_r8	res117[12];
	__85xx_r32	iidr23;		/* 0x504f0 - Internal Interrupt Destination Register 23 */
	__85xx_r8	res118[12];
	__85xx_r32	iivpr24;	/* 0x50500 - Internal Interrupt Vector/Priority Register 24 */
	__85xx_r8	res119[12];
	__85xx_r32	iidr24;		/* 0x50510 - Internal Interrupt Destination Register 24 */
	__85xx_r8	res120[12];
	__85xx_r32	iivpr25;	/* 0x50520 - Internal Interrupt Vector/Priority Register 25 */
	__85xx_r8	res121[12];
	__85xx_r32	iidr25;		/* 0x50530 - Internal Interrupt Destination Register 25 */
	__85xx_r8	res122[12];
	__85xx_r32	iivpr26;	/* 0x50540 - Internal Interrupt Vector/Priority Register 26 */
	__85xx_r8	res123[12];
	__85xx_r32	iidr26;		/* 0x50550 - Internal Interrupt Destination Register 26 */
	__85xx_r8	res124[12];
	__85xx_r32	iivpr27;	/* 0x50560 - Internal Interrupt Vector/Priority Register 27 */
	__85xx_r8	res125[12];
	__85xx_r32	iidr27;		/* 0x50570 - Internal Interrupt Destination Register 27 */
	__85xx_r8	res126[12];
	__85xx_r32	iivpr28;	/* 0x50580 - Internal Interrupt Vector/Priority Register 28 */
	__85xx_r8	res127[12];
	__85xx_r32	iidr28;		/* 0x50590 - Internal Interrupt Destination Register 28 */
	__85xx_r8	res128[12];
	__85xx_r32	iivpr29;	/* 0x505a0 - Internal Interrupt Vector/Priority Register 29 */
	__85xx_r8	res129[12];
	__85xx_r32	iidr29;		/* 0x505b0 - Internal Interrupt Destination Register 29 */
	__85xx_r8	res130[12];
	__85xx_r32	iivpr30;	/* 0x505c0 - Internal Interrupt Vector/Priority Register 30 */
	__85xx_r8	res131[12];
	__85xx_r32	iidr30;		/* 0x505d0 - Internal Interrupt Destination Register 30 */
	__85xx_r8	res132[12];
	__85xx_r32	iivpr31;	/* 0x505e0 - Internal Interrupt Vector/Priority Register 31 */
	__85xx_r8	res133[12];
	__85xx_r32	iidr31;		/* 0x505f0 - Internal Interrupt Destination Register 31 */
	__85xx_r8	res134[4108];
	__85xx_r32	mivpr0;		/* 0x51600 - Messaging Interrupt Vector/Priority Register 0 */
	__85xx_r8	res135[12];
	__85xx_r32	midr0;		/* 0x51610 - Messaging Interrupt Destination Register 0 */
	__85xx_r8	res136[12];
	__85xx_r32	mivpr1;		/* 0x51620 - Messaging Interrupt Vector/Priority Register 1 */
	__85xx_r8	res137[12];
	__85xx_r32	midr1;		/* 0x51630 - Messaging Interrupt Destination Register 1 */
	__85xx_r8	res138[12];
	__85xx_r32	mivpr2;		/* 0x51640 - Messaging Interrupt Vector/Priority Register 2 */
	__85xx_r8	res139[12];
	__85xx_r32	midr2;		/* 0x51650 - Messaging Interrupt Destination Register 2 */
	__85xx_r8	res140[12];
	__85xx_r32	mivpr3;		/* 0x51660 - Messaging Interrupt Vector/Priority Register 3 */
	__85xx_r8	res141[12];
	__85xx_r32	midr3;		/* 0x51670 - Messaging Interrupt Destination Register 3 */
	__85xx_r8	res142[59852];
	__85xx_r32	ipi0dr0;	/* 0x60040 - Processor 0 Interprocessor Interrupt Dispatch Register 0 */
	__85xx_r8	res143[12];
	__85xx_r32	ipi0dr1;	/* 0x60050 - Processor 0 Interprocessor Interrupt Dispatch Register 1 */
	__85xx_r8	res144[12];
	__85xx_r32	ipi0dr2;	/* 0x60060 - Processor 0 Interprocessor Interrupt Dispatch Register 2 */
	__85xx_r8	res145[12];
	__85xx_r32	ipi0dr3;	/* 0x60070 - Processor 0 Interprocessor Interrupt Dispatch Register 3 */
	__85xx_r8	res146[12];
	__85xx_r32	ctpr0;		/* 0x60080 - Current Task Priority Register for Processor 0 */
	__85xx_r8	res147[12];
	__85xx_r32	whoami0;	/* 0x60090 - Who Am I Register for Processor 0 */
	__85xx_r8	res148[12];
	__85xx_r32	iack0;		/* 0x600a0 - Interrupt Acknowledge Register for Processor 0 */
	__85xx_r8	res149[12];
	__85xx_r32	eoi0;		/* 0x600b0 - End Of Interrupt Register for Processor 0 */
	__85xx_r8	res150[130892];
} MPC85XX_PIC_T;

/* CPM Block(0x8_0000-0xc_0000) */
#ifdef MPC85XX_FOR_8540
typedef struct MPC85XX_cpm {
	__85xx_r8 res[262144];
} MPC85XX_CPM_T;
#else
/* 0x8000-0x8ffff:DPARM */

/* 0x9000-0x90bff: General SIU */
typedef struct MPC85XX_CPM_SIU {
	__85xx_r8 	res1[80];
	__85xx_r32	smaer;
	__85xx_r32	smser;
	__85xx_r32	smevr;
	__85xx_r8    res2[4];
	__85xx_r32	lmaer;
	__85xx_r32	lmser;
	__85xx_r32	lmevr;
	__85xx_r8	res3[2964];
} MPC85XX_CPM_SIU_T;

/* 0x90c00-0x90cff: Interrupt Controller */
typedef struct MPC85XX_CPM_INTCTL {
	__85xx_r16  sicr;
	__85xx_r8    res1[2];
	__85xx_r32    sivec;
	__85xx_r32    sipnrh;
	__85xx_r32    sipnrl;
	__85xx_r32    siprr;
	__85xx_r32    scprrh;
	__85xx_r32    scprrl;
	__85xx_r32    simrh;
	__85xx_r32    simrl;
	__85xx_r32    siexr;
	__85xx_r8    res2[88];
	__85xx_r32	sccr;
	__85xx_r8	res3[124];
} MPC85XX_CPM_INTCTL_T;

/* 0x90d00-0x90d7f: input/output port */
typedef struct MPC85XX_CPM_IOP {
	__85xx_r32    pdira;
	__85xx_r32    ppara;
	__85xx_r32    psora;
	__85xx_r32    podra;
	__85xx_r32    pdata;
	__85xx_r8    res1[12];
	__85xx_r32    pdirb;
	__85xx_r32    pparb;
	__85xx_r32    psorb;
	__85xx_r32    podrb;
	__85xx_r32    pdatb;
	__85xx_r8    res2[12];
	__85xx_r32    pdirc;
	__85xx_r32    pparc;
	__85xx_r32    psorc;
	__85xx_r32    podrc;
	__85xx_r32    pdatc;
	__85xx_r8    res3[12];
	__85xx_r32    pdird;
	__85xx_r32    ppard;
	__85xx_r32    psord;
	__85xx_r32    podrd;
	__85xx_r32    pdatd;
	__85xx_r8    res4[12];
} MPC85XX_CPM_IOP_T;

/* 0x90d80-0x91017: CPM timers */
typedef struct MPC85XX_CPM_TIMER {
	__85xx_r8  tgcr1;
	__85xx_r8    res1[3];
	__85xx_r8  tgcr2;
	__85xx_r8    res2[11];
	__85xx_r16  tmr1;
	__85xx_r16  tmr2;
	__85xx_r16  trr1;
	__85xx_r16  trr2;
	__85xx_r16  tcr1;
	__85xx_r16  tcr2;
	__85xx_r16  tcn1;
	__85xx_r16  tcn2;
	__85xx_r16  tmr3;
	__85xx_r16  tmr4;
	__85xx_r16  trr3;
	__85xx_r16  trr4;
	__85xx_r16  tcr3;
	__85xx_r16  tcr4;
	__85xx_r16  tcn3;
	__85xx_r16  tcn4;
	__85xx_r16  ter1;
	__85xx_r16  ter2;
	__85xx_r16  ter3;
	__85xx_r16  ter4;
	__85xx_r8    res3[608];
} MPC85XX_CPM_TIMER_T;

/* 0x91018-0x912ff: SDMA */
typedef struct MPC85XX_CPM_SDMA {
	__85xx_r8	sdsr;
	__85xx_r8 	res1[3];
	__85xx_r8 	sdmr;
	__85xx_r8 	res2[739];
} MPC85XX_CPM_SDMA_T;

/* 0x91300-0x9131f: FCC1 */
typedef struct MPC85XX_CPM_FCC1 {
	__85xx_r32    gfmr;
	__85xx_r32    fpsmr;
	__85xx_r16  ftodr;
	__85xx_r8    res1[2];
	__85xx_r16  fdsr;
	__85xx_r8    res2[2];
	__85xx_r16  fcce;
	__85xx_r8    res3[2];
	__85xx_r16  fccm;
	__85xx_r8    res4[2];
	__85xx_r8  fccs;
	__85xx_r8    res5[3];
	__85xx_r8  ftirr_phy[4];
} MPC85XX_CPM_FCC1_T;

/* 0x91320-0x9133f: FCC2 */
typedef struct MPC85XX_CPM_FCC2 {
	__85xx_r32    gfmr;
	__85xx_r32    fpsmr;
	__85xx_r16  ftodr;
	__85xx_r8    res1[2];
	__85xx_r16  fdsr;
	__85xx_r8    res2[2];
	__85xx_r16  fcce;
	__85xx_r8    res3[2];
	__85xx_r16  fccm;
	__85xx_r8    res4[2];
	__85xx_r8  fccs;
	__85xx_r8    res5[3];
	__85xx_r8  ftirr_phy[4];
} MPC85XX_CPM_FCC2_T;

/* 0x91340-0x9137f: FCC3 */
typedef struct MPC85XX_CPM_FCC3 {
	__85xx_r32    gfmr;
	__85xx_r32    fpsmr;
	__85xx_r16  ftodr;
	__85xx_r8    res1[2];
	__85xx_r16  fdsr;
	__85xx_r8    res2[2];
	__85xx_r16  fcce;
	__85xx_r8    res3[2];
	__85xx_r16  fccm;
	__85xx_r8    res4[2];
	__85xx_r8  fccs;
	__85xx_r8    res5[3];
	__85xx_r8	res[36];
} MPC85XX_CPM_FCC3_T;

/* 0x91380-0x9139f: FCC1 extended */
typedef struct MPC85XX_CPM_FCC1_EXT {
	__85xx_r32	firper;
	__85xx_r32	firer;
	__85xx_r32	firsr_h;
	__85xx_r32	firsr_l;
	__85xx_r8	gfemr;
	__85xx_r8	res[15];

} MPC85XX_CPM_FCC1_EXT_T;

/* 0x913a0-0x913cf: FCC2 extended */
typedef struct MPC85XX_CPM_FCC2_EXT {
	__85xx_r32	firper;
	__85xx_r32	firer;
	__85xx_r32	firsr_h;
	__85xx_r32	firsr_l;
	__85xx_r8	gfemr;
	__85xx_r8	res[31];
} MPC85XX_CPM_FCC2_EXT_T;

/* 0x913d0-0x913ff: FCC3 extended */
typedef struct MPC85XX_CPM_FCC3_EXT {
	__85xx_r8	gfemr;
	__85xx_r8	res[47];
} MPC85XX_CPM_FCC3_EXT_T;

/* 0x91400-0x915ef: TC layers */
typedef struct MPC85XX_CPM_TMP1 {
	__85xx_r8 	res[496];
} MPC85XX_CPM_TMP1_T;

/* 0x915f0-0x9185f: BRGs:5,6,7,8 */
typedef struct MPC85XX_CPM_BRG2 {
	__85xx_r32	brgc5;
	__85xx_r32	brgc6;
	__85xx_r32	brgc7;
	__85xx_r32	brgc8;
	__85xx_r8	res[608];
} MPC85XX_CPM_BRG2_T;

/* 0x91860-0x919bf: I2C */
typedef struct MPC85XX_CPM_I2C {
	__85xx_r8  i2mod;
	__85xx_r8    res1[3];
	__85xx_r8  i2add;
	__85xx_r8    res2[3];
	__85xx_r8  i2brg;
	__85xx_r8    res3[3];
	__85xx_r8  i2com;
	__85xx_r8    res4[3];
	__85xx_r8  i2cer;
	__85xx_r8    res5[3];
	__85xx_r8  i2cmr;
	__85xx_r8    res6[331];
} MPC85XX_CPM_I2C_T;

/* 0x919c0-0x919ef: CPM core */
typedef struct MPC85XX_CPM_CP {
	__85xx_r32    cpcr;
	__85xx_r32    rccr;
	__85xx_r8    res1[14];
	__85xx_r16  rter;
	__85xx_r8    res2[2];
	__85xx_r16  rtmr;
	__85xx_r16  rtscr;
	__85xx_r8    res3[2];
	__85xx_r32    rtsr;
	__85xx_r8    res4[12];
} MPC85XX_CPM_CP_T;

/* 0x919f0-0x919ff: BRGs:1,2,3,4 */
typedef struct MPC85XX_CPM_BRG1 {
	__85xx_r32	brgc1;
	__85xx_r32	brgc2;
	__85xx_r32	brgc3;
	__85xx_r32	brgc4;
} MPC85XX_CPM_BRG1_T;

/* 0x91a00-0x91a9f: SCC1-SCC4 */
typedef struct MPC85XX_CPM_SCC {
	__85xx_r32    gsmrl;
	__85xx_r32    gsmrh;
	__85xx_r16  psmr;
	__85xx_r8    res1[2];
	__85xx_r16  todr;
	__85xx_r16  dsr;
	__85xx_r16  scce;
	__85xx_r8    res2[2];
	__85xx_r16  sccm;
	__85xx_r8    res3;
	__85xx_r8  sccs;
	__85xx_r8    res4[8];
} MPC85XX_CPM_SCC_T;

/* 0x91a80-0x91a9f */
typedef struct MPC85XX_cpm_tmp2 {
	__85xx_r8 	res[32];
} MPC85XX_CPM_TMP2_T;

/* 0x91aa0-0x91aff: SPI */
typedef struct MPC85XX_CPM_SPI {
	__85xx_r16  spmode;
	__85xx_r8    res1[4];
	__85xx_r8  spie;
	__85xx_r8    res2[3];
	__85xx_r8  spim;
	__85xx_r8    res3[2];
	__85xx_r8  spcom;
	__85xx_r8    res4[82];
} MPC85XX_CPM_SPI_T;

/* 0x91b00-0x91b1f: CPM MUX */
typedef struct MPC85XX_CPM_MUX {
	__85xx_r8  cmxsi1cr;
	__85xx_r8    res1;
	__85xx_r8  cmxsi2cr;
	__85xx_r8    res2;
	__85xx_r32    cmxfcr;
	__85xx_r32    cmxscr;
	__85xx_r8    res3[2];
	__85xx_r16  cmxuar;
	__85xx_r8    res4[16];
} MPC85XX_CPM_MUX_T;

/* 0x91b20-0xbffff: SI,MCC,etc */
typedef struct MPC85XX_CPM_TMP3 {
	__85xx_r8 res[58592];
} MPC85XX_CPM_TMP3_T;

typedef struct MPC85XX_CPM_IRAM {
	unsigned long iram[8192];
	__85xx_r8 res[98304];
} MPC85XX_CPM_IRAM_T;

typedef struct MPC85XX_CPM {
	/* Some references are into the unique and known dpram spaces,
	 * others are from the generic base.
	 */
	__85xx_r8          		im_dpram1[16*1024];
	__85xx_r8            		res1[16*1024];
	__85xx_r8          		im_dpram2[16*1024];
	__85xx_r8            		res2[16*1024];

	MPC85XX_CPM_SIU_T  		im_cpm_siu;     /* SIU Configuration */
	MPC85XX_CPM_INTCTL_T    im_cpm_intctl;  /* Interrupt Controller */
	MPC85XX_CPM_IOP_T       im_cpm_iop;     /* IO Port control/status */
	MPC85XX_CPM_TIMER_T  	im_cpm_timer;   /* CPM timers */
	MPC85XX_CPM_SDMA_T      im_cpm_sdma;    /* SDMA control/status */
	MPC85XX_CPM_FCC1_T		im_cpm_fcc1;
	MPC85XX_CPM_FCC2_T		im_cpm_fcc2;
	MPC85XX_CPM_FCC3_T		im_cpm_fcc3;
	MPC85XX_CPM_FCC1_EXT_T	im_cpm_fcc1_ext;
	MPC85XX_CPM_FCC2_EXT_T	im_cpm_fcc2_ext;
	MPC85XX_CPM_FCC3_EXT_T	im_cpm_fcc3_ext;
	MPC85XX_CPM_TMP1_T		im_cpm_tmp1;
	MPC85XX_CPM_BRG2_T		im_cpm_brg2;
	MPC85XX_CPM_I2C_T		im_cpm_i2c;
	MPC85XX_CPM_CP_T		im_cpm_cp;
	MPC85XX_CPM_BRG1_T		im_cpm_brg1;
	MPC85XX_CPM_SCC_T		im_cpm_scc[4];
	MPC85XX_CPM_TMP2_T		im_cpm_tmp2;
	MPC85XX_CPM_SPI_T		im_cpm_spi;
	MPC85XX_CPM_MUX_T		im_cpm_mux;
	MPC85XX_CPM_TMP3_T		im_cpm_tmp3;
	MPC85XX_CPM_IRAM_T		im_cpm_iram;
} MPC85XX_CPM_T;
#endif /* MPC85XX_FOR_8540 */

/* RapidIO Registers(0xc_0000-0xe_0000) */

typedef struct MPC85XX_RIO {
	__85xx_r32	didcar;		/* 0xc0000 - Device Identity Capability Register */
	__85xx_r32	dicar;		/* 0xc0004 - Device Information Capability Register */
	__85xx_r32	aidcar;		/* 0xc0008 - Assembly Identity Capability Register */
	__85xx_r32	aicar;		/* 0xc000c - Assembly Information Capability Register */
	__85xx_r32	pefcar;		/* 0xc0010 - Processing Element Features Capability Register */
	__85xx_r32	spicar;		/* 0xc0014 - Switch Port Information Capability Register */
	__85xx_r32	socar;		/* 0xc0018 - Source Operations Capability Register */
	__85xx_r32	docar;		/* 0xc001c - Destination Operations Capability Register */
	__85xx_r8	res1[32];
	__85xx_r32	msr;		/* 0xc0040 - Mailbox Command And Status Register */
	__85xx_r32	pwdcsr;		/* 0xc0044 - Port-Write and Doorbell Command And Status Register */
	__85xx_r8	res2[4];
	__85xx_r32	pellccsr;	/* 0xc004c - Processing Element Logic Layer Control Command and Status Register */
	__85xx_r8	res3[12];
	__85xx_r32	lcsbacsr;	/* 0xc005c - Local Configuration Space Base Address Command and Status Register */
	__85xx_r32	bdidcsr;	/* 0xc0060 - Base Device ID Command and Status Register */
	__85xx_r8	res4[4];
	__85xx_r32	hbdidlcsr;	/* 0xc0068 - Host Base Device ID Lock Command and Status Register */
	__85xx_r32	ctcsr;		/* 0xc006c - Component Tag Command and Status Register */
	__85xx_r8	res5[144];
	__85xx_r32	pmbh0csr;	/* 0xc0100 - 8/16 LP-LVDS Port Maintenance Block Header 0 Command and Status Register */
	__85xx_r8	res6[28];
	__85xx_r32	pltoccsr;	/* 0xc0120 - Port Link Time-out Control Command and Status Register */
	__85xx_r32	prtoccsr;	/* 0xc0124 - Port Response Time-out Control Command and Status Register */
	__85xx_r8	res7[20];
	__85xx_r32	pgccsr;		/* 0xc013c - Port General Command and Status Register */
	__85xx_r32	plmreqcsr;	/* 0xc0140 - Port Link Maintenance Request Command and Status Register */
	__85xx_r32	plmrespcsr;	/* 0xc0144 - Port Link Maintenance Response Command and Status Register */
	__85xx_r32	plascsr;	/* 0xc0148 - Port Local Ackid Status Command and Status Register */
	__85xx_r8	res8[12];
	__85xx_r32	pescsr;		/* 0xc0158 - Port Error and Status Command and Status Register */
	__85xx_r32	pccsr;		/* 0xc015c - Port Control Command and Status Register */
	__85xx_r8	res9[65184];
	__85xx_r32	cr;		/* 0xd0000 - Port Control Command and Status Register */
	__85xx_r8	res10[12];
	__85xx_r32	pcr;		/* 0xd0010 - Port Configuration Register */
	__85xx_r32	peir;		/* 0xd0014 - Port Error Injection Register */
	__85xx_r8	res11[3048];
	__85xx_r32	rowtar0;	/* 0xd0c00 - RapidIO Outbound Window Translation Address Register 0 */
	__85xx_r8	res12[12];
	__85xx_r32	rowar0;		/* 0xd0c10 - RapidIO Outbound Attributes Register 0 */
	__85xx_r8	res13[12];
	__85xx_r32	rowtar1;	/* 0xd0c20 - RapidIO Outbound Window Translation Address Register 1 */
	__85xx_r8	res14[4];
	__85xx_r32	rowbar1;	/* 0xd0c28 - RapidIO Outbound Window Base Address Register 1 */
	__85xx_r8	res15[4];
	__85xx_r32	rowar1;		/* 0xd0c30 - RapidIO Outbound Attributes Register 1 */
	__85xx_r8	res16[12];
	__85xx_r32	rowtar2;	/* 0xd0c40 - RapidIO Outbound Window Translation Address Register 2 */
	__85xx_r8	res17[4];
	__85xx_r32	rowbar2;	/* 0xd0c48 - RapidIO Outbound Window Base Address Register 2 */
	__85xx_r8	res18[4];
	__85xx_r32	rowar2;		/* 0xd0c50 - RapidIO Outbound Attributes Register 2 */
	__85xx_r8	res19[12];
	__85xx_r32	rowtar3;	/* 0xd0c60 - RapidIO Outbound Window Translation Address Register 3 */
	__85xx_r8	res20[4];
	__85xx_r32	rowbar3;	/* 0xd0c68 - RapidIO Outbound Window Base Address Register 3 */
	__85xx_r8	res21[4];
	__85xx_r32	rowar3;		/* 0xd0c70 - RapidIO Outbound Attributes Register 3 */
	__85xx_r8	res22[12];
	__85xx_r32	rowtar4;	/* 0xd0c80 - RapidIO Outbound Window Translation Address Register 4 */
	__85xx_r8	res23[4];
	__85xx_r32	rowbar4;	/* 0xd0c88 - RapidIO Outbound Window Base Address Register 4 */
	__85xx_r8	res24[4];
	__85xx_r32	rowar4;		/* 0xd0c90 - RapidIO Outbound Attributes Register 4 */
	__85xx_r8	res25[12];
	__85xx_r32	rowtar5;	/* 0xd0ca0 - RapidIO Outbound Window Translation Address Register 5 */
	__85xx_r8	res26[4];
	__85xx_r32	rowbar5;	/* 0xd0ca8 - RapidIO Outbound Window Base Address Register 5 */
	__85xx_r8	res27[4];
	__85xx_r32	rowar5;		/* 0xd0cb0 - RapidIO Outbound Attributes Register 5 */
	__85xx_r8	res28[12];
	__85xx_r32	rowtar6;	/* 0xd0cc0 - RapidIO Outbound Window Translation Address Register 6 */
	__85xx_r8	res29[4];
	__85xx_r32	rowbar6;	/* 0xd0cc8 - RapidIO Outbound Window Base Address Register 6 */
	__85xx_r8	res30[4];
	__85xx_r32	rowar6;		/* 0xd0cd0 - RapidIO Outbound Attributes Register 6 */
	__85xx_r8	res31[12];
	__85xx_r32	rowtar7;	/* 0xd0ce0 - RapidIO Outbound Window Translation Address Register 7 */
	__85xx_r8	res32[4];
	__85xx_r32	rowbar7;	/* 0xd0ce8 - RapidIO Outbound Window Base Address Register 7 */
	__85xx_r8	res33[4];
	__85xx_r32	rowar7;		/* 0xd0cf0 - RapidIO Outbound Attributes Register 7 */
	__85xx_r8	res34[12];
	__85xx_r32	rowtar8;	/* 0xd0d00 - RapidIO Outbound Window Translation Address Register 8 */
	__85xx_r8	res35[4];
	__85xx_r32	rowbar8;	/* 0xd0d08 - RapidIO Outbound Window Base Address Register 8 */
	__85xx_r8	res36[4];
	__85xx_r32	rowar8;		/* 0xd0d10 - RapidIO Outbound Attributes Register 8 */
	__85xx_r8	res37[76];
	__85xx_r32	riwtar4;	/* 0xd0d60 - RapidIO Inbound Window Translation Address Register 4 */
	__85xx_r8	res38[4];
	__85xx_r32	riwbar4;	/* 0xd0d68 - RapidIO Inbound Window Base Address Register 4 */
	__85xx_r8	res39[4];
	__85xx_r32	riwar4;		/* 0xd0d70 - RapidIO Inbound Attributes Register 4 */
	__85xx_r8	res40[12];
	__85xx_r32	riwtar3;	/* 0xd0d80 - RapidIO Inbound Window Translation Address Register 3 */
	__85xx_r8	res41[4];
	__85xx_r32	riwbar3;	/* 0xd0d88 - RapidIO Inbound Window Base Address Register 3 */
	__85xx_r8	res42[4];
	__85xx_r32	riwar3;		/* 0xd0d90 - RapidIO Inbound Attributes Register 3 */
	__85xx_r8	res43[12];
	__85xx_r32	riwtar2;	/* 0xd0da0 - RapidIO Inbound Window Translation Address Register 2 */
	__85xx_r8	res44[4];
	__85xx_r32	riwbar2;	/* 0xd0da8 - RapidIO Inbound Window Base Address Register 2 */
	__85xx_r8	res45[4];
	__85xx_r32	riwar2;		/* 0xd0db0 - RapidIO Inbound Attributes Register 2 */
	__85xx_r8	res46[12];
	__85xx_r32	riwtar1;	/* 0xd0dc0 - RapidIO Inbound Window Translation Address Register 1 */
	__85xx_r8	res47[4];
	__85xx_r32	riwbar1;	/* 0xd0dc8 - RapidIO Inbound Window Base Address Register 1 */
	__85xx_r8	res48[4];
	__85xx_r32	riwar1;		/* 0xd0dd0 - RapidIO Inbound Attributes Register 1 */
	__85xx_r8	res49[12];
	__85xx_r32	riwtar0;	/* 0xd0de0 - RapidIO Inbound Window Translation Address Register 0 */
	__85xx_r8	res50[12];
	__85xx_r32	riwar0;		/* 0xd0df0 - RapidIO Inbound Attributes Register 0 */
	__85xx_r8	res51[12];
	__85xx_r32	pnfedr;		/* 0xd0e00 - Port Notification/Fatal Error Detect Register */
	__85xx_r32	pnfedir;	/* 0xd0e04 - Port Notification/Fatal Error Detect Register */
	__85xx_r32	pnfeier;	/* 0xd0e08 - Port Notification/Fatal Error Interrupt Enable Register */
	__85xx_r32	pecr;		/* 0xd0e0c - Port Error Control Register */
	__85xx_r32	pepcsr0;	/* 0xd0e10 - Port Error Packet/Control Symbol Register 0 */
	__85xx_r32	pepr1;		/* 0xd0e14 - Port Error Packet Register 1 */
	__85xx_r32	pepr2;		/* 0xd0e18 - Port Error Packet Register 2 */
	__85xx_r8	res52[4];
	__85xx_r32	predr;		/* 0xd0e20 - Port Recoverable Error Detect Register */
	__85xx_r8	res53[4];
	__85xx_r32	pertr;		/* 0xd0e28 - Port Error Recovery Threshold Register */
	__85xx_r32	prtr;		/* 0xd0e2c - Port Retry Threshold Register */
	__85xx_r8	res54[464];
	__85xx_r32	omr;		/* 0xd1000 - Outbound Mode Register */
	__85xx_r32	osr;		/* 0xd1004 - Outbound Status Register */
	__85xx_r32	eodqtpar;	/* 0xd1008 - Extended Outbound Descriptor Queue Tail Pointer Address Register */
	__85xx_r32	odqtpar;	/* 0xd100c - Outbound Descriptor Queue Tail Pointer Address Register */
	__85xx_r32	eosar;		/* 0xd1010 - Extended Outbound Unit Source Address Register */
	__85xx_r32	osar;		/* 0xd1014 - Outbound Unit Source Address Register */
	__85xx_r32	odpr;		/* 0xd1018 - Outbound Destination Port Register */
	__85xx_r32	odatr;		/* 0xd101c - Outbound Destination Attributes Register */
	__85xx_r32	odcr;		/* 0xd1020 - Outbound Doubleword Count Register */
	__85xx_r32	eodqhpar;	/* 0xd1024 - Extended Outbound Descriptor Queue Head Pointer Address Register */
	__85xx_r32	odqhpar;	/* 0xd1028 - Outbound Descriptor Queue Head Pointer Address Register */
	__85xx_r8	res55[52];
	__85xx_r32	imr;		/* 0xd1060 - Outbound Mode Register */
	__85xx_r32	isr;		/* 0xd1064 - Inbound Status Register */
	__85xx_r32	eidqtpar;	/* 0xd1068 - Extended Inbound Descriptor Queue Tail Pointer Address Register */
	__85xx_r32	idqtpar;	/* 0xd106c - Inbound Descriptor Queue Tail Pointer Address Register */
	__85xx_r32	eifqhpar;	/* 0xd1070 - Extended Inbound Frame Queue Head Pointer Address Register */
	__85xx_r32	ifqhpar;	/* 0xd1074 - Inbound Frame Queue Head Pointer Address Register */
	__85xx_r8	res56[1000];
	__85xx_r32	dmr;		/* 0xd1460 - Doorbell Mode Register */
	__85xx_r32	dsr;		/* 0xd1464 - Doorbell Status Register */
	__85xx_r32	edqtpar;	/* 0xd1468 - Extended Doorbell Queue Tail Pointer Address Register */
	__85xx_r32	dqtpar;		/* 0xd146c - Doorbell Queue Tail Pointer Address Register */
	__85xx_r32	edqhpar;	/* 0xd1470 - Extended Doorbell Queue Head Pointer Address Register */
	__85xx_r32	dqhpar;		/* 0xd1474 - Doorbell Queue Head Pointer Address Register */
	__85xx_r8	res57[104];
	__85xx_r32	pwmr;		/* 0xd14e0 - Port-Write Mode Register */
	__85xx_r32	pwsr;		/* 0xd14e4 - Port-Write Status Register */
	__85xx_r32	epwqbar;	/* 0xd14e8 - Extended Port-Write Queue Base Address Register */
	__85xx_r32	pwqbar;		/* 0xd14ec - Port-Write Queue Base Address Register */
	__85xx_r8	res58[60176];
} MPC85XX_RIO_T;

/* Global Utilities Register Block(0xe_0000-0xf_ffff) */
typedef struct MPC85XX_GUR {
	__85xx_r32	porpllsr;	/* 0xe0000 - POR PLL ratio status register */
	__85xx_r32	porbmsr;	/* 0xe0004 - POR boot mode status register */
	__85xx_r32	porimpscr;	/* 0xe0008 - POR I/O impedance status and control register */
	__85xx_r32	pordevsr;	/* 0xe000c - POR I/O device status regsiter */
	__85xx_r32	pordbgmsr;	/* 0xe0010 - POR debug mode status register */
	__85xx_r8	res1[12];
	__85xx_r32	gpporcr;	/* 0xe0020 - General-purpose POR configuration register */
	__85xx_r8	res2[12];
	__85xx_r32	gpiocr;		/* 0xe0030 - GPIO control register */
		#define MPC85XX_GPIOCR_GPOUT 0x00000200
	__85xx_r8	res3[12];
	__85xx_r32	gpoutdr;	/* 0xe0040 - General-purpose output data register */
		#define MPC85XX_GPOUTDR_24	 0x00000080
	__85xx_r8	res4[12];
	__85xx_r32	gpindr;		/* 0xe0050 - General-purpose input data register */
	__85xx_r8	res5[12];
	__85xx_r32	pmuxcr;		/* 0xe0060 - Alternate function signal multiplex control */
	__85xx_r8	res6[12];
	__85xx_r32	devdisr;	/* 0xe0070 - Device disable control */
	__85xx_r8	res7[12];
	__85xx_r32	powmgtcsr;	/* 0xe0080 - Power management status and control register */
	__85xx_r8	res8[12];
	__85xx_r32	mcpsumr;	/* 0xe0090 - Machine check summary register */
	__85xx_r8	res9[12];
	__85xx_r32	pvr;		/* 0xe00a0 - Processor version register */
	__85xx_r32	svr;		/* 0xe00a4 - System version register */
		#define MPC85xx_8540		0x80300000
		#define MPC85xx_8560		0x80700000
		#define MPC85xx_8541		0x80720000
		#define MPC85xx_8541E		0x807A0000
		#define MPC85xx_8548E		0x80390000
		#define MPC85xx_8548		0x80310000
		#define MPC85xx_8543E		0x803A0000
		#define MPC85xx_8543		0x80320000

	__85xx_r8	res10a[8];
	__85xx_r32	rstcr;		/* 0xe00b0 - Reset Control Register */
		#define MPC85xx_RSTCR_HRESET_REQ 0x00000002
	__85xx_r8	res10b[2672];
	__85xx_r32	ddrcdr;		/* 0xe0b24 - DDR control driver register */
	__85xx_r8	res10c[728];
	__85xx_r32	clkocr;		/* 0xe0e00 - Clock out select register */
	__85xx_r8	res11[12];
	__85xx_r32	ddrdllcr;	/* 0xe0e10 - DDR DLL control register */
	__85xx_r8	res12[12];
	__85xx_r32	lbcdllcr;	/* 0xe0e20 - LBC DLL control register */
	__85xx_r8	res13[61915];
} MPC85XX_GUR_T;

typedef struct MPC85XX_IMMAP {
	MPC85XX_LOCAL_ECM_T	im_local_ecm;
	MPC85XX_DDR_T		im_ddr;
	MPC85XX_I2C_T		im_i2c;
	MPC85XX_DUART_T		im_duart;
	MPC85XX_LBC_T		im_lbc;
	MPC85XX_PCIX_T		im_pcix;
	MPC85XX_PCI2_T		im_pci2;
	MPC85XX_L2CACHE_T	im_l2cache;
	MPC85XX_DMA_T		im_dma;
	MPC85XX_TSEC_T		im_tsec[2];
	MPC85XX_PIC_T		im_pic;
	MPC85XX_CPM_T		im_cpm;
	MPC85XX_RIO_T		im_rio;
	MPC85XX_GUR_T		im_gur;
} MPC85XX_IMMAP_T;

#endif /* _MPC85XX_H */
