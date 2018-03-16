#include <iostream>
#include "Headers/Component.h"

using namespace CDP;

CDP::Component::Component(std::vector<std::shared_ptr<Component>> &components, GameObject & gobj)
	: m_sibling_components(components)
	, m_game_object(gobj)
{}

Component::~Component() {
}