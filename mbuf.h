/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mbuf.h
 *
 *       Author: uf
 *        $Date: 1998/04/17 15:40:12 $
 *    $Revision: 1.2 $
 *
 *  Description: input/output buffer handling and
 *               high/low water signaling to application
 *
 *     Switches: _NO_MBUF_HANDLE	don't declare MBUF_HANDLE
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1997 by MEN mikro elektronik GmbH, Nuremberg, Germany
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

#ifndef _MBUF_H
#   define MBUF_H

#   ifdef __cplusplus
      extern "C" {
#   endif

   /*-----------------------------------------+
   |  TYPEDEFS                                |
   +------------------------------------------*/
#   ifndef _NO_MBUF_HANDLE
       typedef void* MBUF_HANDLE;
#   endif

   /*-----------------------------------------+
   |  DEFINES & CONST                         |
   +------------------------------------------*/
   /* buffer direction */
   #define MBUF_RD          0
   #define MBUF_WR          1

   /* event codes */
   #define MBUF_EV_full      0x01   /* input buffer full */
   #define MBUF_EV_newspace  0x02   /* input buffer new space available */
   #define MBUF_EV_newdata   0x04   /* output buffer contains new data */
   #define MBUF_EV_empty     0x08   /* output buffer empty */

   /* error flags */
   #define MBUF_ERROR_DISABLED 0
   #define MBUF_ERROR_ENABLED  1    /* underrun/overflow error enable */
   #define MBUF_ERROR_OCCURED  1    /* underrun/overflow error flag */

   /*-----------------------------------------+
   |  GLOBALS                                 |
   +------------------------------------------*/

   /*-----------------------------------------+
   |  PROTOTYPES                              |
   +------------------------------------------*/
   extern int32 MBUF_Create( OSS_HANDLE      *osHdl,
                             OSS_SEM_HANDLE  *devSem,
                             void*           lldrvHdl,
                             int32           size,
                             int32           width,
                             int32           mode,
                             int32           direction,
                             int32           lowHighWater,
                             int32           timeout,
                             OSS_IRQ_HANDLE  *irqHdl,
                             MBUF_HANDLE     **bufHdlP
                             );

   extern int32 MBUF_Remove( MBUF_HANDLE  **bufHdlP );

   extern int32 MBUF_Write(
                              MBUF_HANDLE     *bufHdl,
                              u_int8          *buffer,
                              u_int32         size,
                              int32           *nbrWrBytes
                          );


   extern int32 MBUF_Read(
                             MBUF_HANDLE     *bufHdl,
                             u_int8          *buffer,
                             u_int32         size,
                             int32           *nbrRdBytes
                         );


   extern int32 MBUF_SetStat(
                                MBUF_HANDLE *rdBufHdl,
                                MBUF_HANDLE *wrBufHdl,
                                int32       code,
                                int32       value
                            );



   extern int32 MBUF_GetStat(
                                MBUF_HANDLE  *rdBufHdl,
                                MBUF_HANDLE  *wrBufHdl,
                                int32        code,
                                int32        *valueP
                            );

   extern void* MBUF_GetNextBuf( MBUF_HANDLE *bufHdl, int32 size,
                                 int32 *gotsizeP );

   extern int32 MBUF_ReadyBuf(   MBUF_HANDLE *bufHdl );

   extern int32 MBUF_GetBufferMode(
                                      MBUF_HANDLE  *bufHdl,
                                      int32        *modeP
                                  );

   extern int32 MBUF_EventHdlrInst
   (
       MBUF_HANDLE    *bufHdl,
       int32          (*handler)( void*    lldrvHdl
                                 ,u_int32 ev_flags),
       int32          flags
   );


   extern char* MBUF_Ident( void );


#  ifdef __cplusplus
      }
#  endif

#endif/*_MBUF_H*/

