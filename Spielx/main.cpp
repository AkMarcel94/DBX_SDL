#include "Spiel.h"

Spiel* spiel = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	spiel = new Spiel();

	spiel->init("DragonballX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (spiel->running()) 
	{
		frameStart = SDL_GetTicks();
		
		spiel->handleEvenets();
		spiel->update();
		spiel->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	spiel->clean();

	return 0;
}