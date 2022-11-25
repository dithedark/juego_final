#ifndef SUJETO_H
#define SUJETO_H

#include "Observador.h"

class Subject {

public:
    //parte observador
    virtual void agregar_observador(Observer *observador) = 0;
    virtual void remover_observador() = 0;
    virtual void notificar() = 0;
};

#endif // SUJETO_H
