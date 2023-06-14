#ifndef ABSTACT_AULA_H
#define ABSTACT_AULA_H

#include <QWidget>
#include <QString>

#include "../../Model/aula.h"

class abstractAula_item: public QWidget {
    Q_OBJECT
public:
    abstractAula_item(QWidget* parent = 0);
    virtual ~abstractAula_item();
    virtual aula* create(
        int _piano=0,
        int numero=0,
        string _sede="",
        int _max_persone=0
        ) const = 0;
};

#endif // ABSTACT_AULA_H
