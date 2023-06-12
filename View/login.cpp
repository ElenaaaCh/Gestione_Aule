#include "login.h"
#include "registrazione.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{

    layout = new QVBoxLayout(this);

    // Aggiungi il logo
    QPixmap logo(":/Images/logo_consvi.jpeg");
    logoLabel=new QLabel();
    logoLabel->setPixmap(logo.scaledToHeight(256));
    logoLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logoLabel);

    benvenutoLabel = new QLabel();
    benvenutoLabel->setLayoutDirection(Qt::LeftToRight);
    benvenutoLabel->setText("Benvenuto!");
    benvenutoLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(benvenutoLabel);

    HLayout = new QHBoxLayout();
    layout->addLayout(HLayout);

    Vl1 = new QVBoxLayout();
    emailLabel = new QLabel();
    emailLabel->setText("Email");
    Vl1->addWidget(emailLabel);
    passwLabel = new QLabel();
    passwLabel->setText("Password");
    Vl1->addWidget(passwLabel);
    HLayout->addLayout(Vl1);

    HLayout->addStretch();

    Vl2 = new QVBoxLayout();
    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("inserire email");
    Vl2->addWidget(emailLineEdit);
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setPlaceholderText("inserire password");
    Vl2->addWidget(passwordLineEdit);
    HLayout->addLayout(Vl2);

    // Aggiungi pulsante di login
    loginButton = new QPushButton("Login", this);
    layout->addWidget(loginButton);

    // Connessione del pulsante di login al slot onLoginButtonClicked()
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);

    // Aggiungi link per la registrazione
    registerLabel = new QLabel(this);
    registerLabel->setText("<a href='register'>Non sei registrato? Registrati</a>");
    registerLabel->setAlignment(Qt::AlignRight);
    registerLabel->setTextFormat(Qt::RichText);
    registerLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    registerLabel->setOpenExternalLinks(true);
    layout->addWidget(registerLabel);

    setLayout(layout) ;
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
