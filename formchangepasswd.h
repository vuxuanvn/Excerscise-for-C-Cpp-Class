#ifndef FORMCHANGEPASSWD_H
#define FORMCHANGEPASSWD_H

#include <QWidget>

namespace Ui {
  class FormChangePasswd;
}

class FormChangePasswd : public QWidget
{
  Q_OBJECT

public:
  explicit FormChangePasswd(QWidget *parent = nullptr);
  ~FormChangePasswd();

private slots:
  void on_pushButton_clicked();

private:
  Ui::FormChangePasswd *ui;
};

#endif // FORMCHANGEPASSWD_H
