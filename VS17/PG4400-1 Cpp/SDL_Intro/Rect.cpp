#include "Rect.h"
#include <iostream>

void Rect::LoadTexture(SDL_Renderer* renderer) {

	// Last inn et bilde fra disk (NB: støtter KUN BMP!)
	SDL_Surface* surface = SDL_LoadBMP(m_options.texture_path.c_str());
	// Sjekk for feil
	if (surface == nullptr) {
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface); // Frigjør surface fra CPU-minnet

}

// Creates a black rectangle with the position and dimentions provided.
Rect::Rect(int x, int y, int w, int h)
	: Shape(x, y)
	, m_height(h)
	, m_width(w)
{
	m_SDL_rect.x = x;
	m_SDL_rect.y = y;
	m_SDL_rect.h = h;
	m_SDL_rect.w = w;
}

// Creates a rectangle with the position and dimentions provided.
// You can also use the options to select a background color,
// as well as the anchorpoint of the shape. (you CANNOT provide a texture)
Rect::Rect(int x, int y, int w, int h, ShapeOptions opt)
	: Shape(x, y, opt)
	, m_height(h)
	, m_width(w) {
	m_SDL_rect.x = x;
	m_SDL_rect.y = y;
	m_SDL_rect.h = h;
	m_SDL_rect.w = w;

	// create the appropriate vector for the anchor-point
	switch (m_options.anchor_point) {
		case AnchorPoint::top:
			m_anchor_offset.x = w / 2;
			break;

		case AnchorPoint::top_right:
			m_anchor_offset.x = w;
			break;

		case AnchorPoint::right:
			m_anchor_offset.x = w;
			m_anchor_offset.y = h / 2;
			break;

		case AnchorPoint::bottom_right:
			m_anchor_offset.x = w;
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::bottom:
			m_anchor_offset.x = w / 2;
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::bottom_left:
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::left:
			m_anchor_offset.y = h / 2;
			break;

		case AnchorPoint::center:
			m_anchor_offset.x = w / 2;
			m_anchor_offset.y = h / 2;
			break;

		default:
			break;
	}
}

// Creates a rectangle with the provided position and dimentions.
// You can also provide a background(color or BMP) in the options.
// WILL REQUIRE: SDL_Renderer - generally used indirectly with Canvas
Rect::Rect(int x, int y, int w, int h, ShapeOptions opt, SDL_Renderer* rend)
	: Shape(x, y, opt)
	, m_height(h)
	, m_width(w)
{
	m_SDL_rect.x = x;
	m_SDL_rect.y = y;
	m_SDL_rect.h = h;
	m_SDL_rect.w = w;

	if (m_options.texture_path != "")
		LoadTexture(rend);
	// create the appropriate vector for the anchor-point
	switch (m_options.anchor_point) {
		case AnchorPoint::top :
			m_anchor_offset.x = w / 2;
			break;

		case AnchorPoint::top_right :
			m_anchor_offset.x = w;
			break;

		case AnchorPoint::right :
			m_anchor_offset.x = w;
			m_anchor_offset.y = h / 2;
			break;

		case AnchorPoint::bottom_right :
			m_anchor_offset.x = w;
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::bottom :
			m_anchor_offset.x = w / 2;
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::bottom_left :
			m_anchor_offset.y = h;
			break;

		case AnchorPoint::left :
			m_anchor_offset.y = h / 2;
			break;

		case AnchorPoint::center :
			m_anchor_offset.x = w / 2;
			m_anchor_offset.y = h / 2;
			break;

		default:
			break;
	}
}

// Function for drawing this rectangle to the provided renderer.
// Generally you would pass the object by referance to a Canvas.
void Rect::Draw(SDL_Renderer* renderer) {

	Vector2<double> baked_pos = m_position - m_anchor_offset;
	m_SDL_rect.x = static_cast<int> (baked_pos.x);
	m_SDL_rect.y = static_cast<int> (baked_pos.y);

	if (m_texture != nullptr) {

		if (SDL_RenderCopy(renderer, m_texture, nullptr, &m_SDL_rect) != 0) {
			std::cerr << "Failed to draw rect: " << SDL_GetError() << std::endl;
		}

	} else {

		int sdl_sdc = SDL_SetRenderDrawColor(renderer,
													 m_options.color.r,
													 m_options.color.g,
													 m_options.color.b,
													 m_options.color.a);
		if (sdl_sdc != 0) {
			std::cerr << "Failed to set draw color: " << SDL_GetError() << std::endl;
		}

		if (SDL_RenderFillRect(renderer, &m_SDL_rect) != 0) {
			std::cerr << "Failed to draw rect: " << SDL_GetError() << std::endl;
		}

	}

}

// Sets the height and width of the rectangle.
void Rect::SetScale(int w, int h) {

	m_SDL_rect.w = w;
	m_SDL_rect.h = h;

}