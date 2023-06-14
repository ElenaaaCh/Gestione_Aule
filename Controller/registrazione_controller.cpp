#include "registrazione_controller.h"

RegController::RegController(RegistrationWindow * r, Controller* c) : Controller(r, c){
    connect(view,SIGNAL(Reg_signal(em, pass)),this,SLOT(Registr_enter(_nome, _cognome)));
}

void RegController::Registr_enter(QString _nome, QString _cogn) const {

    //CLICCANDO SU REGISTRA deve inserire gli argomenti passati nel vettore<utenti> pers in storage
    // + controllare che la mail non sia già presente (utente già esistente)

    // e aprire la scheda di login
    LoginWindow* logW =new LoginWindow();
    logW->show();
    hide();
}

void RegController::onViewClosed() const {
    delete this;
}
