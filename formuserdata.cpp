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
  ui->lineEdit->setText(this->name);
  ui->lineEdit_2->setText(this->phone);
  ui->lineEdit_3->setText(this->address);
  ui->lineEdit_4->setText(this->birth_year);
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
   query.prepare("update account set username='"+name+"',ac_address='"+address+"',us_phone='"+phone+"',us_birthYear='"+birth_year+"'");
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
    QSqlQuery query,query1;
    QString old_passwd,new_passwd,again_passwd;
    old_passwd=ui->lineEdit->text();
    new_passwd=ui->lineEdit_2->text();
    again_passwd=ui->lineEdit_3->text();
    query.prepare("update account set password='"+old_passwd+"'");
    if(query.exec()){
      if(new_passwd.length() < 8){
         QMessageBox::warning(this,name, "Mật khẩu mới phải có ít nhất 8 kí tự");
      }
      if(new_passwd != again_passwd){
         QMessageBox::warning(this,name, "Nhập lại mật khẩu không đúng");
      }
      query1.prepare("update account set password='"+new_passwd+"'");
      if(query1.exec()){
         QMessageBox::information(this,name, "Đổi mật khẩu thành công");
      }else{
         QMessageBox::warning(this,name, "Thất bại");
      }

    }else{
       QMessageBox::warning(this,name, "Mật khẩu cũ không đúng!");
    }

}
