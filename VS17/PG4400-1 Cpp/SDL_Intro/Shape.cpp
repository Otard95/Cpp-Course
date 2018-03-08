#include "Shape.h"

Shape::Shape(int x, int y) 
	: m_texture(nullptr)
	, m_position(Vector2<double>(x,y))
	, m_anchor_offset(Vector2<double>())
	, m_options({"",AnchorPoint::top_left, {0,0,0,255}})
{}

Shape::Shape(int x, int y, ShapeOptions opt)
	: m_texture(nullptr)
	, m_position(Vector2<double>(x, y))
	, m_anchor_offset(Vector2<double>())
	, m_options(opt)
{}

void Shape::Translate(Vector2<double> v) {

	m_position += v;

}

void Shape::SetPosition(Vector2<double> pos) {

	m_position = pos;

}

Shape::~Shape()
{
	SDL_DestroyTexture(m_texture);
}
