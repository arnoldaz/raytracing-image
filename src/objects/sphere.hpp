#pragma once

#include "hittable.hpp"

class Sphere : Hittable {
public:
	virtual bool Hit(const Ray& ray, double minDistance, double maxDistance, HitResult& result) const override;
};