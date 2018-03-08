#pragma once
#include <SDL.h>
#include "Rect.h"

#include "Color.h"

class Canvas {

private:
	SDL_Window * m_window;
	SDL_Renderer* m_renderer;
	Color m_background;

public:
	Canvas(Color bg = {255,255,255,255});
	Canvas(int width, int height, Color bg = { 255,255,255,255 });

	Rect* CreateRect(int x, int y, int w, int h);

	Rect* CreateRect(int x, int y, int w, int h, ShapeOptions opt);

	void DrawShape(Shape &);

	void RenderFrame() const;

	~Canvas();
};

