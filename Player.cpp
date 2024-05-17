#include "Player.hpp"



void Player::Animate(SDL_Rect A , SDL_Rect B , SDL_Rect C , SDL_Rect D)
    {
        if (srcRect.x==A.x && srcRect.y==A.y && srcRect.w==A.w && srcRect.h==A.h){srcRect = B;}
        else if (srcRect.x==B.x && srcRect.y==B.y && srcRect.w==B.w && srcRect.h==B.h){srcRect = C;}
        else if (srcRect.x==C.x && srcRect.y==C.y && srcRect.w==C.w && srcRect.h==C.h){srcRect = D;}
        else if (srcRect.x =D.x , srcRect.y = D.y , srcRect.w = D.w , srcRect.h = D.h){srcRect = A;}
        count++;
    }

void Player::MovePlayerLeft()
{moverRect.x -= 40;}

void Player::MovePlayerRight()
{moverRect.x += 40;}

void Player::MovePlayerTop()
{moverRect.y -= 40;}

void Player::MovePlayerBelow()
{moverRect.y += 40;}

void Player::SetServe(bool A){Serve = A;}

bool Player::GetServe(){return Serve;}





