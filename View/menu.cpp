#include "menu.h"

MenuWindow::MenuWindow(const QSize & s, View * parent)
    : View(s,parent)
{
    layout = new QVBoxLayout(this);

    //logo

    benvenuto = new QLabel("Benvenuto" /*+ getNome() + " "+ getCognome() */ );
    layout->addWidget(benvenuto);

    HLayout = new QHBoxLayout();
    viewAuleButton= new QPushButton("Visualizza Aule");
    HLayout->addWidget(viewAuleButton);
    HLayout->addStretch();
    viewPrenButton= new QPushButton("Visualizza Prenotazioni");
    HLayout->addWidget(viewPrenButton);

    layout->addLayout(HLayout);

    // Connessione del pulsante allo slot
    connect(viewAuleButton, &QPushButton::clicked, this, &MenuWindow::onViewAuleButtonClicked);
    connect(viewPrenButton, &QPushButton::clicked, this, &MenuWindow::onViewPrenButtonClicked);
}

void MenuWindow::closeEvent(QCloseEvent *event){
    if(QMessageBox::question(this,QObject::tr("Uscita"),QObject::tr("Vuoi uscire davvero?"),QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes){
        event->accept();
        emit viewClosed();
    }
    else
        event->ignore();
}
