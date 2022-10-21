#pragma once

#include "../ray.hpp"

struct IntersectionResult {
    Point3d HitPoint;
    Vector3d Normal;
    double Distance;
};

class IntersectableObject {
public:
    virtual bool Intersect(const Ray& ray, IntersectionResult& result) const = 0;
};