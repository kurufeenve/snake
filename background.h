#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "my_sdl.h"
#include "square.h"
#include <stdint.h>

class   bachground
{
    public:
        bachground(my_sdl &sdl_obj);
        virtual ~bachground(void);

    private:
        uint32_t    _outerLineColor;
        uint32_t    _innerLineColor;

        void    _draw_horizontals(my_sdl &sdl_obj);
        void    _draw_verticals(my_sdl &sdl_obj);
};

#endif
