/***********************  I n c l u d e  -  F i l e  ************************/
/*!  
 *        \file  lm81.h
 *
 *      \author  men
 * 
 *  	 \brief  Header file for LM81 chip
 *                      
 *     Switches: -
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 2004-2019, MEN Mikro Elektronik GmbH
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

#ifndef _LM81_H
#define _LM81_H

#ifdef __cplusplus
	extern "C" {
#endif


/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*! \defgroup xxxdefgroup header defines

  LM81 internal address
*/
/**@{*/
#define	LM81_AOUT 	0x19		/**< analog out register */
#define	LM81_2_5V 	0x20		/**< 2.5V analog in register */
#define	LM81_VCCP1 	0x21		/**< VCCP1 V analog in register */
#define	LM81_3_3V	0x22		/**< 3.3V analog in register */
#define	LM81_5V 	0x23		/**< 5V analog in register */
#define	LM81_12V	0x24		/**< 12V analog in register */
#define	LM81_VCCP2	0x25		/**< VCCP2 V analog in register */
#define LM81_TEMP	0x27		/**< temperature register */
#define	LM81_FAN1 	0x28		/**< FAN1 count register */
#define	LM81_FAN2	0x29		/**< FAN2 register */
#define	LM81_2_5V_HIGH	0x2B		/**< 2.5V upper limit register */
#define	LM81_2_5V_LOW	0x2C		/**< 2.5V lower limit register */
#define	LM81_VCCP1_HIGH	0x2D		/**< VCCP1 V upper limit register */
#define	LM81_VCCP1_LOW	0x2E		/**< VCCP1 V lower limit register */
#define	LM81_3_3V_HIGH	0x2F		/**< 3.3V upper limit register */
#define	LM81_3_3V_LOW	0x30		/**< 3.3V lower limit register */
#define	LM81_5V_HIGH	0x31		/**< 5V upper limit register */ 
#define	LM81_5V_LOW		0x32		/**< 5V lower limit register */ 
#define	LM81_12V_HIGH	0x33		/**< 12V upper limit register */
#define	LM81_12V_LOW	0x34		/**< 12V lower limit register */
#define	LM81_VCCP2_HIGH	0x35		/**< VCCP2 V upper limit register */
#define	LM81_VCCP2_LOW	0x36		/**< VCCP2 V lower limit register */
#define	LM81_T_CRIT_EXT 0x37		/**< register */
#define	LM81_LOW_EXT	0x38		/**< register */
#define	LM81_T_HIGH		0x39		/**< register */
#define	LM81_T_HI_HYST	0x3A		/**< register */
#define	LM81_FAN1_LOW	0x3B		/**< register */
#define	LM81_FAN2_LOW	0x3C		/**< register */
#define	LM81_VENDOR		0x3E		/**< register */
#define	LM81_REVISION	0x3F		/**< register */

#define LM81_CONF		0x40		/**< configuration register */
#define	LM81_ISTAT1 	0x41		/**< interrupt status 1 register */
#define	LM81_ISTAT2 	0x42		/**< interrupt status 2 register */
#define	LM81_IMASK1 	0x43		/**< interrupt mask 1 register */
#define	LM81_IMASK2 	0x44		/**< interrupt mask 2 register */
#define	LM81_CI_CLEAR  	0x46		/**< chassis intrusion clear register */
#define	LM81_TEM_CFG  	0x4B		/**< temperatur configuration register */
#define LM81_EXT_MODE1  0x4C        /**< extended mode register 1 */
#define LM81_EXT_MODE2  0x4d        /**< extended mode register 2 */
/**@}*/


/*! \defgroup xxxdefgroup header defines

  LM81 config register bit definitions
*/
/**@{*/
#define LM81_CONF_START			0x01 /**< start operation - clear bit -> standby */
#define LM81_CONF_INT_ENABLE	0x02 /**< enable interrupt output */
#define LM81_CONF_INT_CLEAR 	0x08 /**< disable interrupt output */
#define LM81_CONF_RESET     	0x10 /**< reset pulse 20ms */
#define LM81_CONF_CI_CLEAR  	0x40 /**< 20ms CI pulse */
#define LM81_CONF_INIT      	0x80 /**< soft chip reset */
/**@}*/

/*! \defgroup xxxdefgroup header defines

  LM81 interrupt status 1 register bit definitions
*/
/**@{*/
#define LM81_ISTAT1_2_5V			0x01 /**< 2.5 V mask */
#define LM81_ISTAT1_VCCP_1			0x02 /**< VCCP1 mask */
#define LM81_ISTAT1_3_3V			0x04 /**< 3.3 V mask */
#define LM81_ISTAT1_5V				0x08 /**< 5 V mask */
#define LM81_ISTAT1_TEMP			0x10 /**< temperatur mask */
#define LM81_ISTAT1_RESERVED		0x20 /**< reserved mask */
#define LM81_ISTAT1_FAN1			0x40 /**< FAN1 mask */
#define LM81_ISTAT1_FAN2			0x80 /**< FAN2 mask */
/**@{*/

/*! \defgroup xxxdefgroup header defines

  LM81 interrupt status 2 register bit definitions
*/
/**@{*/
#define LM81_ISTAT2_12V   			0x01 /**< 12 V mask */
#define LM81_ISTAT2_VCCP_2			0x02 /**< VCCP2 mask */
#define LM81_ISTAT2_RES1			0x04 /**< reserved mask */
#define LM81_ISTAT2_RES2			0x08 /**< reserved mask */
#define LM81_ISTAT2_CI				0x10 /**< CI mask */
#define LM81_ISTAT2_RES3			0x20 /**< reserved mask */
#define LM81_ISTAT2_RES4			0x40 /**< reserved mask */
#define LM81_ISTAT2_TLOW			0x80 /**< temperature low mask */
/**@{*/

/*! \defgroup xxxdefgroup header defines

  LM81 interrupt mask 1 register bit definitions
*/
/**@{*/
#define LM81_IMASK1_2_5V			LM81_ISTAT1_2_5V	 /**< 2.5 V mask */
#define LM81_IMASK1_VCCP_1			LM81_ISTAT1_VCCP_1	 /**< VCCP1 mask */
#define LM81_IMASK1_3_3V			LM81_ISTAT1_3_3V	 /**< 3.3 V mask */
#define LM81_IMASK1_5V				LM81_ISTAT1_5V		 /**< 5 V mask */
#define LM81_IMASK1_TEMP			LM81_ISTAT1_TEMP	 /**< temperatur mask */
#define LM81_IMASK1_RESERVED		LM81_ISTAT1_RESERVED /**< reserved mask */
#define LM81_IMASK1_FAN1			LM81_ISTAT1_FAN1	 /**< FAN1 mask */
#define LM81_IMASK1_FAN2			LM81_ISTAT1_FAN2	 /**< FAN2 mask */
/**@{*/

/*! \defgroup xxxdefgroup header defines

  LM81 interrupt mask 2 register bit definitions
*/
/**@{*/
#define LM81_IMASK2_12V   			LM81_ISTAT2_12V   	 /**< 12 V mask */
#define LM81_IMASK2_VCCP_2			LM81_ISTAT2_VCCP_2	 /**< VCCP2 mask */
#define LM81_IMASK2_RES1			LM81_ISTAT2_RES1	 /**< reserved mask */
#define LM81_IMASK2_RES2			LM81_ISTAT2_RES2	 /**< reserved mask */
#define LM81_IMASK2_CI				LM81_ISTAT2_CI		 /**< CI mask */
#define LM81_IMASK2_RES3			LM81_ISTAT2_RES3	 /**< reserved mask */
#define LM81_IMASK2_RES4			LM81_ISTAT2_RES4	 /**< reserved mask */
#define LM81_IMASK2_TLOW			LM81_ISTAT2_TLOW	 /**< temperature low mask */
/**@{*/


/*! \defgroup xxxdefgroup header defines

  LM81 interrupt mask 2 register bit definitions
*/
/**@{*/
#define	LM81_TEM_CFG_MODE_REPETITIVE 	0x00	/**< repetitive interrupt mode */
#define	LM81_TEM_CFG_MODE_ONE_TIME	 	0x01	/**< one time interrupt mode */
#define	LM81_TEM_CFG_MODE_COMPERATOR	0x02	/**< comperator interrupt mode */
/**@{*/


/*! \defgroup xxxdefgroup header defines

  LM81 extended mode 1 register bit definitions
*/
/**@{*/
#define	LM81_EXT_ENABLE 	       0x01	/**< extended mode enable */
#define	LM81_EXT_MASK_LOW	       0x02	/**< low limit mask */
#define	LM81_EXT_T_CRIT_REPETITIVE 0x0C	/**< repetitive ext. irq mode */
#define	LM81_EXT_T_CRIT_ONE_TIME   0x04	/**< one time ext. irq mode */
#define	LM81_EXT_T_CRIT_COMPERATOR 0x08	/**< comperator ext. irq mode */
#define	LM81_EXT_T_CRIT_ENABLE     0x10	/**< enable T_CRIT_A# pin*/
#define	LM81_EXT_T_CRIT_ACT_HIGH   0x20	/**< polarity of T_CRIT_A# pin */
#define	LM81_EXT_MASK_T_CRIT_2_INT 0x40	/**< mask T_CRIT_A# -> INT# */
#define	LM81_EXT_T_CRIT_STATUS     0x80	/**< 1 = T_CRIT_A# irq has occured */
/**@{*/

/*! \defgroup xxxdefgroup header defines

  LM81 extended mode 2 register bit definitions
*/
/**@{*/
#define	LM81_EXT_HYST_OFF 	              0x07	/**< HYST Temperature Limit */
#define	LM81_EXT_12_BIT_ENABLE	          0x08	/**< enable 12 bit resolution */
#define	LM81_EXT_12_BIT_DATA              0xF0	/**< 12-bit temperature data */
/**@{*/

/*--------------------------------------+
|   EXTERNALS                           |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
/* none */

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
/* none */


#ifdef __cplusplus
	}
#endif

#endif	/* _LM81_H */
