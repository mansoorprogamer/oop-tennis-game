
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Game{
    const int SCREEN_WIDTH = 500*2;
    const int SCREEN_HEIGHT = 500*2;

    SDL_Window* gWindow = NULL;

    SDL_Renderer* gRenderer = NULL;

    SDL_Texture* gTexture = NULL;
    
    SDL_Texture* assets=NULL;

    Mix_Music *bgMusic = NULL;
    

public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

