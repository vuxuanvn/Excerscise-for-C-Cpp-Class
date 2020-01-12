#include "searchbook.h"
#include "ui_searchbook.h"

SearchBook::SearchBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBook)
{
    ui->setupUi(this);
}

SearchBook::~SearchBook()
{
    delete ui;
}
