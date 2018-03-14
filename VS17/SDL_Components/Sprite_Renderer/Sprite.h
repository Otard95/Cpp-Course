#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <memory>
#include <SDL.h>
#include "Component.h"

class Sprite : public Component {

private:
	 std::unique_ptr<SDL_Texture> m_texture;
	 const SDL_Renderer& m_renderer;

public:
	Sprite();
	~Sprite();

	void Start() override;
	void Update() override;

};

#endif // !__SPRITE_H__


