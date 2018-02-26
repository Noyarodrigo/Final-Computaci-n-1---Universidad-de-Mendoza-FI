#include "queuepartido.h"
#include <iostream>

using namespace std;

Queuepartido::Queuepartido()
{
    qstart = qend = NULL;
}

void Queuepartido::setQStart(Nodepartido* qstart)
{
    this->qstart = qstart;
}

Nodepartido* Queuepartido::getQStart()
{
    return this->qstart;
}

void Queuepartido::setQEnd(Nodepartido* qend)
{
    this->qend = qend;
}

Nodepartido* Queuepartido::getQEnd()
{
    return this->qend;
}

void Queuepartido::qstore(Partido* element)
{
    Nodepartido* newNodepartido = new Nodepartido();

    newNodepartido->setElement(element);
    newNodepartido->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNodepartido;
        return;
    }

    qend->setNext(newNodepartido); //Hace que el último apunte al nuevo último

    qend = newNodepartido; // Hace que el último sea el nuevo
}

Partido* Queuepartido::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Partido* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Nodepartido* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queuepartido::free()
{
    while (this->qretrieve() != NULL);
}

void Queuepartido::show()
{
    if (this->qstart == NULL)
        return;

    Nodepartido* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
