#include "login_controller.h"

LoginController::LoginController(storage* s, LoginWindow * l, Controller* c) : Controller(s, l, c){
    connect(view,SIGNAL(Login_signal(em, pass)),this,SLOT(Login_enter(em, pass)));
}
 storage* LoginController::getModel()const {
    return static_cast<storage*>(mod);
}

 LoginWindow* LoginController::getView() const{
    return static_cast<LoginWindow*>(view) ;
}
 void LoginController::onViewClosed() const {
    delete this;
 }

void LoginController::Login_enter(const string& em, const string& pass) const {
    bool find=1;
    for(auto it: getModel()->getUtente()){
        if(it->getEmail()==em){ //trova corrispondenza email nello storage
            find=0;
            if(it->getPassword()==pass){ //controllo correttezza password
                //MANCA IL CONTROLLO SUL UTENTE VS ADMIN PER LA VISUALIZZAZIONE DELLA RELATIVA SCHEDA
                MenuWindow* menuW = new MenuWindow(QSize(300,400), view);
                menuW->show();
                MenuController* menuC = new MenuController(mod , menuW , const_cast<LoginController*>(this));
                menuC->show();
                hide();
            }
            else{
                view->showError("Errore","Password errata");
            }
        }
    }
    if(find==1){
        view->showError("Errore","Email errata");
    }
}

void LoginController::Label_enter() const {
    RegisterWindow* regW =new regW();
    regW->show();
    hide();
}


