#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>

#include <QKeyEvent>
#include <stdlib.h>
#include "bloques.h"
#include <cstdlib>
#include <time.h>
#include "jugador.h"
#include "enemigo_1.h"

class juego : public QGraphicsScene
{
Q_OBJECT
public:
    juego();
    ~juego();
    void keyPressEvent(QKeyEvent *i);
    void mapa();

private:
    int select_bloc(int i, int j);
    bool aleatorio();

    float p = 0.3;
    bloques *bl[largo][2];
    base *fondo;
    jugador *personaje;
    enemigo_1 *gangster;

    QTimer *caida;

public slots:

    void movimien();

};

#endif // JUEGO_H
