/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  em04touch.h
 *
 *      \author  rla
 *        $Date: 2012/02/27 18:05:42 $
 *    $Revision: 2.14 $
 *
 *  	 \brief  Header file for EM04 touch driver
 *
 *     Switches: EM04TOUCH_USE_OLD_SYSPARAM
 */
/*
 *---------------------------------------------------------------------------
 * (c) Copyright 2002 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
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

#ifndef _TOUCHDRV_H
#define _TOUCHDRV_H

#ifdef __cplusplus
	extern "C" {
#endif

/*--------------------------------------+
|   DEFINES                             |
+--------------------------------------*/

/*! \defgroup RET_CODES retcodes defines
*/
/**@{*/
#define EM04TOUCH_OUT_OF_RESOURCE	0xC1	/**< return code for no memory error */
#define EM04TOUCH_CALIB_LOAD_ERR	0xC2	/**< return code for load calibration
                                             *   parameter from eeprom error */
#define EM04TOUCH_CALIB_SAVE_ERR	0xC3	/**< return code for save calibration
                                             *   parameter to eeprom error */

#define EM04TOUCH_NOTME				1		/**< return code for not my interrupt */
#define EM04TOUCH_SUCCESS			0		/**< return code for success */
#define EM04TOUCH_ERROR				0xFFFFFFFF	/**< return code for error */
/**@}*/

/*! \defgroup CALIBMODES calibration modes defines
*/
/**@{*/
#define EM04TOUCH_CALIB_UL			1	/**< calibrate upper left edge */
#define EM04TOUCH_CALIB_LR			2	/**< calibrate lower right edge */
#define EM04TOUCH_CALIB_SAVE		3	/**< save parameters to EEPROM */
#define EM04TOUCH_CALIB_LOAD		4	/**< load parameters form EEPROM */
#define EM04TOUCH_CALIB_CALC		5	/**< calulate parameters */
#define EM04TOUCH_CALIB_XDELTA		6	/**< read parameters (34) */
#define EM04TOUCH_CALIB_XOFFSET		7   
#define EM04TOUCH_CALIB_YDELTA		8
#define EM04TOUCH_CALIB_YOFFSET		9
#define EM04TOUCH_CALIB_LL			10	/**< calibrate lower left edge */
#define EM04TOUCH_CALIB_UR			11	/**< calibrate upper right edge */
#define EM04TOUCH_CALIB_MAXPARAM	EM04TOUCH_CALIB_UR
/**@}*/


/*! \defgroup DEVICES device defines
*/
/**@{*/
#define EM04TOUCH_DEV_TEMP			0	/**< define for temperature input */
#define EM04TOUCH_DEV_BATT			1	/**< define for battery input */
#define EM04TOUCH_DEV_TEMP_RAW_LO	2	/**< raw temp measurement low current */
#define EM04TOUCH_DEV_TEMP_RAW_HI	3	/**< raw temp measurement hi current */
/**@}*/

#define EM04TOUCH_AD7873_ID			0x800	/**< ID code of AD7873 controller */

/*! \defgroup TOUCHEVT Touch events
	There are 2 different touch events to report to th OS, stored in
	EM04TOUCH_EVENT::event
*/

/**@{*/
#define EM04TOUCH_PRESSED	0x85	/**< touch pressed */
#define EM04TOUCH_RELEASED	0x87	/**< touch released */
/**@}*/

#define EM04TOUCH_DSFLG_MOVE 0x1 	/**< generate move events  */
#define EM04TOUCH_DSFLG_NOSWAP 0x2 	/**< do not swap X/Y coordinates */

/*! \brief data structure for position and event of touch */
typedef struct {
	u_int8		event;	/**< event that causes the interrupt.
						 * touch event codes
						 * - 0x85 = touch pressed first time
						 * - 0x87 = touch relased 			*/
	u_int8		highx;	/**< absolute x position MSB 0..799 */
	u_int8		lowx;	/**< absolute x position LSB 0..799 */
	u_int8		highy;	/**< absolute y position MSB 0..599 */
	u_int8		lowy;	/**< absolute y position LSB 0..599 */
} EM04TOUCH_EVENT;

typedef void EM04TOUCH_HANDLE;
typedef u_int32 EM04TOUCH_ERRCODE;

/*! \brief data structure for touch initialization */
typedef struct {
	OSS_HANDLE			*osh;		/**< Oss handle */
	MACCESS				base;		/**< Base address of touch */
	u_int8				_rsvd1;		/**< was pci interrupt line */
	void				(*tefunctp)(EM04TOUCH_EVENT *, void*);
									/**< pointer to touchevent callback function
                                     *   this routine is implemented in OS and
                                     *   processed the touchevent data */
	void 				*data;		/**< pointer to data of touchevent */
	DBG_HANDLE			*dbh;		/**< debug handle */
	u_int32				debugLevel; /**< debug level */
	u_int16				ds_xres;	/**< current used x resolution of touch */
	u_int16				ds_yres;	/**< current used y resolution of touch */
	u_int16				ds_thresh;	/**< pixel threshold to generate new event */
	u_int8				ds_flags;	/**< was ds_move, now contains 2 flags
									   see EM04TOUCH_DSFLG_ above */
} EM04TOUCH_INIT;

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
u_int32	EM04TOUCH_MeasureAuxInp	( EM04TOUCH_HANDLE *th, u_int8 device );
EM04TOUCH_ERRCODE EM04TOUCH_Calibrate( EM04TOUCH_HANDLE *th, int mode );
EM04TOUCH_ERRCODE EM04TOUCH_Init( EM04TOUCH_INIT *tih,
								  EM04TOUCH_HANDLE **thP );
EM04TOUCH_ERRCODE EM04TOUCH_Irq( EM04TOUCH_HANDLE *th );
void 	EM04TOUCH_Exit( EM04TOUCH_HANDLE **thP );
int		EM04TOUCH_GetID( EM04TOUCH_HANDLE *th );

#ifdef __cplusplus
	}
#endif

#endif	/* _VORLAGEN_H */
