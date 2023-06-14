#ifndef ADMIN_VIEW_H
#define ADMIN_VIEW_H

#include "view.h"

class ResultsWidget: public View {
    Q_OBJECT
private:
    QLabel* results_total;
    QPushButton* previous_page;
    QPushButton* next_page;
    QVector<WidgetLookup> lookup;
    QGridLayout* grid;
    ResultRenderer::IResultRendererStrategy* renderer;

public:
    explicit ResultsWidget(QWidget* parent = 0);

signals:
    void refreshResults();
    void previousPage();
    void nextPage();
    void showItem(const Item::AbstractItem* item);
    void editItem(const Item::AbstractItem* item);
    void deleteItem(const Item::AbstractItem* item);

public slots:
    void showResults(Engine::Query query, Engine::ResultSet results);
    void setListRenderer();
    void setGridRenderer();
};

}

#endif // ADMIN_VIEW_H
