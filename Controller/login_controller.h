#ifndef LOGIN_CONTROLLER_H
#define LOGIN_CONTROLLER_H

#include "controller.h"
#include "View/login_view.h"

class LoginController : public Controller {
    Q_OBJECT
protected:
    LoginController();
public:
    LoginController(LoginWindow* l, Controller* = nullptr);
    void AulaView() const;

};

#endif // LOGIN_CONTROLLER_H
