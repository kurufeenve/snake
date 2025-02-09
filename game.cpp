#include "game.h"
#include "palette.h"

Game::Game(my_sdl &sdl_obj)
{
    _setCoordinates();
    _drawBaseColor(sdl_obj);
}

Game::~Game(void)
{
}

uint16_t    Game::_getX(uint16_t index)
{
    return (index % SQUARE_WIDTH);
}

uint16_t    Game::_getY(uint16_t index)
{
    return (index / SQUARE_WIDTH);
}

void        Game::_setCoordinates(void)
{
    for (uint16_t square = 0; square < FIELD_SIZE; square++)
    {
       _Field[square].color = BASE_SQUARE;
       _Field[square].squareX = _getX(square);
       _Field[square].squareY = _getY(square);
       _Field[square].leftX = _Field[square].squareX * OUTER_SQUARE_SIZE + PIXEL_DELTA;
       _Field[square].rightX = _Field[square].leftX + INNER_SQUARE_SIZE;
       _Field[square].upY = _Field[square].squareY * OUTER_SQUARE_SIZE + PIXEL_DELTA;
       _Field[square].downY = _Field[square].upY + INNER_SQUARE_SIZE;
    }
}

void        Game::_drawBaseColor(my_sdl &sdl_obj)
{
    for (uint16_t square = 0; square < FIELD_SIZE; square++)
    {
        for (uint16_t y = _Field[square].upY; y < _Field[square].downY; y++)
        {
            for (uint16_t x = _Field[square].leftX; x < _Field[square].rightX; x++)
            {
                sdl_obj.putPixel(x, y, _Field[square].color);
            }
        }
    }
}

/*
uint32_t    _getDurationMicroseconds(my_time_point_t _last_frame,
                                     my_time_point_t _current_time)
{
    std::chrono::duration<uint64_t, > time_delta = std::chrono::duration_cast<milliseconds>(_current_time - _last_frame);
    return time_delta.count();
}*/
