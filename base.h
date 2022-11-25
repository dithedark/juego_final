#ifndef BASE_H
#define BASE_H

#include <QGraphicsPixmapItem>
#include <macros.h>
#include <iostream>
#include <sstream>
#include <qstring.h>
#include <QTimer>
#include <QObject>

using namespace std;

class base: public QGraphicsPixmapItem
{
public:
    //Constructores
    base();

    //Desctructores
    ~base();

    //Metodos
    void configuracion(QString nombre,bool copia =false, int x=0,int y =0,int Ancho=32,int Alto=32 );
    void select_bloc(int x =0,int y=0, int Ancho =32 ,int Alto=32,bool defecto =true ,int sx=0, int sy=0,bool rotar=false);
    void CAMbloque( int Tipo_bloque);
    int MOSbloque();

private:
    int type_block=-1;
    QPixmap *img, *im_blq;
    QPixmap rotation(QPixmap *img);

};

#endif // BASE_H
