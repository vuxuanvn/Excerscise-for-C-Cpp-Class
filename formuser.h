#ifndef FORMUSER_H
#define FORMUSER_H

#include <QMainWindow>

namespace Ui {
  class FormUser;
}

class FormUser : public QMainWindow
{
  Q_OBJECT

public:
  void formUser();

private slots:
  void on_pushButton_clicked();

public:
  Ui::FormUser *ui;
};

#endif // FORMUSER_H
