#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "controller.h"
#include "View/menu_view.h"
#include "Model/storage.h"
class MenuController : public Controller {
    Q_OBJECT
protected:
    MenuController();
public:
    MenuController(storage* , MenuWindow* , Controller* = nullptr);
    void AulaView() const;
    void PrenView() const;
    storage* getModel() const override;
    MenuWindow* getView() const override;
public slots:
    void onViewClosed() const override;
};

#endif // MENU_CONTROLLER_H
