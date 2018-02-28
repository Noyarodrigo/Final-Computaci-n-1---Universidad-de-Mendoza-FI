#include "queueest.h"
#include <iostream>

using namespace std;

Queueest::Queueest()
{
    qstart = qend = NULL;
}

void Queueest::setQStart(Nodeest* qstart)
{
    this->qstart = qstart;
}

Nodeest* Queueest::getQStart()
{
    return this->qstart;
}

void Queueest::setQEnd(Nodeest* qend)
{
    this->qend = qend;
}

Nodeest* Queueest::getQEnd()
{
    return this->qend;
}

void Queueest::qstore(Estadistica* element)
{
    Nodeest* newNodeest = new Nodeest();

    newNodeest->setElement(element);
    newNodeest->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNodeest;
        return;
    }

    qend->setNext(newNodeest); //Hace que el último apunte al nuevo último

    qend = newNodeest; // Hace que el último sea el nuevo
}

Estadistica* Queueest::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Estadistica* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Nodeest* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queueest::free()
{
    while (this->qretrieve() != NULL);
}

void Queueest::show()
{
    if (this->qstart == NULL)
        return;

    Nodeest* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
