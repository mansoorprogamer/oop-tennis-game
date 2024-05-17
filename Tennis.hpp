#include<SDL.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "music.hpp"

void DrawObjects(SDL_Renderer* gRnderer, SDL_Texture* assets, SDL_Event& event);
void HandleEvents(SDL_Event& event);


//this is the parent class 
class Unit 
{
    public:
    SDL_Rect srcRect, moverRect; 

    Unit(SDL_Rect A, SDL_Rect B){srcRect = A; moverRect = B;}
    Setsrc(SDL_Rect A){srcRect = A;}
    Setmover(SDL_Rect B){moverRect = B;}
    SetObj(SDL_Rect A , SDL_Rect B){srcRect = A;moverRect =B;}

    SDL_Rect Getsrc(){return srcRect;}
    SDL_Rect Getmover(){return moverRect;}
    
};

//public access type is used for inheritance so that only the public members are accessible to the derived classes
//the unit class data members are public becuase it does not makes sense to hide srcRect and mverRect as they are needed frequently by other functions outside the class


class Tennis{

    
    public:
    //VARIABLES DECALRATION:
    bool GameState = true;   //initially the game is running
    bool serve = false;
    int BallCurve = 0;
    int XDiff = 0;
    int YDiff = 0;
    bool Calculate = false;
    bool Round = false;
    std::string Turn = "";
    bool Toss = false;
    int mouseX; int mouseY;
    bool Decide = false;
    Music x;

    void DrawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Event& event);
    void HandleEvents(SDL_Event& e);

};