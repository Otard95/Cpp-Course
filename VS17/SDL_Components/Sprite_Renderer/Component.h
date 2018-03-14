#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include <vector>
#include <memory>
#include <algorithm>

class Component {

private:
	std::vector<std::shared_ptr<Component>> &m_available_components;

public:
	Component(std::vector<std::shared_ptr<Component>> &components);
	~Component();

	template <class T>
	std::shared_ptr<T> GetComponent() {

		std::shared_ptr<T> comp = nullptr;
		std::for_each(m_available_components.begin(),
									m_available_components.end(),
									[comp] (std::shared_ptr<Component> c) {
			
			if (!comp) comp = std::dynamic_pointer_cast<T>(c);

		});

		return comp;

	}

	virtual void Start() {}
	virtual void Update() {}

};

#endif // !__COMPONENT_H__


