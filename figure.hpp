#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <QOpenGLFunctions>
#include <vecfunctions.hpp>

struct Color {
  Color(){};
  Color(GLubyte _red, GLubyte _green, GLubyte _blue, GLubyte _alpha = 255) : red(_red), green(_green), blue(_blue), alpha(_alpha) {}
  GLubyte red = 50;
  GLubyte green = 50;
  GLubyte blue = 50;
  GLubyte alpha = 255;
  void setAll(GLubyte _red, GLubyte _green, GLubyte _blue, GLubyte _alpha = 255) {
	red = _red;
	green = _green;
	blue = _blue;
	alpha = _alpha;
  };
};

class Figure {
 public:
  Figure(int _ID);
  void shiftCenter(vec3(_shift));
  void setCenter(vec3(_center));
  vec3 getCenter();
  void shiftRotates(vec3(_shift));
  void setRotates(vec3(_rotation));
  vec3 getRotates();
  float getRotX();
  float getRotY();
  float getRotZ();
  virtual void show(){};
  virtual float findNearPoint(double _x, double _y, double _z);
  int tick = 0;
  void setID(int _ID);
  void getIDs(int *_IDr, int *_IDg, int *_IDb);
  void setSelectingMode(bool _mode);
  bool getSelectingMode();
  void setSelected(bool _isSelect);

 protected:
  bool isSelected = false;
  bool selectingMode = false;
  int ID;
  int IDr;
  int IDg;
  int IDb;
  Color planeColor;
  Color edgeColor;
  vec3 rotation = vec3(0, 0, 0);
  vec3 centerPoint;
  int nearestPointIndex = 0;
};

#endif  // FIGURE_HPP
