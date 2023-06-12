#include "login.h"
#include "registrazione.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Aggiungi il logo
    QPixmap logo(":/Images/logo_consvi.jpeg");
    logoLabel=new QLabel();
    logoLabel->setPixmap(logo.scaledToHeight(256));
    logoLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logoLabel);

    QLabel *benvenutoLabel = new QLabel();
    benvenutoLabel->setLayoutDirection(Qt::LeftToRight);
    benvenutoLabel->setText("Benvenuto!");
    benvenutoLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(benvenutoLabel);

    QHBoxLayout *HLayout = new QHBoxLayout();
    layout->addLayout(HLayout);

    QVBoxLayout *Vl1 = new QVBoxLayout();
    HLayout->addLayout(Vl1);

    QLabel *emailLabel = new QLabel();
    emailLabel->setText("Email");
    Vl1->addWidget(emailLabel);
    QLabel *passwLabel = new QLabel();
    passwLabel->setText("Password");
    Vl1->addWidget(passwLabel);

    HLayout->addStretch();

    QVBoxLayout *Vl2 = new QVBoxLayout();
    HLayout->addLayout(Vl2);

    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("inserire email");
    Vl2->addWidget(emailLineEdit);
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setPlaceholderText("inserire password");
    Vl2->addWidget(passwordLineEdit);

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
