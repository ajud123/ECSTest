#pragma once
class Vector3D
{
public:
	float x, y, z;
	Vector3D() {
		x = 0; y = 0; z = 0;
	}
	Vector3D(float x, float y, float z) {
		this->x = x; this->y = y; this->z = z;
	}
	Vector3D(Vector3D& v) {
		x = v.x; y = v.y; z = v.z;
	}
	Vector3D operator+(const Vector3D& rhs) const {
		return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z);
	}
	Vector3D operator-(const Vector3D& rhs) const {
		return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z);
	}
	Vector3D operator*(const float& rhs) const {
		return Vector3D(x * rhs, y * rhs, y * rhs);
	}
	Vector3D operator/(const float& rhs) const {
		return Vector3D(x / rhs, y / rhs, z / rhs);
	}
	Vector3D& operator+=(const Vector3D& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	Vector3D& operator-=(const Vector3D& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
};

