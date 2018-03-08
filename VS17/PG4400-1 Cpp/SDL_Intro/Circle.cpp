#include "Circle.h"
#include <cmath>
#include <algorithm>

Circle::Circle(int x, int y, int r, int res)
	: Shape(x,y)
	, m_radius(r)
	, m_resolution(res)
{
	auto step = 2*M_PI / res;
	for (double theta = 0; theta < 2*M_PI; theta += step) {
		double x = r * std::cos(theta);
		double y = r * std::sin(theta);
		m_vertices.push_back(std::shared_ptr<Vector2<double>> (new Vector2<double>(x, y)));
	}
	m_vertices.push_back(m_vertices.front());
}

Circle::Circle(int x, int y, int r, int res, Color c)
	: Shape(x, y)
	, m_radius(r)
	, m_resolution(res)
{
	// Replace the default color from Shape with the one provided
	m_options.color = c;

	auto step = 2 * M_PI / res;
	for (double theta = 0; theta < 2 * M_PI; theta += step) {
		double x = r * std::cos(theta);
		double y = r * std::sin(theta);
		m_vertices.push_back(std::shared_ptr<Vector2<double>> (new Vector2<double>(x, y)));
	}
	m_vertices.push_back(m_vertices.front());
}

Circle::~Circle() {

	m_vertices.clear();
	
}

void Circle::Draw(SDL_Renderer * renderer) {
	
	auto vector_size = m_vertices.size();
	std::vector<Vector2<int>> renderable_vertices (vector_size);

	/**
	 * Using a while loop to go over the iterators, though not ideal,
	 * prevents unnecessary use of copy contructor.
	*/
	auto rv = renderable_vertices.begin();
	auto v = m_vertices.begin();
	while (rv != renderable_vertices.end() && v != m_vertices.end()) {

		rv->Add(*(*v));
		rv->Add(m_position);

		rv++;
		v++;
	}

	SDL_SetRenderDrawColor(renderer,
												 m_options.color.r,
												 m_options.color.g,
												 m_options.color.b,
												 m_options.color.a);

	SDL_RenderDrawLines(renderer,
										  (SDL_Point*) renderable_vertices.data(),
											vector_size);
	
}
