#ifndef FORM_CUBE_HPP
#define FORM_CUBE_HPP

#include <QDebug>
#include <QOpenGLFunctions>
#include <QWidget>
#include <vecfunctions.hpp>

namespace Ui {
class Form_cube;
}

class Form_cube : public QWidget {
  Q_OBJECT

 public:
  explicit Form_cube(QWidget *parent = nullptr);
  ~Form_cube();

 private slots:
  void on_pushButton_create_clicked();

 private:
  Ui::Form_cube *ui;

  vec3 centerPoint;
  float edge;
  GLubyte edgeRed;
  GLubyte edgeGreen;
  GLubyte edgeBlue;
  GLubyte edgeAlpha;
  GLubyte planeRed;
  GLubyte planeGreen;
  GLubyte planeBlue;
  GLubyte planeAlpha;
  bool isEdgeEneble;
  bool isPlaneEneble;
  vec3 rotation;

 signals:
  void cubeInfoSignal(QString a);
  void cubeCreateSignal(vec3 _centerPoint, float _edge, GLubyte _edgeRed, GLubyte _edgeGreen, GLubyte _edgeBlue, GLubyte _edgeAlpha,
						GLubyte _planeRed, GLubyte _planeGreen, GLubyte _planeBlue, GLubyte _planeAlpha, bool _isEdgeEneble, bool _isPlaneEneble,
						vec3 _rotation);
};

#endif  // FORM_CUBE_HPP
