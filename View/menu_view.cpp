#include "menu_view.h"

MenuWindow::MenuWindow(const QSize & s, View * parent) : View(s,parent) {

    layout = new QVBoxLayout(this);

    //logo
    QPixmap logo(":/Images/logo_consvi.svg");
    logoLabel=new QLabel(this);
    logoLabel->setPixmap(logo.scaledToHeight(256));
    logoLabel->setAlignment(Qt::AlignHCenter);
    layout->addWidget(logoLabel);

    benvenuto = new QLabel("Benvenuto!", this);
    benvenuto->setAlignment(Qt::AlignCenter);
    layout->addWidget(benvenuto);
    QLabel* ut = new QLabel ("Accesso effettuato come ...", this);
    layout->addWidget(ut);
    layout->addStretch();
    HLayout = new QHBoxLayout(this);
    viewAuleButton= new QPushButton("Visualizza \nAule", this);
    HLayout->addWidget(viewAuleButton);
    HLayout->addStretch();
    viewPrenButton= new QPushButton("Visualizza \nPrenotazioni", this);
    HLayout->addWidget(viewPrenButton);

    layout->addLayout(HLayout);
    layout->addStretch();
    // Connessione del pulsante allo slot
    connect(viewAuleButton,SIGNAL(clicked(bool)),this,SLOT(onViewAuleButtonClicked()));
    connect(viewPrenButton,SIGNAL(clicked(bool)),this,SLOT(onViewPrenButtonClicked()));
}

void MenuWindow::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,"Uscita","Vuoi uscire davvero?",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
