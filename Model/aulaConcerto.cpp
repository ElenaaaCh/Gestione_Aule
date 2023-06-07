#include "aulaConcerto.h"

// Impl. costruttore di AulaConcerto
aulaConcerto::aulaConcerto(string _piano, int _numero, string _sede, int _max_persone, const string& _strumento, int _capienza, bool _amplificazione )
    : aula(_piano, _numero, _sede, _max_persone), strumento(_strumento), capienza(_capienza), amplificazione(_amplificazione) {}

aulaConcerto* aulaConcerto::clone() const{
    return new aulaConcerto(*this);
}

const string& aulaConcerto::getStrumento() const { return strumento; }
int aulaConcerto::getCapienza() const { return capienza; }
bool aulaConcerto::getAmplificazione() const { return amplificazione; }

void aulaConcerto::aggiungi() {
    // 
}

void aulaConcerto::modifica() {
    // 
}

void aulaConcerto::elimina() {
    // 
}