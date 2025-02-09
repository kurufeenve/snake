#include <SDL2/SDL.h>
#include "my_sdl.h"
#include "background.h"
#include "game.h"


int main(void)
{
    my_sdl      my_sdl(WINDOW_WIDTH, WINDOW_HEIGHT);
    bachground  bachground(my_sdl);
    Game        Game(my_sdl);

    my_sdl.Draw();
    my_sdl.Loop();
    system("Leaks a.out");
    return 0;
}
