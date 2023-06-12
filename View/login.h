#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


class LoginWindow : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *layout;
    QLabel* logoLabel;
    QLabel *benvenutoLabel;

    QHBoxLayout *HLayout;
    QVBoxLayout *Vl1;
    QLabel *emailLabel;
    QLabel *passwLabel;
    QVBoxLayout *Vl2;
    QLineEdit *emailLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLabel *registerLabel;

public:
    LoginWindow(QWidget *parent = nullptr); 

public slots:
    void onLoginButtonClicked();

};

#endif // LOGIN_H
