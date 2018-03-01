#include "Canvas.h"

Canvas::Canvas(SDL_Window* win)
	: m_renderer(SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED))
	, m_background({0,0,0,255})
{}

Canvas::Canvas(SDL_Window* win, Color bg)
	: m_renderer(SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED))
	, m_background(bg) {
}

Canvas::~Canvas() {
	SDL_DestroyRenderer(m_renderer);
}
