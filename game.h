#ifndef GAME_H
#define GAME_H

#include "square.h"
#include "my_sdl.h"
#include <memory>
#include <chrono>

#define FIELD_SIZE ((SQUARE_WIDTH * SQUARE_HEIGHT))

#define FPS_62_5_MILISECONDS 16

//typedef std::chrono::time_point<std::chrono::steady_clock> my_time_point_t;

class   Game
{
    public:
        Game(my_sdl &sdl_obj);
        virtual ~Game(void);

   private:
        Square      _Field[FIELD_SIZE];

        //my_time_point_t _last_frame;
        //my_time_point_t _current_time;

        uint16_t    _getX(uint16_t index);
        uint16_t    _getY(uint16_t index);
        void        _setCoordinates(void);
        void        _drawBaseColor(my_sdl &sdl_obj);
        void        _setSquareColor(uint32_t x, uint32_t y, uint32_t color);
        //uint32_t    _getDurationMicroseconds(my_time_point_t _last_frame,
        //                                    my_time_point_t _current_time);
};

#endif
