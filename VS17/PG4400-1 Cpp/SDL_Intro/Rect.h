#pragma once
#include "Shape.h"

class Rect : public Shape {

	int m_height, m_width;
	SDL_Rect m_SDL_rect;

	void LoadTexture(SDL_Renderer*);

public:
	Rect(int x, int y, int h, int w);
	Rect(int x, int y, int h, int w, ShapeOptions, SDL_Renderer*);
	~Rect() = default;
	void Draw(SDL_Renderer*) override;
};
