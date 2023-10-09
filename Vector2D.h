#pragma once
class Vector2D
{
public:
	float x, y;
	Vector2D() {
		x = 0; y = 0;
	}
	Vector2D(float x, float y) {
		this->x = x; this->y = y;
	}
	Vector2D(Vector2D &v) {
		x = v.x; y = v.y;
	}
	Vector2D operator+(const Vector2D& rhs) const {
		return Vector2D(x + rhs.x, y + rhs.y);
	}
	Vector2D operator-(const Vector2D& rhs) const {
		return Vector2D(x - rhs.x, y - rhs.y);
	}
	Vector2D operator*(const float& rhs) const {
		return Vector2D(x * rhs, y * rhs);
	}
	Vector2D operator/(const float& rhs) const {
		return Vector2D(x / rhs, y / rhs);
	}
	Vector2D& operator+=(const Vector2D& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}
	Vector2D& operator-=(const Vector2D& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}
};

