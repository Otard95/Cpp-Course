#include "Sprite.h"



Sprite::Sprite() : Component() {
}


Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture.get());
}

void Sprite::Start() {
	// Get renderer
}

void Sprite::Update() {
	// Draw to renderer
}
