/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mac_mem.h
 *
 *       Author: uf
 *        $Date: 2010/09/01 11:44:26 $
 *    $Revision: 1.20 $
 *
 *  Description: access macros for memory mapped devices
 *
 *     Switches: MAC_BYTESWAP
 *
 *-------------------------------[ History ]---------------------------------
 *
 * $Log: mac_mem.h,v $
 * Revision 1.20  2010/09/01 11:44:26  UFranke
 * R: bug in MBLOCK_WRITE_D16/32, MFIFO_WRITE_D16/32 if MAC_BYTESWAP
 *    if the access is not 8-word/dword aligned
 * M: fixed MBLOCK_WRITE_D16/32, MFIFO_WRITE_D16/32
 *
 * Revision 1.19  2010/01/28 16:07:54  ufranke
 * R: VxWorks DIAB PPX85XX compiler error
 * M: use asm keyword directly
 *
 * Revision 1.18  2009/04/01 15:02:54  ufranke
 * R: VXWORKS a lot of code includes maccess.h before oss.h
 *    redefinition of macro `WRS_ASM' and syntax error
 * M: fixed due to including vxWorks.h always in mac_mem.h
 *
 * Revision 1.17  2009/03/18 11:25:37  aw
 * R: Memory access ordering was not guaranted at powerpc e500 cores.
 * M: Added "eieio" syncronisation command after every last write command for OS9000
 *
 * Revision 1.16  2008/11/10 20:10:45  cs
 * R: 1. macros did not match for all versions of VxWorks (or compiler)
 *    2. was not compilable for VxWorks and diab compiler
 * M: 1. fixed macros
 *    2. removed extra paranthesis for each block
 *
 * Revision 1.15  2008/11/10 15:33:49  rt
 * R:1. File not compilable
 * M:1. Corrected comment syntax in macro
 *
 * Revision 1.14  2008/11/10 13:19:32  rt
 * R:1. Memory access ordering was not guaranted at powerpc e500 cores (see Freescale AN147).
 * M:1. Added "mbar 0" syncronisation command after every last write command.
 *      NOTE: Please test well (incl. performance test) before releasing SW including this fix!
 *
 * Revision 1.13  2007/06/06 15:59:53  aw
 * initial checkin
 *
 * Revision 1.11  2003/03/06 12:58:42  UFranke
 * replaced
 *   - 64 bit access type double by u_int64
 *
 * Revision 1.10  2001/03/22 13:37:43  kp
 * fixed MBLOCK_READ_D64
 *
 * Revision 1.9  2000/05/16 14:51:18  gromann
 * Added ";" in macros MBLOCK_SET_D16, MBLOCK_SET_D32 and MBLOCK_SET_D64
 *
 * Revision 1.8  2000/04/25 17:51:55  Franke
 * readded MBLOCK_READ_D64
 *
 * Revision 1.7  2000/04/12 10:43:15  kp
 * uups... forgot MBLOCK_WRITE_D8 for non swapping mode
 *
 * Revision 1.6  2000/03/08 14:04:00  kp
 * Added support for swapped access (MAC_BYTESWAP)
 *
 * Revision 1.5  1998/12/01 17:02:45  Franke
 * added D64
 *
 * Revision 1.4  1998/05/12 09:18:21  kp
 * added MACCESS_CLONE macro
 *
 * Revision 1.3  1998/04/20 10:04:31  kp
 * re-implemented all MBLOCK_xxx macros to speed up execution
 * implemented MFIFO_xxx macros
 *
 * Revision 1.2  1998/02/25 12:03:33  franke
 * MBLOCK_ parameter size is now byte size
 *
 * Revision 1.1  1998/02/19 09:19:17  franke
 * intitial
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 1997..2010 by MEN mikro elektronik GmbH, Nuremberg, Germany
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef _MAC_MEM_H
#   define _MAC_MEM_H

#ifdef MAC_BYTESWAP
#	define RSWAP64(a)	RSWAP64 NOT DEFINED!
#	define WSWAP64(a)	WSWAP64 NOT DEFINED!
#else
#	define RSWAP64(a)	(a)
#	define WSWAP64(a)	(a)
#endif

#if defined( MENMON )
#	if defined( PPC85XX )	/* see AN147 - Memory Access Ordering */
#		define MEN_WRSYNC_CMD {asm("mbar 0");}
#	endif /* PPC85XX */
#elif defined( VXWORKS )
#   include <vxWorks.h>
#	if (CPU == PPC85XX)
#		ifdef __GNUC__
#			define MEN_WRSYNC_CMD __asm__("eieio");
#       else
#			define MEN_WRSYNC_CMD __asm("eieio");
#		endif
#	endif /* PPC85XX */
#elif defined( OS9000 )
#	if defined( PPC85XX )	
#		define MEN_WRSYNC_CMD {_asm(" eieio");}
#	endif /* PPC85XX */
#endif /* MENMON || VXWORKS */

#ifdef MEN_WRSYNC_CMD
#	define MEN_WRSYNC(_wrCmd_) {                                  \
			   _wrCmd_;                                           \
			   MEN_WRSYNC_CMD; /* sync after last write command */ \
		   }
#else
#	define MEN_WRSYNC(_wrCmd_) _wrCmd_ /* default is no sync */
#endif /* MEN_WRSYNC_CMD */

/*------------------------------------------------------------------------+
|  direct access mode - hardware access via pointer                       |
+------------------------------------------------------------------------*/
typedef volatile void* MACCESS;         /* access pointer */

#define MACCESS_CLONE(ma_src,ma_dst,offs)	ma_dst=(MACCESS)((u_int8*)(ma_src)+(offs))

#define MREAD_D8(ma,offs)  \
        (*(volatile u_int8* )((u_int8*)(ma)+(offs)))
#define MREAD_D16(ma,offs) \
        RSWAP16(*(volatile u_int16*)((u_int8*)(ma)+(offs)))
#define MREAD_D32(ma,offs) \
        RSWAP32(*(volatile u_int32*)((u_int8*)(ma)+(offs)))
#define MREAD_D64(ma,offs) \
        RSWAP64(*(volatile u_int64* )((u_int8*)(ma)+(offs)))

#define MWRITE_D8(ma,offs,val) \
   MEN_WRSYNC(*(volatile u_int8* )((u_int8*)(ma)+(offs)) = val)
#define MWRITE_D16(ma,offs,val) \
   MEN_WRSYNC(*(volatile u_int16*)((u_int8*)(ma)+(offs)) = (u_int16)WSWAP16(val))
#define MWRITE_D32(ma,offs,val) \
   MEN_WRSYNC(*(volatile u_int32*)((u_int8*)(ma)+(offs)) = WSWAP32(val))
#define MWRITE_D64(ma,offs,val) \
   MEN_WRSYNC(*(volatile u_int64* )((u_int8*)(ma)+(offs)) = WSWAP64(val))

 #define MSETMASK_D8(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int8* )((u_int8*)(ma)+(offs)) |= (mask))
 #define MSETMASK_D16(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int16*)((u_int8*)(ma)+(offs)) |= WSWAP16(mask))
 #define MSETMASK_D32(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int32*)((u_int8*)(ma)+(offs)) |= WSWAP32(mask))
 #define MSETMASK_D64(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int64* )((u_int8*)(ma)+(offs)) |= WSWAP64(mask))

 #define MCLRMASK_D8(ma,offs,mask)  \
   MEN_WRSYNC(*(volatile u_int8* )((u_int8*)(ma)+(offs)) &= ~(mask))
 #define MCLRMASK_D16(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int16*)((u_int8*)(ma)+(offs)) &= ~WSWAP16(mask))
 #define MCLRMASK_D32(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int32*)((u_int8*)(ma)+(offs)) &= ~WSWAP32(mask))
 #define MCLRMASK_D64(ma,offs,mask) \
   MEN_WRSYNC(*(volatile u_int64* )((u_int8*)(ma)+(offs)) &= ~WSWAP64(mask))

#define MBLOCK_SET_D8(ma,offs,size,val) \
		MEN_WRSYNC(                            \
	        { int i;                           \
	          for( i=0; i<size; i++ )          \
	          {                                \
	               *(volatile u_int8* )((u_int8*)((u_int8*)(ma)+offs)+i) = val;\
	          }                                \
	        }                                  \
        )
#define MBLOCK_SET_D16(ma,offs,size,val) \
        MEN_WRSYNC(                              \
	        { int i; u_int16 swval=WSWAP16(val); \
	          for( i=0; i<size; i+=2 )           \
	          {                                  \
	               *(volatile u_int16* )((u_int8*)((u_int8*)(ma)+offs)+i) = swval;\
	          }                                  \
	        }                                    \
	    )
#define MBLOCK_SET_D32(ma,offs,size,val) \
        MEN_WRSYNC(                              \
	        { int i; u_int32 swval=WSWAP32(val); \
	          for( i=0; i<size; i+=4 )           \
	          {                                  \
	               *(volatile u_int32* )((u_int8*)((u_int8*)(ma)+offs)+i) = swval;\
	          }                                  \
	        }                                    \
        )
#define MBLOCK_SET_D64(ma,offs,size,val) \
		MEN_WRSYNC(                               \
	        { int i; u_int64 swval=WSWAP64(val);  \
	          for( i=0; i<size; i+=8 )            \
	          {                                   \
	               *(volatile u_int64*  )((u_int8*)((u_int8*)(ma)+offs)+i) = swval;\
	          }                                   \
	        }                                     \
		)

#define MBLOCK_READ_D8(ma,offs,size,dst)        			\
   { 														\
	  register volatile u_int8 *hw = 						\
				 (volatile u_int8 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>0;							\
      register u_int8 *mem = (u_int8 *)dst;					\
															\
      while(i >= 8){										\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  *mem++ = RSWAP8(*hw++);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP8(*hw++);							\
  }

#define MBLOCK_READ_D16(ma,offs,size,dst)        			\
   { 														\
	  register volatile u_int16 *hw = 						\
				 (volatile u_int16 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>1;							\
      register u_int16 *mem = (u_int16 *)dst;				\
															\
      while(i >= 8){										\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  *mem++ = RSWAP16(*hw++);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP16(*hw++);							\
  }

#define MBLOCK_READ_D32(ma,offs,size,dst)        			\
   { 														\
	  register volatile u_int32 *hw = 						\
				 (volatile u_int32 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>2;							\
      register u_int32 *mem = (u_int32 *)dst;				\
															\
      while(i >= 8){										\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  *mem++ = RSWAP32(*hw++);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP32(*hw++);							\
  }

#define MBLOCK_READ_D64(ma,offs,size,dst)        			\
   { 														\
	  register volatile u_int64 *hw = 						\
				 (volatile u_int64 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>3;							\
      register u_int64 *mem = (u_int64 *)dst;				\
															\
      while(i >= 8){										\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  *mem++ = RSWAP64(*hw++);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP64(*hw++);							\
  }


#ifndef MAC_BYTESWAP
/*--- MBLOCK_WRITE_DXX, non byteswapping ---*/

#define MBLOCK_WRITE_DXX(ma,offs,size,src,type,shift)		\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile type *hw = 							\
					 (volatile type *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>shift;						\
	      register type *mem = (type *)src;						\
			                                                    \
	      while(i >= 8){										\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
			  *hw++ = *mem++;									\
		}                                                       \
	)
#define MBLOCK_WRITE_D8(ma,offs,size,dst) \
   MBLOCK_WRITE_DXX(ma,offs,size,dst,u_int8,0)

#define MBLOCK_WRITE_D16(ma,offs,size,dst) \
   MBLOCK_WRITE_DXX(ma,offs,size,dst,u_int16,1)

#define MBLOCK_WRITE_D32(ma,offs,size,dst) \
   MBLOCK_WRITE_DXX(ma,offs,size,dst,u_int32,2)

#define MBLOCK_WRITE_D64(ma,offs,size,src) \
   MBLOCK_WRITE_DXX(ma,offs,size,dst,u_int64,3)

#else
/*--- MBLOCK_WRITE_DXX, byteswapping ---*/
#define MBLOCK_WRITE_D8(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int8 *hw = 						\
					 (volatile u_int8 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>0;							\
	      register u_int8 *mem = (u_int8 *)src;					\
			                                                    \
	      while(i >= 8){										\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  *hw++ = *mem++;									\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
			  *hw++ = *mem++;									\
	  }                                                         \
	)

#define MBLOCK_WRITE_D16(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int16 *hw = 						\
					 (volatile u_int16 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>1;							\
	      register u_int16 *mem = (u_int16 *)src;				\
			                                                    \
	      while(i >= 8){										\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  *hw++ = WSWAP16(*mem); mem++;						\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
		  {														\
			  *hw++ = WSWAP16(*mem); mem++;						\
		  }														\
	  }                                                         \
	)

#define MBLOCK_WRITE_D32(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int32 *hw = 						\
					 (volatile u_int32 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>2;							\
	      register u_int32 *mem = (u_int32 *)src;				\
			                                                    \
	      while(i >= 8){										\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  *hw++ = WSWAP32(*mem); mem++;						\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
		  {														\
			  *hw++ = WSWAP32(*mem); mem++;						\
		  }														\
	  }                                                         \
	)

#endif /* ?MAC_BYTESWAP */


#define MFIFO_READ_D8(ma,offs,size,dst)         			\
   { 														\
	  register volatile u_int8 *hw = 						\
				 (volatile u_int8 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>0;		   					\
      register u_int8 *mem = (u_int8 *)dst;					\
		                                                    \
      while(i >= 8){										\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  *mem++ = *hw;  									\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = *hw;  									\
  }

#define MFIFO_READ_D16(ma,offs,size,dst)         			\
   { 														\
	  register volatile u_int16 *hw = 						\
				 (volatile u_int16 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>1;		   					\
      register u_int16 *mem = (u_int16 *)dst;				\
		                                                    \
      while(i >= 8){										\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  *mem++ = RSWAP16(*hw);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP16(*hw);							\
  }

#define MFIFO_READ_D32(ma,offs,size,dst)         			\
   { 														\
	  register volatile u_int32 *hw = 						\
				 (volatile u_int32 *)((u_int8*)(ma)+offs); 	\
	  register u_int32 i=(size)>>2;		   					\
      register u_int32 *mem = (u_int32 *)dst;				\
		                                                    \
      while(i >= 8){										\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  *mem++ = RSWAP32(*hw);							\
		  i -= 8;											\
	  }														\
	  while( i-- )											\
		  *mem++ = RSWAP32(*hw);							\
  }

#ifndef MAC_BYTESWAP
/*--- MFIFO_WRITE_DXX, non byteswapping ---*/

#define MFIFO_WRITE_DXX(ma,offs,size,src,type,shift)	    \
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile type *hw = 							\
					 (volatile type *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>shift;						\
	      register type *mem = (type *)src;						\
			                                                    \
	      while(i >= 8){										\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
			  *hw = *mem++;  									\
	  }                                                         \
	)

#define MFIFO_WRITE_D8(ma,offs,size,dst) \
   MFIFO_WRITE_DXX(ma,offs,size,dst,u_int8,0)

#define MFIFO_WRITE_D16(ma,offs,size,dst) \
   MFIFO_WRITE_DXX(ma,offs,size,dst,u_int16,1)

#define MFIFO_WRITE_D32(ma,offs,size,dst) \
   MFIFO_WRITE_DXX(ma,offs,size,dst,u_int32,2)

#define MFIFO_WRITE_D64(ma,offs,size,dst) \
   MFIFO_WRITE_DXX(ma,offs,size,dst,u_int64,3)

#else
/*--- MFIFO_WRITE_DXX, byteswapping ---*/
#define MFIFO_WRITE_D8(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int8 *hw = 						\
					 (volatile u_int8 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>0;							\
	      register u_int8 *mem = (u_int8 *)src;					\
			                                                    \
	      while(i >= 8){										\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  *hw = *mem++;  									\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
			  *hw = *mem++;  									\
	  }                                                         \
	)

#define MFIFO_WRITE_D16(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int16 *hw = 						\
					 (volatile u_int16 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>1;							\
	      register u_int16 *mem = (u_int16 *)src;				\
			                                                    \
	      while(i >= 8){										\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  *hw = WSWAP16(*mem); mem++;						\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
		  {														\
			  *hw = WSWAP16(*mem); mem++;						\
		  }														\
	  }                                                         \
	)

#define MFIFO_WRITE_D32(ma,offs,size,src)	    			\
	MEN_WRSYNC(                                                 \
	   { 														\
		  register volatile u_int32 *hw = 						\
					 (volatile u_int32 *)((u_int8*)(ma)+offs); 	\
		  register u_int32 i=(size)>>2;							\
	      register u_int32 *mem = (u_int32 *)src;				\
			                                                    \
	      while(i >= 8){										\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  *hw = WSWAP32(*mem); mem++;						\
			  i -= 8;											\
		  }														\
		  while( i-- )											\
		  {														\
			  *hw = WSWAP32(*mem); mem++;						\
		  }														\
	  }                                                         \
	)

#endif /* ?MAC_BYTESWAP */


#endif


