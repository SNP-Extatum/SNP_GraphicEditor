#include "vec2.hpp"

vec2::vec2() {}

void vec2::setvec2(float _x, float _y) {
  x = _x;
  y = _y;
}

vec2 vec2::operator+(const double& other) { return vec2(x + other, y + other); }

vec2 vec2::operator-(const double& other) { return vec2(x - other, y - other); }

vec2 vec2::operator*(const double& other) { return vec2(x * other, y * other); }

vec2 vec2::operator/(const double& other) { return vec2(x / other, y / other); }

vec2& vec2::operator+=(const vec2& other) {
  x += other.x;
  y += other.y;
  return *this;
}

vec2& vec2::operator-=(const vec2& other) {
  x -= other.x;
  y -= other.y;
  return *this;
}

vec2& vec2::operator*=(const vec2& other) {
  x *= other.x;
  y *= other.y;
  return *this;
}

vec2& vec2::operator/=(const vec2& other) {
  x /= other.x;
  y /= other.y;
  return *this;
}

vec2 vec2::xy() { return vec2(x, y); }

vec2 vec2::yx() { return vec2(y, x); }

vec2 vec2::xx() { return vec2(x); }

vec2 vec2::yy() { return vec2(y); }

vec2 vec2::operator/(const vec2& other) { return vec2(x / other.x, y / other.y); }

vec2 vec2::operator*(const vec2& other) { return vec2(x * other.x, y * other.y); }

vec2 vec2::operator-(const vec2& other) { return vec2(x - other.x, y - other.y); }

vec2 vec2::operator+(const vec2& other) { return vec2(x + other.x, y + other.y); }
