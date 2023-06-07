#ifndef AULASTUDIO_H
#define AULASTUDIO_H

#include <Model/aula.h>

class aulaStudio : public aula {
private:
    int leggii;
    int prese_corrente;

public:
    aulaStudio(string _piano="", int _numero=0, string _sede="", int _max_persone=0, int _leggii=0, int _prese_corrente=0);
    int getLeggii() const;
    int getPreseCorrente() const;

    void aggiungi() override;
    void modifica() override;
    void elimina() override;

    //void visualizzaPrenotazioni() const override;
    //bool prenota(const string& email, const string& orarioArrivo, const string& orarioUscita);
};

#endif