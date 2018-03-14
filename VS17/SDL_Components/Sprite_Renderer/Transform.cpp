#include "Transform.h"

Transform::Transform(std::vector<std::shared_ptr<Component>> &components)
	: Component(components)
{
}

Transform::~Transform() {
}

Vector2<double> const & Transform::Position() {
	return m_position;
}
