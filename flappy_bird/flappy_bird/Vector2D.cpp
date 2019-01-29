#include "Vector2D.h"


Vector2D::Vector2D()
{
	this->mX = 0;
	this->mY = 0;
}


Vector2D::~Vector2D()
{
}


Vector2D::Vector2D(float x, float y)
{
	this->mX = x;
	this->mY = y;
}


Vector2D Vector2D::operator=(Vector2D& other)
{
	this->mX = other.mX;
	this->mY = other.mY;
	return *this;
}


Vector2D Vector2D::operator+(Vector2D& other)
{
	return Vector2D(this->mX + other.mX, this->mY + other.mY);
}


Vector2D Vector2D::operator-(Vector2D& other)
{
	return Vector2D(this->mX - other.mX, this->mY - other.mY);
}


Vector2D Vector2D::operator*(Vector2D& other)
{
	return Vector2D((this->mX * other.mX) - (this->mY * other.mY), (this->mY * other.mX) + (this->mX * other.mY));
}


Vector2D Vector2D::operator/(Vector2D& other)
{
	other.GetX()*other.GetX() + other.GetY()*other.GetY();
	return Vector2D(this->GetX()*other.GetX() + this->GetY()*other.GetY(),
		this->GetY()*other.GetX() - this->GetX()*other.GetY());
}


Vector2D Vector2D::operator*(float factor)
{
	return Vector2D(this->mX * factor, this->mY * factor);
}


Vector2D Vector2D::operator/(float factor)
{
	return Vector2D(this->mX / factor, this->mY / factor);
}


Vector2D Vector2D::operator+=(Vector2D& other)
{
	this->mX += other.mX;
	this->mY += other.mY;
	return *this;
}


Vector2D Vector2D::operator-=(Vector2D& other)
{
	this->mX -= other.mX;
	this->mY -= other.mY;
	return *this;
}


Vector2D Vector2D::operator*=(Vector2D& other)
{
	this->mX *= other.mX;
	this->mY *= other.mY;
	return *this;
}


Vector2D Vector2D::operator/=(Vector2D& other)
{
	return (*this = *this / other);
}


Vector2D Vector2D::operator*=(float factor)
{
	this->mX *= factor;
	this->mY *= factor;
	return *this;
}


Vector2D Vector2D::operator/=(float factor)
{
	this->mX /= factor;
	this->mY /= factor;
	return *this;
}


bool Vector2D::operator==(Vector2D& other)
{
	return (this->mX == other.mX) && (this->mY == other.mY);
}


bool Vector2D::operator<(Vector2D& other)
{
	return (this->mX < other.mX) && (this->mY < other.mY);
}


bool Vector2D::operator<=(Vector2D& other)
{
	return (this->mX <= other.mX) && (this->mY <= other.mY);
}


bool Vector2D::operator>(Vector2D& other)
{
	return (this->mX > other.mX) && (this->mY > other.mY);
}


bool Vector2D::operator>=(Vector2D& other)
{
	return (this->mX >= other.mX) && (this->mY >= other.mY);
}


void Vector2D::SetX(float x)
{
	mX = x;
}


void Vector2D::SetY(float y)
{
	mY = y;
}


float Vector2D::GetX()
{
	return this->mX;
}


float Vector2D::GetY()
{
	return this->mY;
}