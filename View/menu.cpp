#include "menu.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout(this);

    //logo

    QLabel* benvenuto = new QLabel("Benvenuto" /*+ getNome() + " "+ getCognome() */ );
    layout->addWidget(benvenuto);

    QHBoxLayout* HLayout = new QHBoxLayout ();

    QPushButton* viewAuleButton= new QPushButton("Visualizza Aule");
    HLayout->addWidget(viewAuleButton);
    HLayout->addStretch();
    QPushButton* viewPrenButton= new QPushButton("Visualizza Prenotazioni");
    HLayout->addWidget(viewPrenButton);

    layout->addLayout(HLayout);

}
