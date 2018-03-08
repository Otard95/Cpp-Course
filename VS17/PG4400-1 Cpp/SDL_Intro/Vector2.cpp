#include "Vector2.h"
#include <mutex>
#include <valarray>

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(double _x, double _y) : x(_x), y(_y) {}

Vector2::Vector2(const double coords[2]) : x(coords[0]), y(coords[1]) {}

/*
* ## Instance Methods
*/

const double* Vector2::ToArray() {
	return &x;
}

void Vector2::SetCoords(double _x, double _y) {
	x = _x;
	y = _y;
}

double Vector2::Length() {
	return sqrt((x*x) + (y*y));
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
	x += v.x;
	y += v.y;
}

void Vector2::Sub(Vector2 const &v) {
	x -= v.x;
	y -= v.y;
}

void Vector2::Mult(double const scalar) {
	x *= scalar;
	y *= scalar;
}

void Vector2::Div(double const scalar) {
	x /= scalar;
	y /= scalar;
}

/*
* ## Static Methods
*/

double Vector2::Dot(Vector2 const &lhs, Vector2 const &rhs) {
	return ((lhs.x * rhs.x) + (lhs.y * rhs.y));
}

Vector2 Vector2::Add(Vector2 const &lhs, Vector2 const &rhs) {
	Vector2 result (lhs.x + rhs.x, lhs.y + rhs.y);
	return  result;
}

Vector2 Vector2::Sub(Vector2 const &lhs, Vector2 const &rhs) {
	Vector2 result (lhs.x - rhs.x, lhs.y - rhs.y);
	return  result;
}

Vector2 Vector2::Mult(double const scalar, Vector2 const &v) {
	Vector2 result (v.x * scalar, v.y * scalar);
	return  result;
}

Vector2 Vector2::Div(double const scalar, Vector2 const &v) {
	Vector2 result (v.x / scalar, v.y / scalar);
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

bool Vector2::operator==(const Vector2 & rhs) {
	return x == rhs.x && y == rhs.y;
}

bool Vector2::operator!=(const Vector2 & rhs) {
	return !(*this == rhs);
}
