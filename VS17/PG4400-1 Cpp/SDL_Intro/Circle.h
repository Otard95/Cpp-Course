#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class Circle : public Shape {

private:
	int m_radius;
	int m_resolution;
	std::vector<std::shared_ptr<Vector2<double>>> m_vertices;

public:
	Circle(int x, int y, int r, int res);
	Circle(int x, int y, int r, int res, Color c);
	~Circle();

	void Draw(SDL_Renderer *) override;

};

