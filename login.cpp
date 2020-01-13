#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "connectdb.h"
#include "formuser1.h"
Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

//void Login::on_pushButton_clicked()
//{
//    QString userName = ui->lineEdit->text();
//    QString passWord = ui->lineEdit_2->text();
//    ConnectDb *conn;

//    if(userName == "test" && passWord == "test"){
//        QMessageBox::information(this,"Login", "Username and pass is correct");
//        hide();
//        bw = new BookWindow();
//        bw->show();
//    } else {
//        QMessageBox::warning(this,"Login", "not correct");
//    }
//}
void Login::on_pushButton_clicked()
{
//    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    QString uName;
    QString pass;
    QString authority;
    int id;
    int count = 0;
    QString userName = ui->lineEdit->text();
    QString passWord = ui->lineEdit_2->text();
    ConnectDb *c=new ConnectDb();
    if (c->checkConnect()==true) {
        QSqlQuery query;
           query.exec("SELECT id, username, password , authority FROM account WHERE username=\""+userName+"\" AND password=\""+passWord+"\" ");
           while (query.next()) {
                    id = query.value(0).toInt();
                    uName = query.value(1).toString();
                    pass = query.value(2).toString();
                    authority = query.value(3).toString();
                   qDebug() << uName << pass << id <<authority;
                   count++;

               }
    }


    if(userName == "test" && passWord == "test"){
    if (count!=0 ) {
        QMessageBox::information(this,"Login", "Username and pass is correct");
        hide();
        if (authority=="1") {
            bw = new BookWindow();

           // qDebug() << bw->getName();

            bw->show();
            bw->ui.lblavlelklevkevmk->setText(uName);
        } else{
            qDebug() << "ok";
            FormUser1 *u = new FormUser1();
            u->ui.labelTen->setText(uName);
            u->show();

        }


        // bw->setName(Login::getUserName());

    } else {
        QMessageBox::warning(this,"Login", "not correct");
    }

}
