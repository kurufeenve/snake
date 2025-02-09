#ifndef MY_SDL_H
#define MY_SDL_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <memory>

enum
{
    EXIT = 0
}

class   my_sdl
{
    private:
        SDL_Window  *_window = nullptr;
        SDL_Surface *_surface = nullptr;
        bool        _exit = false;
        SDL_Event   _eventData;
        uint32_t    _window_width = 0;
        uint32_t    _window_height = 0;

        void        _SdlInit(void);

    public:
        my_sdl() = delete;
        my_sdl(uint32_t screen_width, uint32_t screen_height);
        virtual ~my_sdl();

        void        Draw(void);
        void        Loop(void);
        void        putPixel(uint32_t x, uint32_t y, uint32_t color);
        uint32_t    getPixel(uint32_t x, uint32_t y);

        uint32_t    *getPixels(void);
        uint32_t    getWindowWidth(void);
        uint32_t    getWindowHeight(void);
        void        getEvent();
};

#endif
