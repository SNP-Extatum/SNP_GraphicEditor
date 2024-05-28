#ifndef FORM_ABOUT_HPP
#define FORM_ABOUT_HPP

#include <QWidget>

namespace Ui {
class Form_about;
}

class Form_about : public QWidget {
  Q_OBJECT

 public:
  explicit Form_about(QWidget *parent = nullptr);
  ~Form_about();

 private:
  Ui::Form_about *ui;
};

#endif  // FORM_ABOUT_HPP
