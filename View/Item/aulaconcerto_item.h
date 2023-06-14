#ifndef AULACONCERTO_ITEM_H
#define AULACONCERTO_ITEM_H

#include "abstact_aula.h"

namespace Item {
class aulaConcerto_item : public View::ItemEditor::abstractAula_item{
private:
    unsigned int availability;
    double price;
    //inserire solo gli elementi "in più" rispetto ad aula_abstract
public:
    aulaConcerto_item();//inserire i parametri del costruttore tutti
};
}

#endif // AULACONCERTO_ITEM_H
