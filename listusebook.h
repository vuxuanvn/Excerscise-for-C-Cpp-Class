#ifndef LISTUSEBOOK_H
#define LISTUSEBOOK_H

#include <QWidget>
#include <QtSql>
namespace Ui {
class ListUseBook;
}

class ListUseBook : public QWidget
{
    Q_OBJECT

public:
    explicit ListUseBook(QWidget *parent = nullptr);
    ~ListUseBook();

private:
    Ui::ListUseBook *ui;
    QSqlRelationalTableModel *model;
    int userID;
};

#endif // LISTUSEBOOK_H
