#include "menu_controller.h"

MenuController::MenuController(MenuWindow * m, Controller* c) : Controller(m, c){
    connect(view,SIGNAL(View_aule_signal()),this,SLOT(AulaView()));
    connect(view,SIGNAL(View_pren_signal()),this,SLOT(PrenView()));
}

void MenuController::AulaView() const {

}
