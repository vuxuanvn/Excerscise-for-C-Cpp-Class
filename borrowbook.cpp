#include "borrowbook.h"
#include "ui_borrowbook.h"

BorrowBook::BorrowBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowBook)
{
    ui->setupUi(this);
}

BorrowBook::~BorrowBook()
{
    delete ui;
}
