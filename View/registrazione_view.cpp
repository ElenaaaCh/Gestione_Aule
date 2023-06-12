#include "registrazione_view.h"

RegistrationWindow::RegistrationWindow(const QSize & s, View * parent) : View(s,parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Form di registrazione", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QHBoxLayout *HLayout = new QHBoxLayout(this);
    layout->addLayout(HLayout);

    QVBoxLayout *Vl1 = new QVBoxLayout(this);
    HLayout->addLayout(Vl1);

    QLabel *nomeLabel = new QLabel(this);
    nomeLabel->setText("Codice fiscale");
    QLabel *cognomeLabel = new QLabel(this);
    cognomeLabel->setText("Codice fiscale");
    QLabel *codLabel = new QLabel(this);
    codLabel->setText("Codice fiscale");
    QLabel *phoneLabel = new QLabel(this);
    phoneLabel->setText("Numero di telefono");
    QLabel *emailLabel = new QLabel(this);
    emailLabel->setText("Email");
    QLabel *ruoloLabel = new QLabel(this);
    ruoloLabel->setText("Ruolo");
    QLabel *passwLabel = new QLabel(this);
    passwLabel->setText("Password");
    QLabel *cPasswLabel = new QLabel(this);
    cPasswLabel->setText("Conferma Password");

    Vl1->addWidget(nomeLabel);
    Vl1->addWidget(cognomeLabel);
    Vl1->addWidget(codLabel);
    Vl1->addWidget(phoneLabel);
    Vl1->addWidget(emailLabel);
    Vl1->addWidget(ruoloLabel);
    Vl1->addWidget(passwLabel);
    Vl1->addWidget(cPasswLabel);

    HLayout->addStretch();

    QVBoxLayout *Vl2 = new QVBoxLayout(this);
    HLayout->addLayout(Vl2);

    nomeLineEdit = new QLineEdit(this);
    nomeLineEdit->setPlaceholderText("Inserire nome");
    cognomeLineEdit = new QLineEdit(this);
    cognomeLineEdit->setPlaceholderText("Inserire cognome");
    codLineEdit = new QLineEdit(this);
    codLineEdit->setPlaceholderText("Inserire codice fiscale");
    phoneLineEdit = new QLineEdit(this);
    phoneLineEdit->setPlaceholderText("Inserire numero di telefono");
    emailLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Inserire email");

    docenteRadioButton = new QRadioButton("Docente", this);
    studenteRadioButton = new QRadioButton("Studente", this);
    QHBoxLayout *roleLayout = new QHBoxLayout(this);
    roleLayout->addWidget(docenteRadioButton);
    roleLayout->addWidget(studenteRadioButton);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Inserire password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setPlaceholderText("Re-inserire password");
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    Vl2->addWidget(nomeLineEdit);
    Vl2->addWidget(cognomeLineEdit);
    Vl2->addWidget(codLineEdit);
    Vl2->addWidget(phoneLineEdit);
    Vl2->addWidget(emailLineEdit);
    Vl2->addLayout(roleLayout);
    Vl2->addWidget(passwordLineEdit);
    Vl2->addWidget(confirmPasswordLineEdit);

    // Pulsante di registrazione
    QPushButton *registerButton = new QPushButton("Registrati", this);
    layout->addWidget(registerButton);

    // Connessione del pulsante di registrazione al slot onRegisterButtonClicked()
    connect(registerButton, &QPushButton::clicked, this, &RegistrationWindow::onRegisterButtonClicked);
}

void RegistrationWindow::onRegisterButtonClicked()
{
    // Elaborazione della registrazione
    QString name = nomeLineEdit->text();
    QString surname = cognomeLineEdit->text();
    QString fiscalCode = codLineEdit->text();
    QString phone = phoneLineEdit->text();
    QString email = emailLineEdit->text();
    QString role = docenteRadioButton->isChecked() ? "Docente" : "Studente";
    QString password = passwordLineEdit->text();
    QString confirmPassword = confirmPasswordLineEdit->text();

    // Controllo campi vuoti
    if (name.isEmpty() || surname.isEmpty() || fiscalCode.isEmpty() || phone.isEmpty() ||
        email.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Errore di registrazione", "Riempi tutti i campi.");
        return;
    }

    //controllo corrispondenza password
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Errore di registrazione", "Le password non corrispondono.");
        return;
    }

    QMessageBox::information(this, "Registrazione completata", "Registrazione avvenuta con successo!");
    close();
}
