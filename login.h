#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);

private:
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
};

#endif // LOGIN_H
