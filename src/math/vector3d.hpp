#pragma once

class Vector3d {
public:
    Vector3d(double x = 0, double y = 0, double z = 0)
        : x(x), y(y), z(z) {}

    Vector3d(double x1, double y1, double z1, double x2, double y2, double z2)
        : x(x2 - x1), y(y2 - y1), z(z2 - z1) {}

    double X() const { return x; }
    double Y() const { return y; }
    double Z() const { return z; }

    Vector3d operator+(const Vector3d& other) const;
    Vector3d operator-(const Vector3d& other) const;
    Vector3d operator*(const Vector3d& other) const;
    Vector3d operator/(const Vector3d& other) const;

    Vector3d& operator+=(const Vector3d& other);
    Vector3d& operator-=(const Vector3d& other);
    Vector3d& operator*=(const Vector3d& other);
    Vector3d& operator/=(const Vector3d& other);

    Vector3d operator+(double scalar) const = delete;
    Vector3d operator-(double scalar) const = delete;
    Vector3d operator*(double scalar) const;
    Vector3d operator/(double scalar) const;

    friend Vector3d operator*(double scalar, const Vector3d& vector) { return vector * scalar; }
    friend Vector3d operator/(double scalar, const Vector3d& vector) { return vector / scalar; }

    Vector3d CrossProduct(const Vector3d& other) const;
    double DotProduct(const Vector3d& other) const;

    double Length() const;
    double LengthSquared() const;

    Vector3d Normalized() const;

protected:
    double x;
    double y;
    double z;
};

using Point3d = Vector3d;

class ColorRGB : public Vector3d {
public:
    ColorRGB(double r = 0, double g = 0, double b = 0)
        : Vector3d(r, g, b) {}

    double X() = delete;
    double Y() = delete;
    double Z() = delete;

    double R() const { return x; }
    double G() const { return y; }
    double B() const { return z; }
};