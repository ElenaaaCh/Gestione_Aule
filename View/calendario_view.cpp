#include "calendario_view.h"


CalendarWindow::CalendarWindow(const QString &aula, View *parent) : View(parent), aula(aula) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    calendarTable = new QTableWidget(this);
    layout->addWidget(calendarTable);


    for (const Prenotazione &prenotazione : prenotazioni) {
        int row_index = getRowIndex(prenotazione.oraArrivo);
        int column_index = getColumnIndex(prenotazione.data_prenotazione);
        QTableWidgetItem *item = new QTableWidgetItem(QString("%1 %2").arg(prenotazione.nome, prenotazione.cognome));
        item->setBackground(Qt::green);  // Imposta il colore di sfondo per indicare l'occupazione
        calendarTable->setItem(row_index, column_index, item);
    }
};

int CalendarWindow::getRowIndex(const QString &time) {
    QStringList time_parts = time.split(':');
    int hour = time_parts[0].toInt();
    int minute = time_parts[1].toInt();

    // Verifica se l'ora è compresa tra 9:00 e 19:00
    if (hour < 9 || hour > 19) {
        return -1; // Non visualizzare le ore al di fuori dell'intervallo desiderato
    }

    // Calcola l'indice delle righe
    int adjusted_hour = hour - 9; // Considera solo le ore da 9:00
    int row_index = adjusted_hour * 2; // Ogni ora viene divisa in mezz'ora
    if (minute >= 30) {
        row_index++; // Se il minuto è maggiore o uguale a 30, considera la mezz'ora successiva
    }

    return row_index;
}


int CalendarWindow::getColumnIndex(const QString &date) {
    QDate qdate = QDate::fromString(date, "yyyy-MM-dd");
    int day_of_week = qdate.dayOfWeek();
    return day_of_week - 1;
}
