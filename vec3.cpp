#include "vec3.hpp"

void vec3::setvec3(float _x, float _y, float _z) {
  x = _x;
  y = _y;
  z = _z;
}

vec3 vec3::operator+(double other) { return vec3(x + other, y + other, z + other); }

vec3 vec3::operator*(double other) { return vec3(x * other, y * other, z * other); }

vec3 vec3::operator/(double other) { return vec3(x / other, y / other, z / other); }

vec3 vec3::operator-() { return vec3(-x, -y, -z); }

vec3& vec3::operator+=(vec3 other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return *this;
}

vec3& vec3::operator-=(vec3 other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return *this;
}

vec3& vec3::operator*=(vec3 other) {
  x *= other.x;
  y *= other.y;
  z *= other.z;
  return *this;
}

vec3& vec3::operator/=(vec3 other) {
  x /= other.x;
  y /= other.y;
  z /= other.z;
  return *this;
}

vec2 vec3::xy() { return vec2(x, y); }

vec2 vec3::xz() { return vec2(x, z); }

vec2 vec3::yz() { return vec2(y, z); }

vec2 vec3::xx() { return vec2(x); }

vec2 vec3::yy() { return vec2(y); }

vec2 vec3::zz() { return vec2(z); }

vec2 vec3::yx() { return vec2(y, x); }

vec2 vec3::zx() { return vec2(z, x); }

vec2 vec3::zy() { return vec2(z, y); }

vec3 vec3::operator/(vec3 other) { return vec3(x / other.x, y / other.y, z / other.z); }

vec3 vec3::operator*(vec3 other) { return vec3(x * other.x, y * other.y, z * other.z); }

vec3 vec3::operator-(double other) { return vec3(x - other, y - other, z - other); }

vec3 vec3::operator-(vec3 other) { return vec3(x - other.x, y - other.y, z - other.z); }

vec3 vec3::operator+(vec3 other) { return vec3(x + other.x, y + other.y, z + other.z); }

bool vec3::operator==(vec3 other) {
  if (x == other.x && y == other.y && z == other.z) return true;
  return false;
}
