#include <iostream>
#include "Canvas.h"

Canvas::Canvas(Color bg)
	: m_window(nullptr)
	, m_renderer(nullptr)
	, m_background(bg)
{
	m_window = SDL_CreateWindow(
		"Et awesome SDL2-vindu!",             //  window title
		SDL_WINDOWPOS_UNDEFINED,              //  initial m_x position
		SDL_WINDOWPOS_UNDEFINED,              //  initial m_y position
		550,                                  //  width, in pixels
		400,                                  //  height, in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL  // flags
	);

	if (m_window == nullptr) {
		std::cerr << "Failed to create window: "
			<< SDL_GetError() << std::endl;
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == nullptr) {
		std::cerr << "Failed to create renderer: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		return;
	}

	SDL_SetRenderDrawColor(m_renderer, m_background.r, m_background.g, m_background.b, m_background.a);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

Canvas::Canvas(int width, int height, Color bg)
	: m_window(nullptr)
	, m_renderer(nullptr)
	, m_background(bg)
{

	m_window = SDL_CreateWindow(
		"Et awesome SDL2-vindu!",             //  window title
		SDL_WINDOWPOS_UNDEFINED,              //  initial m_x position
		SDL_WINDOWPOS_UNDEFINED,              //  initial m_y position
		width,                                //  width, in pixels
		height,                               //  height, in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL  // flags
	);

	if (m_window == nullptr) {
		std::cerr << "Failed to create window: "
			<< SDL_GetError() << std::endl;
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == nullptr) {
		std::cerr << "Failed to create renderer: "
			<< SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		return;
	}

	SDL_SetRenderDrawColor(m_renderer, m_background.r, m_background.g, m_background.b, m_background.a);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

Rect * Canvas::CreateRect(int x, int y, int w, int h) {
	return new Rect(x, y, w, h);
}

Rect* Canvas::CreateRect(int x, int y, int w, int h, ShapeOptions opt) {
	return new Rect(x, y, w, h, opt, m_renderer);
}

void Canvas::DrawShape(Shape & shape) {

	shape.Draw(m_renderer);

}

void Canvas::RenderFrame() const {

	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, m_background.r, m_background.g, m_background.b, m_background.a);
	SDL_RenderClear(m_renderer);

}

Canvas::~Canvas() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}
