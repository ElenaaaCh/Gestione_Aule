#ifndef STORAGE_H
#define STORAGE_H

#include "aula.h"
#include "prenotazione.h"

struct NodoA {
    aula* aula;
    NodoA* prec;
    NodoA* succ;
};

struct NodoPr {
    prenotazione* pren;
    NodoPr* prec;
    NodoPr* succ;
};

class storage{
private:
    NodoA* first_A;
    NodoPr* first_P;
public:
    void addAula(aula* a);
    void viewAule();
    void removeAula(aula* aula);
    aula* searchAula(const int piano, const int numero);

    void addPrenotazione(prenotazione* pr);
    void viewPrenotazioni();
    void removePrenotazione(prenotazione* pr);
    aula* searchPrenotazione(const Date& data, const aula* aulaRiferimento);
};

#endif // STORAGE_H
