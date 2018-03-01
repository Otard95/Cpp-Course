#pragma once
#include <SDL.h>
#include "Color.h"

class Canvas {

private:
	SDL_Renderer* m_renderer;
	Color m_background;

public:
	Canvas(SDL_Window*);
	Canvas(SDL_Window*, Color);
	~Canvas();
};

