#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "view.h"

class LoginWindow : public View {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel *logoLabel;
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

protected:
    explicit LoginWindow();

public:
    explicit LoginWindow(const QSize& s, View *parent = nullptr);
    void closeEvent(QCloseEvent *event) override;

public slots:
    void onLoginButtonClicked();

signals:
    void Login_signal(QString e, QString p) const; //è corretto o vanno come puntatori??
    void Label_signal() const;
};

#endif // LOGIN_VIEW_H
