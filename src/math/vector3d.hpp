#pragma once

class Vector3d {
public:
	Vector3d() {}

	Vector3d(double x, double y, double z)
		: m_x(x), m_y(y), m_z(z) {}

	Vector3d(double x1, double y1, double z1, double x2, double y2, double z2)
		: m_x(x2 - x1), m_y(y2 - y1), m_z(z2 - z1) {}

	double X() { return m_x; }
	double Y() { return m_y; }
	double Z() { return m_z; }

	Vector3d operator+(const Vector3d& other) const;
	Vector3d operator-(const Vector3d& other) const;
	Vector3d operator*(const Vector3d& other) const;
	Vector3d operator/(const Vector3d& other) const;

	Vector3d& operator+=(const Vector3d& other);
	Vector3d& operator-=(const Vector3d& other);
	Vector3d& operator*=(const Vector3d& other);
	Vector3d& operator/=(const Vector3d& other);

	Vector3d operator*(const double scalar) const;
	Vector3d operator/(const double scalar) const;


private:
	double m_x = 0;
	double m_y = 0;
	double m_z = 0;

};

