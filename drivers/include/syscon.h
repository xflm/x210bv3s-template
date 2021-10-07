#ifndef _SYSCON_H_
#define _SYSCON_H_

#include "soc.h"

#define SYSCON_BASE                                      SOC_SYSCON_BASE_ADDR

#define _SYSCON_OFF(off, val)                            off
#define _SYSCON_VAL(off, val)                            val

#define SYSCON_CLK_SRC_MASK(src)                         (0xF<<(_SYSCON_OFF(src)*4))
#define SYSCON_CLK_SRC_SEL(src)                          (_SYSCON_VAL(src)<<(_SYSCON_OFF(src)*4))

#define SYSCON_CLK_SRC0_APLL_SEL_FINPLL                  0,0
#define SYSCON_CLK_SRC0_APLL_SEL_FOUTAPLL                0,1
#define SYSCON_CLK_SRC0_MPLL_SEL_FINPLL                  1,0
#define SYSCON_CLK_SRC0_MPLL_SEL_FOUTMPLL                1,1
#define SYSCON_CLK_SRC0_EPLL_SEL_FINPLL                  2,0
#define SYSCON_CLK_SRC0_EPLL_SEL_FOUTEPLL                2,1
#define SYSCON_CLK_SRC0_VPLL_SEL_FINVPLL                 3,0
#define SYSCON_CLK_SRC0_VPLL_SEL_FOUTVPLL                3,1
#define SYSCON_CLK_SRC0_MUX_MSYS_SEL_SCLKAPLL            4,0
#define SYSCON_CLK_SRC0_MUX_MSYS_SEL_SCLKMPLL            4,1
#define SYSCON_CLK_SRC0_MUX_DSYS_SEL_SCLKMPLL            5,0
#define SYSCON_CLK_SRC0_MUX_DSYS_SEL_SCLKA2M             5,1
#define SYSCON_CLK_SRC0_MUX_PSYS_SEL_SCLKMPLL            6,0
#define SYSCON_CLK_SRC0_MUX_PSYS_SEL_SCLKA2M             6,1
#define SYSCON_CLK_SRC0_ONENAND_SEL_HCLK_PSYS            7,0
#define SYSCON_CLK_SRC0_ONENAND_SEL_HCLK_DSYS            7,1

#define SYSCON_CLK_SRC1_HDMI_SEL_SCLK_PIXEL              0,0
#define SYSCON_CLK_SRC1_HDMI_SEL_SCLK_HDMIPHY            0,1
#define SYSCON_CLK_SRC1_MIXER_SEL_SCLK_DAC               1,0
#define SYSCON_CLK_SRC1_MIXER_SEL_SCLK_HDMI              1,1
#define SYSCON_CLK_SRC1_DAC_SEL_SCLKVPLL                 2,0
#define SYSCON_CLK_SRC1_DAC_SEL_SCLK_HDMIPHY             2,1
#define SYSCON_CLK_SRC1_CAM0_SEL_XXTI                    3,0
#define SYSCON_CLK_SRC1_CAM0_SEL_XusbXTI                 3,1
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLK_HDMI27M            3,2
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLK_USBPHY0            3,3
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLK_USBPHY1            3,4
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLK_HDMIPHY            3,5
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLKMPLL                3,6
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLKEPLL                3,7
#define SYSCON_CLK_SRC1_CAM0_SEL_SCLKVPLL                3,8
#define SYSCON_CLK_SRC1_CAM1_SEL_XXTI                    4,0
#define SYSCON_CLK_SRC1_CAM1_SEL_XusbXTI                 4,1
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLK_HDMI27M            4,2
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLK_USBPHY0            4,3
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLK_USBPHY1            4,4
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLK_HDMIPHY            4,5
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLKMPLL                4,6
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLKEPLL                4,7
#define SYSCON_CLK_SRC1_CAM1_SEL_SCLKVPLL                4,8
#define SYSCON_CLK_SRC1_FIMD_SEL_XXTI                    5,0
#define SYSCON_CLK_SRC1_FIMD_SEL_XusbXTI                 5,1
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLK_HDMI27M            5,2
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLK_USBPHY0            5,3
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLK_USBPHY1            5,4
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLK_HDMIPHY            5,5
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLKMPLL                5,6
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLKEPLL                5,7
#define SYSCON_CLK_SRC1_FIMD_SEL_SCLKVPLL                5,8
#define SYSCON_CLK_SRC1_CSIS_SEL_XXTI                    6,0
#define SYSCON_CLK_SRC1_CSIS_SEL_XusbXTI                 6,1
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLK_HDMI27M            6,2
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLK_USBPHY0            6,3
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLK_USBPHY1            6,4
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLK_HDMIPHY            6,5
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLKMPLL                6,6
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLKEPLL                6,7
#define SYSCON_CLK_SRC1_CSIS_SEL_SCLKVPLL                6,8

#define SYSCON_CLK_SRC2_G3D_SEL_SCLKA2M                  0,0
#define SYSCON_CLK_SRC2_G3D_SEL_SCLKMPLL                 0,1
#define SYSCON_CLK_SRC2_G3D_SEL_SCLKEPLL                 0,2
#define SYSCON_CLK_SRC2_G3D_SEL_SCLKVPLL                 0,3
#define SYSCON_CLK_SRC2_MFC_SEL_SCLKA2M                  1,0
#define SYSCON_CLK_SRC2_MFC_SEL_SCLKMPLL                 1,1
#define SYSCON_CLK_SRC2_MFC_SEL_SCLKEPLL                 1,2
#define SYSCON_CLK_SRC2_MFC_SEL_SCLKVPLL                 1,3
#define SYSCON_CLK_SRC2_G2D_SEL_SCLKA2M                  2,0
#define SYSCON_CLK_SRC2_G2D_SEL_SCLKMPLL                 2,1
#define SYSCON_CLK_SRC2_G2D_SEL_SCLKEPLL                 2,2
#define SYSCON_CLK_SRC2_G2D_SEL_SCLKVPLL                 2,3

#define SYSCON_CLK_SRC3_F0_XXTI                          3,0
#define SYSCON_CLK_SRC3_F0_XusbXTI                       3,1
#define SYSCON_CLK_SRC3_F0_SCLK_HDMI27M                  3,2
#define SYSCON_CLK_SRC3_F0_SCLK_USBPHY0                  3,3
#define SYSCON_CLK_SRC3_F0_SCLK_USBPHY1                  3,4
#define SYSCON_CLK_SRC3_F0_SCLK_HDMIPHY                  3,5
#define SYSCON_CLK_SRC3_F0_SCLKMPLL                      3,6
#define SYSCON_CLK_SRC3_F0_SCLKEPLL                      3,7
#define SYSCON_CLK_SRC3_F0_SCLKVPLL                      3,8
#define SYSCON_CLK_SRC3_F1_XXTI                          4,0
#define SYSCON_CLK_SRC3_F1_XusbXTI                       4,1
#define SYSCON_CLK_SRC3_F1_SCLK_HDMI27M                  4,2
#define SYSCON_CLK_SRC3_F1_SCLK_USBPHY0                  4,3
#define SYSCON_CLK_SRC3_F1_SCLK_USBPHY1                  4,4
#define SYSCON_CLK_SRC3_F1_SCLK_HDMIPHY                  4,5
#define SYSCON_CLK_SRC3_F1_SCLKMPLL                      4,6
#define SYSCON_CLK_SRC3_F1_SCLKEPLL                      4,7
#define SYSCON_CLK_SRC3_F1_SCLKVPLL                      4,8
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_XXTI               5,0
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_XusbXTI            5,1
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLK_HDMI27M       5,2
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLK_USBPHY0       5,3
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLK_USBPHY1       5,4
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLK_HDMIPHY       5,5
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLKMPLL           5,6
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLKEPLL           5,7
#define SYSCON_CLK_SRC3_FIMC_LCLK_SEL_SCLKVPLL           5,8

#define SYSCON_CLK_SRC4_MMC0_SEL_XXTI                    0,0
#define SYSCON_CLK_SRC4_MMC0_SEL_XusbXTI                 0,1
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLK_HDMI27M            0,2
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLK_USBPHY0            0,3
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLK_USBPHY1            0,4
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLK_HDMIPHY            0,5
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLKMPLL                0,6
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLKEPLL                0,7
#define SYSCON_CLK_SRC4_MMC0_SEL_SCLKVPLL                0,8
#define SYSCON_CLK_SRC4_MMC1_SEL_XXTI                    1,0
#define SYSCON_CLK_SRC4_MMC1_SEL_XusbXTI                 1,1
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLK_HDMI27M            1,2
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLK_USBPHY0            1,3
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLK_USBPHY1            1,4
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLK_HDMIPHY            1,5
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLKMPLL                1,6
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLKEPLL                1,7
#define SYSCON_CLK_SRC4_MMC1_SEL_SCLKVPLL                1,8
#define SYSCON_CLK_SRC4_MMC2_SEL_XXTI                    2,0
#define SYSCON_CLK_SRC4_MMC2_SEL_XusbXTI                 2,1
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLK_HDMI27M            2,2
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLK_USBPHY0            2,3
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLK_USBPHY1            2,4
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLK_HDMIPHY            2,5
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLKMPLL                2,6
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLKEPLL                2,7
#define SYSCON_CLK_SRC4_MMC2_SEL_SCLKVPLL                2,8
#define SYSCON_CLK_SRC4_MMC3_SEL_XXTI                    3,0
#define SYSCON_CLK_SRC4_MMC3_SEL_XusbXTI                 3,1
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLK_HDMI27M            3,2
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLK_USBPHY0            3,3
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLK_USBPHY1            3,4
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLK_HDMIPHY            3,5
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLKMPLL                3,6
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLKEPLL                3,7
#define SYSCON_CLK_SRC4_MMC3_SEL_SCLKVPLL                3,8
#define SYSCON_CLK_SRC4_UART0_SEL_XXTI                   4,0
#define SYSCON_CLK_SRC4_UART0_SEL_XusbXTI                4,1
#define SYSCON_CLK_SRC4_UART0_SEL_SCLK_HDMI27M           4,2
#define SYSCON_CLK_SRC4_UART0_SEL_SCLK_USBPHY0           4,3
#define SYSCON_CLK_SRC4_UART0_SEL_SCLK_USBPHY1           4,4
#define SYSCON_CLK_SRC4_UART0_SEL_SCLK_HDMIPHY           4,5
#define SYSCON_CLK_SRC4_UART0_SEL_SCLKMPLL               4,6
#define SYSCON_CLK_SRC4_UART0_SEL_SCLKEPLL               4,7
#define SYSCON_CLK_SRC4_UART0_SEL_SCLKVPLL               4,8
#define SYSCON_CLK_SRC4_UART1_SEL_XXTI                   5,0
#define SYSCON_CLK_SRC4_UART1_SEL_XusbXTI                5,1
#define SYSCON_CLK_SRC4_UART1_SEL_SCLK_HDMI27M           5,2
#define SYSCON_CLK_SRC4_UART1_SEL_SCLK_USBPHY0           5,3
#define SYSCON_CLK_SRC4_UART1_SEL_SCLK_USBPHY1           5,4
#define SYSCON_CLK_SRC4_UART1_SEL_SCLK_HDMIPHY           5,5
#define SYSCON_CLK_SRC4_UART1_SEL_SCLKMPLL               5,6
#define SYSCON_CLK_SRC4_UART1_SEL_SCLKEPLL               5,7
#define SYSCON_CLK_SRC4_UART1_SEL_SCLKVPLL               5,8
#define SYSCON_CLK_SRC4_UART2_SEL_XXTI                   6,0
#define SYSCON_CLK_SRC4_UART2_SEL_XusbXTI                6,1
#define SYSCON_CLK_SRC4_UART2_SEL_SCLK_HDMI27M           6,2
#define SYSCON_CLK_SRC4_UART2_SEL_SCLK_USBPHY0           6,3
#define SYSCON_CLK_SRC4_UART2_SEL_SCLK_USBPHY1           6,4
#define SYSCON_CLK_SRC4_UART2_SEL_SCLK_HDMIPHY           6,5
#define SYSCON_CLK_SRC4_UART2_SEL_SCLKMPLL               6,6
#define SYSCON_CLK_SRC4_UART2_SEL_SCLKEPLL               6,7
#define SYSCON_CLK_SRC4_UART2_SEL_SCLKVPLL               6,8
#define SYSCON_CLK_SRC4_UART3_SEL_XXTI                   7,0
#define SYSCON_CLK_SRC4_UART3_SEL_XusbXTI                7,1
#define SYSCON_CLK_SRC4_UART3_SEL_SCLK_HDMI27M           7,2
#define SYSCON_CLK_SRC4_UART3_SEL_SCLK_USBPHY0           7,3
#define SYSCON_CLK_SRC4_UART3_SEL_SCLK_USBPHY1           7,4
#define SYSCON_CLK_SRC4_UART3_SEL_SCLK_HDMIPHY           7,5
#define SYSCON_CLK_SRC4_UART3_SEL_SCLKMPLL               7,6
#define SYSCON_CLK_SRC4_UART3_SEL_SCLKEPLL               7,7
#define SYSCON_CLK_SRC4_UART3_SEL_SCLKVPLL               7,8

#define SYSCON_CLK_SRC5_SPI0_SEL_XXTI                    0,0
#define SYSCON_CLK_SRC5_SPI0_SEL_XusbXTI                 0,1
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLK_HDMI27M            0,2
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLK_USBPHY0            0,3
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLK_USBPHY1            0,4
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLK_HDMIPHY            0,5
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLKMPLL                0,6
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLKEPLL                0,7
#define SYSCON_CLK_SRC5_SPI0_SEL_SCLKVPLL                0,8
#define SYSCON_CLK_SRC5_SPI1_SEL_XXTI                    1,0
#define SYSCON_CLK_SRC5_SPI1_SEL_XusbXTI                 1,1
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLK_HDMI27M            1,2
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLK_USBPHY0            1,3
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLK_USBPHY1            1,4
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLK_HDMIPHY            1,5
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLKMPLL                1,6
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLKEPLL                1,7
#define SYSCON_CLK_SRC5_SPI1_SEL_SCLKVPLL                1,8
#define SYSCON_CLK_SRC5_PWM_SEL_XXTI                     3,0
#define SYSCON_CLK_SRC5_PWM_SEL_XusbXTI                  3,1
#define SYSCON_CLK_SRC5_PWM_SEL_SCLK_HDMI27M             3,2
#define SYSCON_CLK_SRC5_PWM_SEL_SCLK_USBPHY0             3,3
#define SYSCON_CLK_SRC5_PWM_SEL_SCLK_USBPHY1             3,4
#define SYSCON_CLK_SRC5_PWM_SEL_SCLK_HDMIPHY             3,5
#define SYSCON_CLK_SRC5_PWM_SEL_SCLKMPLL                 3,6
#define SYSCON_CLK_SRC5_PWM_SEL_SCLKEPLL                 3,7
#define SYSCON_CLK_SRC5_PWM_SEL_SCLKVPLL                 3,8

#define SYSCON_CLK_SRC6_AUDIO0_SEL_XXTI                  0,0
#define SYSCON_CLK_SRC6_AUDIO0_SEL_XusbXTI               0,1
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLK_HDMI27M          0,2
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLK_USBPHY0          0,3
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLK_USBPHY1          0,4
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLK_HDMIPHY          0,5
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLKMPLL              0,6
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLKEPLL              0,7
#define SYSCON_CLK_SRC6_AUDIO0_SEL_SCLKVPLL              0,8
#define SYSCON_CLK_SRC6_AUDIO1_SEL_XXTI                  1,0
#define SYSCON_CLK_SRC6_AUDIO1_SEL_XusbXTI               1,1
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLK_HDMI27M          1,2
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLK_USBPHY0          1,3
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLK_USBPHY1          1,4
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLK_HDMIPHY          1,5
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLKMPLL              1,6
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLKEPLL              1,7
#define SYSCON_CLK_SRC6_AUDIO1_SEL_SCLKVPLL              1,8
#define SYSCON_CLK_SRC6_AUDIO2_SEL_XXTI                  2,0
#define SYSCON_CLK_SRC6_AUDIO2_SEL_XusbXTI               2,1
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLK_HDMI27M          2,2
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLK_USBPHY0          2,3
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLK_USBPHY1          2,4
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLK_HDMIPHY          2,5
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLKMPLL              2,6
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLKEPLL              2,7
#define SYSCON_CLK_SRC6_AUDIO2_SEL_SCLKVPLL              2,8
#define SYSCON_CLK_SRC6_SPDIF_SEL_SCLK_AUDIO0            3,0
#define SYSCON_CLK_SRC6_SPDIF_SEL_SCLK_AUDIO1            3,1
#define SYSCON_CLK_SRC6_SPDIF_SEL_SCLK_AUDIO2            3,2
#define SYSCON_CLK_SRC6_HPM_SEL_SCLKAPLL                 4,0
#define SYSCON_CLK_SRC6_HPM_SEL_SCLKMPLL                 4,1
#define SYSCON_CLK_SRC6_PWI_SEL_XXTI                     5,0
#define SYSCON_CLK_SRC6_PWI_SEL_XusbXTI                  5,1
#define SYSCON_CLK_SRC6_PWI_SEL_SCLK_HDMI27M             5,2
#define SYSCON_CLK_SRC6_PWI_SEL_SCLK_USBPHY0             5,3
#define SYSCON_CLK_SRC6_PWI_SEL_SCLK_USBPHY1             5,4
#define SYSCON_CLK_SRC6_PWI_SEL_SCLK_HDMIPHY             5,5
#define SYSCON_CLK_SRC6_PWI_SEL_SCLKMPLL                 5,6
#define SYSCON_CLK_SRC6_PWI_SEL_SCLKEPLL                 5,7
#define SYSCON_CLK_SRC6_PWI_SEL_SCLKVPLL                 5,8
#define SYSCON_CLK_SRC6_DMC0_SEL_SCLKA2M                 6,0
#define SYSCON_CLK_SRC6_DMC0_SEL_SCLKMPLL                6,1
#define SYSCON_CLK_SRC6_DMC0_SEL_SCLKEPLL                6,2
#define SYSCON_CLK_SRC6_DMC0_SEL_SCLKVPLL                6,3


#define SYSCON_CLK_SRC_MASK_MASK(mask)                   (0x1<<(mask))
#define SYSCON_CLK_SRC_MASK_DIS                          (0x0<<(mask))
#define SYSCON_CLK_SRC_MASK_EN                           (0x1<<(mask))

#define SYSCON_CLK_SRC_MASK0_PWI                         29
#define SYSCON_CLK_SRC_MASK0_SPDIF                       27
#define SYSCON_CLK_SRC_MASK0_AUDIO2                      26
#define SYSCON_CLK_SRC_MASK0_AUDIO1                      25
#define SYSCON_CLK_SRC_MASK0_AUDIO0                      24
#define SYSCON_CLK_SRC_MASK0_PWM                         19
#define SYSCON_CLK_SRC_MASK0_SPI1                        17
#define SYSCON_CLK_SRC_MASK0_SPI0                        16
#define SYSCON_CLK_SRC_MASK0_UART3                       15
#define SYSCON_CLK_SRC_MASK0_UART2                       14
#define SYSCON_CLK_SRC_MASK0_UART1                       13
#define SYSCON_CLK_SRC_MASK0_UART0                       12
#define SYSCON_CLK_SRC_MASK0_MMC3                        11
#define SYSCON_CLK_SRC_MASK0_MMC2                        10
#define SYSCON_CLK_SRC_MASK0_MMC1                        9
#define SYSCON_CLK_SRC_MASK0_MMC0                        8
#define SYSCON_CLK_SRC_MASK0_FINVPLL                     7
#define SYSCON_CLK_SRC_MASK0_CSIS                        6
#define SYSCON_CLK_SRC_MASK0_FIMD                        5
#define SYSCON_CLK_SRC_MASK0_CAM1                        4
#define SYSCON_CLK_SRC_MASK0_CAM0                        3
#define SYSCON_CLK_SRC_MASK0_DAC                         2
#define SYSCON_CLK_SRC_MASK0_MIXER                       1
#define SYSCON_CLK_SRC_MASK0_HDMI                        0

#define SYSCON_CLK_SRC_MASK1_FIMC_LCLK                   4
#define SYSCON_CLK_SRC_MASK1_F1                          3
#define SYSCON_CLK_SRC_MASK1_F0                          2


#define SYSCON_CLK_DIV_MASK(div)                         (_SYSCON_VAL(div)<<(_SYSCON_OFF(div)*4))
#define SYSCON_CLK_DIV_SET(div, val)                     ((val)<<(_SYSCON_OFF(div)*4))

#define SYSCON_CLK_DIV0_APLL_RATIO_RATIO_MOUT_MSYS_7     0,0x7  /* ARMCLK */
#define SYSCON_CLK_DIV0_A2M_RATIO_SCLKAPLL_7             1,0x7  /* SCLKA2M */
#define SYSCON_CLK_DIV0_HCLK_MSYS_RATIO_ARMCLK_7         2,0x7
#define SYSCON_CLK_DIV0_PCLK_MSYS_RATIO_HCLK_MSYS_7      3,0x7
#define SYSCON_CLK_DIV0_HCLK_DSYS_RATIO_MOUT_DSYS_F      4,0xF
#define SYSCON_CLK_DIV0_PCLK_DSYS_RATIO_HCLK_DSYS_7      5,0x7
#define SYSCON_CLK_DIV0_HCLK_PSYS_RATIO_MOUT_PSYS_F      6,0xF
#define SYSCON_CLK_DIV0_PCLK_PSYS_RATIO_HCLK_PSYS_7      7,0x7

#define SYSCON_CLK_DIV1_TBLK_RATIO_SCLKVPLL_F            0,0xF
#define SYSCON_CLK_DIV1_CAM0_RATIO_MOUTCAM0_F            3,0xF
#define SYSCON_CLK_DIV1_CAM1_RATIO_MOUTCAM1_F            4,0xF
#define SYSCON_CLK_DIV1_FIMD_RATIO_MOUTFIMD_F            5,0xF
#define SYSCON_CLK_DIV1_CSIS_RATIO_MOUTCSIS_F            7,0xF

#define SYSCON_CLK_DIV2_G3D_RATIO_MOUTG3D_F              0,0xF
#define SYSCON_CLK_DIV2_MFC_RATIO_MOUTMFC_F              0,0xF
#define SYSCON_CLK_DIV2_G2D_RATIO_MOUTG2D_F              0,0xF

#define SYSCON_CLK_DIV3_F0_MOUTFIMC_LCLK_F               3,0xF
#define SYSCON_CLK_DIV3_F1_MOUTFIMC_LCLK_F               3,0xF
#define SYSCON_CLK_DIV3_FIMC_LCLK_RATIO_MOUTFIMC_LCLK_F  3,0xF

#define SYSCON_CLK_DIV4_MMC0_RATIO_MOUTMMC0_F            0,0xF
#define SYSCON_CLK_DIV4_MMC1_RATIO_MOUTMMC1_F            0,0xF
#define SYSCON_CLK_DIV4_MMC2_RATIO_MOUTMMC2_F            0,0xF
#define SYSCON_CLK_DIV4_MMC3_RATIO_MOUTMMC3_F            0,0xF
#define SYSCON_CLK_DIV4_UART0_RATIO_MOUTUART0_F          0,0xF
#define SYSCON_CLK_DIV4_UART1_RATIO_MOUTUART1_F          0,0xF
#define SYSCON_CLK_DIV4_UART2_RATIO_MOUTUART2_F          0,0xF
#define SYSCON_CLK_DIV4_UART3_RATIO_MOUTUART3_F          0,0xF

#define SYSCON_CLK_DIV5_SPI0_RATIO_MOUTSPI0_F            0,0xF
#define SYSCON_CLK_DIV5_SPI1_RATIO_MOUTSPI1_F            0,0xF
#define SYSCON_CLK_DIV5_PWM_RATIO_MOUTPWM_F              3,0xF

#define SYSCON_CLK_DIV6_AUDIO0_RATIO_MOUTAUDIO0_F        0,0xF
#define SYSCON_CLK_DIV6_AUDIO1_RATIO_MOUTAUDIO1_F        0,0xF
#define SYSCON_CLK_DIV6_AUDIO2_RATIO_MOUTAUDIO2_F        0,0xF
#define SYSCON_CLK_DIV6_ONENAND_RATIO_MOUTFLASH_7        0,0x7
#define SYSCON_CLK_DIV6_COPY_RATIO_MOUTHPM_7             0,0x7
#define SYSCON_CLK_DIV6_HPM_RATIO_DOUTCOPY_7             0,0x7
#define SYSCON_CLK_DIV6_PWI_RATIO_MOUTPWI_F              0,0xF
#define SYSCON_CLK_DIV6_DMC0_RATIO_MOUTDMC0_F            0,0xF

#define SYSCON_CLK_GATE_SCLK_FIMC_LCLK                   (0x1<<5)

#define SYSCON_CLK_GATE_IP0_DMC0                         (0x1<<0)
#define SYSCON_CLK_GATE_IP0_DMC1                         (0x1<<1)
#define SYSCON_CLK_GATE_IP0_MDMA                         (0x1<<2)
#define SYSCON_CLK_GATE_IP0_PDMA0                        (0x1<<3)
#define SYSCON_CLK_GATE_IP0_PDMA1                        (0x1<<4)
#define SYSCON_CLK_GATE_IP0_IMEM                         (0x1<<5)
#define SYSCON_CLK_GATE_IP0_G3D                          (0x1<<8)
#define SYSCON_CLK_GATE_IP0_G2D                          (0x1<<12)
#define SYSCON_CLK_GATE_IP0_MFC                          (0x1<<16)
#define SYSCON_CLK_GATE_IP0_FIMC0                        (0x1<<24)
#define SYSCON_CLK_GATE_IP0_FIMC1                        (0x1<<25)
#define SYSCON_CLK_GATE_IP0_FIMC2                        (0x1<<26)
#define SYSCON_CLK_GATE_IP0_ROTATOR                      (0x1<<29)
#define SYSCON_CLK_GATE_IP0_CSIS                         (0x1<<31)

#define SYSCON_CLK_GATE_IP1_FIMD                         (0x1<<0)
#define SYSCON_CLK_GATE_IP1_DSIM                         (0x1<<2)
#define SYSCON_CLK_GATE_IP1_VP                           (0x1<<8)
#define SYSCON_CLK_GATE_IP1_MIXER                        (0x1<<9)
#define SYSCON_CLK_GATE_IP1_TVENC                        (0x1<<10)
#define SYSCON_CLK_GATE_IP1_HDMI                         (0x1<<11)
#define SYSCON_CLK_GATE_IP1_USBOTG                       (0x1<<16)
#define SYSCON_CLK_GATE_IP1_USBHOST                      (0x1<<17)
#define SYSCON_CLK_GATE_IP1_NANDXL                       (0x1<<24)
#define SYSCON_CLK_GATE_IP1_CFCON                        (0x1<<25)
#define SYSCON_CLK_GATE_IP1_SROMC                        (0x1<<26)
#define SYSCON_CLK_GATE_IP1_NFCON                        (0x1<<28)

#define SYSCON_CLK_GATE_IP2_SECSS                        (0x1<<0)
#define SYSCON_CLK_GATE_IP2_SDM                          (0x1<<1)
#define SYSCON_CLK_GATE_IP2_CORESIGHT                    (0x1<<8)
#define SYSCON_CLK_GATE_IP2_MODEM                        (0x1<<9)
#define SYSCON_CLK_GATE_IP2_JTAG                         (0x1<<11)
#define SYSCON_CLK_GATE_IP2_HSMMC0                       (0x1<<16)
#define SYSCON_CLK_GATE_IP2_HSMMC1                       (0x1<<17)
#define SYSCON_CLK_GATE_IP2_HSMMC2                       (0x1<<18)
#define SYSCON_CLK_GATE_IP2_HSMMC3                       (0x1<<19)
#define SYSCON_CLK_GATE_IP2_TSI                          (0x1<<20)
#define SYSCON_CLK_GATE_IP2_VIC0                         (0x1<<24)
#define SYSCON_CLK_GATE_IP2_VIC1                         (0x1<<25)
#define SYSCON_CLK_GATE_IP2_VIC2                         (0x1<<26)
#define SYSCON_CLK_GATE_IP2_VIC3                         (0x1<<27)
#define SYSCON_CLK_GATE_IP2_TZIC0                        (0x1<<28)
#define SYSCON_CLK_GATE_IP2_TZIC1                        (0x1<<29)
#define SYSCON_CLK_GATE_IP2_TZIC2                        (0x1<<30)
#define SYSCON_CLK_GATE_IP2_TZIC3                        (0x1<<31)

#define SYSCON_CLK_GATE_IP3_SPDIF                        (0x1<<0)
#define SYSCON_CLK_GATE_IP3_AC97                         (0x1<<1)
#define SYSCON_CLK_GATE_IP3_I2S0                         (0x1<<4)
#define SYSCON_CLK_GATE_IP3_I2S1                         (0x1<<5)
#define SYSCON_CLK_GATE_IP3_I2S2                         (0x1<<6)
#define SYSCON_CLK_GATE_IP3_I2C0                         (0x1<<7)
#define SYSCON_CLK_GATE_IP3_I2C2                         (0x1<<9)
#define SYSCON_CLK_GATE_IP3_I2C_HDMI_DDC                 (0x1<<10)
#define SYSCON_CLK_GATE_IP3_I2C_HDMI_PHY                 (0x1<<11)
#define SYSCON_CLK_GATE_IP3_SPI0                         (0x1<<12)
#define SYSCON_CLK_GATE_IP3_SPI1                         (0x1<<13)
#define SYSCON_CLK_GATE_IP3_RTC                          (0x1<<15)
#define SYSCON_CLK_GATE_IP3_SYSTIMER                     (0x1<<16)
#define SYSCON_CLK_GATE_IP3_UART0                        (0x1<<17)
#define SYSCON_CLK_GATE_IP3_UART1                        (0x1<<18)
#define SYSCON_CLK_GATE_IP3_UART2                        (0x1<<19)
#define SYSCON_CLK_GATE_IP3_UART3                        (0x1<<20)
#define SYSCON_CLK_GATE_IP3_KEYIF                        (0x1<<21)
#define SYSCON_CLK_GATE_IP3_WDT                          (0x1<<22)
#define SYSCON_CLK_GATE_IP3_PWM                          (0x1<<23)
#define SYSCON_CLK_GATE_IP3_TSADC                        (0x1<<24)
#define SYSCON_CLK_GATE_IP3_GPIO                         (0x1<<26)
#define SYSCON_CLK_GATE_IP3_SYSCON                       (0x1<<27)
#define SYSCON_CLK_GATE_IP3_PCM0                         (0x1<<28)
#define SYSCON_CLK_GATE_IP3_PCM1                         (0x1<<29)
#define SYSCON_CLK_GATE_IP3_PCM2                         (0x1<<30)

#define SYSCON_CLK_GATE_IP4_CHIP_ID                      (0x1<<0)
#define SYSCON_CLK_GATE_IP4_IEM_IEC                      (0x1<<1)
#define SYSCON_CLK_GATE_IP4_IEM_APC                      (0x1<<2)
#define SYSCON_CLK_GATE_IP4_SECKEY                       (0x1<<3)
#define SYSCON_CLK_GATE_IP4_TZPC0                        (0x1<<5)
#define SYSCON_CLK_GATE_IP4_TZPC1                        (0x1<<6)
#define SYSCON_CLK_GATE_IP4_TZPC2                        (0x1<<7)
#define SYSCON_CLK_GATE_IP4_TZPC3                        (0x1<<8)

#define SYSCON_CLK_GATE_BLOCK_G3D                        (0x1<<0)
#define SYSCON_CLK_GATE_BLOCK_MFC                        (0x1<<1)
#define SYSCON_CLK_GATE_BLOCK_IMG                        (0x1<<2)
#define SYSCON_CLK_GATE_BLOCK_LCD                        (0x1<<3)
#define SYSCON_CLK_GATE_BLOCK_TV                         (0x1<<4)
#define SYSCON_CLK_GATE_BLOCK_USB                        (0x1<<5)
#define SYSCON_CLK_GATE_BLOCK_MEMORY                     (0x1<<6)
#define SYSCON_CLK_GATE_BLOCK_SECURITY                   (0x1<<7)
#define SYSCON_CLK_GATE_BLOCK_DEBUG                      (0x1<<8)
#define SYSCON_CLK_GATE_BLOCK_HSMMC                      (0x1<<9)
#define SYSCON_CLK_GATE_BLOCK_INTC                       (0x1<<10)

#define SYSCON_CLK_GATE_IP5_CLK_JPEG                     (0x1<<29)

void SYSCON_PreInit(void);

#endif /* _SYSCON_H_ */
