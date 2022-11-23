#include "iobserver.h"

class IObserver::IObserver()
{
    public:
    virtual ~IObserver(){};
    virtual void recibir_disparo() = 0;
}
