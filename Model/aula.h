#ifndef AULA_H
#define AULA_H

#include<string>
using std::string;

class aula {
private:
    int piano;
    int numero;
    string sede;
    int max_persone;

public:
    aula(int _piano=0, int numero=0, string _sede="", int _max_persone=0);
    virtual ~aula() = default;
    virtual aula* clone() const = 0;

    //metodi get
    string getPiano() const;
    int getNumero() const;
    string getSede() const;
    int getMaxPersone() const;

    //metodi set
    void setPiano(const string &value);
    void setNumero(int value);
    void setSede(const string &value);
    void setMaxPersone(int value);


    virtual void aggiungi() = 0;
    virtual void modifica() = 0;
    virtual void elimina() = 0;

    /*virtual void visualizzaPrenotazioni() const = 0;
    virtual bool prenota(const std::string& email, const std::string& orarioArrivo, const std::string& orarioUscita) = 0;
*/
};

#endif // AULA_H

