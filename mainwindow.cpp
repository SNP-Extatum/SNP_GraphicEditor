#include "mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  form_about = new Form_about();
  form_cube = new Form_cube();
  ui->openGLWidget->setFormCube(form_cube);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::mouseMoveEvent(QMouseEvent* event) {
  // if (event->pos().x() > ui->openGLWidget->pos().x() && event->pos().x() < ui->openGLWidget->pos().x() + ui->openGLWidget->size().width() &&
  //   event->pos().y() > ui->openGLWidget->pos().y() && event->pos().y() < ui->openGLWidget->pos().y() + ui->openGLWidget->size().height()) {
  // ModuleCamera::setWindowPos(vec2(ui->openGLWidget->pos().x() + this->x(), ui->openGLWidget->pos().y() + this->y()));
  // if (!mouseMustBeVisible) {
  //   ModuleCamera::setRotating(true);
  //   ShowCursor(false);
  // }
  //}
}

void MainWindow::mousePressEvent(QMouseEvent* event) {}

void MainWindow::mouseReleaseEvent(QMouseEvent* event) {
  ModuleCamera::setRotating(false);
  ShowCursor(true);
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
	case Qt::Key_Space:
	  ModuleCamera::reverseCursorStatus();
	  break;
  }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
  switch (event->key()) {}
}

void MainWindow::wheelEvent(QWheelEvent* event) {}

void MainWindow::on_action_about_triggered() { form_about->show(); }

void MainWindow::on_create_cube_triggered() { form_cube->show(); }

void MainWindow::on_action_sphere_triggered() {}

void MainWindow::on_action_exit_triggered() { close(); }

void MainWindow::closeEvent(QCloseEvent* e) /*событие закртия окна*/ {
  // if (isSaved)
  // e->accept();
  // else {
  // if (msgBox_save_call())
  //   e->accept();
  // else
  //   e->ignore();
  //}
}
