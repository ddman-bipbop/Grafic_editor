#include "Rastr.h"
#include "Description.h"

const int windowX = 1200;
const int windowY = 900;



int main(int argc, char** argv)
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Привет!", 300, 100, windowX, windowY, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

	TTF_Init();
	Rastr rastr;
	Description des;


	SDL_Event event;
	bool quit = false;

	while (!quit)
	{
		SDL_SetRenderDrawColor(renderer, 150, 0, 150, 0);
		SDL_RenderClear(renderer);
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_q)
				{
					quit = true;
				}
				
			}
		}
		
		rastr.Draw(renderer, event, des);
		rastr.DrawProp(renderer,event,des);
		





		SDL_RenderPresent(renderer);
		//SDL_Delay(1000 / 120);
	}
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}