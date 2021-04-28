#include "Spiel.h"
#include "TextureManager.h"
#include "GameObject.h"


GameObject* hintergrund;
GameObject* goku;

Spiel::Spiel()
{

}
Spiel::~Spiel()
{

}

void Spiel::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "Subsystem Initialisiert!..." << std::endl;
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
		std::cout << "Fenster erstellt!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer erstellt!" << std::endl;
		}
		
		isRunning = true;

	}
	else 
	{
		isRunning = false;
	}

	hintergrund = new GameObject("assets/kamehouse.png", renderer,0,0,600,800);
	goku = new GameObject("assets/ssj.png", renderer, 50, 50, 210, 128);
}
void Spiel::handleEvenets() 
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	   case SDL_QUIT:
		   isRunning = false;
		   break;

	   default:
		   break;
	}
}
void Spiel::update()
{
	hintergrund->Update();
	goku->Update();
}
void Spiel::render()
{
	SDL_RenderClear(renderer);
	hintergrund->Render();
	goku->Render();
	//this is where we would add stuff to render
	SDL_RenderPresent(renderer);
}
void Spiel::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}