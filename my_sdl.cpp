#include "my_sdl.h"
#include <iostream>

my_sdl::my_sdl(uint32_t screen_width, uint32_t screen_height)
{
    _window_width = screen_width;
    _window_height = screen_height;
    _SdlInit();
}

my_sdl::~my_sdl()
{
    if (nullptr != _window)
    {
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }
}

void    my_sdl::_SdlInit(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("SDL_Init Error: %s\n", SDL_GetError());
    }

    _window = SDL_CreateWindow("Snake",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                _window_width,
                                _window_height,
                                SDL_WINDOW_SHOWN);

    _surface = SDL_GetWindowSurface(_window);
}

void    my_sdl::Draw(void)
{
    SDL_UpdateWindowSurface(_window);
    SDL_LockSurface(_surface);
}

void    my_sdl::Loop(void)
{
    while (!_exit)
    {
    }
}

void    my_sdl::putPixel(uint32_t x, uint32_t y, uint32_t color)
{
    uint32_t    pixel = 0;
    uint32_t    *my_pixels = static_cast<uint32_t *>(_surface->pixels);

    pixel = y * _window_width + x;
    my_pixels[pixel] = color;
}

uint32_t    my_sdl::getPixel(uint32_t x, uint32_t y)
{
    uint32_t    pixel = 0;
    uint32_t    *my_pixels = static_cast<uint32_t *>(_surface->pixels);
    
    pixel = y * _window_width + x;
    return my_pixels[pixel];
}

uint32_t    *my_sdl::getPixels(void)
{
    uint32_t    *my_pixels = static_cast<uint32_t *>(_surface->pixels);

    return my_pixels;
}

uint32_t    my_sdl::getWindowWidth(void)
{
    return _window_width;
}


uint32_t    my_sdl::getWindowHeight(void)
{
    return _window_height;
}

uint8_t     my_sdl::getEvent()
{
    while (SDL_PollEvent(&_eventData))
    {
        switch (_eventData.type)
        {
            case SDL_QUIT:
                return EXIT;
                break;
            case SDL_KEYUP:
                std::cout << _eventData.key.keysym.scancode << "\n";
                break;
        }
    }
}
