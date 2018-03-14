#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <memory>
#include <SDL.h>
#include "Component.h"

class Sprite : public Component {

private:
	 SDL_Texture* m_texture;
	 SDL_Renderer* const m_renderer;
	 SDL_Rect m_coords;

public:
	Sprite(std::vector<std::shared_ptr<Component>> &components);
	~Sprite();

	void Start() override;
	void Update() override;

};

#endif // !__SPRITE_H__


