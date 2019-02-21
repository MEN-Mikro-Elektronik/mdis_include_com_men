/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  rtc8581.h
 *
 *      \author  kp
 *        $Date: 2014/10/10 11:57:11 $
 *    $Revision: 2.5 $
 *
 *  	 \brief  header file for EPSON RTC 8581
 *
 *     Switches: -
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 2004-2019, MEN Mikro Elektronik GmbH
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

#ifndef _RTC_8581_H
#define _RTC_8581_H


/*-----------+
|  Defines   |
+-----------*/
#ifndef RTC8581_SMB_ADDR
#define RTC8581_SMB_ADDR	0xa2		/* fix for this RTC */
#endif

/* register indices */
#define RTC8581_SEC				0
#define RTC8581_MIN				1
#define RTC8581_HOUR			2
#define RTC8581_WEEK			3
#define RTC8581_DAY				4
#define RTC8581_MONTH			5
#define RTC8581_YEAR			6
#define RTC8581_RAM				7
#define RTC8581_MIN_ALARM		8
#define RTC8581_HOUR_ALARM		9
#define RTC8581_WEEK_ALARM		9
#define RTC8581_X_ALARM			0xa
#define RTC8581_TIMER_COUNTER_0	0xb
#define RTC8581_TIMER_COUNTER_1	0xc
#define RTC8581_EXT				0xd
#define RTC8581_FLAG	   		0xe
#define RTC8581_CONTROL			0xf

/* extension reg bits */
#define RTC8581_EXT_TEST  		0x80

/* flag reg bits */
#define RTC8581_FLAG_VLF  		0x02
#define RTC8581_FLAG_UF  		0x02

/* control reg bits */
#define RTC8581_CONTROL_RESET	0x01
#define RTC8581_CONTROL_STOP   	0x02




#endif /* _RTC_8581_H */


