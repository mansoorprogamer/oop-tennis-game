#include<SDL.h>
#include <thread>
#include <chrono>


class Score : public Unit{

    protected:

    int s;

    public:
    Score(SDL_Rect A1, SDL_Rect B1) : Unit(A1 , B1) , s(0) {}

    //OVERLAODING THE ++ OPERATOR:
    //USING PRE FIX VERSION AS ITS MORE EFFEIECENT AS STATED IN THE BOOK:

    Score& operator++()
    {
        s = s + 1;
        return *this;
    }

    //OVERLOADING THE == OPERARTOR TO COMPARE THE SCORE WITH AN INTEGER 
    bool operator==(int x)
    {
        if (s == x){return true;}
        else {return false;}
    }

    int Gets(){return s;}

    void SetSrc(SDL_Rect A){Unit::Setsrc(A);}
   
};