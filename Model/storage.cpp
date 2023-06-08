#include "storage.h"

void storage::addAula(aula* a) {
    NodoA* nuovoNodo = new NodoA;
    nuovoNodo->aula = a;
    nuovoNodo->prec = nullptr;
    nuovoNodo->succ = nullptr;

    //lista vuota
    if (first_A == nullptr) {
        first_A = nuovoNodo;
    } else {
        NodoA* nodoCorr = first_A;
        NodoA* nodoPrec = nullptr;

        while (nodoCorr != nullptr && (nodoCorr->aula->getPiano() < nuovoNodo->aula->getPiano() ||
                                           (nodoCorr->aula->getPiano() == nuovoNodo->aula->getPiano() &&
                                            nodoCorr->aula->getNumero() < nuovoNodo->aula->getNumero()))) {
            nodoPrec = nodoCorr;
            nodoCorr = nodoCorr->succ;
        }

        if (nodoPrec == nullptr) {
            // Inserimento in testa
            nuovoNodo->succ = first_A;
            first_A->prec = nuovoNodo;
            first_A = nuovoNodo;
        } else {
            // Inserimento tra due nodi o in coda
            nuovoNodo->succ = nodoCorr;
            nuovoNodo->prec = nodoPrec;
            nodoPrec->succ = nuovoNodo;

            if (nodoCorr!= nullptr) {
                nodoCorr->prec = nuovoNodo;
            }
        }
    }
}

void storage::viewAule() {
    NodoA* nodoCorr = first_A;
    while (nodoCorr != nullptr) {

        // Stampa i dati dell'aula, conviene collegare tale funzione a un file di grafica qt??

        nodoCorr = nodoCorr->succ;
    }
}

void storage::removeAula(aula* aula) {
    NodoA* corr = first_A;

    while (corr != nullptr) {
        if (corr->aula == aula) {
            if (corr->prec != nullptr) {
                corr->prec->succ = corr->succ;
            } else {
                first_A = corr->succ;
            }

            if (corr->succ != nullptr) {
                corr->succ->prec = corr->prec;
            }

            delete corr;
            break;
        }
        corr = corr->succ;
    }
}

aula* storage::searchAula(const int piano, const int numero) {
    NodoA* corr = first_A;

    while (corr != nullptr) {
        aula* a = corr->aula;
        if (a->getPiano() == piano && a->getNumero() == numero) {
            return a;
        }
        corr = corr->succ;
    }
    return nullptr; // Aula non trovata
}

void storage::addPrenotazione(prenotazione* pr) {
    NodoPr* nuovoNodo = new NodoPr;
    nuovoNodo->pren = pr;
    nuovoNodo->prec = nullptr;
    nuovoNodo->succ = nullptr;

    //lista vuota
    if (first_P == nullptr) {
        first_P = nuovoNodo;
    } else {
        NodoPr* nodoCorr = first_P;
        NodoPr* nodoPrec = nullptr;

        while (nodoCorr != nullptr && (nodoCorr->pren->getData() < nuovoNodo->pren->getData() ||
                                       (nodoCorr->pren->getData() == nuovoNodo->pren->getData() &&
                                        nodoCorr->pren->getOraArrivo() < nuovoNodo->pren->getOraArrivo()))) {
            nodoPrec = nodoCorr;
            nodoCorr = nodoCorr->succ;
        }

        if (nodoPrec == nullptr) {
            // Inserimento in testa
            nuovoNodo->succ = first_P;
            first_P->prec = nuovoNodo;
            first_P = nuovoNodo;
        } else {
            // Inserimento tra due nodi o in coda
            nuovoNodo->succ = nodoCorr;
            nuovoNodo->prec = nodoPrec;
            nodoPrec->succ = nuovoNodo;

            if (nodoCorr!= nullptr) {
                nodoCorr->prec = nuovoNodo;
            }
        }
    }
}

void storage::viewPrenotazioni() {
    NodoPr* nodoCorr = first_P;
    while (nodoCorr != nullptr) {

        // Stampa i dati dell'aula, conviene collegare tale funzione a un file di grafica qt??

        nodoCorr = nodoCorr->succ;
    }
}

void storage::removePrenotazione(prenotazione* pr) {
    NodoPr* corr = first_P;

    while (corr != nullptr) {
        if (corr->pren == pr) {
            if (corr->prec != nullptr) {
                corr->prec->succ = corr->succ;
            } else {
                first_P = corr->succ;
            }

            if (corr->succ != nullptr) {
                corr->succ->prec = corr->prec;
            }

            delete corr;
            break;
        }
        corr = corr->succ;
    }
}

prenotazione* storage::searchPrenotazione(const QDate& data, const aula* aulaRiferimento) {
    NodoPr* nodoCorr = first_P;

    while (nodoCorr != nullptr) {
        if (nodoCorr->pren->getData() == data && nodoCorr->pren->getAula() == aulaRiferimento) {
            return nodoCorr->pren;  // La prenotazione è stata trovata
        }

        nodoCorr = nodoCorr->succ;
    }

    return nullptr;  // La prenotazione non è stata trovata
}


