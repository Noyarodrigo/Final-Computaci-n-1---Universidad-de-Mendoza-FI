#include "queueusuario.h"
#include <iostream>

using namespace std;

Queueusuario::Queueusuario()
{
    qstart = qend = NULL;
}

void Queueusuario::setQStart(Nodeusuario* qstart)
{
    this->qstart = qstart;
}

Nodeusuario* Queueusuario::getQStart()
{
    return this->qstart;
}

void Queueusuario::setQEnd(Nodeusuario* qend)
{
    this->qend = qend;
}

Nodeusuario* Queueusuario::getQEnd()
{
    return this->qend;
}

void Queueusuario::qstore(Usuario* element)
{
    Nodeusuario* newNodeusuario = new Nodeusuario();

    newNodeusuario->setElement(element);
    newNodeusuario->setNext(NULL);

    if (qstart == NULL)
    {
        qstart = qend = newNodeusuario;
        return;
    }

    qend->setNext(newNodeusuario); //Hace que el último apunte al nuevo último

    qend = newNodeusuario; // Hace que el último sea el nuevo
}

Usuario* Queueusuario::qretrieve()
{
    if (this->qstart == NULL)
        return NULL;
    Usuario* aux = this->qstart->getElement(); //Recupero elemento a devolver
    Nodeusuario* nx = this->qstart; // Apunto nodo para no perder la referencia

    this->qstart = nx->getNext(); // Corro el start al siguiente nodo

    if (this->qstart == NULL)
        this->qend = NULL;

    delete nx; // Elimino el que era el primer nodo de la cola

    return aux; // Devuelvo el elemento recuperado

}

void Queueusuario::free()
{
    while (this->qretrieve() != NULL);
}

void Queueusuario::show()
{
    if (this->qstart == NULL)
        return;

    Nodeusuario* aux = this->qstart;

    while (aux != NULL)
    {
        cout << aux->getElement()->toString() << "<br>" << endl;
        aux = aux->getNext();
    }

    cout << endl;

}
