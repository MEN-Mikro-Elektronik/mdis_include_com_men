/***********************  I n c l u d e  -  F i l e  ***********************/
/*!
*        \file  wdog.h
*
*      \author  dp
*        $Date: 2006/05/26 15:08:34 $
*    $Revision: 2.6 $
*
*       \brief  Header file for Watchdog drivers
*               - Watchdog specific status codes
*
*    \switches  ---
*/
/*
* (c) Copyright 1999 by MEN mikro elektronik GmbH, Nuernberg, Germany
****************************************************************************/

#ifndef _WDOG_H
#define _WDOG_H

#ifdef __cplusplus
extern "C" {
#endif

	/*-----------------------------------------+
	|  DEFINES                                 |
	+-----------------------------------------*/
#define M_CH_PROFILE_WDOG	200		/**< profile type (returned in M_LL_CH_TYP */

/** \name Watchdog specific Getstat/Setstat standard codes
*  \anchor wdog_getstat_setstat_codes
*/
/**@{*/
/* ----------- codes before 2016 ----------- */
#define WDOG_START		(M_DEV_OF+0xe0)		/**<  S: Enable watchdog counter */
#define WDOG_TRIG		(M_DEV_OF+0xe1)		/**<  S: Clear watchdog counter */
#define WDOG_STOP		(M_DEV_OF+0xe2) 	/**<  S: Disable watchdog counter */
#define WDOG_TIME		(M_DEV_OF+0xe3)		/**<G,S: Get-/Set watchdog MAX time [ms] */
#define WDOG_STATUS		(M_DEV_OF+0xe4)		/**<G  : Get watchdog counter state
											         (0=disabled, 1=enabled) */
#define WDOG_SHOT		(M_DEV_OF+0xe5)		/**<G  : Get watchdog shot info:
											           0=no wdog shot
											           1=wdog shot
											         255=not identifiable */

/* ----------- additional codes since 2016 ----------- */
#define WDOG_RESET_CTRL (M_DEV_OF+0xf0)		/**<  S: Reset watchdog controller 
											         (counter, output/IRQ pin) */
#define WDOG_TRIG_PAT	(M_DEV_OF+0xf1)		/**<G,S: Trigger watchdog with pattern
													 get last used pattern */
#define WDOG_TIME_MIN	(M_DEV_OF+0xf2)		/**<G,S: Get-/Set watchdog MIN time [us] */
#define WDOG_TIME_MAX	(M_DEV_OF+0xf3)		/**<G,S: Get-/Set watchdog MAX time [us] */
#define WDOG_TIME_IRQ	(M_DEV_OF+0xf4)		/**<G,S: Get-/Set Watchdog IRQ time [us] */
#define WDOG_OUT_PIN	(M_DEV_OF+0xf5)		/**<G,S: 0=clear, 1=set output pin */
#define WDOG_OUT_REASON	(M_DEV_OF+0xf6)		/**<G,S: get/clear reason of last output pin
											         trigger since power-up:
											         0=not triggered
											         1=triggered due to min timeout
											         2=triggered due to max timeout
											         3=manually triggered */
#define WDOG_IRQ_PIN	(M_DEV_OF+0xf7)		/**<G,S: 0=clear, 1=set IRQ pin */
#define WDOG_IRQ_SIGSET	(M_DEV_OF+0xf8)		/**<  S: Install signal to be sent on IRQ */
#define WDOG_IRQ_SIGCLR	(M_DEV_OF+0xf9)		/**<  S: Uninstall signal */
#define WDOG_IRQ_REASON	(M_DEV_OF+0xfa)		/**<G,S: get/clear reason of IRQ pin
											         trigger since power-up:
											         0=not triggered
													 1 is unused
											         2=triggered due to IRQ timeout
											         3=manually triggered */
#define WDOG_ERR_PIN	(M_DEV_OF+0xfb)		/**<G,S: 0=clear, 1=set error pin */

/*
 * Trigger pattern for WDOG_TRIG_PAT SetStat.
 *
 * Alternating 0x5A/0xA5 pattern required for Z47 IP core and defined here
 * for common WDOG_TRIG_PAT SetStat. Should be mapped within other WDOG drivers
 * to device specific patterns (if neccessary).
 */
#define WDOG_TRIGPAT(n)		(((n)==0) ? 0x5A : 0xA5)
/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* WDOG_H */




