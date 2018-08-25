#include "move.h"

int beats(int draw)
{
   switch (draw)
   {
      case 0 : return 1;
      case 1 : return 2;
      case 2 : return 0;
      default: return 0; // This is only needed to avoid compiler warnings
   }
} // end of beats

