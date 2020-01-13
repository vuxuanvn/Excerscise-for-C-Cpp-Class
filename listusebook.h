#ifndef LISTUSEBOOK_H
#define LISTUSEBOOK_H

#include <QWidget>

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
};

#endif // LISTUSEBOOK_H
