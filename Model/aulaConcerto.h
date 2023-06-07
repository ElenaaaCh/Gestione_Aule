#ifndef AULACONCERTO_H
#define AULACONCERTO_H

#include <Model/aula.h>

class aulaConcerto : public aula {
private:
    string strumento;
    int capienza;
    bool amplificazione; //0=false, 1=true

public:
    aulaConcerto(string _piano="", int _numero=0, string _sede="", int _max_persone=0, const string& _strumento="", int _capienza=0, bool _amplificazione=0 );
    ~aulaConcerto() = default;
    virtual aulaConcerto* clone() const override;

    const string& getStrumento() const;
    int getCapienza() const;
    bool getAmplificazione() const;

    void aggiungi() override;
    void modifica() override;
    void elimina() override;
};

#endif