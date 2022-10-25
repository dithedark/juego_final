#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H

#include "base.h"

class enemigo_1:public QObject , public base
{
Q_OBJECT

public:
    enemigo_1();
    ~enemigo_1();
private:
    QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Attack1.png";
    QTimer *animacionE1;
    int cambioE1_sprit=0;

private slots:
    void cambioE1();
};

#endif // ENEMIGO_1_H
