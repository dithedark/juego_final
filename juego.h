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



    float p = 0.3;
    objetivo *trampolin;
    bloques *bl[largo][2];
    base *fondo;
    jugador *personaje;
    enemigo_1 *gangster;
    enemigo_2 *tanque;
    int t_enemigos = 3000;

    QTimer *caida
    ,*DisparoProta,
    *movimiento_drones,
    *Disparo_enemigos,
    *t_cargar_enemigos;

    QVector<polvora*> cartuchoprota;
    QVector<polvora*> cartuchoEnemigos;

    QVector<enemigo_3*> drones;
    QVector<enemigo_2*> tanques;






    /*



        desaparece.setPos(malitos[var]->x(),malitos[var]->y());
        removeItem(malitos[var]);
        malitos.remove(var);
        addItem(&desaparece);
        muerteMalo->start(200);




    */

public slots:

    //movimiento personaje
    void movimien();

    // fisicas disparos
    void FuncionDisparoProta();
    void disparoEnemigos();


    // inteligencia enemigos
    void inteligencia_drones();

    void cargar_enemigos();

};

#endif // JUEGO_H
