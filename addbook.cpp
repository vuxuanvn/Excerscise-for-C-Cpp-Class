#include "addbook.h"
#include "ui_addbook.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
AddBook::AddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_pushButtonAddBook_clicked()
{
    QSqlQuery query;
       query.prepare("insert into books(title, author, genre, year, rating)"
                     "values(?, ?, ?, ?, ?)");
       query.addBindValue(ui->lineTitle->text());
       query.addBindValue(ui->comboBoxAuthor->itemText(indexAuthor));
       query.addBindValue(ui->comboBoxGenre->itemText(indexGenre));
       query.addBindValue(ui->lineYear->text());
       query.addBindValue(ui->lineRating->text());
       query.exec();
       QMessageBox::information(this,"addbook", "add susscess");
}

void AddBook::on_pushButtonLoad_clicked()
{
    QSqlQuery query;
       query.exec("SELECT COUNT(*) FROM authors");
       while (query.next()) {
           int id = query.value(0).toInt();
           for (int i=1; i<=2; i++) {

               ui->comboBoxAuthor->addItem(QString::number(i));
           }
       }
       query.exec("SELECT COUNT(*) FROM genres");
       while (query.next()) {
           int id = query.value(0).toInt();
           for (int i=1; i<=2; i++) {

               ui->comboBoxGenre->addItem(QString::number(i));
           }
       }

}
void AddBook::setIndexGenre(int index)
{
    indexGenre=index;
}

void AddBook::setIndexAuthor(int index)
{
    indexAuthor=index;

}

int AddBook::getIndexGenre()
{
    return indexGenre;
}

int AddBook::getIndexAuthor()
{
    return indexAuthor;
}

void AddBook::on_comboBoxAuthor_currentIndexChanged(int index)
{
    setIndexAuthor(index);
}



void AddBook::on_comboBoxGenre_currentIndexChanged(int index)
{
    setIndexGenre(index);
}
