#include<QApplication>
#include<QMessageBox>
#include<QDebug>
#include<QObject>
//#include "View/login.h"
//#include "View/registrazione_view.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*LoginWindow* l = new LoginWindow();
    l->show();

    RegistrationWindow* r= new RegistrationWindow();
    r->show();
*/
    return QApplication::exec();

}
