#ifndef REGISTRAZIONE_H
#define REGISTRAZIONE_H

#include <QtWidgets>

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    RegistrationWindow(QWidget *parent = nullptr);

private slots:
    void onRegisterButtonClicked();

private:
    QLineEdit *nameLineEdit;
    QLineEdit *surnameLineEdit;
    QLineEdit *fiscalCodeLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *emailLineEdit;
    QRadioButton *teacherRadioButton;
    QRadioButton *studentRadioButton;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
};

#endif // REGISTRAZIONE_H
