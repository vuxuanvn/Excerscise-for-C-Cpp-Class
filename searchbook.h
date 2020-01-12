#ifndef SEARCHBOOK_H
#define SEARCHBOOK_H

#include <QWidget>

namespace Ui {
class SearchBook;
}

class SearchBook : public QWidget
{
    Q_OBJECT

public:
    explicit SearchBook(QWidget *parent = nullptr);
    ~SearchBook();

private:
    Ui::SearchBook *ui;
};

#endif // SEARCHBOOK_H
