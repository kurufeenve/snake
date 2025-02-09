#include "background.h"
#include "palette.h"

bachground::bachground(my_sdl &sdl_obj)
{
    _outerLineColor = OUTER_LINE;
    _innerLineColor = INNER_LINE;
    _draw_horizontals(sdl_obj);
    _draw_verticals(sdl_obj);
}

bachground::~bachground(void) {}

void    bachground::_draw_horizontals(my_sdl &sdl_obj)
{
    uint32_t    height = sdl_obj.getWindowHeight();
    uint32_t    width = sdl_obj.getWindowWidth();

    for (uint32_t y = 0; y < height; y += OUTER_SQUARE_SIZE)
    {
        for (uint32_t x = 0; x < width; x++)
        {
            if ((0 != y) && (sdl_obj.getPixel(x, (y - 1)) != _outerLineColor))
            {
                sdl_obj.putPixel(x, (y - 1), _innerLineColor);
            }
            if ((height > y) && (sdl_obj.getPixel(x, (y + 1)) != _outerLineColor))
            {
                sdl_obj.putPixel(x, (y + 1), _innerLineColor);
            }
            sdl_obj.putPixel(x, y, _outerLineColor);
        }
    }
}

void    bachground::_draw_verticals(my_sdl &sdl_obj)
{
    uint32_t    height = sdl_obj.getWindowHeight();
    uint32_t    width = sdl_obj.getWindowWidth();

    for (uint32_t x = 0; x < width; x += OUTER_SQUARE_SIZE)
    {
        for (uint32_t y = 0; y < height; y++)
        {
            if ((0 != x) && (sdl_obj.getPixel((x - 1), y) != _outerLineColor))
            {
                sdl_obj.putPixel((x - 1), y, _innerLineColor);
            }
            if ((width > x) && (sdl_obj.getPixel((x + 1), y) != _outerLineColor))
            {
                sdl_obj.putPixel((x + 1), y, _innerLineColor);
            }
            sdl_obj.putPixel(x, y, _outerLineColor);
        }
    }
}
