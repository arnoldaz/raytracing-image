#include "ray.hpp"

Point3d Ray::AtDistance(double distance) const {
    return m_origin + m_direction * distance;
}