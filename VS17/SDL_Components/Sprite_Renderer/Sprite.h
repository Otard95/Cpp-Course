#ifndef __SPRITE_COMPONENT_H__
#define __SPRITE_COMPONENT_H__

#include <memory>
#include <SDL.h>
#include "Component.h"
#include "Transform.h"

class Sprite : public Component {

private:
	 SDL_Texture* m_texture;
	 SDL_Renderer* const m_renderer;
	 SDL_Rect m_coords;

	 std::shared_ptr<Transform> m_transform;

public:
	Sprite(std::vector<std::shared_ptr<Component>> &components);
	~Sprite();

	void Start() override;
	void Update() override;

};

#endif // !__SPRITE_COMPONENT_H__


