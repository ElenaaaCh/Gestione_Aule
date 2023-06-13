#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "controller.h"
#include "View/login_view.h"
#include "Model/storage.h"
#include "Model/utente.h"
#include "View/menu_view.h"
#include "View/registrazione_view.h"

class LoginController : public Controller {
    Q_OBJECT
protected:
    LoginController();
public:
    LoginController(LoginWindow*, Controller* = nullptr);
public slots:
    void Login_enter(QString em, QString pass) const;
    void Label_enter() const;
    void onViewClosed() const override;
};

#endif // LOGIN_CONTROLLER_H
