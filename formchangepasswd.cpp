#include "formchangepasswd.h"
#include "ui_formchangepasswd.h"

FormChangePasswd::FormChangePasswd(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::FormChangePasswd)
{
  ui->setupUi(this);
}

FormChangePasswd::~FormChangePasswd()
{
  delete ui;
}

void FormChangePasswd::on_pushButton_clicked()
{

}
