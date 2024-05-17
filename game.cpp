#include "game.hpp"
#include "Tennis.hpp"
bool Menu = true;
bool Game::init()
{
	
	bool success = true;

	
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		
		gWindow = SDL_CreateWindow( "Tennis", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if (Mix_OpenAudio(44100 , MIX_DEFAULT_FORMAT, 2 , 2048)<0)
				{
					printf("SDL_mixer could not initiliaze! SDL_mixer Error: %s\n" , Mix_GetError());
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	
	bool success = true;
	
	assets = loadTexture("MyAssets.png");
    gTexture = loadTexture("tennisfield.png");
	
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic = Mix_LoadMUS("tt.mp3");

	if (bgMusic == NULL){
		printf("Unacle to load Music: %s \n" , Mix_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic);
	bgMusic = NULL;
	
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	
	SDL_Texture* newTexture = NULL;

	
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}
void Game::run()
{
    SDL_Event event;
    bool quit = false;

    while (!quit)
    {
        
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }

			if (Mix_PlayingMusic() == 0)
			{
				Mix_PlayMusic(bgMusic , 2);
			}
            
            handleEvents(event);
        }

        
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
        drawObjects(gRenderer, assets, event);
        SDL_RenderPresent(gRenderer);
		
        SDL_Delay(200);
    }
}
