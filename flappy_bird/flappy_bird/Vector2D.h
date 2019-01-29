#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
	float mX;
	float mY;
public:
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();

	Vector2D operator=(Vector2D& other);

	Vector2D operator+(Vector2D& other);
	Vector2D operator-(Vector2D& other);
	Vector2D operator*(Vector2D& other);
	Vector2D operator/(Vector2D& other);

	Vector2D operator*(float factor);
	Vector2D operator/(float factor);

	Vector2D operator+=(Vector2D& other);
	Vector2D operator-=(Vector2D& other);
	Vector2D operator*=(Vector2D& other);
	Vector2D operator/=(Vector2D& other);

	Vector2D operator*=(float factor);
	Vector2D operator/=(float factor);

	bool operator==(Vector2D& other);
	bool operator<(Vector2D& other);
	bool operator<=(Vector2D& other);
	bool operator>(Vector2D& other);
	bool operator>=(Vector2D& other);

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();
};

#endif