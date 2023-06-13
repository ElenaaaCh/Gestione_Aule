#include "login_controller.h"

LoginController::LoginController(LoginWindow * l, Controller* c) : Controller(l, c){
    connect(view,SIGNAL(Login_signal(em, pass)),this,SLOT(Login_enter(em, pass)));
}

void LoginController::Login_enter(QString em, QString pass) const {
    bool find=1;
    foreach(auto it: pers){
        if(it->getEmail==em){ //trova corrispondenza email nello storage
            find=0;
            if(it->getPassword==pass){ //controllo correttezza password
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

void LoginController::onViewClosed() const {
    delete this;
}
