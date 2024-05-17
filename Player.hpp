#include<SDL.h>
#include <thread>
#include <chrono>
#include "Tennis.hpp"



class Player : public Unit{

    protected:
    
    bool Serve;

    public:
    int count = 0;
    void Animate(SDL_Rect A , SDL_Rect B , SDL_Rect C , SDL_Rect D);

    Player(SDL_Rect A1, SDL_Rect B1) : Unit(A1 , B1) , Serve(false) {}

    void MovePlayerLeft();
    void MovePlayerRight();
    void MovePlayerTop();
    void MovePlayerBelow();

    //GETTERS
    bool GetServe();
    void SetServe(bool A);

   
    

};
