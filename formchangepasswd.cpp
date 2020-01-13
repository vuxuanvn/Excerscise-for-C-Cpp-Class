#include "formchangepasswd.h"
#include "ui_formchangepasswd.h"
#include "formuserdata.h"
#include "ui_formuserdata.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "ui_bookwindow.h"
#include "bookwindow.h"
#include "login.h"
#include "formchangepasswd.h"
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
  QSqlQuery query,query1;
  QString old_passwd,new_passwd,again_passwd;
  old_passwd=ui->lineEdit->text();
  new_passwd=ui->lineEdit_2->text();
  again_passwd=ui->lineEdit_3->text();
  query.prepare("SELECT * FROM account WHERE password='"+old_passwd+"'");
  bool hasError = false;
  if(query.exec()){
    int count = 0;
    while(query.next()){
      count++;
    }
    if(count == 0){
        QMessageBox::warning(this,"Đổi mật khẩu", "Mật khẩu cũ không đúng");
        hasError=true;
    }
    if(new_passwd.length() < 8){
       QMessageBox::warning(this,"Đổi mật khẩu", "Mật khẩu mới phải có ít nhất 8 kí tự");
       hasError=true;
    }
    if(new_passwd != again_passwd){
       QMessageBox::warning(this,"Đổi mật khẩu", "Nhập lại mật khẩu không đúng");
       hasError=true;
    }
    if(hasError==false){
       query1.prepare("update account set password='"+new_passwd+"' where id='3'");
       if(query1.exec()){
          QMessageBox::information(this,"Đổi mật khẩu", "Đổi mật khẩu thành công");
       };
    }

  }else{
     QMessageBox::warning(this,"Đổi mật khẩu", "Mật khẩu cũ không đúng!");
  }
}
