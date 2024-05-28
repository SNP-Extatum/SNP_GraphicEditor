#ifndef VECFUNCTIONS_HPP
#define VECFUNCTIONS_HPP

#define PI 3.1415926535

#include <math.h>

#include "vec2.hpp"
#include "vec3.hpp"

class vecFunctions {
 public:
  vecFunctions();

  static float clamp(float value, float min, float max);
  static double sign(double a);
  static double step(double edge, double x);

  static float length(vec2 const& v);

  static float length(vec3 const& v);
  static vec3 norm(vec3 v);
  static float dot(vec3 const& a, vec3 const& b);
  static vec3 cross(vec3 const& a, vec3 const& b);
  static vec3 abs(vec3 const& v);
  static vec3 sign(vec3 const& v);
  static vec3 step(vec3 const& edge, vec3 v);
  static vec3 reflect(vec3 rd, vec3 n);

  static vec3 rotateX(vec3 a, double angle);

  static vec3 rotateY(vec3 a, double angle);

  static vec3 rotateZ(vec3 a, double angle);
};

#endif  // VECFUNCTIONS_HPP
