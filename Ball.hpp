#include<SDL.h>
#include <thread>
#include <chrono>


class Ball : public Unit{

    protected:

    int Curve;
    int Speed;

    public:

    Ball(SDL_Rect A1, SDL_Rect B1) : Unit(A1 , B1) , Curve(0) , Speed(0) {}
    
    //FUNCTIONS TO ANIMATE THE BALL
    void BallMove(){moverRect.y = moverRect.y + Speed;}
    void BallSwing(){moverRect.x = moverRect.x  + Curve*2;}

    //GETTERS:
    void SetSpeed(int x){Speed =x;}
    void SetCurve(int x){Curve = x;}
    void Setsrc(SDL_Rect A){Unit::Setsrc(A);}
    void Setmover(SDL_Rect A){Unit::Setmover(A);}
    void SetObj(SDL_Rect A , SDL_Rect B){Unit::SetObj(A , B);}
    

    //SETTERS:
    bool GetSpeed(){return Speed;}
    int GetCurve(){return Curve;}

    void Reverse(){Speed = Speed * -1;}



    

    
};