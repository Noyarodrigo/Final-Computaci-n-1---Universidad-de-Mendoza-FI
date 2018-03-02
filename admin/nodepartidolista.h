#ifndef NODEPARTIDOLISTA_H
#define NODEPARTIDOLISTA_H

#include "partidolista.h"

class Nodepartidolista
{
    public:
        Nodepartidolista();
        void setElement(Partidolista*);
        Partidolista* getElement();
        void setNext(Nodepartidolista*);
        Nodepartidolista* getNext();

    protected:

    private:
        Partidolista* partido;
        Nodepartidolista* next;
};

#endif // NODEPARTIDO_H
