#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "View/view.h"

class Controller : public QObject {
    Q_OBJECT

protected:
    View* view;
    Controller();
public:
    Controller (View*, Controller* = nullptr);
    virtual ~Controller();
};

#endif // CONTROLLER_H
