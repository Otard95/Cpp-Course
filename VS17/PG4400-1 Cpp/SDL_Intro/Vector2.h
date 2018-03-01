#pragma once
#include <cinttypes>

class Vector2 {

	double m_x;
	double m_y;

public:

	Vector2();
	Vector2(double _x, double _y);
	Vector2(double const coords[2]);
	Vector2(Vector2 const &v) = default;

	~Vector2() = default;

	/*
	 * ## Instance Methods
	*/

	// Get this vectors components as a const double array.
	const double* ToArray();
	// Get the x component
	double x();
	// Get the y component
	double y();
	// Sets the x and y component of the vector
	void SetCoords(double _x, double _y);

	// Get the length of this vector
	double Length();
	// Normalize this vector
	void Normalize();
	// Get a nomalized copy of this vector.
	Vector2 normalized();

	// Functions for Vector's
	void Add (Vector2 const &v);
	// Functions for subtracting Vector's
	void Sub (Vector2 const &v);
	// Scale this vector by a scalar
	void Mult (double const scalar);
	// Scale this vector by a scalar.
	void Div (double const scalar);

	/*
	* ## Static Methods
	*/

	// Get the dot product of two vectors
	static double Dot(Vector2 const & lhs, Vector2 const & rhs);
	// Adds the vectors and retern's as a new one.
	static Vector2 Add (Vector2 const &lhs, Vector2 const &rhs);
	// Subtracts the vectors and retern's as a new one.
	static Vector2 Sub (Vector2 const &lhs, Vector2 const &rhs);
	// Get a new vector scaled from another.
	static Vector2 Mult (double const scalar, Vector2 const &v);
	// Get a new vector scaled from another.
	static Vector2 Div (double const scalar, Vector2 const &v);

	/*
	 * ## Operator overloads
	*/

	// Adds the right-hand vector onto itself.
	Vector2& operator += (const Vector2 &rhs);
	// Adds the left and right-hand vector and returns a new one.
	Vector2  operator  + (const Vector2 &rhs) const;
	// Subtracts the right-hand vector from itself.
	Vector2& operator -= (const Vector2 &rhs);
	// Returns a new vector that is the left subtracted by the right-hand vector.
	Vector2  operator  - (const Vector2 &rhs) const;
	// Multiply this vector with the right-hand scalar.
	Vector2& operator *= (double scalar);
	// Multiply the left-hand vector with the right-hand scalar, returns new vector.
	Vector2  operator  * (double scalar) const;
	friend Vector2 operator *(double scalar, const Vector2 &v);
	// Devide this vector with the right-hand scalar.
	Vector2& operator /= (double scalar);
	// Devide the left-hand vector with the right-hand scalar, returns new vector.
	Vector2  operator  / (double scalar) const;
	friend Vector2 operator /(double scalar, const Vector2 &v);

	// Gets the dot product of the two vectors.
	double operator *(const Vector2 &rhs) const;

};

