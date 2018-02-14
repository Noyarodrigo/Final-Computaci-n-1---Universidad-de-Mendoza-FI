#ifndef NODE_H
#define NODE_H

#include "usuario.h"
#include "candidato.h"

class Node
{
    public:
        Node();
        void setElement(Usuario*);
        Usuario* getElement();
        void setNext(Node*);
        Node* getNext();

    protected:

    private:
        Usuario* usuario;
        Node* next;
};

#endif // NODE_H
