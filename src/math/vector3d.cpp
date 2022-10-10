#include "vector3d.hpp"
#include <cmath>

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

Vector3d Vector3d::operator*(double scalar) const {
    return Vector3d(m_x * scalar, m_y * scalar, m_z * scalar);
}

Vector3d Vector3d::operator/(double scalar) const {
    return Vector3d(m_x / scalar, m_y / scalar, m_z / scalar);
}

Vector3d Vector3d::CrossProduct(const Vector3d& other) const {
    return Vector3d(
        (m_y * other.m_z) - (m_z * other.m_y),
        (m_z * other.m_x) - (m_x * other.m_z),
        (m_x * other.m_y) - (m_y * other.m_x)
    );
}

double Vector3d::DotProduct(const Vector3d& other) const {
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
}

double Vector3d::Length() const {
    return sqrt(LengthSquared());
}

double Vector3d::LengthSquared() const {
    double x2 = m_x * m_x;
    double y2 = m_y * m_y;
    double z2 = m_z * m_z;

    return x2 + y2 + z2;
}
