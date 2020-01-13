#include "givebook.h"
#include "ui_givebook.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDate>
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

void GiveBook::on_pushButtonSearch_clicked()
{
    QString nameBook = ui->lineEditSearch->text();
    int count = 0;
        QSqlQuery query;
           query.exec("SELECT title FROM books WHERE title=\""+nameBook+"\";");
           while (query.next()) {
                   QString nameBook1 = query.value(0).toString();
                   qDebug() << nameBook1;
                   count ++;
           }
           if (count==0)
               QMessageBox::warning(this,"search", "not found!");
           ui->lineBookName->setText(nameBook);
           query.exec("SELECT username FROM account ");
           while(query.next()){
               ui->comboBoxUserName->addItem(query.value(0).toString());
           }

}

void GiveBook::on_comboBoxUserName_currentIndexChanged(int index)
{
    setUserNameId(index);
}

void GiveBook::on_pushButtonGiveBook_clicked()
{
    QString bookName = ui->lineBookName->text();
    QString userName = ui->comboBoxUserName->itemText(getUserNameId());
    QString day = QString::number(QDate::currentDate().day());
    QString month = QString::number(QDate::currentDate().month());
    QString year = QString::number(QDate::currentDate().year());
    QString dayGiveBook;
    dayGiveBook.append(year);
    dayGiveBook.append("-");
    dayGiveBook.append(month);
     dayGiveBook.append("-");
     dayGiveBook.append(day);
     qDebug() << dayGiveBook;
     QString d = dayGiveBook;
     QSqlQuery query;

     query.exec("SELECT id FROM account WHERE username='"+userName+"'");
     while (query.next()) {
         QString id = query.value(0).toString();
          qDebug() << id << bookName;
          query.exec("UPDATE muonsach SET ngaytra='"+d+"' WHERE user_id='"+id+"' AND name_book='"+bookName+"'");
          QMessageBox::warning(this,"givebook", "susscess!");
     }



}

void GiveBook::setUserNameId(int id)
{
    usernameId=id;
}

int GiveBook::getUserNameId()
{
    return  usernameId;
}
