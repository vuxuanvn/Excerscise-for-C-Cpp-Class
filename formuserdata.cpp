#include "formuserdata.h"
#include "ui_formuserdata.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "ui_bookwindow.h"
#include "bookwindow.h"
#include "login.h"
#include "formchangepasswd.h"
FormUserData::FormUserData(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::FormUserData)

{
  ui->setupUi(this);
  QSqlQuery query;
  QString name,phone,address,birth_year;
  query.prepare("SELECT * FROM account WHERE id='3'");
  if(query.exec()){
      while (query.next()) {
          name = query.value(1).toString();
          address = query.value(4).toString();
          phone = query.value(5).toString();
          birth_year = query.value(6).toString();
     }
      ui->lineEdit->setText(name);
      ui->lineEdit_2->setText(phone);
      ui->lineEdit_3->setText(address);
      ui->lineEdit_4->setText(birth_year);
     //QMessageBox::information(this,name, "Cập nhật thành công");
  }/*else{
     QMessageBox::warning(this,name, "Thất bại");
  }*/
  qDebug() << "name==" << this->name;
  qDebug() << "phone==" << this->phone;
  qDebug() << "address==" << this->address;
  qDebug() << "birth_year==" << this->birth_year;
}

FormUserData::~FormUserData()
{
  delete ui;
}

void FormUserData::on_pushButton_clicked()
{
   Login login;
   QSqlQuery query;
   QString name,phone,address,birth_year;
   name=ui->lineEdit->text();
   phone=ui->lineEdit_2->text();
   address=ui->lineEdit_3->text();
   birth_year=ui->lineEdit_4->text();
   query.prepare("update account set username='"+name+"',ac_address='"+address+"',us_phone='"+phone+"',us_birthYear='"+birth_year+"' where id = '3'");
   if(query.exec()){
      QMessageBox::information(this,name, "Cập nhật thành công");
   }else{
      QMessageBox::warning(this,name, "Thất bại");
   }

}

void FormUserData::on_pushButton_2_clicked()
{
   Login login;
   hide();
   BookWindow *bw = new BookWindow();
   bw->show();
}

void FormUserData::on_pushButton_3_clicked()
{
    hide();
    FormChangePasswd *changePass = new FormChangePasswd();
    changePass->show();
}
