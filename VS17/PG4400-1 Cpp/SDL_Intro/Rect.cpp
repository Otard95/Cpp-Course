#include "Rect.h"
#include <iostream>

void Rect::LoadTexture(SDL_Renderer* renderer) {

	// Last inn et bilde fra disk (NB: støtter KUN BMP!)
	SDL_Surface* surface = SDL_LoadBMP("my_picture.bmp");
	// Sjekk for feil
	if (surface == nullptr) {
		std::cerr << "Failed to load image: "
			<< SDL_GetError() << std::endl;
		return;
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface); // Frigjør surface fra CPU-minnet

}

Rect::Rect(int x, int y, int h, int w)
	: Shape(x, y)
	, m_height(h)
	, m_width(w)
	, m_SDL_rect({ x, y, w, h }) {
}

Rect::Rect(int x, int y, int h, int w, ShapeOptions opt, SDL_Renderer* rend)
	: Shape(x, y, opt)
	, m_height(h)
	, m_width(w) {
	LoadTexture(rend);
}

void Rect::Draw(SDL_Renderer* renderer) {


	SDL_RenderCopy(renderer, m_texture, nullptr, &m_SDL_rect);

}
