#include "nodepartidolista.h"

Nodepartidolista::Nodepartidolista()
{
    this->partido = NULL;
    this->next = NULL;
}

void Nodepartidolista::setElement(Partidolista* partido)
{
    this->partido = partido;
}


Partidolista* Nodepartidolista::getElement()
{
    return this->partido;
}

void Nodepartidolista::setNext(Nodepartidolista* next)
{
    this->next = next;
}

Nodepartidolista* Nodepartidolista::getNext()
{
    return this->next;
}
