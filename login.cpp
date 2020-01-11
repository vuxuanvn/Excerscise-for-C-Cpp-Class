#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

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

void Login::on_pushButton_clicked()
{
    QString userName = ui->lineEdit->text();
    QString passWord = ui->lineEdit_2->text();

    if(userName == "test" && passWord == "test"){
        QMessageBox::information(this,"Login", "Username and pass is correct");
        hide();
        bw = new BookWindow();
        bw->show();
    } else {
        QMessageBox::warning(this,"Login", "not correct");
    }
}
