#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <vector>
#include <memory>
#include "CDP_fwd.h"

namespace CDP {

	class GameObject {

	private:
		std::vector <std::shared_ptr <Component>> m_components;

	public:
		GameObject();
		~GameObject();

	};

}

#endif // !__GAMEOBJECT_H__


