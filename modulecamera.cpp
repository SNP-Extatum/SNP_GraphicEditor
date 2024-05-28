#include "modulecamera.hpp"

int ModuleCamera::windowXAbs;
int ModuleCamera::windowYAbs;
vec2 ModuleCamera::direction = vec2(80, 0);
vec3 ModuleCamera::position = vec3(1, -1, 1);
bool ModuleCamera::isOrtho = false;
float ModuleCamera::aspect;
float ModuleCamera::sz = 0.1;
bool ModuleCamera::isRotating = false;
vec2 ModuleCamera::windowPosition = vec2(0, 0);
int ModuleCamera::windowXCurr;
int ModuleCamera::windowYCurr;
int ModuleCamera::blindZone = 3;
bool ModuleCamera::isCursorEnable = false;

ModuleCamera::ModuleCamera() {}

void ModuleCamera::changeDirection(vec2 changes) { direction += changes; }

void ModuleCamera::setDirection(vec2 changes) {
  if (changes.x > 0) direction.x = (direction.x + changes.x) > 180 ? 180 : direction.x + changes.x;
  if (changes.x < 0) direction.x = (direction.x + changes.x) < 0 ? 0 : direction.x + changes.x;
  if (changes.y > 0) direction.y = (direction.y + changes.y) > 360 ? 0 : (direction.y + changes.y);
  if (changes.y < 0) direction.y = (direction.y + changes.y) < -360 ? 0 : (direction.y + changes.y);
}

void ModuleCamera::setOrtho(bool _isOrtho) {
  isOrtho = _isOrtho;
  // resizeGL(windowSize.x, windowSize.y);
}

void ModuleCamera::setRotating(bool _change) { isRotating = _change; }

void ModuleCamera::setWindowSize(int _newXSize, int _newYSize) {
  windowXAbs = _newXSize;
  windowYAbs = _newYSize;
}

void ModuleCamera::setMousePos(int _newXPos, int _newYPos) {
  windowXCurr = _newXPos;
  windowYCurr = _newYPos;
}

void ModuleCamera::getMousePos(int* x, int* y) {
  *x = windowXCurr;
  *y = windowYCurr;
}

void ModuleCamera::setAspect(float _newAspect) { aspect = _newAspect; }

bool ModuleCamera::getOrtho() { return isOrtho; }

void ModuleCamera::turnGLOrtho(double _focus) { glOrtho(-aspect * sz * _focus, aspect * sz * _focus, -sz * _focus, sz * _focus, sz * 2, 100); }

void ModuleCamera::turnGLFrustum() { glFrustum(-aspect * sz, aspect * sz, -sz, sz, sz * 2, 1000); }

void ModuleCamera::rotateCamera(float _xAngle, float _zAngle) {
  direction.y += _zAngle;
  if (direction.y < 0) direction.y += 360;
  if (direction.y > 360) direction.y -= 360;
  direction.x += _xAngle;
  if (direction.x < 0) direction.x = 0;
  if (direction.x > 180) direction.x = 180;
}

void ModuleCamera::rotateCameraByMouse(float _speed) {
  // POINT cur;
  // POINT base{(int)(windowPosition.x + windowSize.x / 2), (int)(windowPosition.y + windowSize.y / 2)};
  // GetCursorPos(&cur);
  int dy = windowYAbs / 2 - windowYCurr;
  int dx = windowXAbs / 2 - windowXCurr;

  if (sqrt(dx * dx + dy * dy) < blindZone) return;
  rotateCamera(dy * _speed, dx * _speed);
  // rotateCamera((base.y - cur.y) / 5.0 * _speed, (base.x - cur.x) / 5.0 * _speed);
  // SetCursorPos(base.x, base.y);
  // SetCursorPos(windowXAbs / 2.0, windowYAbs / 2.0);
}

bool ModuleCamera::getCursorStatus() { return isCursorEnable; }

void ModuleCamera::setCursorStatus(bool _status) { isCursorEnable = _status; }

void ModuleCamera::reverseCursorStatus() { isCursorEnable = !isCursorEnable; }

void ModuleCamera::moveCamera() {
  if (isRotating && !isCursorEnable) {
	rotateCameraByMouse(0.2);
  }
  if (GetKeyState(VK_UP) < 0) direction.x = ++direction.x > 180 ? 180 : direction.x;
  if (GetKeyState(VK_DOWN) < 0) direction.x = --direction.x < 0 ? 0 : direction.x;
  if (GetKeyState(VK_LEFT) < 0) direction.y = ++direction.y;
  if (GetKeyState(VK_RIGHT) < 0) direction.y = --direction.y;
  float speed = 0;
  float angle = -direction.y / 180.0 * M_PI;
  if (GetKeyState('W') < 0) speed = 0.1;
  if (GetKeyState('S') < 0) speed = -0.1;
  if (GetKeyState('A') < 0) {
	speed = 0.1;
	angle -= M_PI * 0.5;
  }
  if (GetKeyState('D') < 0) {
	speed = 0.1;
	angle += M_PI * 0.5;
  }
  if (speed != 0) {
	position.x += sin(angle) * speed;
	position.y += cos(angle) * speed;
  }
  if (GetKeyState(VK_SHIFT) < 0) position.z += 0.1;
  if (GetKeyState(VK_LCONTROL) < 0) position.z += -0.1;

  glRotatef(-direction.x, 1, 0, 0);
  glRotatef(-direction.y, 0, 0, 1);
  glTranslatef(-position.x, -position.y, -position.z);
}
