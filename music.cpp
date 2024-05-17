#include "music.hpp"

Music::Music()
{
    bgMusic = NULL;
    musicPlaying=false;
    musicPlaying2=false;
    hit=false;
    bounce=false;
}

Music::~Music() 
{
    Mix_FreeMusic(bgMusic);
    bgMusic = NULL;
    musicPlaying=false;
    musicPlaying2=false;
    hit=false;
    bounce=false;
}

void Music::loadmusic1() 
{
    if (musicPlaying==false)
    {
            bgMusic = Mix_LoadMUS("tt.mp3");
            if (bgMusic == NULL) {
                printf("Unable to load Music: %s\n", Mix_GetError());
                return;
            }
            Mix_PlayMusic(bgMusic , 2); 
            musicPlaying=true;
    }
}


void Music::loadmusic2() 
{
    if (musicPlaying2==false)
    {
        bgMusic = Mix_LoadMUS("win.mp3");
        if (bgMusic == NULL) {
            printf("Unable to load Music: %s\n", Mix_GetError());
            return;
        }

        Mix_PlayMusic(bgMusic , 2); 
        musicPlaying2=true;
    }
}

void Music::loadhit()
{
    if (hit==false)
    {
            bgMusic = Mix_LoadMUS("hit.mp3");
            if (bgMusic == NULL) {
                printf("Unable to load Music: %s\n", Mix_GetError());
                return;
            }
            Mix_PlayMusic(bgMusic , 2); 
            hit=true;
    }
}


void Music::loadbounce()
{
    if (bounce==false)
    {
            bgMusic = Mix_LoadMUS("ball_bounce.mp3");
            if (bgMusic == NULL) {
                printf("Unable to load Music: %s\n", Mix_GetError());
                return;
            }
            Mix_PlayMusic(bgMusic , 2); 
            bounce=true;
    }
}


