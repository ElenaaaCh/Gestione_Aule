#include "aulaStrumentale.h"

//impl. costruttore
aulaStrumentale::aulaStrumentale(string _piano, int _numero, string _sede, int _max_persone, const string& _strumento)
    : aula(_piano, _numero, _sede, _max_persone), strumento(_strumento) {}


const string& aulaStrumentale::getStrumento() const { return strumento; }


void aulaStrumentale::aggiungi() {
    //
}

void aulaStrumentale::modifica() {
    // 
}

void aulaStrumentale::elimina() {
    // 
}

/*
// Implementazione del metodo visualizzaPrenotazioni di AulaStrumentale
void AulaStrumentale::visualizzaPrenotazioni() const {
    // Implementazione della visualizzazione delle prenotazioni per l'aula strumentale
}

bool AulaStrumentale::prenota(const std::string& email, const std::string& orarioArrivo, const std::string& orarioUscita) {
    // Implementa la logica di prenotazione specifica per l'aula strumentale
    // ...

    return true;
}
*/
