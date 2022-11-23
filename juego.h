#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>

#include <QKeyEvent>
#include <stdlib.h>
#include "bloques.h"
#include <cstdlib>
#include <time.h>
#include "jugador.h"
#include "enemigo_2.h"
#include "enemigo_3.h"
#include "polvora.h"
#include "objetivo.h"

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
    bool aleatorio(),permisoO=true;

    unsigned dispa=0;
    unsigned dronesEnemigos=0,dronesbalas=0,limiteDrones;
    unsigned enemigos1_muertos = 0;



    float p = 0.3;
    objetivo *trampolin;
    bloques *bl[largo][2];
    base *fondo;
    jugador *personaje;

    //enemigo_2 *tanque;
    int t_enemigos = 2000;
    int e1_vidas = 3;

    QTimer *caida
    ,*t_disparo_protagonista,
    *movimiento_drones,
    *Disparo_enemigos,
    *t_cargar_enemigos;

    QVector<polvora*> cartuchoprota;
    QVector<polvora*> cartuchoEnemigos;

    QVector<enemigo_3*> drones;
    //QVector<enemigo_2*> tanques;

public slots:

    //movimiento personaje
    void movimien();

    // fisicas disparos
    void disparo_protagonista();
    void disparoEnemigos();


    // inteligencia enemigos
    void inteligencia_drones();

    void cargar_enemigos();

};

#endif // JUEGO_H
