#include "aulaStudio.h"

// Implementazione del costruttore di AulaStudio
aulaStudio::aulaStudio(string _piano, int _numero, string _sede, int _max_persone, int _leggii, int _prese)
    : aula(_piano, _numero, _sede, _max_persone), leggii(_leggii), prese_corrente(_prese) {
}


int aulaStudio::getLeggii() const { return leggii; }
int aulaStudio::getPreseCorrente() const { return prese_corrente; }


void aulaStudio::aggiungi() {
    // 
}

void aulaStudio::modifica() {
    // 
}

void aulaStudio::elimina() {
    // 
}

/*
// Implementazione del metodo visualizzaPrenotazioni di AulaStudio
void aulaStudio::visualizzaPrenotazioni() const {
    // Implementazione della visualizzazione delle prenotazioni per l'aula studio
}

bool AulaStudio::prenota(const std::string& email, const std::string& orarioArrivo, const std::string& orarioUscita) {
    // Implementa la logica di prenotazione specifica per l'aula studio
    // ...

    return true;
}
*/


