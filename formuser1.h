#ifndef FORMUSER1_H
#define FORMUSER1_H

#include <QWidget>

namespace Ui {
class FormUser1;
}

class FormUser1 : public QWidget
{
    Q_OBJECT

public:
    explicit FormUser1(QWidget *parent = nullptr);
    ~FormUser1();

private:
    Ui::FormUser1 *ui;
};

#endif // FORMUSER1_H
