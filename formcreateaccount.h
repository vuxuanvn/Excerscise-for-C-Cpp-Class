#ifndef FORMCREATEACCOUNT_H
#define FORMCREATEACCOUNT_H

#include <QWidget>

namespace Ui {
  class FormCreateAccount;
}

class FormCreateAccount : public QWidget
{
  Q_OBJECT

public:
  explicit FormCreateAccount(QWidget *parent = nullptr);
  ~FormCreateAccount();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::FormCreateAccount *ui;
};

#endif // FORMCREATEACCOUNT_H
