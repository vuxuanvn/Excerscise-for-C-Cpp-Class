#include "formuser1.h"
#include "ui_formuser1.h"

FormUser1::FormUser1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormUser1)
{
    ui->setupUi(this);
}

FormUser1::~FormUser1()
{
    delete ui;
}
