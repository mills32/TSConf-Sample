#include <stdio.h>
#include <string.h>

uint16_t VCONFIG         = 0x00AF;
uint16_t STATUS          = 0x00AF;
uint16_t VPAGE           = 0x01AF;
uint16_t GXOFFSL         = 0x02AF;
uint16_t GXOFFSH         = 0x03AF;
uint16_t GYOFFSL         = 0x04AF;
uint16_t GYOFFSH         = 0x05AF;
uint16_t TSCONFIG        = 0x06AF;
uint16_t PALSEL          = 0x07AF;
uint16_t BORDER          = 0x0FAF;
uint16_t PAGE0           = 0x10AF;
uint16_t PAGE1           = 0x11AF;
uint16_t PAGE2           = 0x12AF;
uint16_t PAGE3           = 0x13AF;
uint16_t FMADDR          = 0x15AF;
uint16_t TMPAGE          = 0x16AF;
uint16_t T0GPAGE         = 0x17AF;
uint16_t T1GPAGE         = 0x18AF;
uint16_t SGPAGE          = 0x19AF;
uint16_t DMASADDRL       = 0x1AAF;
uint16_t DMASADDRH       = 0x1BAF;
uint16_t DMASADDRX       = 0x1CAF;
uint16_t DMADADDRL       = 0x1DAF;
uint16_t DMADADDRH       = 0x1EAF;
uint16_t DMADADDRX       = 0x1FAF;
uint16_t SYSCONFIG       = 0x20AF;
uint16_t MEMCONFIG       = 0x21AF;
uint16_t HSINT           = 0x22AF;
uint16_t VSINTL          = 0x23AF;
uint16_t VSINTH          = 0x24AF;
uint16_t DMALEN          = 0x26AF;
uint16_t DMACTR          = 0x27AF;
uint16_t DMASTATUS       = 0x27AF;
uint16_t DMANUM          = 0x28AF;
uint16_t FDDVIRT         = 0x29AF;
uint16_t INTMASK         = 0x2AAF;
uint16_t T0XOFFSL        = 0x40AF;
uint16_t T0XOFFSH        = 0x41AF;
uint16_t T0YOFFSL        = 0x42AF;
uint16_t T0YOFFSH        = 0x43AF;
uint16_t T1XOFFSL        = 0x44AF;
uint16_t T1XOFFSH        = 0x45AF;
uint16_t T1YOFFSL        = 0x46AF;
uint16_t T1YOFFSH        = 0x47AF;

//TS parameters
uint16_t FM_EN           = 0x10;

//FPGA arrays
uint16_t FM_CRAM         = 0x0000;
uint16_t FM_SFILE        = 0x0200;
//VIDEO
uint8_t VID_256X192     = 0x00;
uint8_t VID_320X200     = 0x40;
uint8_t VID_320X240     = 0x80;
uint8_t VID_360X288     = 0xC0;
uint8_t VID_RASTER_BS   = 6;

uint8_t VID_ZX          = 0x00;
uint8_t VID_16C         = 0x01;
uint8_t VID_256C        = 0x02;
uint8_t VID_TEXT        = 0x03;
uint8_t VID_FT812       = 0x04;
uint8_t VID_NOGFX       = 0x20;
uint8_t VID_MODE_BS     = 0;

//PALSEL
uint8_t PAL_GPAL_MASK   = 0x0F;
uint8_t PAL_GPAL_BS     = 0;
uint8_t PAL_T0PAL_MASK  = 0x30;
uint8_t PAL_T0PAL_BS    = 4;
uint8_t PAL_T1PAL_MASK  = 0xC0;
uint8_t PAL_T1PAL_BS    = 6;

//TSU
uint8_t TSU_T0ZEN     = 0x04;
uint8_t TSU_T1ZEN     = 0x08;
uint8_t TSU_T0EN      = 0x20;
uint8_t TSU_T1EN      = 0x40;
uint8_t TSU_SEN       = 0x80;

//SYSTEM
uint8_t SYS_ZCLK3_5   = 0x00;
uint8_t SYS_ZCLK7     = 0x01;
uint8_t SYS_ZCLK14    = 0x02;
uint8_t SYS_ZCLK_BS   = 0;

uint8_t SYS_CACHEEN   = 0x04;

//MEMORY
uint8_t MEM_ROM128    = 0x01;
uint8_t MEM_W0WE      = 0x02;
uint8_t MEM_W0MAP_N   = 0x04;
uint8_t MEM_W0RAM     = 0x08;

uint8_t MEM_LCK512    = 0x00;
uint8_t MEM_LCK128    = 0x40;
uint8_t MEM_LCKAUTO   = 0x80;
uint8_t MEM_LCK1024   = 0xC0;
uint8_t MEM_LCK_BS    = 6;

//INT
uint8_t INT_VEC_FRAME   = 0xFF;
uint8_t INT_VEC_LINE    = 0xFD;
uint8_t INT_VEC_DMA     = 0xFB;

uint8_t INT_MSK_FRAME   = 0x01;
uint8_t INT_MSK_LINE    = 0x02;
uint8_t INT_MSK_DMA     = 0x04;

//DMA
uint8_t DMA_WNR         = 0x80;
uint8_t DMA_SALGN       = 0x20;
uint8_t DMA_DALGN       = 0x10;
uint8_t DMA_ASZ         = 0x08;

uint8_t DMA_RAM         = 0x01;
uint8_t DMA_BLT         = 0x81;
uint8_t DMA_FILL        = 0x04;
uint8_t DMA_SPI_RAM     = 0x02;
uint8_t DMA_RAM_SPI     = 0x82;
uint8_t DMA_IDE_RAM     = 0x03;
uint8_t DMA_RAM_IDE     = 0x83;
uint8_t DMA_RAM_CRAM    = 0x84;
uint8_t DMA_RAM_SFILE   = 0x85;

//SPRITES
uint8_t SP_XF       = 0x80;
uint8_t SP_YF       = 0x80;
uint8_t SP_LEAP     = 0x40;
uint8_t SP_ACT      = 0x20;

uint8_t SP_SIZE8    = 0x00;
uint8_t SP_SIZE16   = 0x02;
uint8_t SP_SIZE24   = 0x04;
uint8_t SP_SIZE32   = 0x06;
uint8_t SP_SIZE40   = 0x08;
uint8_t SP_SIZE48   = 0x0A;
uint8_t SP_SIZE56   = 0x0C;
uint8_t SP_SIZE64   = 0x0E;
uint8_t SP_SIZE_BS  = 1;

uint8_t SP_PAL_MASK     = 0xF0;

uint16_t SP_XF_W         = 0x8000;
uint16_t SP_YF_W         = 0x8000;
uint16_t SP_LEAP_W       = 0x4000;
uint16_t SP_ACT_W        = 0x2000;

uint16_t SP_SIZE8_W      = 0x0000;
uint16_t SP_SIZE16_W     = 0x0200;
uint16_t SP_SIZE24_W     = 0x0400;
uint16_t SP_SIZE32_W     = 0x0600;
uint16_t SP_SIZE40_W     = 0x0800;
uint16_t SP_SIZE48_W     = 0x0A00;
uint16_t SP_SIZE56_W     = 0x0C00;
uint16_t SP_SIZE64_W     = 0x0E00;
uint16_t SP_SIZE_BS_W    = 9;

uint16_t SP_X_MASK_W     = 0x01FF;
uint16_t SP_Y_MASK_W     = 0x01FF;
uint16_t SP_TNUM_MASK_W  = 0x0FFF;
uint16_t SP_PAL_MASK_W   = 0xF000;

//TILES
uint8_t TL_XF			= 0x40;
uint8_t TL_YF			= 0x80;
uint8_t TL_PAL_MAS		= 0x30;
uint8_t TL_PAL_BS		= 0x04;

uint16_t TL_XF_W       = 0x4000;
uint16_t TL_YF_W       = 0x8000;
uint16_t TL_TNUM_MASK_W  = 0x0FFF;
uint16_t TL_PAL_MASK_W   = 0x3000;
uint16_t TL_PAL_BS_W     = 12;
