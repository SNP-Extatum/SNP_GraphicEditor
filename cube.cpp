#include "cube.hpp"

float Cube::cubePoints[24] = {-1.0, -1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, -1.0, 1.0, -1.0, -1.0,
							  -1.0, -1.0, 1.0,  -1.0, 1.0, 1.0,  1.0, 1.0, 1.0,  1.0, -1.0, 1.0};
GLuint Cube::cubeIndexes[36] = {0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 0, 1, 4, 1, 4, 5, 1, 2, 5, 2, 5, 6, 2, 3, 6, 3, 6, 7, 0, 3, 4, 3, 4, 7};
GLuint Cube::cubeEdgeIndexes[24] = {0, 1, 1, 2, 2, 3, 3, 0, 0, 4, 1, 5, 2, 6, 3, 7, 4, 5, 5, 6, 6, 7, 7, 4};

Cube::Cube(vec3 _centerPoint, float _edge, int _ID) : Figure(_ID) {
  centerPoint = _centerPoint;
  edge = _edge;
  createCube();
}

Cube::Cube(vec3 _centerPoint, float _edge, GLubyte _edgeRed, GLubyte _edgeGreen, GLubyte _edgeBlue, GLubyte _edgeAlpha, GLubyte _planeRed,
		   GLubyte _planeGreen, GLubyte _planeBlue, GLubyte _planeAlpha, bool _isEdgeEneble, bool _isPlaneEneble, vec3 _rotation, int _ID)
	: Figure(_ID) {
  centerPoint = _centerPoint;
  edge = _edge;
  edgeColor.setAll(_edgeRed, _edgeGreen, _edgeBlue, _edgeAlpha);
  planeColor.setAll(_planeRed, _planeGreen, _planeBlue, _planeAlpha);
  isEdgeEnable = _isEdgeEneble;
  isPlaneEnable = _isPlaneEneble;
  rotation = _rotation;
}

void Cube::createCube() {
  float diff = edge / 2.0;
  for (int i = 0; i < 8; ++i) {
	points[i * 3 + 0] = centerPoint.x + diff * cubePoints[i * 3 + 0];
	points[i * 3 + 1] = centerPoint.y + diff * cubePoints[i * 3 + 1];
	points[i * 3 + 2] = centerPoint.z + diff * cubePoints[i * 3 + 2];
  }
}

void Cube::show() {
  // rotZ += 0.0175 * 100;
  ++tick;
  rotateCube();
  glEnableClientState(GL_VERTEX_ARRAY);

  if (isPlaneEnable) {
	glVertexPointer(3, GL_FLOAT, 0, &points);
	if (selectingMode)
	  glColor4ub(IDr, IDg, IDb, 255);
	else
	  glColor4ub(planeColor.red, planeColor.green, planeColor.blue, planeColor.alpha);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &cubeIndexes);
  }
  if ((isEdgeEnable || isSelected) && !selectingMode) {
	glVertexPointer(3, GL_FLOAT, 0, &points);
	if (isSelected)
	  glColor4ub(128 + sin(tick / 10.0) * 128, 128 - sin(tick / 10.0) * 128, 128 + cos(tick / 10.0) * 128, 255);
	else
	  glColor4ub(edgeColor.red, edgeColor.green, edgeColor.blue, edgeColor.alpha);
	glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, &cubeEdgeIndexes);
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void Cube::rotateCube() {
  GLfloat A1, B1, C1, A2, B2, C2, A3, B3, C3, A4, B4, C4;
  float diff = edge / 2.0;
  for (int i = 0; i < 8; ++i) {
	A1 = cubePoints[i * 3 + 0];
	B1 = cubePoints[i * 3 + 1];
	C1 = cubePoints[i * 3 + 2];

	// вокруг Z
	A2 = A1 * cos(rotation.z) - B1 * sin(rotation.z);
	B2 = A1 * sin(rotation.z) + B1 * cos(rotation.z);
	C2 = C1;
	// вокруг X
	A3 = A2;
	B3 = B2 * cos(rotation.x) - C2 * sin(rotation.x);
	C3 = B2 * sin(rotation.x) + C2 * cos(rotation.x);
	// вокруг Y
	A4 = C3 * sin(rotation.y) + A3 * cos(rotation.y);
	B4 = B3;
	C4 = C3 * cos(rotation.y) - A3 * sin(rotation.y);

	points[i * 3 + 0] = centerPoint.x + diff * (A4);
	points[i * 3 + 1] = centerPoint.y + diff * (B4);
	points[i * 3 + 2] = centerPoint.z + diff * (C4);
  }
}

float Cube::findNearPoint(double _x, double _y, double _z) {
  float lenght, min;
  min = sqrtf(powf(points[0] - _x, 2.0) + powf(points[1] - _y, 2.0) + powf(points[2] - _z, 2.0));
  nearestPointIndex = 0;

  for (int i = 1; i < 8; ++i) {
	lenght = sqrtf(powf(points[i * 3 + 0] - _x, 2.0) + powf(points[i * 3 + 1] - _y, 2.0) + powf(points[i * 3 + 2] - _z, 2.0));
	if (lenght < min) {
	  min = lenght;
	  nearestPointIndex = i;
	}
  }
  return min;
}
