#include "Sprite.h"
#include "Canvas.h"

Sprite::Sprite(std::vector<std::shared_ptr<Component>> &components)
	: Component(components)
	, m_texture(nullptr)
	, m_renderer(Canvas::Instance().GetRenderer())
{}


Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

void Sprite::Start() {
	// Get renderer
}

void Sprite::Update() {

	SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_coords);

}
