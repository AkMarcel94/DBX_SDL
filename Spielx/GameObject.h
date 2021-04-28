#pragma once
#include "Spiel.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren,int x,int y,int h,int w);
	~GameObject();

	void Update();
	void Render();


private:

	int xpos;
	int ypos;
	int height;
	int widht;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;


};