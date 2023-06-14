#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "controller.h"
#include "View/menu_view.h"

class MenuController : public Controller {
    Q_OBJECT
protected:
    MenuController();
public:
    MenuController(MenuWindow*, Controller* = nullptr);
    void AulaView() const;
    void PrenView() const;
};

#endif // MENU_CONTROLLER_H
