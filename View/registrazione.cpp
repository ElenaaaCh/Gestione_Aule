#include "registrazione.h"

RegistrationWindow::RegistrationWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Registrazione", this);
    layout->addWidget(titleLabel);

    // Campi di input per la registrazione
    nameLineEdit = new QLineEdit(this);
    surnameLineEdit = new QLineEdit(this);
    fiscalCodeLineEdit = new QLineEdit(this);
    phoneLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);

    QLabel *roleLabel = new QLabel("Ruolo:", this);
    teacherRadioButton = new QRadioButton("Docente", this);
    studentRadioButton = new QRadioButton("Studente", this);
    QHBoxLayout *roleLayout = new QHBoxLayout;
    roleLayout->addWidget(roleLabel);
    roleLayout->addWidget(teacherRadioButton);
    roleLayout->addWidget(studentRadioButton);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    layout->addWidget(nameLineEdit);
    layout->addWidget(surnameLineEdit);
    layout->addWidget(fiscalCodeLineEdit);
    layout->addWidget(phoneLineEdit);
    layout->addWidget(emailLineEdit);
    layout->addLayout(roleLayout);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(confirmPasswordLineEdit);

    // Pulsante di registrazione
    QPushButton *registerButton = new QPushButton("Registrati", this);
    layout->addWidget(registerButton);

    // Connessione del pulsante di registrazione al slot onRegisterButtonClicked()
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterButtonClicked);
}

void RegistrationWindow::onRegisterButtonClicked()
{
    // Elaborazione della registrazione
    QString name = nameLineEdit->text();
    QString surname = surnameLineEdit->text();
    QString fiscalCode = fiscalCodeLineEdit->text();
    QString phone = phoneLineEdit->text();
    QString email = emailLineEdit->text();
    QString role = teacherRadioButton->isChecked() ? "Docente" : "Studente";
    QString password = passwordLineEdit->text();
    QString confirmPassword = confirmPasswordLineEdit->text();

    // Esempio di validazione dei campi
    if (name.isEmpty() || surname.isEmpty() || fiscalCode.isEmpty() || phone.isEmpty() ||
        email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Errore di registrazione", "Riempi tutti i campi.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Errore di registrazione", "Le password non corrispondono.");
        return;
    }

    // Eseguire altre operazioni di registrazione qui, ad esempio salvare i dati nel database

    // Mostra un messaggio di successo
    QMessageBox::information(this, "Registrazione completata", "Registrazione avvenuta con successo!");
    close();
}
