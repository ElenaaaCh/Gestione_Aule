#include "registrazione.h"

RegistrationWindow::RegistrationWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("Form di registrazione", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QHBoxLayout *HLayout = new QHBoxLayout();
    layout->addLayout(HLayout);

    QVBoxLayout *Vl1 = new QVBoxLayout();
    HLayout->addLayout(Vl1);

    QLabel *nomeLabel = new QLabel("Nome");
    QLabel *cognomeLabel = new QLabel("Cognome");
    //cognomeLabel->setText("Cognome");
    QLabel *codLabel = new QLabel();
    codLabel->setText("Codice fiscale");
    QLabel *phoneLabel = new QLabel();
    phoneLabel->setText("Numero di telefono");
    QLabel *emailLabel = new QLabel();
    emailLabel->setText("Email");
    QLabel *ruoloLabel = new QLabel();
    ruoloLabel->setText("Ruolo");
    QLabel *passwLabel = new QLabel();
    passwLabel->setText("Password");
    QLabel *cPasswLabel = new QLabel();
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

    QVBoxLayout *Vl2 = new QVBoxLayout();
    HLayout->addLayout(Vl2);

    nomeLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Inserire nome");
    cognomeLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Inserire cognome");
    codLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Inserire codice fiscale");
    phoneLineEdit = new QLineEdit(this);
    emailLineEdit->setPlaceholderText("Inserire numero di telefono");
    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("Inserire email");

    docenteRadioButton = new QRadioButton("Docente", this);
    studenteRadioButton = new QRadioButton("Studente", this);
    QHBoxLayout *roleLayout = new QHBoxLayout;
    roleLayout->addWidget(docenteRadioButton);
    roleLayout->addWidget(studenteRadioButton);

    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setPlaceholderText("Inserire password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    confirmPasswordLineEdit = new QLineEdit();
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
