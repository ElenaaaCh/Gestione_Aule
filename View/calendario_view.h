#ifndef CALENDARIO_VIEW_H
#define CALENDARIO_VIEW_H

#include "view.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QDate>

class CalendarWindow : public View {
private:
    QString aula;

public:
    explicit CalendarWindow(const QString &_aula, View *parent = nullptr);

    int getRowIndex(const QString &time);
    int getColumnIndex(const QString &date);

    QTableWidget *calendarTable;

};


#endif // CALENDARIO_VIEW_H
