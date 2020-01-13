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

public slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    BookWindow *bw;
public:
    QString *user_passwd;
private slots:
    void on_pushButton_2_clicked();
};

#endif // LOGIN_H
