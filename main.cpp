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

    RegistrationWindow* r= new RegistrationWindow(QSize(500,500),nullptr);
    r->show();
*/
    return QApplication::exec();

}
