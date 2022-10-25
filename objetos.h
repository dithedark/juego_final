#ifndef OBJETOS_H
#define OBJETOS_H
#include <QObject>
#include <QGraphicsPixmapItem>

class objetos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    objetos();
};

#endif // OBJETOS_H
