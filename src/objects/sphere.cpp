#include "sphere.hpp"
#include <cmath>

bool Sphere::Intersect(const Ray& ray, IntersectionResult& result) const {
    // Calculated using https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
    Vector3d oc = ray.Origin() - m_center;
    double a = ray.Direction().DotProduct(ray.Direction());
    double b = 2.0 * oc.DotProduct(ray.Direction());
    double c = oc.DotProduct(oc) - m_radius * m_radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        result.Distance = (-b - sqrt(discriminant)) / (2.0 * a);
        result.HitPoint = ray.AtDistance(result.Distance);
        result.Normal = (result.HitPoint - m_center) / m_radius;
        return true;
    }
    else {
        result.Distance = -1;
        return false;
    }
}