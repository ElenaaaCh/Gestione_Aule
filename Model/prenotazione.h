#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include "aula.h"
#include <string>
#include<QDate>

using std::string;

class prenotazione{
private:
    string email;
    QDate data;
    int oraArrivo;
    int oraUscita;
    string causale;
    aula* aula_pr;

public:
    prenotazione(string _email="", int _oraArrivo=0, int _oraUscita=0, string _causale="");
    ~prenotazione() = default;
    bool operator==(const prenotazione&)const;
    bool operator!=(const prenotazione&)const;
    
    string getEmail() const;
    //data
    int getOraArrivo() const;
    int getOraUscita() const;
    string getCausale() const;

    void setEmail(const string &value);
    //data
    void setOraArrivo(int value);
    void setOraUscita(int value);
    void setCausale(const string &value);
};

#endif // PRENOTAZIONE_H
