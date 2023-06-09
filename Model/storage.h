#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>
#include<vector>
#include "aula.h"
#include "prenotazione.h"
#include "utente.h"
using std::vector;

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
    vector<utente*>pers;
public:
    storage(NodoA*, NodoPr*, vector<utente*> );//costr
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
    void removeUtente(const string& nome, const string& cognome);
    void modifyUtente(const string& nome, const string& cognome, const string& nuovoTelefono, const string& nuovaEmail);
};



#endif // STORAGE_H
