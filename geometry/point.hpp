#include <bits/stdc++.h>

struct Point {
    using C = std::complex<double>;
    Point() : z() {}
    Point(double _x, double _y) : z(_x, _y) {}
    Point(C _z) : z(_z) {}

    double x() const {
        return z.real();
    }
    double y() const {
        return z.imag();
    }
    C c() const {
        return z;
    }

    Point operator+(const Point &pt) {
        return Point(z + pt.c());
    }
    Point operator-(const Point &pt) {
        return Point(z - pt.c());
    }
    Point operator*(const Point &pt) {
        return Point(z * pt.c());
    }
    Point operator/(const Point &pt) {
        return Point(z / pt.c());
    }

    Point &operator=(const Point &pt) {
        z = pt.c();
        return *this;
    }
    Point &operator+=(const Point &pt) {
        *this = *this + pt;
        return *this;
    }
    Point &operator-=(const Point &pt) {
        *this = *this - pt;
        return *this;
    }
    Point &operator*=(const Point &pt) {
        *this = *this * pt;
        return *this;
    }
    Point &operator/=(const Point &pt) {
        *this = *this / pt;
        return *this;
    }

    double dot(const Point &pt) {
        return x() * pt.x() + y() * pt.y();
    }
    double cross(const Point &pt) {
        return x() * pt.y() - y() * pt.x();
    }
    
    private:
    C z;
};