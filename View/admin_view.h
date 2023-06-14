#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "view.h"
#include "Item/abstact_aula.h"
#include <QGridLayout>

class AdminWindow: public View {
    Q_OBJECT
private:
    QPushButton* previous_page;
    QPushButton* next_page;
    //QVector<WidgetLookup> lookup;
    QGridLayout* grid;
    //ResultRenderer::IResultRendererStrategy* renderer;

public:
    explicit AdminWindow(const QSize& s, View *parent = nullptr);

signals:
    void aggiornaPagina_signal();
    void addAConcerto_signal();
    void addAStrumentale_signal();
    void addAStudio_signal();
    void showAula(const abstractAula_item* aula);
    void modificaAula_signal(const abstractAula_item* aula);
    void eliminaAula_signal(const abstractAula_item* aula);
};

#endif // ADMIN_VIEW_H
