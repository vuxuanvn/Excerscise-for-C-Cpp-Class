#include "searchbook.h"
#include "ui_searchbook.h"
#include "connectdb.h"
#include "login.h"
#include <QDebug>
#include <QSqlQuery>
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

void SearchBook::on_pushButtonSearch_clicked()
{
    QString nameBook = ui->lineEditSearch->text();

        QSqlQuery query;
           query.exec("SELECT id,title FROM books WHERE title=\""+nameBook+"\";");
           //query.addBindValue(nameBook);
           while (query.next()) {
                   int id = query.value(0).toInt();
                   QString name = query.value(1).toString();
                   qDebug() << id << name;
               }

}
