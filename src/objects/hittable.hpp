#pragma once

#include "../ray.hpp"

struct HitResult {
	Point3d HitPoint;
	Vector3d Normal;
	double Distance;
};

class Hittable {
public:
	virtual bool Hit(const Ray& ray, double minDistance, double maxDistance, HitResult& result) const = 0;
};