#pragma once
class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float X, float Y);
	~Vector2();
	void Reset();
	Vector2 operator+(Vector2 other);
	Vector2 operator-(Vector2 other);
	void operator=(Vector2 other);
	void operator+=(Vector2 other);
	Vector2 operator-=(Vector2);
	Vector2 operator*(Vector2);
	Vector2 operator*(float);
	Vector2 operator/(Vector2);
	Vector2 operator*=(Vector2);
	Vector2 operator/=(Vector2);
	bool operator==(Vector2);
	bool operator!=(Vector2);
private:

};
