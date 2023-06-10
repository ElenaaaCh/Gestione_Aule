#include "login.h"
#include "registrazione.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Aggiungi il logo
    QPixmap logo(":/Images/logo_consvi.jpeg");
    QLabel *logoLabel = new QLabel(this);
    logoLabel->setPixmap(logo);
    logoLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logoLabel);

    // Aggiungi campi di testo per email e password
    emailLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    layout->addWidget(emailLineEdit);
    layout->addWidget(passwordLineEdit);

    // Aggiungi pulsante di login
    QPushButton *loginButton = new QPushButton("Login", this);
    layout->addWidget(loginButton);

    // Connessione del pulsante di login al slot onLoginButtonClicked()
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    // Aggiungi link per la registrazione
    QLabel *registerLabel = new QLabel(this);
    registerLabel->setText("<a href='register'>Non sei registrato? Registrati</a>");
    registerLabel->setTextFormat(Qt::RichText);
    registerLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    registerLabel->setOpenExternalLinks(true);
    layout->addWidget(registerLabel);
}

void LoginWindow::onLoginButtonClicked()
{
    // Effettua l'elaborazione del login
    QString email = emailLineEdit->text();
    QString password = passwordLineEdit->text();

    // Esempio di controllo delle credenziali
    if (email == "user@example.com" && password == "password") {
        // Login riuscito, passa alla finestra successiva
        RegistrationWindow *registrationWindow = new RegistrationWindow();
        registrationWindow->show();
        close(); // Chiude la finestra di login
    } else {
        // Login non valido, mostra un messaggio di errore
        QMessageBox::warning(this, "Login fallito", "Credenziali non valide. Riprova.");
    }
}
