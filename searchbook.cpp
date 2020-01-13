#include "searchbook.h"
#include "ui_searchbook.h"
#include "connectdb.h"
#include "login.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QMessageBox>

SearchBook::SearchBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBook)
{
    ui->setupUi(this);



    // Create the data model:

}

SearchBook::~SearchBook()
{
    delete ui;
}

void SearchBook::on_pushButtonSearch_clicked()
{
    QString nameBook = ui->lineEditSearch->text();

        QSqlQuery query;
           query.exec("SELECT * FROM books WHERE title=\""+nameBook+"\";");
           //query.addBindValue(nameBook);
           while (query.next()) {
                   QString id = query.value(0).toString();
                   QString title = query.value(1).toString();
                   QString author = query.value(2).toString();
                   QString genre = query.value(3).toString();
                   QString year = query.value(4).toString();
                   QString rating = query.value(5).toString();

                   qDebug() << title << author << genre << year << rating;
//                   query.prepare("insert into timbooks(id, title, year, author, genre, rating) values(?, ?, ?, ?, ?, ?)");
//                   query.addBindValue(1);
//                   query.addBindValue(title);
//                   query.addBindValue(author);
//                   query.addBindValue(genre);
//                   query.addBindValue(year);
//                   query.addBindValue(rating);
//                   query.exec();
                    ui->lineBookName->setText(title);
                    ui->lineAuthor->setText(author);
                    ui->lineGenre->setText(genre);
                    ui->lineYear->setText(year);
                    ui->lineRating->setText(rating);
                    ui->lableId->setText(id);

           }

//           model = new QSqlRelationalTableModel();

//           model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//           model->setTable("timbooks");


//           // Remember the indexes of the columns:
//           authorIdx = model->fieldIndex("author");
//           genreIdx = model->fieldIndex("genre");

//           // Set the relations to the other database tables:
//           model->setRelation(authorIdx, QSqlRelation("authors", "id", "name"));
//           model->setRelation(genreIdx, QSqlRelation("genres", "id", "name"));

//           // Set the localized header captions:
//           model->setHeaderData(authorIdx, Qt::Horizontal, tr("Author Name"));
//           model->setHeaderData(genreIdx, Qt::Horizontal, tr("Genre"));
//           model->setHeaderData(model->fieldIndex("title"),
//                                Qt::Horizontal, tr("Title"));
//           model->setHeaderData(model->fieldIndex("year"), Qt::Horizontal, tr("Year"));
//           model->setHeaderData(model->fieldIndex("rating"),
//                                Qt::Horizontal, tr("Rating"));
//            model->select();
//           ui->tableView->setModel(model);
           //query.exec("DELETE FROM timsach");

}

void SearchBook::on_pushButtonUpdate_clicked()
{
    QString id = ui->lableId->text();
    QString title = ui->lineBookName->text();
    QString author = ui->lineAuthor->text();
    QString genre = ui->lineGenre->text();
    QString year = ui->lineYear->text();
    QString rating = ui->lineRating->text();
     QSqlQuery query;
     query.exec("UPDATE books SET title = '"+title+"', author='"+author+"', genre='"+genre+"', year='"+year+"', rating='"+rating+"' WHERE id = '"+id+"'");
    QMessageBox::information(this,"updatebook", "update susscess");
}

void SearchBook::on_pushButtonDelete_clicked()
{
    QString id = ui->lableId->text();
    QSqlQuery query;
    query.exec("DELETE from books WHERE id = '"+id+"'");
    QMessageBox::information(this,"deletebook", "delete susscess");
}
