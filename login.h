#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "bookwindow.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    BookWindow *bw;

};

#endif // LOGIN_H
