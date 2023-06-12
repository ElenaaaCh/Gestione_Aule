#ifndef MENU_H
#define MENU_H

#include <QtWidgets>
#include <QLabel>

class MenuWindow : public QWidget {
    Q_OBJECT

public:
    MenuWindow(QWidget *parent = nullptr);

private slots:
    void onViewAuleButtonClicked();
    void onViewPrenButtonClicked();

private:
    QLabel* logoLabel;
};

#endif // MENU_H
