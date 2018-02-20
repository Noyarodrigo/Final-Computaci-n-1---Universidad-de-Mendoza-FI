#include "nodeusuario.h"

Nodeusuario::Nodeusuario()
{
    this->usuario = NULL;
    this->next = NULL;
}

void Nodeusuario::setElement(Usuario* usuario)
{
    this->usuario = usuario;
}


Usuario* Nodeusuario::getElement()
{
    return this->usuario;
}

void Nodeusuario::setNext(Nodeusuario* next)
{
    this->next = next;
}

Nodeusuario* Nodeusuario::getNext()
{
    return this->next;
}
