#ifndef STORAGE_H
#define STORAGE_H

#include<iostream>
#include<vector>
#include "aula.h"
#include "prenotazione.h"
#include "utente.h"
using std::vector;

template <class T>
class contenitore{
    friend class iteratore;
    friend class iteratore_const;
private:
    class nodo{
    public:
        T info;
        nodo* next;
        nodo();
        ~nodo();
        nodo(const nodo&);
        nodo(const T&, nodo*);
    };
    nodo* head;
    static nodo* copia(nodo*);

public:
    class iteratore{
        friend class contenitore<T>;
    private:
        nodo* p;
        nodo* getNodo();
    public:
        iteratore();
        iteratore(nodo*);
        iteratore &operator++();
        iteratore &operator++(int);
        T &operator*();
        T *operator->();
        bool operator ==(const iteratore&)const;
        bool operator !=(const iteratore&)const;
    };
    class iteratore_const{
        friend class contenitore<T>;
    private:
        nodo* p;
        const nodo* getNodo() const;
    public:
        iteratore_const();
        iteratore_const(const iteratore&);
        iteratore_const(nodo*);
        iteratore_const& operator++();
        iteratore_const& operator++(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const iteratore_const&)const;
        bool operator!=(const iteratore_const&)const;
    };
    contenitore();
    contenitore(const contenitore&);
    ~contenitore();

    bool operator==(const contenitore&)const;
    bool operator!=(const contenitore&)const;
    contenitore& operator=(const contenitore&);

    void push(const T&);
    int size() const;
    void clear();
    bool contains(const T&) const;
    T& value(int _pos);
    const T& value(int _pos) const;
    void remove(int _pos);
    void remove(const T& t);
    void replace(int _pos, const T&);

    iteratore begin();
    iteratore end();
    iteratore_const begin()const;
    iteratore_const end()const;


};

/*
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

*/

#endif // STORAGE_H
