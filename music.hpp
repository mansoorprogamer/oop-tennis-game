#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>


class Music{

    private:
    Mix_Music *bgMusic;
    bool musicPlaying;
    bool musicPlaying2;


    public:
    bool hit;
    bool bounce;
    Music();
    ~Music() ;
    void loadmusic1();
    void loadmusic2();
    void loadhit();
    void loadbounce();

};