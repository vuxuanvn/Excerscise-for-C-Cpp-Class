#ifndef FORMUSERDATA_H
#define FORMUSERDATA_H

#include <QWidget>

namespace Ui {
  class FormUserData;
}

class FormUserData : public QWidget
{
  Q_OBJECT

public:
  explicit FormUserData(QWidget *parent = nullptr);
  ~FormUserData();


private:
  Ui::FormUserData *ui;


public:
  QString name;
  QString address;
  QString birth_year;
  QString phone;
private slots:
  void on_pushButton_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
};


#endif // FORMUSERDATA_H
