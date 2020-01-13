#include "listusebook.h"
#include "ui_listusebook.h"

ListUseBook::ListUseBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListUseBook)
{
    ui->setupUi(this);
}

ListUseBook::~ListUseBook()
{
    delete ui;
}
