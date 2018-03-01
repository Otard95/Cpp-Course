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
	left

};

using ShapeOptions = struct {

	// ralvative or absolute path to .BMP
	std::string texture_path;
	// <x-size>X<y-size> || <number>% || cover || fit
	// (default) <Texture.x>X<Texture.y>
	std::string texture_size;
	// (default) top_left || bottom || right || ... ||  center
	AnchorPoint anchor_point;
	// { red, green, blue, alpha } int valuses in range 0-255
	Color color;

};
