#include "givebook.h"
#include "ui_givebook.h"

GiveBook::GiveBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GiveBook)
{
    ui->setupUi(this);
}

GiveBook::~GiveBook()
{
    delete ui;
}
