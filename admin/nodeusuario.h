#ifndef NODEUSUARIO_H
#define NODEUSUARIO_H

#include "usuario.h"

class Nodeusuario
{
    public:
        Nodeusuario();
        void setElement(Usuario*);
        Usuario* getElement();
        void setNext(Nodeusuario*);
        Nodeusuario* getNext();

    protected:

    private:
        Usuario* usuario;
        Nodeusuario* next;
};

#endif // NODEUSUARIO_H
