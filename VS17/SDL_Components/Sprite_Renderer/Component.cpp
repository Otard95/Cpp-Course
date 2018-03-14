#include "Component.h"

Component::Component(std::vector<std::shared_ptr<Component>> &components)
	: m_available_components(components)
{}

Component::~Component() {
}
