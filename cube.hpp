#ifndef CUBE_HPP
#define CUBE_HPP

#include <QOpenGLFunctions>

#include "figure.hpp"
#include "vecfunctions.hpp"

class Cube : public Figure {
 public:
  Cube(vec3 _centerPoint, float _edge, int _ID);
  Cube(vec3 _centerPoint, float _edge, GLubyte _edgeRed, GLubyte _edgeGreen, GLubyte _edgeBlue, GLubyte _edgeAlpha, GLubyte _planeRed,
	   GLubyte _planeGreen, GLubyte _planeBlue, GLubyte _planeAlpha, bool _isEdgeEneble, bool _isPlaneEneble, vec3 _rotation, int _ID);
  bool isPlaneEnable = false;
  bool isEdgeEnable = true;
  void createCube();
  // void show();
  void rotateCube();

  float edge;
  float points[24];
  static float cubePoints[24];
  static GLuint cubeIndexes[36];
  static GLuint cubeEdgeIndexes[24];

  // Figure interface
 public:
  virtual float findNearPoint(double _x, double _y, double _z) override;
  virtual void show() override;
};

#endif  // CUBE_HPP
