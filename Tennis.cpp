#include<iostream>
#include "Player.hpp"
#include <vector>
#include <random>
#include "Score.hpp"
#include "Game.hpp"
#include "Ball.hpp"


//DECLARING OPBJECTS
Player PlayerUp({271,7,30,57}, {220*2, 40*2, 50*2, 50*2});
Player PlayerDown({15,7,30,57}  , {220*2,380*2,50*2,50*2});
Score UpScore({0,0,0,0} , {100,200,35,35});
Score DownScore( {0,0,0,0,} , {100,700,35,35});
Unit ScoreBoard = {{16,344,52,326},{50,160,100,600}};
Unit Winner = {{0,0,0,0} , {0,0,0,0}};
Ball ball({0,0,0,0} , {0,0,0,0});
Unit Pointer = {{0,0,0,0} , {0,0,0,0}};




void Tennis::DrawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Event& event)
{
    SDL_RenderCopy(gRenderer, assets, &PlayerUp.srcRect, &PlayerUp.moverRect);
    SDL_RenderCopy(gRenderer, assets, &PlayerDown.srcRect, &PlayerDown.moverRect);
   
    SDL_RenderCopy(gRenderer, assets, &UpScore.srcRect, &UpScore.moverRect);
    SDL_RenderCopy(gRenderer, assets, &DownScore.srcRect, &DownScore.moverRect);
    
    SDL_RenderCopy(gRenderer, assets, &ScoreBoard.srcRect, &ScoreBoard.moverRect);
    SDL_RenderCopy(gRenderer, assets, &Winner.srcRect, &Winner.moverRect);
    

    
    if (PlayerUp.GetServe()==true && PlayerUp.count <4){PlayerUp.Animate({271,7,30,57} , {271,135,35,57} , {330,135,31,57} , {391,137,30,55});}
    if (PlayerDown.GetServe()==true && PlayerDown.count<4){PlayerDown.Animate({15,7,30,57} , {195,135,45,57} , {15,200,43,56} , {72,200,39,56});}
    ball.BallMove();
    if (ball.GetSpeed()>0 && ball.moverRect.y >120*2)
    {
        ball.BallSwing();
    }

    if (ball.GetSpeed()<0 && ball.moverRect.y <120*2)
    {
        ball.BallSwing();
    }

    SDL_RenderCopy(gRenderer, assets, &ball.srcRect, &ball.moverRect);
    HandleEvents(event);

    if (Turn == "up"){Pointer.srcRect = {744,176,156,52} ; Pointer.moverRect =  {820,90,30,30};}
    else if (Turn == "down"){Pointer.srcRect = {744,176,156,52} ; Pointer.moverRect =  {820,870,30,30};} 
    SDL_RenderCopy(gRenderer, assets, &Pointer.srcRect, &Pointer.moverRect);


}

//CREATING ARRAYS TO HANDLE THE EVENTS OF BOTH PLAYERS SIMULTANEOUSLY
bool keysPlayerUp[SDL_NUM_SCANCODES] = {false};
bool keysPlayerDown[SDL_NUM_SCANCODES] = {false};

void Tennis::HandleEvents(SDL_Event& event)
{
   
    //Ending the game when any player reaches a score of 3
    if (UpScore.Gets() == 3 ||  DownScore.Gets() == 3){GameState = false;}

    //START EVENT HANDLING FOR KEY PRESSES
    if (event.type == SDL_KEYDOWN) 
    {
        keysPlayerUp[event.key.keysym.scancode] = true;
        keysPlayerDown[event.key.keysym.scancode] = true;
    }
    else if (event.type == SDL_KEYUP) 
    {
        keysPlayerUp[event.key.keysym.scancode] = false;
        keysPlayerDown[event.key.keysym.scancode] = false;
    }
    if (event.type == SDL_QUIT) {} 
    else if (event.type == SDL_MOUSEBUTTONDOWN) 
    {
        if (event.button.button == SDL_BUTTON_LEFT) 
        {
                mouseX = event.button.x;
                mouseY = event.button.y;

                //PRINTING THE COORDINATES WHERE THE MOUSE WAS PRESSED 
                printf("Left click at (%d, %d)\n", mouseX, mouseY);
                if (Decide == false){
                if (mouseY < 450){Turn = "up";Decide = true;}
                else if (mouseY > 500){Turn = "down";Decide = true;}}

        }
    }

    

    //MOVING PLAYER UP USING AWSD KEYS AND SPACE FOR SERVING
    if (keysPlayerUp[SDL_SCANCODE_A] && PlayerUp.moverRect.x >= 105*2 && GameState == true) 
        {PlayerUp.MovePlayerLeft();}
    if (keysPlayerUp[SDL_SCANCODE_D] && PlayerUp.moverRect.x <= 365*2 && GameState == true) 
        {PlayerUp.MovePlayerRight();}
    if (keysPlayerUp[SDL_SCANCODE_W] && PlayerUp.moverRect.y >= 60*2 && GameState == true) 
        {PlayerUp.MovePlayerTop();}
    if (keysPlayerUp[SDL_SCANCODE_S] && PlayerUp.moverRect.y <= 120*2 && GameState == true)
        {PlayerUp.MovePlayerBelow();}
    if (keysPlayerUp[SDL_SCANCODE_SPACE] && Round == false && GameState == true && Turn == "up")
    {
        x.hit = false;
        Round = true; PlayerUp.SetServe(true); 
       
        x.loadhit();
        //SHOW THE BALL ON SCREEN COMING FROM PLAYER UP
        ball.srcRect = {512,155,9,9}; ball.moverRect =  {PlayerUp.moverRect.x, PlayerUp.moverRect.y, 20*2, 20*2};
        ball.SetSpeed(60);
        PlayerUp.count = 0;
    }

    //MOVING PLAYER DOWN USING L,R;U,D KEYS AND RSHIFT FOR SERVING
    if (keysPlayerDown[SDL_SCANCODE_LEFT] && PlayerDown.moverRect.x >= 105*2 && GameState == true) 
        {PlayerDown.MovePlayerLeft();}
    if (keysPlayerDown[SDL_SCANCODE_RIGHT] && PlayerDown.moverRect.x <= 365*2 && GameState == true) 
        {PlayerDown.MovePlayerRight();}
    if (keysPlayerDown[SDL_SCANCODE_UP] && PlayerDown.moverRect.y >= 280*2 && GameState == true) 
        {PlayerDown.MovePlayerTop();}
    if (keysPlayerDown[SDL_SCANCODE_DOWN] && PlayerDown.moverRect.y <= 350*2 && GameState == true)
        {PlayerDown.MovePlayerBelow();}
    if (keysPlayerDown[SDL_SCANCODE_RSHIFT] && Round == false && GameState == true && Turn == "down" )
    {
        x.hit = false;
         x.loadhit();
        Round = true; PlayerDown.SetServe(true);

        //SHOW THE BALL ON SCREEN COMING FROM PLAYER UP
        ball.srcRect = {512,155,9,9}; ball.moverRect=  {PlayerDown.moverRect.x, PlayerDown.moverRect.y, 20*2, 20*2};
        ball.SetSpeed(-60);
        PlayerDown.count = 0;
    }

    //DETERMINING COLLISIONS BETWEEN THE BALL;

    //The Hitting turn = PLayerUP ie player down made the serve and now its time for player up to hit 
    if (PlayerUp.GetServe() == false && PlayerDown.GetServe() == true)
    {
        XDiff = abs(PlayerUp.moverRect.x - ball.moverRect.x);
        YDiff = abs(PlayerUp.moverRect.y - ball.moverRect.y);
        if (keysPlayerUp[SDL_SCANCODE_SPACE] && XDiff < 80 && YDiff <80)  //BALL SUCCESSFULLY HIT
        {
            x.hit = false;
            x.loadhit();
            ball.Reverse();
            PlayerUp.SetServe(true);
            PlayerDown.SetServe(false);
            PlayerUp.count = 0;

            if (ball.moverRect.x>750){ball.SetCurve(-10);}
            else if (ball.moverRect.x<240){ball.SetCurve(10);}
            else if (XDiff > -10 && XDiff < 10){ball.SetCurve(0);}
            else if (XDiff > 0){ball.SetCurve(10);}
            else {ball.SetCurve(-10);}
        }
    }

    //THE HITTING TURN = PlayerDown ie PlayerUp made the serve and now its time for player down to hir
    if (PlayerDown.GetServe() == false && PlayerUp.GetServe() == true)
    {
        int XDiff = abs(PlayerDown.moverRect.x - ball.moverRect.x);
        int YDiff = abs(PlayerDown.moverRect.y - ball.moverRect.y);

        if (keysPlayerDown[SDL_SCANCODE_RSHIFT] && XDiff < 80 && YDiff <80)  //BALL SUCCESSFULLY HIT
        {   
            x.hit = false;
            x.loadhit();
            
            ball.Reverse();
            PlayerUp.SetServe(false);
            PlayerDown.SetServe(true);
            PlayerDown.count = 0;

            if (ball.moverRect.x>750){ball.SetCurve(-10);}
            else if (ball.moverRect.x<240){ball.SetCurve(10);}
            else if (XDiff > -10 && XDiff < 10){ball.SetCurve(0);}
            else if (XDiff > 0){ball.SetCurve(-10);}
            else {ball.SetCurve(10);}
        }
    }


    //CALCULATING THE SCORE OF EACH PLAYER:

    //CASE 1: ITS PLAYER UP'S TURN TO HIT AND HE HIT OUTSIDE THE VERTICAL BOUNDARY
    if (PlayerUp.GetServe() == true && (ball.moverRect.x >780 || ball.moverRect.x <160))
    {++DownScore; PlayerUp.SetServe(false); Round=false; Turn = (Turn == "up") ? "down" : "up";}
    else if (PlayerDown.GetServe() == true && (ball.moverRect.x >780 || ball.moverRect.x <160))
    {++UpScore; PlayerDown.SetServe(false); Round=false; Turn = (Turn == "up") ? "down" : "up";}
    else if (PlayerUp.GetServe() == true && ball.moverRect.y > 900)
    {++UpScore; PlayerUp.SetServe(false); Round = false;Turn = (Turn == "up") ? "down" : "up";}
    else if (PlayerDown.GetServe() == true && ball.moverRect.y < 75)
    {++DownScore;PlayerDown.SetServe(false); Round = false;Turn = (Turn == "up") ? "down" : "up";}

    




    //DISPLAYING THE SCORE OF EACH PLAYER ON THE SCREEN

    if (DownScore == 0){DownScore.Setsrc({113,363,16,20});}
    else if (DownScore == 1){DownScore.Setsrc({158,362,14,21});}
    else if (DownScore == 2){DownScore.Setsrc({201,362,15,21});}
    else if (DownScore == 3) {DownScore.Setsrc({245,363,15,20});}

    if (UpScore == 0){UpScore.Setsrc({113,363,16,20});}
    else if (UpScore == 1){UpScore.Setsrc({158,362,14,21});}
    else if (UpScore == 2){UpScore.Setsrc({201,362,15,21});}
    else if (UpScore == 3) {UpScore.Setsrc({245,363,15,20});}


    //DISPLAY THE WINNER BATCH
    if (UpScore.Gets() == 3)
    {
        Winner.SetObj({292,337,379,310} , {400, 200, 100*2, 100*2});
        x.loadmusic2();
    }
    else if (DownScore.Gets() == 3)
    {
        Winner.SetObj({292,337,379,310}  , {400,500,100*2,100*2});
        x.loadmusic2();
    }

  
}



