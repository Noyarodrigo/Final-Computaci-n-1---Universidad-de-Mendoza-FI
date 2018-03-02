#include "queuepartidolista.h"
#include <iostream>

using namespace std;

Queuepartidolista::Queuepartidolista()
{
    qstart = qend = NULL;
}

void Queuepartidolista::setQStart(Nodepartidolista* qstart)
{
    this->qstart = qstart;
}

Nodepartidolista* Queuepartidolista::getQStart()
{
    return this->qstart;
}

void Queuepartidolista::setQEnd(Nodepartidolista* qend)
{
    this->qend = qend;
}

Nodepartidolista* Queuepartidolista::getQEnd()
{
    return this->qend;
}

void Queuepartidolista::qstore(Partidolista* element)
{
    Nodepartidolista* newNodepartidolista = new Nodepartidolista();

    newNodepartidolista->setElement(element);
    newNodepartidolista->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNodepartidolista;
        return;
    }

    qend->setNext(newNodepartidolista); //Hace que el último apunte al nuevo último

    qend = newNodepartidolista; // Hace que el último sea el nuevo
}

Partidolista* Queuepartidolista::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Partidolista* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Nodepartidolista* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queuepartidolista::free()
{
    while (this->qretrieve() != NULL);
}

void Queuepartidolista::show()
{
    if (this->qstart == NULL)
        return;

    Nodepartidolista* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
