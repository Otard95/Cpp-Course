#pragma once
#include "Vector2.h"
#include <SDL.h>
#include <memory>
#include "ShapeOptions.h"

class Shape {

protected:
	SDL_Texture* m_texture;
	Vector2<double> m_position;
	Vector2<double> m_anchor_offset;
	ShapeOptions m_options;

public:
	Shape(int x, int y);
	Shape(int x, int y, ShapeOptions opt);
	virtual void Draw(SDL_Renderer*) = 0;
	virtual void Translate(Vector2<double>);
	virtual void SetPosition(Vector2<double>);
	virtual ~Shape();

};
