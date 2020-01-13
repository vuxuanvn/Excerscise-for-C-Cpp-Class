#include "changepassword.h"
#include "ui_changepassword.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("account");
    model->select();
    ui->tableAccount->setModel(model);
}

ChangePassword::~ChangePassword()
{
    delete ui;

}
