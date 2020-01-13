#ifndef BORROWBOOK_H
#define BORROWBOOK_H

#include <QWidget>

namespace Ui {
class BorrowBook;
}

class BorrowBook : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowBook(QWidget *parent = nullptr);
    ~BorrowBook();

private:
    Ui::BorrowBook *ui;
};

#endif // BORROWBOOK_H
