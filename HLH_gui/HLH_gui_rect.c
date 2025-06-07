/*
HLH_gui - gui framework

Written in 2023 by Lukas Holzbeierlein (Captain4LK) email: captain4lk [at] tutanota [dot] com

To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to this software to the public domain worldwide. This software is distributed without any warranty.

You should have received a copy of the CC0 Public Domain Dedication along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
*/

//External includes
//-------------------------------------

//Internal includes
#include "HLH_gui.h"
//-------------------------------------

//#defines
//-------------------------------------

//Typedefs
//-------------------------------------

//Variables
//-------------------------------------

//Function prototypes
//-------------------------------------

//Function implementations

HLH_gui_rect HLH_gui_rect_make(int minx, int miny, int maxx, int maxy)
{
   return (HLH_gui_rect){
             .minx = minx, .miny = miny, .maxx = maxx, .maxy = maxy
   };
}


HLH_gui_rect HLH_gui_rect_shrink(HLH_gui_rect* bounds, int x_pad, int y_pad)
{
   return HLH_gui_rect_make(bounds->minx + x_pad, bounds->miny + y_pad, bounds->maxx - x_pad, bounds->maxy - y_pad);
}

int HLH_gui_rect_inside(HLH_gui_rect r, HLH_gui_point p)
{
   if(p.x<r.minx||p.y<r.miny)
      return 0;

   if(p.x>r.maxx||p.y>r.maxy)
      return 0;

   return 1;
}
//-------------------------------------
