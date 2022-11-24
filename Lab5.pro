QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base.cpp \
    bloques.cpp \
    button.cpp \
    enemigo_1.cpp \
    enemigo_2.cpp \
    enemigo_3.cpp \
    juego.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    objetivo.cpp \
    operaciones.cpp \
    polvora.cpp

HEADERS += \
    Observador.h \
    Sujeto.h \
    base.h \
    bloques.h \
    button.h \
    enemigo_1.h \
    enemigo_2.h \
    enemigo_3.h \
    juego.h \
    jugador.h \
    macros.h \
    mainwindow.h \
    objetivo.h \
    operaciones.h \
    polvora.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

DISTFILES += \
    sprites/armas y movimientos sprites/1 Characters/1 Biker/Run1.png
