#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include "Move.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 1200/*WIDTH*/, 600/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    background = IMG_LoadTexture(renderer,"fondo.png");
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 500;
    rect_background.h = 250;

    character = IMG_LoadTexture(renderer, "personaje.png");
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = 32;
    rect_character.h = 32;

    vector<Sprite*>sprites;
    sprites.push_back(new Sprite(renderer,"assets/idle/1.png",75,0));
    sprites.push_back(new Sprite(renderer,"assets/idle/2.png",75,0));
    sprites.push_back(new Sprite(renderer,"assets/idle/3.png",75,0));
    sprites.push_back(new Sprite(renderer,"assets/idle/4.png",75,0));

    vector<Sprite*>sprites1;
    sprites1.push_back(new Sprite(renderer,"assets/kick/1.png",75,150));
    sprites1.push_back(new Sprite(renderer,"assets/kick/2.png",75,150));
    sprites1.push_back(new Sprite(renderer,"assets/kick/3.png",75,150));
    sprites1.push_back(new Sprite(renderer,"assets/kick/4.png",75,150));
    sprites1.push_back(new Sprite(renderer,"assets/kick/5.png",75,150));
    sprites1.push_back(new Sprite(renderer,"assets/kick/6.png",75,150));

    vector<Sprite*>sprites2;
    sprites2.push_back(new Sprite(renderer,"assets/punch/1.png",75,400));
    sprites2.push_back(new Sprite(renderer,"assets/punch/2.png",75,400));
    sprites2.push_back(new Sprite(renderer,"assets/punch/3.png",75,400));

    vector<Sprite*>sprites3;
    sprites3.push_back(new Sprite(renderer,"assets/walk/1.png",75,700));
    sprites3.push_back(new Sprite(renderer,"assets/walk/2.png",75,700));
    sprites3.push_back(new Sprite(renderer,"assets/walk/3.png",75,700));
    sprites3.push_back(new Sprite(renderer,"assets/walk/4.png",75,700));
    sprites3.push_back(new Sprite(renderer,"assets/walk/5.png",75,700));



    Move move(renderer,sprites);
    Move move1(renderer,sprites1);
    Move move2(renderer,sprites2);
    Move move3(renderer,sprites3);


    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_character.x--;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);

        move.draw();
        move1.draw();
        move2.draw();
        move3.draw();

        SDL_RenderPresent(renderer);
    }

	return 0;
}
