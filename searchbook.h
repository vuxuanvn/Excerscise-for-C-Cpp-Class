#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QWidget>
#include <QtSql>
namespace Ui {
class SearchBook;
}
class QSqlTableModel;

class SearchBook : public QWidget
{
    Q_OBJECT

public:
    explicit SearchBook(QWidget *parent = nullptr);
    ~SearchBook();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonUpdate_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::SearchBook *ui;
    QSqlRelationalTableModel *model;
    int authorIdx, genreIdx;

};

#endif // SEARCHBOOK_H
