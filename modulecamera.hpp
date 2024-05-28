#ifndef MODULECAMERA_HPP
#define MODULECAMERA_HPP

#include <QDebug>
#include <QList>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>
#include <limits>

#include "vecfunctions.hpp"

/*
Не забыть:
1) в конструкторе:
  frameTimer = new QTimer();
  connect(frameTimer, SIGNAL(timeout()), this, SLOT(update()));
  frameTimer->start(1000 / 60);

2) initializeGL:
  initializeOpenGLFunctions();
  initializeOpenGLFunctions();
  ModuleCamera::turnGLFrustum();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

3) resizeGL:
  ModuleCamera::setWindowSize(vec2(w, h));
  glViewport(0, 0, w, h);
  ModuleCamera::setAspect(w / (float)h);
  glLoadIdentity();

4) paintGL:
  shaderTime += shaderdTime; // если надо использовать время в шейдерах
  glClearColor(0.3f, 0.4f, 0.5f, 1.0f); // цвет очистки (очевидно же, да?)
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана и буфера глубины

  glPushMatrix(); // ПРОСТО НАДО
  ModuleCamera::moveCamera(); // для работы камеры
  showWorld(); // запихни сюда все что у тебя должно отображаться
  showOrts(); // если надо отобрази оси
  glPopMatrix();  // ТОЖЕ ПРОСТО НАДО :)

5) Функция для единичных осей:

void MainScene::showOrts() {
  glLineWidth(5);
  glBegin(GL_LINES);
  glColor4f(1.0, 0.0, 0.0, 0.3);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(10.0, 0.0, 0.0);

  glColor4f(0.0, 1.0, 0.0, 0.3);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 10.0, 0.0);

  glColor4f(0.0, 0.0, 1.0, 0.3);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.0, 0.0, 10.0);

  glColor4f(0.5, 0.5, 0.5, 0.3);
  glVertex3f(10.0, 0.0, 0.0);
  glVertex3f(10.0, 10.0, 0.0);
  glVertex3f(0.0, 10.0, 0.0);
  glVertex3f(10.0, 10.0, 0.0);
  glVertex3f(10.0, 10.0, 0.0);
  glVertex3f(10.0, 10.0, 10.0);
  glVertex3f(10.0, 0.0, 10.0);
  glVertex3f(10.0, 10.0, 10.0);
  glVertex3f(0.0, 10.0, 10.0);
  glVertex3f(10.0, 10.0, 10.0);
  glVertex3f(0.0, 0.0, 10.0);
  glVertex3f(10.0, 0.0, 10.0);
  glVertex3f(0.0, 0.0, 10.0);
  glVertex3f(0.0, 10.0, 10.0);
  glVertex3f(10.0, 0.0, 0.0);
  glVertex3f(10.0, 0.0, 10.0);
  glVertex3f(0.0, 10.0, 0.0);
  glVertex3f(0.0, 10.0, 10.0);

  glEnd();
}

6)

*/

class ModuleCamera {
 public:
  ModuleCamera();
  static void changeDirection(vec2 changes);
  static void setDirection(vec2 changes);
  static void setOrtho(bool _isOrtho);
  static void setRotating(bool _change);
  static void setWindowSize(int _newXSize, int _newYSize);
  static void setMousePos(int _newXPos, int _newYPos);
  static void getMousePos(int *x, int *y);
  static void setAspect(float _newAspect);
  static bool getOrtho();
  static void turnGLOrtho(double _focus);
  static void turnGLFrustum();
  static void moveCamera();
  static void rotateCamera(float _xAngle, float _zAngle);
  static void rotateCameraByMouse(float _speed);

  static bool getCursorStatus();
  static void setCursorStatus(bool _status);
  static void reverseCursorStatus();

 private:
  static int windowXAbs;
  static int windowYAbs;
  static vec2 direction;
  static vec3 position;
  static bool isOrtho;
  static float aspect;
  static float sz;
  static bool isRotating;
  static vec2 windowPosition;
  static bool isCursorEnable;
  static int windowXCurr;
  static int windowYCurr;
  static int blindZone;
};

#endif  // MODULECAMERA_HPP
