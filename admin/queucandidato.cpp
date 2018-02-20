#include "queuecandidato.h"
#include <iostream>

using namespace std;

Queuecandidato::Queuecandidato()
{
    qstart = qend = NULL;
}

void Queuecandidato::setQStart(Nodecandidato* qstart)
{
    this->qstart = qstart;
}

Nodecandidato* Queuecandidato::getQStart()
{
    return this->qstart;
}

void Queuecandidato::setQEnd(Nodecandidato* qend)
{
    this->qend = qend;
}

Nodecandidato* Queuecandidato::getQEnd()
{
    return this->qend;
}

void Queuecandidato::qstore(Candidato* element)
{
    Nodecandidato* newNodecandidato = new Nodecandidato();

    newNodecandidato->setElement(element);
    newNodecandidato->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNodecandidato;
        return;
    }

    qend->setNext(newNodecandidato); //Hace que el último apunte al nuevo último

    qend = newNodecandidato; // Hace que el último sea el nuevo
}

Candidato* Queuecandidato::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Candidato* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Nodecandidato* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queuecandidato::free()
{
    while (this->qretrieve() != NULL);
}

void Queuecandidato::show()
{
    if (this->qstart == NULL)
        return;

    Nodecandidato* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
