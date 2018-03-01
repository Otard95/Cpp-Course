#include "Vector2.h"
#include <mutex>
#include <valarray>

Vector2::Vector2() : m_x(0), m_y(0) {}

Vector2::Vector2(double _x, double _y) : m_x(_x), m_y(_y) {}

Vector2::Vector2(const double coords[2]) : m_x(coords[0]), m_y(coords[1]) {}

/*
* ## Instance Methods
*/

const double* Vector2::ToArray() {
	return &m_x;
}

double Vector2::x() {
	return m_x;
}

double Vector2::y() {
	return m_y;
}

void Vector2::SetCoords(double _x, double _y) {
	m_x = _x;
	m_y = _y;
}

double Vector2::Length() {
	return sqrt((m_x*m_x) + (m_y*m_y));
}

void Vector2::Normalize() {
	double const len = Length();
	Div(len);
}

Vector2 Vector2::normalized() {
	auto result = *this;
	result.Normalize();
	return result;
}

void Vector2::Add(Vector2 const &v) {
	m_x += v.m_x;
	m_y += v.m_y;
}

void Vector2::Sub(Vector2 const &v) {
	m_x -= v.m_x;
	m_y -= v.m_y;
}

void Vector2::Mult(double const scalar) {
	m_x *= scalar;
	m_y *= scalar;
}

void Vector2::Div(double const scalar) {
	m_x /= scalar;
	m_y /= scalar;
}

/*
* ## Static Methods
*/

double Vector2::Dot(Vector2 const &lhs, Vector2 const &rhs) {
	return ((lhs.m_x * rhs.m_x) + (lhs.m_y * rhs.m_y));
}

Vector2 Vector2::Add(Vector2 const &lhs, Vector2 const &rhs) {
	Vector2 result (lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y);
	return  result;
}

Vector2 Vector2::Sub(Vector2 const &lhs, Vector2 const &rhs) {
	Vector2 result (lhs.m_x - rhs.m_x, lhs.m_y - rhs.m_y);
	return  result;
}

Vector2 Vector2::Mult(double const scalar, Vector2 const &v) {
	Vector2 result (v.m_x * scalar, v.m_y * scalar);
	return  result;
}

Vector2 Vector2::Div(double const scalar, Vector2 const &v) {
	Vector2 result (v.m_x / scalar, v.m_y / scalar);
	return  result;
}

/*
* ## Operator overloads
*/

Vector2& Vector2::operator+=(const Vector2 &rhs) {
	Add(rhs);
	return *this;
}

Vector2 Vector2::operator+(const Vector2 &rhs) const {
	return Vector2::Add(*this, rhs);
}

Vector2& Vector2::operator-=(const Vector2 &rhs) {
	Sub(rhs);
	return *this;
}

Vector2 Vector2::operator-(const Vector2 &rhs) const {
	return Vector2::Sub(*this, rhs);
}

Vector2& Vector2::operator*=(const double scalar) {
	Mult(scalar);
	return *this;
}

Vector2 Vector2::operator*(const double scalar) const {
	return Vector2::Mult(scalar, *this);
}

Vector2 operator*(const double scalar, const Vector2 &v) {
	return Vector2::Mult(scalar, v);
}

Vector2& Vector2::operator/=(const double scalar) {
	Div(scalar);
	return *this;
}

Vector2 Vector2::operator/(const double scalar) const {
	return Vector2::Div(scalar, *this);
}

Vector2 operator/(const double scalar, const Vector2 &v) {
	return Vector2::Div(scalar, v);
}

double Vector2::operator*(const Vector2 &rhs) const {
	return Vector2::Dot(*this, rhs);
}
