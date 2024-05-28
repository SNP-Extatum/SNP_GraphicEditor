#ifndef vec3_HPP
#define vec3_HPP

#include "vec2.hpp"

struct vec3 {
 public:
  float x, y, z;
  vec3() : x(1), y(1), z(1){};
  vec3(float _value) : x(_value), y(_value), z(_value){};
  vec3(float _x, vec2 vec) : x(_x), y(vec.x), z(vec.y){};
  vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};

  void setvec3(float _x, float _y, float _z);

  vec3 operator+(vec3 other);
  vec3 operator+(double other);
  vec3 operator-(vec3 other);
  vec3 operator-(double other);
  vec3 operator*(vec3 other);
  vec3 operator*(double other);
  vec3 operator/(vec3 other);
  vec3 operator/(double other);
  vec3 operator-();
  vec3& operator+=(vec3 other);
  vec3& operator-=(vec3 other);
  vec3& operator*=(vec3 other);
  vec3& operator/=(vec3 other);
  bool operator==(vec3 other);

  // float x();
  // float y();
  // float z();

  vec2 xy();
  vec2 xz();
  vec2 yz();
  vec2 xx();
  vec2 yy();
  vec2 zz();
  vec2 yx();
  vec2 zx();
  vec2 zy();

  vec3 xxx() { return vec3(); };
  vec3 yyy() { return vec3(); };
  vec3 zzz() { return vec3(); };
  vec3 xxy() { return vec3(x, x, y); };
  vec3 xxz() { return vec3(x, x, z); };
  vec3 xyz() { return vec3(x, y, z); };
  vec3 xyy() { return vec3(x, y, y); };
  vec3 xzz() { return vec3(x, z, z); };
  vec3 xyx() { return vec3(x, y, x); };
  vec3 xzx() { return vec3(x, z, x); };
  vec3 xzy() { return vec3(x, z, y); };
  vec3 yxy() { return vec3(y, x, y); };
  vec3 yxz() { return vec3(y, x, z); };
  vec3 yyz() { return vec3(y, y, z); };
  vec3 yxx() { return vec3(y, x, x); };
  vec3 yzz() { return vec3(y, z, z); };
  vec3 yyx() { return vec3(y, y, x); };
  vec3 yzx() { return vec3(y, z, x); };
  vec3 yzy() { return vec3(y, z, y); };
  vec3 zxy() { return vec3(z, x, y); };
  vec3 zxz() { return vec3(z, x, z); };
  vec3 zyz() { return vec3(z, y, z); };
  vec3 zxx() { return vec3(z, x, x); };
  vec3 zyy() { return vec3(z, y, y); };
  vec3 zyx() { return vec3(z, y, x); };
  vec3 zzx() { return vec3(z, z, x); };
  vec3 zzy() { return vec3(z, z, y); };
};

#endif  // vec3_HPP
