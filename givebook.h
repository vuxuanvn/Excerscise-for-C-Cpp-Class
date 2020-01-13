#ifndef GIVEBOOK_H
#define GIVEBOOK_H

#include <QWidget>

namespace Ui {
class GiveBook;
}

class GiveBook : public QWidget
{
    Q_OBJECT

public:
    explicit GiveBook(QWidget *parent = nullptr);
    ~GiveBook();

private:
    Ui::GiveBook *ui;
};

#endif // GIVEBOOK_H
