#include "nodepartido.h"

Nodepartido::Nodepartido()
{
    this->partido = NULL;
    this->next = NULL;
}

void Nodepartido::setElement(Partido* partido)
{
    this->partido = partido;
}


Partido* Nodepartido::getElement()
{
    return this->partido;
}

void Nodepartido::setNext(Nodepartido* next)
{
    this->next = next;
}

Nodepartido* Nodepartido::getNext()
{
    return this->next;
}
