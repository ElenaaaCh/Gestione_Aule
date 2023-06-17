#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include "Model/model.h"
#include "View/view.h"

class Controller : public QObject {
    Q_OBJECT

protected:
    model* mod;
    View* view;
    explicit Controller(); //costr
public:
    Controller (model*, View*, Controller* = nullptr); //costr
    virtual ~Controller();
    virtual  model* getModel() const=0;
    virtual  View* getView() const=0;
    void show() const;
    void hide() const;

public slots:
    virtual void onViewClosed() const=0 ;
    //virtual void onBack() const;
};

#endif // CONTROLLER_H
