#include "Vector2.h";
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float X, float Y)
{
	x = X;
	y = Y;
}

Vector2::~Vector2()
{
}


Vector2 Vector2::operator+(Vector2 other)
{
	Vector2 vector = Vector2(x + other.x, y + other.y);
	return vector;
}
Vector2 Vector2::operator-(Vector2 other)
{
	Vector2 vector = Vector2(x - other.x, y - other.y);
	return vector;
}
void Vector2::operator=(Vector2 other)
{
	x = other.x;
	y = other.y;
}