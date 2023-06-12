#ifndef REGISTRAZIONE_H
#define REGISTRAZIONE_H

#include <QtWidgets>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>


class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    RegistrationWindow(QWidget *parent = nullptr);

private slots:
    void onRegisterButtonClicked();

private:
    QLineEdit *nomeLineEdit;
    QLineEdit *cognomeLineEdit;
    QLineEdit *codLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QRadioButton *docenteRadioButton;
    QRadioButton *studenteRadioButton;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
};

#endif // REGISTRAZIONE_H
