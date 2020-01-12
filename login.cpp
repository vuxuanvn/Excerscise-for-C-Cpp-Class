#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "connectdb.h"

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

int Login::on_pushButton_clicked()
{
    QString uName;
    QString pass;
    int id;
    int count = 0;
    QString userName = ui->lineEdit->text();
    QString passWord = ui->lineEdit_2->text();
    ConnectDb *c=new ConnectDb();
    if (c->checkConnect()==true) {
        QSqlQuery query;
           query.exec("SELECT id, username, password FROM account WHERE username=\""+userName+"\" AND password=\""+passWord+"\" ");
           while (query.next()) {
                    id = query.value(0).toInt();
                    uName = query.value(1).toString();
                    pass = query.value(2).toString();
                   qDebug() << uName << pass << id;
                   count++;
                   Login::setUserName(uName);
               }
    }
    qDebug() << Login::getUserName();

    if (count!=0) {
        QMessageBox::information(this,"Login", "Username and pass is correct");
        hide();
        bw = new BookWindow();

       // qDebug() << bw->getName();
         bw->setObjectName(Login::getUserName());
        bw->show();

        // bw->setName(Login::getUserName());

    } else {
        QMessageBox::warning(this,"Login", "not correct");
    }
     return id ;
}
void Login::setUserName(QString userName)
{
    this->UserName=userName;
}
QString Login::getUserName() const
{
    return this->UserName;
}
