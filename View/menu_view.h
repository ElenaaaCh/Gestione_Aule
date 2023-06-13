#ifndef MENU_VIEW_H
#define MENU_VIEW_H

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
    explicit MenuWindow(const QSize&, View*);
    void closeEvent(QCloseEvent *event) override;

signals:
    void View_aule_signal() const;
    void View_pren_signal() const;
};

#endif // MENU_VIEW_H
