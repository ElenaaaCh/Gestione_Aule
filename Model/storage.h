#ifndef STORAGE_H
#define STORAGE_H

#include<vector>
#include "aula.h"
#include "prenotazione.h"
#include "utente.h"

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
    std::vector<utente*>pers;
public:
    storage();//costr
    ~storage();//distr
    void addAula(aula* a);
    void viewAule();
    void removeAula(aula* aula);
    aula* searchAula(const int piano, const int numero);

    void addPrenotazione(prenotazione* pr);
    void viewPrenotazioni();
    void removePrenotazione(prenotazione* pr);
    prenotazione* searchPrenotazione(const QDate& data, const aula* aulaRiferimento);

    void addUtente(utente* ut);

};



#endif // STORAGE_H
