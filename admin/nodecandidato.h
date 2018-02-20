#ifndef NODECANDIDATO_H
#define NODECANDIDATO_H

#include "candidato.h"

class Nodecandidato
{
    public:
        Nodecandidato();
        void setElement(Candidato*);
        Candidato* getElement();
        void setNext(Nodecandidato*);
        Nodecandidato* getNext();

    protected:

    private:
        Nodecandidato* next;
        Candidato* candidato;
};

#endif // NODECANDIDATO_H
