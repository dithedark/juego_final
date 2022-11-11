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

    unsigned numbalas=0;



    float p = 0.3;
    bloques *bl[largo][2];
    base *fondo;
    jugador *personaje;
    enemigo_1 *gangster;
    enemigo_2 *tanque;
    enemigo_3 *dron;
    QTimer *caida,*DisparoProta;

    QVector<polvora*> cartuchoprota;





    /*



        desaparece.setPos(malitos[var]->x(),malitos[var]->y());
        removeItem(malitos[var]);
        malitos.remove(var);
        addItem(&desaparece);
        muerteMalo->start(200);




    */

public slots:

    void movimien();
    void FuncionDisparo();


};

#endif // JUEGO_H
