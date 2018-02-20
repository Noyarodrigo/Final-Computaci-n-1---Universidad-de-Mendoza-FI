#include "nodecandidato.h"

Nodecandidato::Nodecandidato()
{
    this->candidato = NULL;
    this->next = NULL;
}

void Nodecandidato::setElement(Candidato* candidato)
{
    this->candidato = candidato;
}


Candidato* Nodecandidato::getElement()
{
    return this->candidato;
}

void Nodecandidato::setNext(Nodecandidato* next)
{
    this->next = next;
}

Nodecandidato* Nodecandidato::getNext()
{
    return this->next;
}
