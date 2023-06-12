QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = Gestione_Aule
TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/aula.cpp \
    Model/aulaConcerto.cpp \
    Model/aulaStrumentale.cpp \
    Model/aulaStudio.cpp \
    Model/prenotazione.cpp \
    Model/storage.cpp \
    Model/utente.cpp \
    View/login_view.cpp \
    View/menu_view.cpp \
    View/registrazione_view.cpp \
    View/view.cpp \
    main.cpp \

HEADERS += \
    Model/aula.h \
    Model/aulaConcerto.h \
    Model/aulaStrumentale.h \
    Model/aulaStudio.h \
    Model/contenitore.h \
    Model/prenotazione.h \
    Model/storage.h \
    Model/utente.h \
    View/login_view.h \
    View/menu_view.h \
    View/registrazione_view.h \
    View/view.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    View/Images/logo_consvi.jpeg

