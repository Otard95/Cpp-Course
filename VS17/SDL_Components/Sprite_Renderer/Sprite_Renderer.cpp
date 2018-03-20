// CDP::Sprite_Renderer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include "CDP\Headers\CDP.h"

int main(int argc, char *argv[])
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Failed to initilize SDL!" << std::endl;
		std::cin.get();
		return EXIT_FAILURE;
	}

	std::vector<std::shared_ptr<CDP::Component>> cmp;
	CDP::GameObject test;

	std::shared_ptr<CDP::Component> sp(new CDP::Sprite(cmp, test, "Resources/MissingTexture.bmp"));
	std::shared_ptr<CDP::Component> tr(new CDP::Transform(cmp, test));

	cmp.push_back(sp);
	cmp.push_back(tr);

	std::for_each(cmp.begin(), cmp.end(), [](auto c) {

		c->Start();

	});

	std::for_each(cmp.begin(), cmp.end(), [](auto c) {

		c->Update();

	});

	CDP::Canvas::Instance().RenderFrame();

	std::cin.get();
	cmp.clear();
	SDL_Quit();

  return 0;
}

