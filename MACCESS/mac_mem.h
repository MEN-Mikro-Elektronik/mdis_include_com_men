/***********************  I n c l u d e  -  F i l e  ************************
 *
 *         Name: mac_mem.h
 *
 *       Author: uf
 *
 *  Description: access macros for memory mapped devices
 *
 *     Switches: MAC_BYTESWAP
 *
 *---------------------------------------------------------------------------
 * Copyright 1997-2019, MEN Mikro Elektronik GmbH
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


