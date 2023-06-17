#ifndef AULASTUDIO_ITEM_H
#define AULASTUDIO_ITEM_H

#include "abstact_aula.h"
#include"Model/aulaStudio.h"
#include <QWidget>

class aulastudio_item:public abstractAula_item
{
private:
    int leggii;
    int prese_corrente;
public:
    aulastudio_item();
};

#endif // AULASTUDIO_ITEM_H
