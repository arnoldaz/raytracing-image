#pragma once
#include "math/vector3d.hpp"

class Ray {
public:
    Ray(const Point3d& origin, const Vector3d& direction)
        : m_origin(origin), m_direction(direction) {}

    Point3d Origin() const { return m_origin; }
    Vector3d Direction() const { return m_direction; }

    Point3d AtDistance(double distance) const;

private:
    Point3d m_origin;
    Vector3d m_direction;
};
