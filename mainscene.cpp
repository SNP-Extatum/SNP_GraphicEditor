#include "mainscene.hpp"

MainScene::MainScene(QWidget* parent) : QOpenGLWidget(parent), QOpenGLFunctions() {
  frameTimer = new QTimer();
  connect(frameTimer, SIGNAL(timeout()), this, SLOT(update()));
  frameTimer->start(1000 / 60);
  setMouseTracking(true);
}

void MainScene::setFormCube(Form_cube* form) {
  formCube = form;
  connect(formCube, &Form_cube::cubeInfoSignal, this, &MainScene::cubeInfoSlot);
  connect(formCube, &Form_cube::cubeCreateSignal, this, &MainScene::cubeCreateSlot);
}

void MainScene::initializeGL() {
  initializeOpenGLFunctions();
  ModuleCamera::turnGLFrustum();
  // glFrustum(-1, 1, -1, 1, 1, 100);

  // glLoadIdentity();
  // glOrtho(-4, 4, -4, 4, 0, 800);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  //  glBlendFunc(GL_SRC_ALPHA, GL_ONE);
  // setOrtho(true);
  //  glFrustum(-1, 1, -1, 1, 1, 80);
  //   Set up the rendering context, load shaders and other resources, etc.:
  //   QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
  //   f->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  //   f->glEnable(GL_DEPTH_TEST);  // буффер глубины
  //   f->glEnable(GL_CULL_FACE);   // отсечение задних граней (чтобы не рисовались)

  // testProgram.create();
  //  if (!testProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/gravity.fsh")) {
  //..qDebug() << "Компиляции шейдера НЕуспешна";
  //..close();
  // } else {
  //..qDebug() << "Компиляции шейдера успешна";
  // }
  //  if (!testProgram.link()) {
  //..qDebug() << "Линковка программы НЕуспешна";
  //..close();
  // } else {
  //..qDebug() << "Линковка программы успешна";
  // }
  // testProgram.bind();
}

void MainScene::resizeGL(int w, int h) {
  ModuleCamera::setWindowSize(w, h);
  glViewport(0, 0, w, h);
  ModuleCamera::setAspect(w / (float)h);
  glLoadIdentity();
  // what "sz" is?
  if (ModuleCamera::getOrtho()) {
	float focus = 50.0;
	ModuleCamera::turnGLOrtho(focus);
  } else
	ModuleCamera::turnGLFrustum();
}

void MainScene::paintGL() {
  // selectObject();
  shaderTime += shaderdTime;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (selectingMode)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  else
	glClearColor(0.3f, 0.4f, 0.5f, 1.0f);

  glPushMatrix();
  ModuleCamera::moveCamera();
  if (!selectingMode) showOrts();
  showWorld();

  glPopMatrix();
  // SwapBuffers (HDC);
  // double x, y, z;
  // int xpos, ypos;
  // ModuleCamera::getMousePos(&xpos, &ypos);
  // clientToOpenGL(xpos, ypos, &x, &y, &z);
  // qDebug() << x << y << z;
  // if (getNearObject(x, y, z)) {
  // }
}

void MainScene::showWorld() {
  // glPushMatrix();
  for (int i = 0; i < cubeList.size(); ++i) {
	cubeList[i].setSelectingMode(selectingMode);
	cubeList[i].show();
  }
  // glPopMatrix();
}

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

  glEnd();
  worldBox.show();
}

void MainScene::clientToOpenGL(int _x, int _y, double* _ox, double* _oy, double* _oz) {
  // int vp[4];
  // double mMatrix[16], pMatrix[16];
  // float z;
  //
  // glGetIntegerv(GL_VIEWPORT, vp);
  // _y = vp[3] - _y - 1;
  //
  // glGetDoublev(GL_MODELVIEW_MATRIX, mMatrix);
  // glGetDoublev(GL_PROJECTION_MATRIX, pMatrix);
  // glReadPixels(_x, _y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);
  // gluUnProject(_x, _y, z, mMatrix, pMatrix, vp, _ox, _oy, _oz);
}

bool MainScene::getNearObject(double _x, double _y, double _z) {
  // float current, nearest;
  // ObjectType nearestType = NOTOBJECT;
  // int nearestID;
  // nearest = 10000.0;
  //
  //// Cubes
  // for (int i = 0; i < cubeList.size(); ++i) {
  // cubeList[i].isSelected = false;
  // current = cubeList[i].findNearPoint(_x, _y, _z);
  // if (current < nearest) {
  //   nearest = current;
  //   nearestType = CUBE;
  //   nearestID = i;
  // }
  //}
  //
  // switch (nearestType) {
  // case NOTOBJECT:
  //  return false;
  // case CUBE:
  //  cubeList[nearestID].isSelected = true;
  //  return true;
  //}
}

void MainScene::selectObject() {
  // selectingMode = !selectingMode;
  // if (!selectingMode) return;
  selectingMode = true;
  //  glPushMatrix();
  showWorld();
  GLubyte color[3];
  glReadPixels(mousePos[0], size().height() - mousePos[1], 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
  int r = 0;
  int g = 0;
  int b = 0;
  // Cubes
  for (int i = 0; i < cubeList.size(); ++i) {
	cubeList[i].setSelected(false);

	cubeList[i].getIDs(&r, &g, &b);
	if (r == color[0] && g == color[1] && b == color[2]) {
	  cubeList[i].setSelected(true);
	  qDebug() << color[0] << color[1] << color[2];
	  qDebug() << r << g << b;
	  qDebug() << "попал";
	  selectingMode = false;
	  return;
	}
  }
  qDebug() << color[0] << color[1] << color[2];
  qDebug() << r << g << b;
  selectingMode = false;
}

void MainScene::cubeInfoSlot(QString a) { qDebug() << a; }

void MainScene::cubeCreateSlot(vec3 _centerPoint, float _edge, GLubyte _edgeRed, GLubyte _edgeGreen, GLubyte _edgeBlue, GLubyte _edgeAlpha,
							   GLubyte _planeRed, GLubyte _planeGreen, GLubyte _planeBlue, GLubyte _planeAlpha, bool _isEdgeEneble,
							   bool _isPlaneEneble, vec3 _rotation) {
  cubeList.append(Cube(_centerPoint, _edge, _edgeRed, _edgeGreen, _edgeBlue, _edgeAlpha, _planeRed, _planeGreen, _planeBlue, _planeAlpha,
					   _isEdgeEneble, _isPlaneEneble, _rotation, ID));
  //++ID;
  ID += IDShift;
}

void MainScene::mouseMoveEvent(QMouseEvent* event) {
  QCursor c = cursor();
  mousePos[0] = event->pos().x();
  mousePos[1] = event->pos().y();
  // selectObject();

  if (ModuleCamera::getCursorStatus()) {
	ModuleCamera::setMousePos(event->pos().x(), event->pos().y());
	ModuleCamera::setRotating(false);
	c.setShape(Qt::ArrowCursor);
  } else {
	ModuleCamera::setMousePos(event->pos().x(), event->pos().y());
	ModuleCamera::setRotating(true);
	c.setPos(mapToGlobal(QPoint(width() / 2, height() / 2)));
	c.setShape(Qt::BlankCursor);
  }
  setCursor(c);
  // qDebug() << event->pos();
}

void MainScene::mousePressEvent(QMouseEvent* event) {
  selectObject();
  // selectObject();
}
