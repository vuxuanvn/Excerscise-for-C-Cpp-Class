#include "formcreateaccount.h"
#include "ui_formcreateaccount.h"
#include "formuserdata.h"
#include "ui_formuserdata.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "ui_bookwindow.h"
#include "bookwindow.h"
#include "login.h"
#include "formchangepasswd.h"
FormCreateAccount::FormCreateAccount(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::FormCreateAccount)
{
  ui->setupUi(this);
}

FormCreateAccount::~FormCreateAccount()
{
  delete ui;
}

//void FormCreateAccount::on_pushButton_clicked()
//{

//}

//void FormCreateAccount::on_pushButton_2_clicked()
//{
//  QSqlQuery query;
//  QString name,phone,address,birth_year,passwd,level;
//  name=ui->lineEdit->text();
//  address=ui->lineEdit_2->text();
//  phone=ui->lineEdit_3->text();
//  birth_year=ui->lineEdit_4->text();
//  passwd=ui->lineEdit_5->text();
//  //level=ui->comboBox->currentText();
//  bool hasError = false;
//  if(name.length() <= 0 || phone.length() <= 0 || birth_year.length()<= 0 || passwd.length()<= 0){
//      QMessageBox::warning(this,name, "Có trường để trống là không được");
//      hasError=true;
//  }
//  if(level == "1"){
//    level = "admin";
//  }else{
//    level = "user";
//  }

//  if(hasError == false){
//       query.prepare("INSERT INTO account (name, password,ac_address,us_phone,us_birthYear,us_level)"
//                        "VALUES (?, ?, ?,?,?,?)");
//        query.addBindValue(name);
//        query.addBindValue(passwd);
//        query.addBindValue(address);
//        query.addBindValue(phone);
//        query.addBindValue(birth_year);
//        query.addBindValue(0);
//      if(query.exec()){
//         QMessageBox::information(this,name, "Tạo thành công");
//      }
//  }
//  else{
//      QMessageBox::warning(this,name, "Thất bại");
//  }

//}

void FormCreateAccount::on_pushButton_2_clicked()
{
  QSqlQuery query;
    QString name,phone,address,birth_year,passwd,level;
    name=ui->lineEdit->text();
    address=ui->lineEdit_2->text();
    phone=ui->lineEdit_3->text();
    birth_year=ui->lineEdit_4->text();
    passwd=ui->lineEdit_5->text();
    //level=ui->comboBox->currentText();
    bool hasError = false;
    if(name.length() <= 0 || phone.length() <= 0 || birth_year.length()<= 0 || passwd.length()<= 0){
        QMessageBox::warning(this,name, "Có trường để trống là không được");
        hasError=true;
    }
    if(level == "1"){
      level = "admin";
    }else{
      level = "user";
    }

    if(hasError == false){
         query.prepare("insert into account(username, password, authority, ac_address, us_phone,us_birthYear)"
                       "values(?, ?, ?, ?, ?,?)");
          query.addBindValue(name);
          query.addBindValue(passwd);
          query.addBindValue(0);
          query.addBindValue(address);
          query.addBindValue(phone);
          query.addBindValue(birth_year);

        if(query.exec()){
           QMessageBox::information(this,name, "Tạo thành công");
        }
    }
    else{
        QMessageBox::warning(this,name, "Thất bại");
    }
}
