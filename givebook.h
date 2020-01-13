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
    void setUserNameId(int id);
    int getUserNameId();

private slots:
    void on_pushButtonSearch_clicked();

    void on_comboBoxUserName_currentIndexChanged(int index);

    void on_pushButtonGiveBook_clicked();

private:
    Ui::GiveBook *ui;
    int usernameId;
};

#endif // GIVEBOOK_H
