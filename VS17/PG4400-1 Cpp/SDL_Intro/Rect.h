#pragma once
#include "Shape.h"

class Rect : public Shape {

	int m_height, m_width;
	SDL_Rect m_SDL_rect;

	void LoadTexture(SDL_Renderer*);

public:
	Rect(int x, int y, int w, int h);
	Rect(int x, int y, int w, int h, ShapeOptions);
	Rect(int x, int y, int w, int h, ShapeOptions, SDL_Renderer*);
	~Rect() = default;

	void Draw(SDL_Renderer*) override;
	void SetScale(int w, int h);
};
