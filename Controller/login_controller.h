#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "controller.h"
#include "View/login_view.h"
#include "Model/storage.h"
#include "menu_controller.h"
#include "View/menu_view.h"
#include "View/registrazione_view.h"

class LoginController : public Controller {
    Q_OBJECT
protected:
    LoginController();
public:
    LoginController(storage*, LoginWindow*, Controller* = nullptr);
public slots:
    void Login_enter(const string& em, const string& pass) const;
    void Label_enter() const;
    storage* getModel() const override;
    LoginWindow* getView() const override;
    void onViewClosed() const override;
};

#endif // LOGIN_CONTROLLER_H
