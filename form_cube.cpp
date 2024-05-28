#include "form_cube.hpp"

#include "ui_form_cube.h"

Form_cube::Form_cube(QWidget *parent) : QWidget(parent), ui(new Ui::Form_cube) { ui->setupUi(this); }

Form_cube::~Form_cube() { delete ui; }

void Form_cube::on_pushButton_create_clicked() {
  emit cubeCreateSignal(vec3(ui->dSpinB_centralX->value(), ui->dSpinB_centralY->value(), ui->dSpinB_centralZ->value()), ui->dSpinB_edge->value(),
						ui->SpinB_edgeR->value(), ui->SpinB_edgeG->value(), ui->SpinB_edgeB->value(), ui->SpinB_edgeA->value(),
						ui->SpinB_planeR->value(), ui->SpinB_planeG->value(), ui->SpinB_planeB->value(), ui->SpinB_planeA->value(),
						ui->checkBox_isEdgesEnable->isChecked(), ui->checkBox_isPlanesEnable->isChecked(),
						vec3(ui->dSpinB_angleX->value(), ui->dSpinB_angleY->value(), ui->dSpinB_angleZ->value()));
  // bool allIsOk = false;
  //  emit cubeCreateSignal();
  //  emit cubeInfoSignal(ui->lineEdit->text());
  this->close();
}
