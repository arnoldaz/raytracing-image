#include "vector3d.hpp"
#include <cmath>

Vector3d Vector3d::operator+(const Vector3d& other) const {
    return Vector3d(x + other.x, y + other.y, z + other.z);
}

Vector3d Vector3d::operator-(const Vector3d& other) const {
    return Vector3d(x - other.x, y - other.y, z - other.z);
}

Vector3d Vector3d::operator*(const Vector3d& other) const {
    return Vector3d(x * other.x, y * other.y, z * other.z);
}

Vector3d Vector3d::operator/(const Vector3d& other) const {
    return Vector3d(x / other.x, y / other.y, z / other.z);
}

Vector3d& Vector3d::operator+=(const Vector3d& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector3d& Vector3d::operator-=(const Vector3d& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vector3d& Vector3d::operator*=(const Vector3d& other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vector3d& Vector3d::operator/=(const Vector3d& other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vector3d Vector3d::operator*(double scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}

Vector3d Vector3d::operator/(double scalar) const {
    return Vector3d(x / scalar, y / scalar, z / scalar);
}

Vector3d Vector3d::CrossProduct(const Vector3d& other) const {
    return Vector3d(
        (y * other.z) - (z * other.y),
        (z * other.x) - (x * other.z),
        (x * other.y) - (y * other.x)
    );
}

double Vector3d::DotProduct(const Vector3d& other) const {
    return x * other.x + y * other.y + z * other.z;
}

double Vector3d::Length() const {
    return sqrt(LengthSquared());
}

double Vector3d::LengthSquared() const {
    double x2 = x * x;
    double y2 = y * y;
    double z2 = z * z;

    return x2 + y2 + z2;
}

Vector3d Vector3d::Normalized() const {
    double lengthSquared = LengthSquared();
    if (lengthSquared == 0)
        return Vector3d();

    double length = sqrt(lengthSquared);
    return Vector3d(x / length, y / length, z / length);
}