#include "admin_view.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>

AdminWindow::AdminWindow(const QSize& s, View* parent) : View(s, parent)
{
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout* hbox = new QHBoxLayout();
    hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    vbox->addLayout(hbox);

    QLabel* titolo = new QLabel("ADMIN", this);
    hbox->addWidget(titolo);

    hbox->addStretch();

    previous_page = new QPushButton(QIcon(QPixmap("Images/previous.svg")), "");
    previous_page->setEnabled(false);
    hbox->addWidget(previous_page);

    next_page = new QPushButton(QIcon(QPixmap("Images/previous.svg")), "");
    next_page->setEnabled(false);
    hbox->addWidget(next_page);

    QVBoxLayout* sinistra = new QVBoxLayout();
    QPushButton* new_aulaConcerti = new QPushButton ("Nuova aula concerto", this);
    QPushButton* new_aulaStrumentale = new QPushButton ("Nuova aula strumentale", this);
    QPushButton* new_aulaStudio = new QPushButton ("Nuova aula studio", this);
    sinistra->addWidget(new_aulaConcerti);
    sinistra->addWidget(new_aulaStrumentale);
    sinistra->addWidget(new_aulaStudio);
    vbox->addLayout(sinistra);

    grid = new QGridLayout();
    grid->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(grid);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    vbox->addWidget(scroll_area);


    // Connects signals
    connect(previous_page, &QPushButton::clicked, this, &ResultsWidget::previousPage);
    connect(next_page, &QPushButton::clicked, this, &ResultsWidget::nextPage);

}

void ResultsWidget::showResults(Engine::Query query, Engine::ResultSet results) {
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
