#pragma once
#include <memory>
#include "SDL.h"
#include "Keys.h"
#include "MouseButtons.h"
#include "Vector2.h"

class InputManager {

public:

	static InputManager& Instance();
	InputManager(InputManager const&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	// Like GetKey(), but only returns true if it's the first frame the butten is pressed
	bool GetKeyDown(Keys) const;
	// Returns true if the key specified is pressed
	bool GetKey(Keys) const;
	// Like GetKeyDown(), but for the first frame the button is relesed
	bool GetKeyUp(Keys) const;

	// Returns the position of the cursor relative to the window as a Vector2
	Vector2 GetMousePos() const;
	// Returns the a Vector2 for the position difference from the last frame
	Vector2 GetMouseMovement() const;
	// Like GetKeyDown(), but for the mouse-button specified
	bool GetMouseButtonDown(MouseButton mouse_button) const;
	// Like GetKey(), but for the mouse-button specified
	bool GetMouseButton(MouseButton) const;
	// Like GetKeyUp(), but for the mouse-button specified
	bool GetMouseButtonUp(MouseButton mouse_button) const;

	// Update saves the last state of the keyboard
	// and updates the current state
	void Update();

	~InputManager();

private:

	InputManager();

	static InputManager m_instance;
	static int m_num_instances;

	// Keyboeard state
	int m_num_keys;
	const Uint8* m_keys;
	std::unique_ptr<Uint8> m_prev_keys;
	// Mouse state

	/* NOTE:
		* Using a proper Vector2 implementation is overkill.
		* Using a simple struct would probably be more appropriate.
		* However this was a good oppertunity to create it for later use.
	*/

	// The cursors current position relative to the window
	Vector2 m_mouse_pos;
	Vector2 m_mouse_prev_pos;
	Uint32 m_mouse_btn_state;
	Uint32 m_mouse_prev_btn_state;

	// Update local mouse state
	void UpdateMouseState();

};

