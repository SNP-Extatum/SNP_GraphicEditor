#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include <windows.h>
#include <GL/glu.h>

#include <QDebug>
#include <QList>
#include <QObject>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QTimer>
#include <QtOpenGL>
#include <form_cube.hpp>
#include <limits>

#include "cube.hpp"
#include "modulecamera.hpp"
#include "vecfunctions.hpp"

enum ObjectType {
  NOTOBJECT,
  CUBE,
};

class MainScene : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  MainScene(QWidget* parent = 0);
  void setFormCube(Form_cube* form);
  bool isCursorEneble = false;
  void selectObject();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  QOpenGLShaderProgram testProgram;
  float shaderTime = 0.0f;
  float shaderdTime = 0.05f;
  QTimer* frameTimer;
  QList<Cube> cubeList;
  void showWorld();
  void showMaskWorld();
  void showOrts();
  void clientToOpenGL(int _x, int _y, double* _ox, double* _oy, double* _oz);
  bool getNearObject(double _x, double _y, double _z);
  int ID = 50;
  int IDShift = 10;
  bool selectingMode = false;
  int mousePos[2] = {0, 0};
  int windowSize[2] = {0, 0};

  HWND hwnd;  // ЧТО ЭТО - (не знаю, но похоже нужное) Да нужное. это хэндл твоего окна!

  Form_cube* formCube;
  Cube worldBox = Cube(vec3(0, 0, 0), 200, 50, 50, 50, 255, 0, 0, 0, 0, true, false, vec3(0, 0, 0), 0);

 public slots:
  void cubeInfoSlot(QString a);
  void cubeCreateSlot(vec3 _centerPoint, float _edge, GLubyte _edgeRed, GLubyte _edgeGreen, GLubyte _edgeBlue, GLubyte _edgeAlpha, GLubyte _planeRed,
					  GLubyte _planeGreen, GLubyte _planeBlue, GLubyte _planeAlpha, bool _isEdgeEneble, bool _isPlaneEneble, vec3 _rotation);

  // QWidget interface
 protected:
  void mouseMoveEvent(QMouseEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
};

#endif  // MAINSCENE_HPP
