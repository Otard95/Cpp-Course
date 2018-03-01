#include "Shape.h"

Shape::Shape(int x, int y) 
	: m_texture(nullptr)
	, m_position(Vector2(x,y))
	, m_opsition_offset(Vector2())
	, m_options({"","",AnchorPoint::top_left, {0,0,0,255}})
{}

Shape::Shape(int x, int y, ShapeOptions opt)
	: m_texture(nullptr)
	, m_position(Vector2(x, y))
	, m_opsition_offset(Vector2())
	, m_options(opt)
{}

Shape::~Shape()
{
	SDL_DestroyTexture(m_texture);
}
