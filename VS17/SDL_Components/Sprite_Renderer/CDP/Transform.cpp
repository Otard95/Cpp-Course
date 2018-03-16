#include <iostream>
#include "Headers/Transform.h"

using namespace CDP;

Transform::Transform(std::vector<std::shared_ptr<Component>> &components, GameObject& gobj)
	: Component(components, gobj)
{}

Transform::~Transform() {
}

Vector2<double> const& Transform::Position() {
	return m_position;
}

void Transform::Translate(Vector2<double> &translation) {
	m_position.Add(translation);
}
