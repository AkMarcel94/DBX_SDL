#ifndef Spiel_hpp
#define Spiel_hpp

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Spiel {
public:
	Spiel();
		~Spiel();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		
		void handleEvenets();
		void update();
		void render();
		void clean();

		bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif /* Spiel_hpp */