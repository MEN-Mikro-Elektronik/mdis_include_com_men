/***********************  I n c l u d e  -  F i l e  ***********************/
/*
 *         \file men_id.h
 *
 *       \author mko
 *
 *        \brief Header file with MEN specific PCI IDs
 *
 *     
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 2009-2019, MEN Mikro Elektronik GmbH
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

#ifndef _MEN_ID_H
#define _MEN_ID_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "chameleon.h"

/*--------------------------------------+
|   VENDOR IDs                          |
+--------------------------------------*/

#define     MEN_PCI_VEN_ID_ALTERA    CHAMELEON_PCI_VENID_ALTERA /* Altera PCI Vendor ID */
#define     MEN_PCI_VEN_ID_MEN       CHAMELEON_PCI_VENID_MEN    /* MEN PCI Vendor ID    */
  
/*--------------------------------------+
|   DEVICE IDs                          |
+--------------------------------------*/
  
#define     MEN_PCI_DEV_ID_CHAMELEON            CHAMELEON_PCI_DEV_ID /* standard chameleon device id */

 #define    MEN_PCI_DEV_ID_15EM05_01_A          0x0001      /* 15EM05_EC01  */
 #define    MEN_PCI_DEV_ID_15EM05_02_A          0x0002      /* 15EM05_F501  */
 #define    MEN_PCI_DEV_ID_15EM05_03_B          0x0003      /* 15EM05_F501 (old: same as 15EM05_02) */
 #define    MEN_PCI_DEV_ID_15EM05_AD65_A        0x0004      /* 15EM05_AD65  */
 #define    MEN_PCI_DEV_ID_15EM05_A500_A        0x0005      /* 15EM05_A500  */
 #define    MEN_PCI_DEV_ID_15EM05_02_B          0x0007      /* 15EM05_F501  */
 #define    MEN_PCI_DEV_ID_15EM03_A             0x0006      /* 15EM03_  */
 #define    MEN_PCI_DEV_ID_15EM07_03_A          0x0008      /* 15EM07-F502 */
 #define    MEN_PCI_DEV_ID_02F206_01_A          0x0009      /* 02F206-01    */
 #define    MEN_PCI_DEV_ID_02F401_A             0x000A      /* 02F401-  */
 #define    MEN_PCI_DEV_ID_02F206_00_B          0x000B      /* 02F206-00    */
 #define    MEN_PCI_DEV_ID_15PP04B_A            0x000C      /* 15PP04B  */
 #define    MEN_PCI_DEV_ID_02F206_A             0x000D      /* 02F206i01    */
 #define    MEN_PCI_DEV_ID_15EM07_02_A          0x000E      /* 15EM07-EC01n */
 #define    MEN_PCI_DEV_ID_15EM04NAD75_E        0x5104      /* 15EM04NAD75 with VGA */
 #define    MEN_PCI_DEV_ID_15EM07_01_B          0x0010      /* 15EM07-EC01n (EM07-00/01)    */
 #define    MEN_PCI_DEV_ID_02F206I00_B          0x0013      /* 02F206i00    */

/*--------------------------------------+
|   SUBSYSTEM VENDOR IDs                |
+--------------------------------------*/
#define     MEN_PCI_SUBSYSVEN_ID_15P018             0x0007      /* 15P018   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_01_A        0x0009      /* 02F206-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_04_B        0x000F      /* 15EM07-F502- */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_06_A        0x0011      /* 15EM07-A500- */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_05_C        0x0012      /* 15EM07-F502- */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04N08_A        0x0014      /* 15EM04NF500 */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_00_B        0x0015      /* 15EM01-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04N11_A        0x0016      /* 15EM04NEC04 */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_01_A        0x0017      /* 15EM01-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_01_A        0x0018      /* 15EM03-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04_02_K        0x0019      /* 15EM04-02    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_00_A        0x001A      /* 15EM01-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_00_C        0x001B      /* 15EM01-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_07_A        0x001C      /* 15EM07-07    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206N00_C        0x001D      /* 02F206N00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_03_A        0x001E      /* 15EM01-03    */
#define     MEN_PCI_SUBSYSVEN_ID_02D006_00_F0_A     0x001F      /* 02D006-00 func.0 */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_08_A        0x0020      /* 15EM07-08    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_02_A        0x0021      /* 15EM03-02    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM08_ZZ_A        0x0022      /* 15EM08-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_ZZ_A        0x0023      /* 15EM07-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_02D006_00_F1_A     0x0024      /* 02D006-00 func.1 */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03A_00_A       0x0025      /* 15EM03A-00   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A05_D        0x0026      /* 15EM01A05    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_00_E_A      0x0027      /* 15EM03-00 eval */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04N01_F        0x0028      /* 15EM04N-EC01-00  */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A02_A        0x0029      /* 15EM01A02    */
#define     MEN_PCI_SUBSYSVEN_ID_01A404_A           0x002a      /* A404 */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_ZZ_A        0x002b      /* 02F206-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_ZZ_B        0x002c      /* 02F206-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206N00_A        0x002d      /* F206N00  */
#define     MEN_PCI_SUBSYSVEN_ID_02F206N00_B        0x002e      /* F206N00  */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_00_A        0x002f      /* 15EM03-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03A00_B        0x0030      /* 15EM03A00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A04_F        0x0031      /* 15EM01A04    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A03_E        0x0032      /* 15EM01A03    */
#define     MEN_PCI_SUBSYSVEN_ID_15P599_00_A        0x0033      /* 15P599-00    */
#define     MEN_PCI_SUBSYSVEN_ID_02D006_01_A        0x0034      /* 02D006-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04N12_A        0x0035      /* 15EM04N12    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01_00_G        0x0036      /* 15EM01-00 (08EK06-ZZ)    */
#define     MEN_PCI_SUBSYSVEN_ID_15EP01_00_A        0x0037      /* 15EP01-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM04N11_B        0x0038      /* 15EM04NEC04 */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A06_A        0x0039      /* 15EM01A06(A406)  */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_01_B        0x003A      /* 15EM03-01    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_02_A        0x003B      /* 02F206-02    */
#define     MEN_PCI_SUBSYSVEN_ID_01A406_00_IC1_A    0x003C      /* 01A406-00IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_02F208_01_A        0x003D      /* 02F208-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM03_00_B        0x003E      /* 15EM03-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01A00_B        0x003F      /* 15EM01A00    */
#define     MEN_PCI_SUBSYSVEN_ID_01A406_00_IC2_A    0x0040      /* 01A406-00IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N00_A        0x0041      /* 15EM07N00IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N10_A        0x0042      /* 15EM07N10IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N03_A        0x0043      /* 15EM07N03IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N04_A        0x0044      /* 15EM07N04IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N08_D        0x0045      /* 15EM07N08IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM08_02_A        0x0046      /* 15EM08-02IC013   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01N02_A        0x0047      /* 15EM01N02IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_06VC01_00_A        0x0048      /* 06VC01-00IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07_AV_A        0x0049      /* 15EM07-AVIC008   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206N00_D        0x004A      /* 02F206N00    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_04_A        0x004B      /* 02F206-04    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N03_B        0x004C      /* 15EM07N03IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N10_B        0x004D      /* 15EM07N10IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM06_00_F0_A     0x004E      /* 15EM06-00 func.0   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01N00_A        0x004F      /* 15EM01N00IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_15P599_00_B        0x0050      /* 15P599-00    */
#define     MEN_PCI_SUBSYSVEN_ID_02F210_00_A        0x0051      /* 02F210-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM08_02_D        0x0052      /* 15EM08-02IC013   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01N01_A        0x0053      /* 15EM01N01IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_02F208_01_B        0x0054      /* 02F208-01    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_01_A        0x0055      /* 15EM09-01IC005   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_00_A        0x0056      /* 15EM09-00IC005   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_05_A        0x0057      /* 02F206-05    */
#define     MEN_PCI_SUBSYSVEN_ID_02D006_00_A        0x0058      /* 02D006-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM06_00_F1_A     0x0059      /* 15EM06-00 func.1    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206NZZ_A        0x005A      /* 02F206NZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_01A017_00_A        0x005B      /* 01A017-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15P598_00_A        0x005C      /* 15P598-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_00_B        0x005D      /* 15EM09-00IC005   */
#define     MEN_PCI_SUBSYSVEN_ID_02F302A00_A        0x005E      /* 02F302A00    */
#define     MEN_PCI_SUBSYSVEN_ID_01A017_00_B        0x005F      /* 01A017-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM08_ZZ_B        0x0060      /* 15EM08-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_02_A        0x0061      /* 15EM09-02    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM07N06_A        0x0062      /* 15EM07N06IC008   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206N00_E        0x0063      /* 02F206N00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM01N03_A        0x0064      /* 15EM01N03    */
#define     MEN_PCI_SUBSYSVEN_ID_15P599_Z1_A        0x0065      /* 15P599-ZZ (Z1)   */
#define     MEN_PCI_SUBSYSVEN_ID_15P599_Z2_B        0x0066      /* 15P599-ZZ (Z2)   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_ZZ_C        0x0067      /* 02F206-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_02F607_00_IC1_A    0x0068      /* 02F607-00IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_02F607_00_IC2_A    0x0069      /* 02F607-00IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_02F215_00_A        0x006A      /* 02F215-00IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_02F215_01_A        0x006B      /* 02F215-01IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_15EP01_01_A        0x006C      /* 15EP01-01IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_06VC01_01_A        0x006D      /* 06VC01-01IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_16P506_00_A        0x006E      /* 16P506-00    */
#define     MEN_PCI_SUBSYSVEN_ID_16P511_00_A        0x006F      /* 16P511-00    */
#define     MEN_PCI_SUBSYSVEN_ID_16P505_00_A        0x0070      /* 16P505-00    */
#define     MEN_PCI_SUBSYSVEN_ID_16P699_00_A        0x0071      /* 16P699-00    */
#define     MEN_PCI_SUBSYSVEN_ID_02F216_00_A        0x0072      /* 02F216-00    */
#define     MEN_PCI_SUBSYSVEN_ID_16P507_00_A        0x0073      /* 16P507-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_ZZ_A        0x0074      /* 15EM09-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_16AE16_00_IC1_A    0x0075      /* 16AE16-00IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_ZZ_D        0x0076      /* 02F206-ZZ    */
#define     MEN_PCI_SUBSYSVEN_ID_16AE16_01_A        0x0077      /* 16AE16-01IC001   */
#define     MEN_PCI_SUBSYSVEN_ID_16AE16_00_IC2_A    0x0078      /* 16AE16-00IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_16P508_01_A        0x0079      /* 16P508-01    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_Z2_A        0x007A      /* 02F206-Z2    */
#define     MEN_PCI_SUBSYSVEN_ID_15EM09_Z2_A        0x007B      /* 15EM09-Z2    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_08_A        0x007C      /* 02F206-08    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_09_A        0x007D      /* 02F206-09    */
#define     MEN_PCI_SUBSYSVEN_ID_02G300_00_A        0x007E      /* 02G300-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15MM01_00_A        0x0080      /* 15MM01-00    */
#define     MEN_PCI_SUBSYSVEN_ID_15EP01_00_B        0x0081      /* 15EP01-00IC002   */
#define     MEN_PCI_SUBSYSVEN_ID_01A012_A           0x0082      /* 01A012   */
#define     MEN_PCI_SUBSYSVEN_ID_15EM08_01_A        0x0083      /* 15EM08-01IC013   */
#define     MEN_PCI_SUBSYSVEN_ID_16D603_00          0x0084      /* 16D603-00    */
#define     MEN_PCI_SUBSYSVEN_ID_16P508_00_A        0x0085      /* 16P508-00    */
#define     MEN_PCI_SUBSYSVEN_ID_02F206_10_A        0x0086      /* 02F206-10    */ 


#endif /* _MEN_ID_H */


