#include "vector3d.hpp"

Vector3d Vector3d::operator+(const Vector3d& other) const {
	return Vector3d(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
}

Vector3d Vector3d::operator-(const Vector3d& other) const {
	return Vector3d(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
}

Vector3d Vector3d::operator*(const Vector3d& other) const {
	return Vector3d(m_x * other.m_x, m_y * other.m_y, m_z * other.m_z);
}

Vector3d Vector3d::operator/(const Vector3d& other) const {
	return Vector3d(m_x / other.m_x, m_y / other.m_y, m_z / other.m_z);
}

Vector3d& Vector3d::operator+=(const Vector3d& other) {
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	return *this;
}

Vector3d& Vector3d::operator-=(const Vector3d& other) {
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	return *this;
}

Vector3d& Vector3d::operator*=(const Vector3d& other) {
	m_x *= other.m_x;
	m_y *= other.m_y;
	m_z *= other.m_z;
	return *this;
}

Vector3d& Vector3d::operator/=(const Vector3d& other) {
	m_x /= other.m_x;
	m_y /= other.m_y;
	m_z /= other.m_z;
	return *this;
}

Vector3d Vector3d::operator*(const double scalar) const {
	return Vector3d(m_x * scalar, m_y * scalar, m_z * scalar);
}

Vector3d Vector3d::operator/(const double scalar) const {
	return Vector3d(m_x / scalar, m_y / scalar, m_z / scalar);
}
