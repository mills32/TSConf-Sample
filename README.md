-------
 TSConf
-------

TSConf is basicaly a zx spectrum created by tslabs. But, it has a PPU very similar to a Mega Drive/Genesis.

![alt tag](https://raw.githubusercontent.com/mills32/TSConf-Sample/main/tsconf.png)

You can emulate it using Zesarux or UnrealSpeccy. Or you can use an FPGA core in MiSTer.

Because nearly all the info about this computer is not in a language I can understand, (and the samples I found 
are not complete), I had to create this by taking code from demos, samples, a lot of testing, and also relay on 
crappy google translations. 

I got info from these webs related to TSLabs: 
https://hype.retroscene.org/blog/dev/page5/
http://forum.tslabs.info/viewtopic.php?f=35&t=157
http://prods.tslabs.info/

You can find spgbld and tga2ts utils here https://ooh3dpsdytm34sfhws63yjfbwy--github-com.translate.goog/tslabs/zx-evo#hg%2Fpentevo%2Ftools%2Ftga2ts
Do not use the samples from the last link as they don't contain real TSConf samples, but some kind of development kit to compile "pentevo" games for TSConf. (pentevo is another spectrum clone).

First of all, I used z88dk, because it lets you mix assembly and c, and that's great for not getting lost inside big assembly codes.
Any z80 compiler will work as long as you use the correct sintax.

This code does the folloween:
-Loads image to GFX layer
-Loads tiles for tile-map layers
-Loads maps
-Sets sprites and animate them
-Scrolls GFX and tile-map layers

ABOUT IMAGES
------------
You need to convert your images to tga 256 colours, and then use tga2ts to create resources for the spg container.
Tga2ts nees a file called "levels.map" to work.
All tiles, graphics and sprites on screen, will share the same 256 colours palette. This palette has to be arranged in 16 palettes,
(16 colours each), because Tsconf uses the 256 colours with limitations:
	-GFX layer can use the whole 256 colours, but I prefer to use only 16, because I saw garbage on screen when using all layers. 
	-Tile map layers use one 16 colours palette per tile (8x8 pixels each). Every tile can use a different palette, but only 4 consecutive palettes can be used for one layer.
	-Sprites can use one 16 colours palette per sprite, (even if they are 64x64). You can select any of the 16 palettes for the sprites
	 
SPG
---

TSConf uses spg files read from a hard disc, they are some kind of rom that stores resources and programs. To generate them, you need spgbld and mhmt.exe.


DMA TRANSFER
------------

I copied a DMA transfer function from tslabs forums. It uses some arrays like this to transfer things:
```
uint8_t Copy[] = {
	0x1a,0,		// Source low
	0x1b,0,		// Source high
	0x1c,0,		// start page High?
	0x1d,0,		// Destination Low?
	0x1e,0,		// Destination High?
	0x1f,0,		// start page?
	0x26,0,		// Busrt length
	0x28,0,		// Burst number
	0x27,0,//DMA_RAM_SFILE	// Start
	0xff
};
```
SPRITE DESCRIPTOR STRUCTURE
---------------------------
Every sprite is described by 6 bytes. First sprite starts at address 0x0200, and so on.

BITS | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
----- |----- |----- |----- |----- |----- |----- |----- |----- |
0 R0L | Y[7:0]|
1 R0H|YF|LEAP|ACT|reserved|YS[2:0]
2 R1L|X[7:0]|
3 R1H|XF|-|-|reserved|XS[2:0]|X[8]
4 R2L|TNUM[7:0] (X pos in vram)	
5 R2H|SPAL[7:4]||||TNUM[11:8] (Y pos in vram)	

```
R-- = Register + Number + Low/High
X = coordinate, byte + 1 bit (address can be in the range of 0-511)
Y = coordinate, byte + 1 bit
XS = size. (0 = 8, 1 = 16, ... 7 = 64 pixels)
YS = size. (0 = 8, 1 = 16, ... 7 = 64 lines)
XF = Flip the sprite horizontally in output. <em> Note that we need to draw 2 times less sprites! </em>
YF = Flip the sprite vertically on output
ACT = Display sprite (on / off)
LEAP = Bit that determines the transition to the next layer for subsequent sprites. The third transition marks the end of the sprite handles
TNUM = Number of the first tile in a sprite of the specified size. Bits 0-5 = X position in sprite graphics page, bits 6-11 = Y position.
SPAL = Select a palette. 4 bits - 16 palettes available.
```

TILE MAPS
---------

TSConf has two tile-map layers, every tile is structured in two bytes like this:

TILE|7|6|5|4|3|2|1|0|
----- |----- |----- |----- |----- |----- |----- |----- |----- |
0 R0L|TNUM[7:0]|						
1 R0H|YF|XF|TPAL[5:4]||TNUM[11:8]|	

```
R-- = Register + Number + Low/High
TNUM = tile number.
XF, YF Flip atributes.
TPAL = palete
```
