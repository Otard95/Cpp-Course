#pragma once
#include <vector>
#include <memory>
#include "Shape.h"

class Ellipse : public Shape {

private:
	int m_semi_major;
	int m_semi_minor;
	int m_resolution;
	std::vector<std::shared_ptr<Vector2<double>>> m_vertices;

public:
	Ellipse(int x, int y, int major, int minor, int res);
	Ellipse(int x, int y, int major, int minor, int res, Color c);
	~Ellipse();

	void Draw(SDL_Renderer *) override;

};

