#include "nodeest.h"

Nodeest::Nodeest()
{
    this->estadistica = NULL;
    this->next = NULL;
}

void Nodeest::setElement(Estadistica* estadistica)
{
    this->estadistica = estadistica;
}


Estadistica* Nodeest::getElement()
{
    return this->estadistica;
}

void Nodeest::setNext(Nodeest* next)
{
    this->next = next;
}

Nodeest* Nodeest::getNext()
{
    return this->next;
}
