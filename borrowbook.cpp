#include "borrowbook.h"
#include "ui_borrowbook.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>
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

void BorrowBook::on_pushButtonSearch_clicked()
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
               ui->comboBoxNguoiMuon->addItem(query.value(0).toString());
           }

}

void BorrowBook::on_pushButtonBorrow_clicked()
{
    QString bookName = ui->lineBookName->text();
    QString userName = ui->comboBoxNguoiMuon->itemText(nameBorrowID);
    QString dateBorrow = ui->dateBorrow->text();
    qDebug() << bookName << userName << dateBorrow;

    QSqlQuery query;
    query.exec("SELECT id FROM account WHERE username=\""+userName+"\";");
    while (query.next()) {
        int id = query.value(0).toInt();
        query.prepare("INSERT INTO muonsach (user_id, name_book, ngaymuon) value (?,?,?)");
        query.addBindValue(id);
        query.addBindValue(bookName);
        query.addBindValue(dateBorrow);
        query.exec();
        QMessageBox::warning(this,"borrow", "susscess!");
    }

}



void BorrowBook::setNameBorrow(int nameId)
{
    nameBorrowID=nameId;
}

int BorrowBook::getNameBorrow()
{
    return nameBorrowID;
}

void BorrowBook::on_comboBoxNguoiMuon_currentIndexChanged(int index)
{
    setNameBorrow(index);
}
