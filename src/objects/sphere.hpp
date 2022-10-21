#pragma once

#include "hittable.hpp"

class Sphere : IntersectableObject {
public:
    Sphere(const Point3d& center, double radius)
        : m_center(center), m_radius(radius) {}

    virtual bool Intersect(const Ray& ray, IntersectionResult& result) const override;


private:
    Point3d m_center;
    double m_radius;
};