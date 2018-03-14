#include "Sprite.h"
#include "Canvas.h"

Sprite::Sprite() : Component()
, m_texture(nullptr)
, m_renderer(Canvas::Instance().GetRenderer())
{}


Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture.get());
}

void Sprite::Start() {
	// Get renderer
}

void Sprite::Update() {
	// Draw to renderer
}
