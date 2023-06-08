#include "Model/utente.h"

string utente::getNome() const { return nome; }
void utente::setNome(const string &value) { 
    nome=value; 
}
string utente::getCognome() const { return cognome; }
void utente::setCognome(const string &value){
    cognome=value;
}
string utente::getCodiceFiscale() const { return codiceFiscale; }
void utente::setCodiceFiscale(const string &value){
    codiceFiscale=value;
}
string utente::getTelefono() const { return telefono; }
void utente::setTelefono(const string &value){
    telefono=value;
}
string utente::getEmail() const { return email; }
void utente::setEmail(const string &value){
    email=value;
}
