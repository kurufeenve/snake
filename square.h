#ifndef SQUARE_H
#define SQUARE_H

#include "common.h"
#include <stdint.h>

struct   Square
{
   uint32_t color;
   uint32_t squareX;
   uint32_t squareY;
   uint32_t leftX;
   uint32_t rightX;
   uint32_t upY;
   uint32_t downY;
};

#endif
