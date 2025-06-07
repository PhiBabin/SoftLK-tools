/*
SLK_img2pixel - a tool for converting images to pixelart

Written in 2023,2024 by Lukas Holzbeierlein (Captain4LK) email: captain4lk [at] tutanota [dot] com

To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.

You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/

//External includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

#define HLH_IMPLEMENTATION
#include "HLH.h"
#define HLH_PATH_IMPLEMENTATION
#include "HLH_path.h"
#define HLH_RW_IMPLEMENTATION
#include "HLH_rw.h"
#define HLH_JSON_IMPLEMENTATION
#include "HLH_json.h"
#define FOPEN_UTF8_IMPLEMENTATION
#include "../../external/fopen_utf8.h"
#define CUTE_FILES_IMPLEMENTATION
#include "cute_files.h"

#include "HLH_gui.h"

#include <emscripten.h>
#include <emscripten/html5.h>
//-------------------------------------

//Internal includes
#include "img2pixel.h"
#include "util.h"
#include "gui.h"
//-------------------------------------

//#defines
//-------------------------------------

//Typedefs
//-------------------------------------

//Variables
//-------------------------------------

//Function prototypes

int load_file(uint8_t *buffer, size_t size);
//-------------------------------------


//Function implementations

void one_iter(void)
{ 
  static HLH_gui_mouse mouse = {0};
  HLH_gui_iterate_once(&mouse);
}

int main(int, char **)
{
   HLH_gui_init();

   settings_load("settings.json");
   atexit(settings_save);

   gui_construct();

   FILE *f = fopen("default.json","r");
   gui_load_preset(f);
   if(f!=NULL)
      fclose(f);
   #ifdef __EMSCRIPTEN__
      puts("Start main loop");
      // Receives a function to call and some user data to provide it.
      emscripten_set_main_loop(one_iter, -1, 1);
   #else
      return HLH_gui_message_loop();
   #endif
}
//-------------------------------------
