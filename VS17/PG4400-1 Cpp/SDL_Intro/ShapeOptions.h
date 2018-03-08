#pragma once
#include <string>
#include "Color.h"

enum class AnchorPoint {

	top_right,
	top,
	top_left,
	bottom_right,
	bottom,
	bottom_left,
	right,
	left,
	center

};

using ShapeOptions = struct {

	// ralvative or absolute path to .BMP
	std::string texture_path;
	// (default) top_left || bottom || right || ... ||  center
	AnchorPoint anchor_point;
	// { red, green, blue, alpha } int valuses in range 0-255
	Color color;

};
