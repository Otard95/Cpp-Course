#define SDL_MAIN_HANDLED

#include <iostream>
#include <SDL.h>
#include "InputManager.h"
#include <algorithm>

// NB: Denne koden tar seg IKKE av feilhåndtering ved init.
int main() {

	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {// Init. SDL2
		std::cout << "Initilization error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_Window* window = nullptr; // Pointer to Window

																// Lag et vindu med gitte settings
																// For alle mulige konfigurasjonsalternativer, se: http://goo.gl/8vDJN
	window = SDL_CreateWindow(
		"Et awesome SDL2-vindu!",          //    window title
		SDL_WINDOWPOS_UNDEFINED,           //    initial m_x position
		SDL_WINDOWPOS_UNDEFINED,           //    initial m_y position
		550,                               //    width, in pixels
		400,                               //    height, in pixels
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL //    flags
	);
	// Sjekk om noe gikk galt
	if (window == nullptr) {
		std::cerr << "Failed to create window: "
			<< SDL_GetError() << std::endl;
		SDL_Quit(); // Rydd opp!
		return EXIT_FAILURE;
	}

	InputManager &input = InputManager::Instance();

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

		Vector2 mouse_rel = input.GetMouseMovement();
		std::cout << mouse_rel.x() << " - " << mouse_rel.y() << std::endl;

#pragma endregion 

		// Pause for 17 ms (aprox 60 fps)
		SDL_Delay(17);
	}

	SDL_DestroyWindow(window);
	SDL_Quit(); // Have SDL clean ip its mess
	return EXIT_SUCCESS;

}
