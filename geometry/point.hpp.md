---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/point.hpp\"\n#include <bits/stdc++.h>\n\nstruct\
    \ Point {\n    using C = std::complex<double>;\n    Point() : z() {}\n    Point(double\
    \ _x, double _y) : z(_x, _y) {}\n    Point(C _z) : z(_z) {}\n\n    double x()\
    \ const {\n        return z.real();\n    }\n    double y() const {\n        return\
    \ z.imag();\n    }\n    C c() const {\n        return z;\n    }\n\n    Point operator+(const\
    \ Point &pt) {\n        return Point(z + pt.c());\n    }\n    Point operator-(const\
    \ Point &pt) {\n        return Point(z - pt.c());\n    }\n    Point operator*(const\
    \ Point &pt) {\n        return Point(z * pt.c());\n    }\n    Point operator/(const\
    \ Point &pt) {\n        return Point(z / pt.c());\n    }\n\n    Point &operator=(const\
    \ Point &pt) {\n        z = pt.c();\n        return *this;\n    }\n    Point &operator+=(const\
    \ Point &pt) {\n        *this = *this + pt;\n        return *this;\n    }\n  \
    \  Point &operator-=(const Point &pt) {\n        *this = *this - pt;\n       \
    \ return *this;\n    }\n    Point &operator*=(const Point &pt) {\n        *this\
    \ = *this * pt;\n        return *this;\n    }\n    Point &operator/=(const Point\
    \ &pt) {\n        *this = *this / pt;\n        return *this;\n    }\n\n    double\
    \ dot(const Point &pt) {\n        return x() * pt.x() + y() * pt.y();\n    }\n\
    \    double cross(const Point &pt) {\n        return x() * pt.y() - y() * pt.x();\n\
    \    }\n    \n    private:\n    C z;\n};\n"
  code: "#include <bits/stdc++.h>\n\nstruct Point {\n    using C = std::complex<double>;\n\
    \    Point() : z() {}\n    Point(double _x, double _y) : z(_x, _y) {}\n    Point(C\
    \ _z) : z(_z) {}\n\n    double x() const {\n        return z.real();\n    }\n\
    \    double y() const {\n        return z.imag();\n    }\n    C c() const {\n\
    \        return z;\n    }\n\n    Point operator+(const Point &pt) {\n        return\
    \ Point(z + pt.c());\n    }\n    Point operator-(const Point &pt) {\n        return\
    \ Point(z - pt.c());\n    }\n    Point operator*(const Point &pt) {\n        return\
    \ Point(z * pt.c());\n    }\n    Point operator/(const Point &pt) {\n        return\
    \ Point(z / pt.c());\n    }\n\n    Point &operator=(const Point &pt) {\n     \
    \   z = pt.c();\n        return *this;\n    }\n    Point &operator+=(const Point\
    \ &pt) {\n        *this = *this + pt;\n        return *this;\n    }\n    Point\
    \ &operator-=(const Point &pt) {\n        *this = *this - pt;\n        return\
    \ *this;\n    }\n    Point &operator*=(const Point &pt) {\n        *this = *this\
    \ * pt;\n        return *this;\n    }\n    Point &operator/=(const Point &pt)\
    \ {\n        *this = *this / pt;\n        return *this;\n    }\n\n    double dot(const\
    \ Point &pt) {\n        return x() * pt.x() + y() * pt.y();\n    }\n    double\
    \ cross(const Point &pt) {\n        return x() * pt.y() - y() * pt.x();\n    }\n\
    \    \n    private:\n    C z;\n};"
  dependsOn: []
  isVerificationFile: false
  path: geometry/point.hpp
  requiredBy: []
  timestamp: '2024-04-20 19:50:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/point.hpp
layout: document
redirect_from:
- /library/geometry/point.hpp
- /library/geometry/point.hpp.html
title: geometry/point.hpp
---
