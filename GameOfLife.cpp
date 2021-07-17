#include <stdio.h>
#include <iostream>
#include <Game.h>
#include <SDL.h>
#include <SDL_render.h>

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 810;

enum buttonStates {MOUSE_DOWN, MOUSE_UP};

// Initializes SDL
bool init();

// Closes and deallocates all data related to SDL
void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL failed to initialize. SDL ERROR: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering is not enabled." << std::endl;
		}

		gWindow = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "Failed to create Window. SDL_ERROR: " << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				std::cout << "Failed to create renderer. SDL_ERROR: " << SDL_GetError() << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0, 0, 0xFF);
			}
		}
	}

	return success;
}

void close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		std::cout << "Failed to initialize SDL." << std::endl;
	}
	else
	{
		std::cout << "Running program." << std::endl;

		bool quit = false;
		bool buttonState = MOUSE_UP;
		SDL_Event e;

		Game mainGame(0, 0, SCREEN_WIDTH/10, SCREEN_HEIGHT/10);

		while(!quit)
		{
			while (SDL_PollEvent(&e) > 0)
			{
				switch (e.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if (!mainGame.simulationRunning())
					{
						buttonState = MOUSE_DOWN;
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if (!mainGame.simulationRunning())
					{
						buttonState = MOUSE_UP;
					}
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
					case SDLK_SPACE:
						if (!mainGame.simulationRunning())
						{
							std::cout << "Running simulation.\n";
							mainGame.setSimulationStatus(true);
						}
						else
						{
							std::cout << "Stopping simulation.\n";
							mainGame.setSimulationStatus(false);
						}
						break;
					case SDLK_e:
						if (!mainGame.simulationRunning())
						{
							std::cout << "Updating simulation by one step.\n";
							mainGame.update();
						}
						break;
					case SDLK_c:
						if (!mainGame.simulationRunning())
						{
							std::cout << "Clearing game board\n";
							mainGame.clear();
						}
					}
				}		
			}

			if (mainGame.simulationRunning())
			{
				mainGame.update();
				SDL_Delay(100);
			}
			else if (buttonState == MOUSE_DOWN)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				x -= mainGame.getX();
				y -= mainGame.getY();
				x /= 10;
				y /= 10;

				if (!mainGame.getGrid()[x][y]->isAlive())
				{
					mainGame.switchCellState(x, y);
				}
			}

			mainGame.draw(gRenderer);

			SDL_RenderPresent(gRenderer);
		}
	}

	close();

	return 0;
}