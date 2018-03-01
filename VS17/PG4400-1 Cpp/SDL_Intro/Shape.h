#pragma once
#include "Vector2.h"
#include <SDL.h>
#include <memory>
#include "ShapeOptions.h"

class Shape {

protected:
	SDL_Texture* m_texture;
	Vector2 m_position;
	Vector2 m_opsition_offset;
	ShapeOptions m_options;

public:
	Shape(int x, int y);
	Shape(int x, int y, ShapeOptions opt);
	virtual void Draw(SDL_Renderer*) = 0;
	virtual ~Shape();

};
