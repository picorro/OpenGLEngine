#pragma once
class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float, float);
	~Vector2();
	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);
	void operator=(Vector2);
	Vector2 operator+=(Vector2);
	Vector2 operator-=(Vector2);
	Vector2 operator*(Vector2);
	Vector2 operator/(Vector2);
	Vector2 operator*=(Vector2);
	Vector2 operator/=(Vector2);
private:

};
