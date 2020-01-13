#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>

namespace Ui {
class AddBook;
}

class AddBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();
    void setIndexAuthor(int index);
    int getIndexAuthor();

    void setIndexGenre(int index);
    int getIndexGenre();


private slots:
    void on_pushButtonAddBook_clicked();

    void on_pushButtonLoad_clicked();

    void on_comboBoxAuthor_currentIndexChanged(int index);

    void on_comboBoxGenre_currentIndexChanged(int index);

private:
    Ui::AddBook *ui;
    int indexAuthor;
    int indexGenre;

};

#endif // ADDBOOK_H
