#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
    qstart = qend = NULL;
}

void Queue::setQStart(Node* qstart)
{
    this->qstart = qstart;
}

Node* Queue::getQStart()
{
    return this->qstart;
}

void Queue::setQEnd(Node* qend)
{
    this->qend = qend;
}

Node* Queue::getQEnd()
{
    return this->qend;
}

void Queue::qstore(Usuario* element)
{
    Node* newNode = new Node();

    newNode->setElement(element);
    newNode->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNode;
        return;
    }

    qend->setNext(newNode); //Hace que el último apunte al nuevo último

    qend = newNode; // Hace que el último sea el nuevo
}

Usuario* Queue::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Usuario* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Node* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queue::free()
{
    while (this->qretrieve() != NULL);
}

void Queue::show()
{
    if (this->qstart == NULL)
        return;

    Node* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
