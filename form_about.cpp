#include "form_about.hpp"

#include "ui_form_about.h"

Form_about::Form_about(QWidget *parent) : QWidget(parent), ui(new Ui::Form_about) { ui->setupUi(this); }

Form_about::~Form_about() { delete ui; }
