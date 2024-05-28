#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QList>
#include <QMainWindow>

#include "form_about.hpp"
#include "form_cube.hpp"
#include "modulecamera.hpp"
#include "settings.hpp"
#include "vecfunctions.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  // int a;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void closeEvent(QCloseEvent *e) override;

 private slots:
  void on_action_about_triggered();

  void on_create_cube_triggered();

  void on_action_sphere_triggered();

  void on_action_exit_triggered();

 private:
  Ui::MainWindow *ui;
  Form_about *form_about;
  Form_cube *form_cube;
  bool mouseMustBeVisible = false;
};
#endif  // MAINWINDOW_HPP
