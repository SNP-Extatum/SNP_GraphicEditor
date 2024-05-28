#ifndef vec2_HPP
#define vec2_HPP

struct vec2 {
 public:
  float x, y;
  vec2();
  vec2(float value) : x(value), y(value) {}
  vec2(float _x, float _y) : x(_x), y(_y) {}

  void setvec2(float _x, float _y);

  vec2 operator+(vec2 const& other);
  vec2 operator+(double const& other);
  vec2 operator-(vec2 const& other);
  vec2 operator-(double const& other);
  vec2 operator*(vec2 const& other);
  vec2 operator*(double const& other);
  vec2 operator/(vec2 const& other);
  vec2 operator/(double const& other);

  vec2& operator+=(vec2 const& other);
  vec2& operator-=(vec2 const& other);
  vec2& operator*=(vec2 const& other);
  vec2& operator/=(vec2 const& other);

  vec2 xy();
  vec2 yx();
  vec2 xx();
  vec2 yy();
};

#endif  // vec2_HPP
