#include "storage.h"
#include "aula.h"
#include "prenotazione.h"

contenitore<aula> auleContainer;
contenitore<prenotazione> prenotazioniContainer;

// Aggiungi aule al contenitore
aula aula1(1, 101, "Sede A", 50);
aula aula2(2, 201, "Sede B", 30);
auleContainer.push(aula1);
auleContainer.push(aula2);

// Aggiungi prenotazioni al contenitore
prenotazione prenotazione1(&utente1, 9, 12, "Lezione", &aula1);
prenotazione prenotazione2(&utente2, 14, 16, "Prova", &aula2);
prenotazioniContainer.push(prenotazione1);
prenotazioniContainer.push(prenotazione2);

// Accesso agli elementi del contenitore
for (contenitore<aula>::iteratore it = auleContainer.begin(); it != auleContainer.end(); ++it) {
    aula& a = *it;
    // Esegui le operazioni desiderate sull'aula
    // ...
}

for (contenitore<prenotazione>::iteratore it = prenotazioniContainer.begin(); it != prenotazioniContainer.end(); ++it) {
    prenotazione& p = *it;
    // Esegui le operazioni desiderate sulla prenotazione
    // ...
}
