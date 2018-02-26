#ifndef NODEPARTIDO_H
#define NODEPARTIDO_H

#include "partido.h"

class Nodepartido
{
    public:
        Nodepartido();
        void setElement(Partido*);
        Partido* getElement();
        void setNext(Nodepartido*);
        Nodepartido* getNext();

    protected:

    private:
        Partido* partido;
        Nodepartido* next;
};

#endif // NODEPARTIDO_H
