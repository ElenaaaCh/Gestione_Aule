#ifndef LOGIN_H
#define LOGIN_H

#include <QtWidgets>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPixmap>

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr); 

private slots:
    void onLoginButtonClicked();

private:
    QLabel* logoLabel;
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
};

#endif // LOGIN_H
