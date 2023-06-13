#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "View/view.h"

class Controller : public QObject {
    Q_OBJECT

protected:
    View* view;
    Controller();
public:
    Controller (View*, Controller* = nullptr);
    virtual ~Controller();
    void show() const;
    void hide() const;

public slots:
    virtual void onViewClosed() const=0 ;
    virtual void onBack() const;
};

#endif // CONTROLLER_H
