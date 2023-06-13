#include "login_controller.h"

LoginController::LoginController(LoginWindow * l, Controller* c) : Controller(m, c){
    connect(view,SIGNAL(Login_signal()),this,SLOT(Login_enter()));
}

void LoginController::Login_enter() const {
    foreach(auto it: utenti){
        email=it->getEmail;
        if(email=="mailpassata"){ //la mail passata esiste
            if(it->getPassword=="passwordpassata"){ //controllo correttezza password
                MenuWindow* menuW = new MenuWindow;
                menuW->show();
                MenuController* menuC = new MenuController();
                menuC->show();
                hide();
            }
            else{
                view->showError("Errore","Password errata");
            }
        }
        else{
            view->showError("Errore","Email errata");
        }
    }
}
