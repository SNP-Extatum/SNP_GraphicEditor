#include "figure.hpp"

Figure::Figure(int _ID) { setID(_ID); }

void Figure::shiftCenter(vec3 _shift) { centerPoint += _shift; }

void Figure::setCenter(vec3 _center) { centerPoint = _center; }

void Figure::shiftRotates(vec3 _shift) { rotation += _shift; }

void Figure::setRotates(vec3 _rotation) { rotation = _rotation; }

vec3 Figure::getRotates() { return rotation; }

float Figure::getRotX() { return rotation.x; }

float Figure::getRotY() { return rotation.y; }

float Figure::getRotZ() { return rotation.z; }

float Figure::findNearPoint(double _x, double _y, double _z) { return 99999999.0; }

void Figure::setID(int _ID) {
  ID = _ID;
  IDr = ID % 256;
  IDg = (ID / 256) % 256;
  IDb = (ID / (256 * 256)) % 256;
}

void Figure::getIDs(int* _IDr, int* _IDg, int* _IDb) {
  *_IDr = IDr;
  *_IDg = IDg;
  *_IDb = IDb;
}

void Figure::setSelectingMode(bool _mode) { selectingMode = _mode; }

bool Figure::getSelectingMode() { return selectingMode; }

void Figure::setSelected(bool _isSelect) { isSelected = _isSelect; }
