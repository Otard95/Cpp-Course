#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include <algorithm>
#include <memory>
#include "InputManager.h"
#include "Canvas.h"
#include "Ellipse.h"

// NB: Denne koden tar seg IKKE av feilhåndtering ved init.
int main() {

	/*
	 * ## Setup
	*/
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Initilization error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		std::cin.get();
		return EXIT_FAILURE;
	}

	std::shared_ptr<Canvas> canvas(new Canvas(1600, 900, { 100,100,200,255 }));

	//std::shared_ptr<Rect> r1 (canvas->CreateRect(100, 150, 364, 121, { "WHY.bmp", AnchorPoint::center,{ 255,255,255,255 } }));

	// Ellipse c (800, 450, 200, 100, 50, {255,255,255,255});

	InputManager &input = InputManager::Instance();

	/*
	 * ## Main Program Loop
	*/
	bool running = true;
	while (running) {

		input.Update();

		if (input.GetKeyDown(Keys::Esc)) running = false;

		#pragma region InputManager Test

		/*if (input.GetKey(Keys::W))     std::cout << "W"     << std::endl;
		if (input.GetKey(Keys::A))     std::cout << "A"     << std::endl;
		if (input.GetKey(Keys::S))     std::cout << "S"     << std::endl;
		if (input.GetKey(Keys::D))     std::cout << "D"     << std::endl;
		if (input.GetKey(Keys::Shift)) std::cout << "Shift" << std::endl;

		if (input.GetKeyDown(Keys::W))     std::cout << "W - Was pressed down" << std::endl;
		if (input.GetKeyDown(Keys::A))     std::cout << "A - Was pressed down" << std::endl;
		if (input.GetKeyDown(Keys::S))     std::cout << "S - Was pressed down" << std::endl;
		if (input.GetKeyDown(Keys::D))     std::cout << "D - Was pressed down" << std::endl;
		if (input.GetKeyDown(Keys::Shift)) std::cout << "Shift - Was pressed down" << std::endl;

		if (input.GetKeyUp(Keys::W))     std::cout << "W - Was released" << std::endl;
		if (input.GetKeyUp(Keys::A))     std::cout << "A - Was released" << std::endl;
		if (input.GetKeyUp(Keys::S))     std::cout << "S - Was released" << std::endl;
		if (input.GetKeyUp(Keys::D))     std::cout << "D - Was released" << std::endl;
		if (input.GetKeyUp(Keys::Shift)) std::cout << "Shift - Was released" << std::endl;

		if (input.GetMouseButton(MouseButton::Left))   std::cout << "Left Mouse" << std::endl;
		if (input.GetMouseButton(MouseButton::Right))  std::cout << "Right Mouse" << std::endl;
		if (input.GetMouseButton(MouseButton::Middle)) std::cout << "Middle Mouse" << std::endl;

		if (input.GetMouseButtonDown(MouseButton::Left))   std::cout << "Left Mouse - Down" << std::endl;
		if (input.GetMouseButtonDown(MouseButton::Right))  std::cout << "Right Mouse - Down" << std::endl;
		if (input.GetMouseButtonDown(MouseButton::Middle)) std::cout << "Middle Mouse - Down" << std::endl;

		if (input.GetMouseButtonUp(MouseButton::Left))   std::cout << "Left Mouse - Up" << std::endl;
		if (input.GetMouseButtonUp(MouseButton::Right))  std::cout << "Right Mouse - Up" << std::endl;
		if (input.GetMouseButtonUp(MouseButton::Middle)) std::cout << "Middle Mouse - Up" << std::endl;*/

		/*Vector2 mouse_rel = input.GetMousePos();
		std::cout << mouse_rel.x << " - " << mouse_rel.y << std::endl;*/

		#pragma endregion

		#pragma region Canvas Test

		//r1->SetPosition(input.GetMousePos());

		//canvas->DrawShape(*r1);

		// canvas->DrawShape(c);

		// canvas->RenderFrame();

		#pragma endregion

		// Pause for 1000ms / 60frames = 16.666666667ms = 60 fps
		SDL_Delay(1000/60);
	}

	SDL_Quit(); // Have SDL clean ip its mess
	return EXIT_SUCCESS;

}
