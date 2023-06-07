#ifndef AULASTRUMENTALE_H
#define AULASTRUMENTALE_H

#include <Model/aula.h>

class aulaStrumentale : public aula {
private:
    string strumento;

public:
    aulaStrumentale(string _piano="", int _numero=0, string _sede="", int _max_persone=0, const string& _strumento="");
    const string& getStrumento() const;

    void aggiungi() override;
    void modifica() override;
    void elimina() override;

    //void visualizzaPrenotazioni() const override;
    //bool prenota(const std::string& email, const std::string& orarioArrivo, const std::string& orarioUscita);

};

#endif