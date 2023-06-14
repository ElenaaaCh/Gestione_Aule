#include "admin_view.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

AdminWindow::AdminWindow(const QSize& s, View* parent) : View(s, parent)
{
    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* titolo = new QLabel("ADMIN", this);
    vbox->addWidget(titolo);
    vbox->addStretch();

    QPushButton* new_aulaConcerti = new QPushButton ("Nuova aula concerto", this);
    QPushButton* new_aulaStrumentale = new QPushButton ("Nuova aula strumentale", this);
    QPushButton* new_aulaStudio = new QPushButton ("Nuova aula studio", this);
    vbox->addWidget(new_aulaConcerti);
    vbox->addWidget(new_aulaStrumentale);
    vbox->addWidget(new_aulaStudio);
    hbox->addLayout(vbox);

    //non so esattamente a cosa serva
    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    hbox->addWidget(scroll_area);

 //l'idea è quella di inserire nella scroll_area le varie aule tramite un for...per visualizzarle tutte

}

//MI SERVE SOLO COME SPUNTO!!!
/*void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results) {
    // Clears previous data
    while (!lookup.isEmpty()) {
        WidgetLookup info = lookup.takeLast();
        delete info.getWidget();
    }

    // Shows new data
    if (results.getTotal() > 0) {
        results_total->setText(QString::number(results.getTotal()) + " results for \"" + QString::fromStdString(query.getText()) + "\":");
    }
    else {
        results_total->setText("No results for \"" + QString::fromStdString(query.getText()) + "\".");
    }
    previous_page->setEnabled(query.getOffset() > 0);
    next_page->setEnabled(results.getItems().size() == query.getSize());
    renderer->render(grid, results, &lookup);

    // Connects signals
    for (
        QVector<WidgetLookup>::const_iterator it = lookup.begin();
        it != lookup.end();
        it++
        ) {
        if (it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, std::bind(&ResultsWidget::editItem, this, it->getItem()));
        }
        if (it->getDeleteButton()) {
            connect(it->getDeleteButton(), &QPushButton::clicked, std::bind(&ResultsWidget::deleteItem, this, it->getItem()));
        }
    }
}
*/
