#ifndef NODEEST_H
#define NODEEST_H

#include "estadistica.h"

class Nodeest
{
    public:
        Nodeest();
        void setElement(Estadistica*);
        Estadistica* getElement();
        void setNext(Nodeest*);
        Nodeest* getNext();

    protected:

    private:
        Estadistica* estadistica;
        Nodeest* next;
};

#endif // NODEEST_H
