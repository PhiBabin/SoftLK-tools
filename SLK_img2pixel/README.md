# SLK_img2pixel

![anim](../screenshots/crate.gif)

A tool for transforming images into pixel art.

This is a fork of the [SoftLK-tools](https://github.com/Captain4LK/SoftLK-tools.git) which port the SLK img2pixel tool to webassembly. 

#[Test it here](https://google.com/TODO)

# Download 

* SLK_img2pixel: [itch.io](https://captain4lk.itch.io/slk-img2pixel)

# Contact

Here is a link to the SLK_img2pixel Discord. Feel free to pop in and make suggestions or ask questions: https://discord.gg/Nch8hjdZ2V

# Building from source

* First, clone this repository: ``https://github.com/Captain4LK/SoftLK-tools.git``

## Dependencies

In general, I try to keep the amount of external dependencies as low as possible, but some are still needed, as listed below:

* [SDL2](https://www.libsdl.org/download-2.0.php)

## Building

* cd into SLK_img2pixels directory: ``cd SLK_img2pixel``
* there are multiple build scripts in the folder (linux.sh, win_cross.sh), running these generates a makefile for building the program, to build, pipe the output into make: ``sh linux.sh | make -f -``
* alternatively, there is a pre-generated makefile for the linux version, to compile, simply run ``make``
* The binary can be found at the top level of the repo in the ``bin/`` directory

# Gallery

![SLK_img2pixel_preview](../screenshots/SLK_img2pixel.png)

# Image Credits
The program provides the following example images:

| Image       | Author                                                                                                                                                               | License                                                                       |
| ----------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| `crate.png` | [Luke Noonan](https://opengameart.org/content/3-crate-textures-w-bump-normal)                                                                                        | [Public Domain (CC0 1.0)](https://creativecommons.org/publicdomain/zero/1.0/) |
| `david.png` | [Jörg Bittner Unna](https://commons.wikimedia.org/wiki/Category:Details_of_David_by_Michelangelo_Buonarroti#/media/File:'David'_by_Michelangelo_FI_Acca_JBS_080.jpg) | [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0)                |
| `rock.png`  | [Eberhard Grossgasteiger](https://www.pexels.com/photo/grey-and-brown-brick-wall-966927/)                                                                            | [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0) w              |

# Palette Credits
A bunch of palettes mostly from https://lospec.com
| Image           | Source                                                                                 |
| --------------- | -------------------------------------------------------------------------------------- |
| `3-3-2`         | 256 colors for 3-3-2 bits RGB                                                          |
| `aap-64`        | [Adigun A. Polack](https://lospec.com/palette-list/aap-64)                             |
| `apollo`        | [Adam C. Younis](https://lospec.com/palette-list/apollo)                               |
| `aurora`        | [Richard Fhager (DawnBringer)](https://pixeljoint.com/forum/forum_posts.asp?TID=26080) |
| `dawnbringer-X` | [Richard Fhager (DawnBringer)](https://pixeljoint.com/p/23821.htm)                     |
| `duel`          | [Arilyn](https://lospec.com/palette-list/duel)                                         |
| `endesga-X`     | [ENDESGA](https://lospec.com/palette-list/endesga-32)                                  |
| `pico-8`        | From PICO-8 by [Lexaloffle](https://www.lexaloffle.com/pico-8.php)                     |
| `playpal`       | From Doom by [ID Software](https://doomwiki.org/wiki/PLAYPAL)                          |
| `quake`         | From Quake by [ID Software](https://quakewiki.org/wiki/Quake_palette)                  |
| `resurrect-64`  | [Kerrie Lake](https://lospec.com/palette-list/resurrect-64)                            |
| `slso-8`        | [Luis Miguel Maldonado](https://lospec.com/palette-list/slso8)                         |
| `sweetie-16`    | [GrafxKid](https://lospec.com/palette-list/sweetie-16)                                 |


# Changelog

Change specific to the Emscripten fork:
* Create Makefile for Emscripten
* Adapt the various save / load function for the web browser
* Move the main loop iteration to its own function
* Update the top menu to include example palettes and images
* Update the top menu ordering
* Remove separated Scale X and Y, now there is only one scale slider
* Add padding in menubar when text is left align

Current development version: SLK_img2pixel 1.5.1-dev

----------------------------------------
Version:                SLK_img2pixel 1.5.1 (TBA)
----------------------------------------

CHANGES:

* palette generation for cmd version
* pcx export for cmd version
* crash fixes

----------------------------------------
Version:                SLK_img2pixel 1.5 (26.04.2024)
----------------------------------------

CHANGES:

* added new sampling mode --> "cluster"
* combined "ceil", "floor" and "round" sampling options into "nearest"
* added tinting
* optimized and corrected gaussian blur: about 5x faster and more correct for large blurring radius
* sharpening is now unsharp-masking
* new gui
* multithreading
* new color assignment mode: "median-cut"
* new color distance metrics: "weighted rgb" and "redmean"
* removed "yuv", "ycc", "yiq", "hsv" and "xyz" distance metrics

----------------------------------------
Version:                SLK_img2pixel 1.4 (17.09.2022)
----------------------------------------

CHANGES:

* new gui
* drag'n drop support for images
* fixed batch processing appending png extension without removing original extension

----------------------------------------
Version:                SLK_img2pixel 1.3 (21.04.2022)
----------------------------------------

CHANGES:

* fixed multiple memory leaks
* removed supersampling sample mode (virtually the same results can be achieved using a high gauss blurring setting)
* added persistent paths for file/folder selection
* added K-means color distance mode
* made empty tabs in gui unclickable
* removed gif processing (it was basically useless anyway)
* Options in the gui are now only shown if they actually do anything
* Support for [qoi format](https://qoiformat.org/)

----------------------------------------
Version:                SLK_img2pixel 1.2 (16.08.2021)
----------------------------------------

CHANGES:

* replaced image quantization algorithm with higher quality one
* added command line version
* added hue adjustment slider
* rearranged the gui, moved all sampling options in separate tab
* added x and y offset sliders for fine-tuned sampling
* added option to add inlines/outlines
* reworked dithering, availible modes: 
   * no dithering
   * bayer 8x8
   * bayer 4x4
   * bayer 2x2
   * cluster 8x8
   * cluster 4x4
   * floyd-steinberg
* lowered memory consumption by using rgb888 pixel format while processing images

----------------------------------------
Version:                SLK_img2pixel 1.1 - color quantization (24.04.2021)
----------------------------------------

CHANGES:

* added support for changing default settings
* fixed kdialog support
* added support for exporting upscaled images
* added color count slider
* added basic color quantization

----------------------------------------
Version:                SLK_img2pixel 1.0 - initial release (14.02.2021)
----------------------------------------

CHANGES:

* improved all sampling modes
* improved gaussian blur and image sharpening
* added color distance calculation modes (CIE76, CIE94, CIEDE2000, XYZ, YCC, YIQ, YUV)

----------------------------------------
Version:                SLK_img2pixel 0.4 - palette formats! (27.01.2021)
----------------------------------------

NOTE: 

* Consider downsizing very high resolution images before using them with SLK_img2pixel. Sharpening and gaussian blur are done on the input image, so performance will suffer when loading high resolution images.

CHANGES:

* fix sharpness not changing at value of 0
* renamed supersampling to box sampling
* added gaussian blur
* added lanczos sample mode
* added support for more palette formats(.gpl,.png,.hex)

----------------------------------------
Version:                SLK_img2pixel 0.3 - supersampling is amazing (24.01.2021)
----------------------------------------

CHANGES:

* preview now drawn by the gpu
* added relative image sizes
* added image sharpening
* improved bilinear sampling
* added bicubic sampling mode
* added supersampling sampling mode (works great for portraits!)

----------------------------------------
Version:                SLK_img2pixel 0.2 - unicode hell (22.01.2021)
----------------------------------------

CHANGES:

* added bilinear sampling mode
* added alpha threshold
* added gif support
* added quake, doom palettes
* added unicode support for windows

----------------------------------------
Version:                SLK_img2pixel 0.1 - initial prerelease (20.01.2021)
----------------------------------------
