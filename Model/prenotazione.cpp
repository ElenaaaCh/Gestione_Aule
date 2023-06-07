#include "prenotazione.h"

prenotazione::prenotazione(string _email, int _oraArrivo, int _oraUscita, string _causale)
: email(_email), oraArrivo(_oraArrivo), oraUscita(_oraUscita), causale(_causale){};


bool prenotazione::operator==(const prenotazione &_pr) const{
    return (_pr.email==email && _pr.oraArrivo==oraArrivo && _pr.oraUscita==oraUscita && _pr.causale==causale);
}

bool prenotazione::operator!=(const prenotazione &_pr) const{
    return !(*this==_pr);
}

//impl metodi get
string prenotazione::getEmail() const { return email; };
    //data
int prenotazione::getOraArrivo() const { return oraArrivo; };
int prenotazione::getOraUscita() const { return oraUscita; };
string prenotazione::getCausale() const { return causale; };

//impl metodi set
void prenotazione::setEmail(const string &value){
    email=value;
}
    //data
void prenotazione::setOraArrivo(int value){
    oraArrivo=value;
}
void prenotazione::setOraUscita(int value){
    oraUscita=value;
}
void prenotazione::setCausale(const string &value){
    causale=value;
}
