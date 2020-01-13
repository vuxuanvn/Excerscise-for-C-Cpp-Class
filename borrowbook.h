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
    void setNameBorrow(int nameId);
    int getNameBorrow();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonBorrow_clicked();



    void on_comboBoxNguoiMuon_currentIndexChanged(int index);

private:
    Ui::BorrowBook *ui;
    int nameBorrowID;
};

#endif // BORROWBOOK_H
