#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <Model/prenotazione.h>
#include <Model/contenitore.h>

using std::string;

enum tipoutente{Studente=0, Docente=1};

class utente{
private:
    string nome;
    string cognome;
    string codiceFiscale;
    string telefono;
    string email;
    tipoutente persona;
    contenitore<prenotazione> prenotazioni;

public:
    utente(string _nome="", string _cognome="", string _codiceFiscale="", string _telefono="", string _email="", tipoutente _tipo=Studente);
    virtual ~utente() = default;
    virtual utente* clone() const = 0;
    virtual tipoutente getTipoUtente() const = 0; //????

    string getNome() const;
    void setNome(const string &value);
    string getCognome() const;
    void setCognome(const string &value);
    string getCodiceFiscale() const;
    void setCodiceFiscale(const string &value);
    string getTelefono() const;
    void setTelefono(const string &value);
    string getEmail() const;
    void setEmail(const string &value);

    contenitore<prenotazione> getPrenotazione() const;
    void setPrenotazioni(const contenitore<prenotazione> &_listaPrenotazioni);
    void addPrenotazione(const prenotazione &_pr);
    void removePrenotazione(const prenotazione &_pr);

};


#endif // UTENTE_H
