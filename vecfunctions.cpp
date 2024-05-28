#include "vecfunctions.hpp"

float vecFunctions::clamp(float value, float min, float max) { return fmax(fmin(value, max), min); }

double vecFunctions::sign(double a) { return (0 < a) - (a < 0); }

double vecFunctions::step(double edge, double x) { return x > edge; }

float vecFunctions::length(const vec2& v) { return sqrt(v.x * v.x + v.y * v.y); }

float vecFunctions::length(const vec3& v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

vec3 vecFunctions::norm(vec3 v) { return v / length(v); }

float vecFunctions::dot(const vec3& a, const vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

vec3 vecFunctions::cross(const vec3& a, const vec3& b) { return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

vec3 vecFunctions::abs(const vec3& v) { return vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }

vec3 vecFunctions::sign(const vec3& v) { return vec3(sign(v.x), sign(v.y), sign(v.z)); }

vec3 vecFunctions::step(const vec3& edge, vec3 v) { return vec3(step(edge.x, v.x), step(edge.y, v.y), step(edge.z, v.z)); }

vec3 vecFunctions::reflect(vec3 rd, vec3 n) { return rd - n * (2 * dot(n, rd)); }

vec3 vecFunctions::rotateX(vec3 a, double angle) {
  vec3 b = a;
  b.z = a.z * cos(angle) - a.y * sin(angle);
  b.y = a.z * sin(angle) + a.y * cos(angle);
  return b;
}

vec3 vecFunctions::rotateY(vec3 a, double angle) {
  vec3 b = a;
  b.x = a.x * cos(angle) - a.z * sin(angle);
  b.z = a.x * sin(angle) + a.z * cos(angle);
  return b;
}

vec3 vecFunctions::rotateZ(vec3 a, double angle) {
  vec3 b = a;
  b.x = a.x * cos(angle) - a.y * sin(angle);
  b.y = a.x * sin(angle) + a.y * cos(angle);
  return b;
}
