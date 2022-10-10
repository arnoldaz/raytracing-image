#pragma once

class Vector3d {
public:
    Vector3d(double x = 0, double y = 0, double z = 0)
        : m_x(x), m_y(y), m_z(z) {}

    Vector3d(double x1, double y1, double z1, double x2, double y2, double z2)
        : m_x(x2 - x1), m_y(y2 - y1), m_z(z2 - z1) {}

    double X() const { return m_x; }
    double Y() const { return m_y; }
    double Z() const { return m_z; }

    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d operator*(const Vector3d& other) const;
    Vector3d operator/(const Vector3d& other) const;

    Vector3d& operator+=(const Vector3d& other);
    Vector3d& operator-=(const Vector3d& other);
    Vector3d& operator*=(const Vector3d& other);
    Vector3d& operator/=(const Vector3d& other);

    Vector3d operator*(double scalar) const;
    Vector3d operator/(double scalar) const;

    Vector3d CrossProduct(const Vector3d& other) const;
    double DotProduct(const Vector3d& other) const;

    double Length() const;
    double LengthSquared() const;

private:
    double m_x;
    double m_y;
    double m_z;
};

using Point3d = Vector3d;
