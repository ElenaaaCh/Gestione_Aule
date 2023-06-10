#include "login.h"

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

    // Aggiungi link per la registrazione
    QLabel *registerLabel = new QLabel(this);
    registerLabel->setText("<a href='register'>Non sei registrato? Registrati</a>");
    registerLabel->setTextFormat(Qt::RichText);
    registerLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    registerLabel->setOpenExternalLinks(true);
    layout->addWidget(registerLabel);
}
