#ifndef OPERACIONES_H
#define OPERACIONES_H


class operaciones
{
public:
    operaciones(float PX_,float PY_,float VX_,float VY_,float mass, float R_);

    float getPX() const;
    float getPY() const;
    float getmasa() const;
    float getR() const;

    void acelerar(float px2_, float py2_, float masa2);
    void actualizarY(float dt);
    void actualizarX(float dt);
    void formula();


    void setAY(float _ay);
    void setVY(float _vy);
    void setPY(float py);


    void setAX(float _ax);
    void setVX(float _vx);


private:
    float PX,PY,VX,VY, radio, masa, ax,ay, G, R;
};

#endif // OPERACIONES_H
