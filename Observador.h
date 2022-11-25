#ifndef OBSERVADOR_H
#define OBSERVADOR_H

class Observer {

public:
    virtual void notificacion_enemigo(int tipo_enemigo, int x, int y, bool giro) = 0;
};

#endif // OBSERVADOR_H
