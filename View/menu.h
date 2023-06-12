#ifndef MENU_H
#define MENU_H

#include "view.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QObject>

class MenuWindow : public View {
    Q_OBJECT
private:
    QVBoxLayout *layout;
    QLabel* logoLabel;
    QLabel* benvenuto;
    QHBoxLayout* HLayout;
    QPushButton* viewAuleButton;
    QPushButton* viewPrenButton;

protected:
    explicit MenuWindow();//costr

public:
    MenuWindow(const QSize&, View*);
    void closeEvent(QCloseEvent *event) override;

public slots:
    void onViewAuleButtonClicked();
    void onViewPrenButtonClicked();
};

#endif // MENU_H
