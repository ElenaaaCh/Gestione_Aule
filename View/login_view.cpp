#include "login_view.h"

LoginWindow::LoginWindow(const QSize& s, View* parent) : View(s, parent) {

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
    connect(loginButton,SIGNAL(clicked(bool)),this,SLOT(onLoginButtonClicked()));

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

void LoginWindow::onLoginButtonClicked(){
    //controlli base, gli altri vanno fatti sul login_controller
    QString email = emailLineEdit->text();
    QString password = passwordLineEdit->text();

    if(email.isEmpty() || password.isEmpty()){
        static_cast<View*>(this)->showError("Inserimento errato", "Il valore inserito non è permesso");
    } else {
        //emit Login_valido(email, password);
    }
}
