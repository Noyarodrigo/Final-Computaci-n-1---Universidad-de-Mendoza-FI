#include "node.h"

Node::Node()
{
    this->usuario = NULL;
    this->next = NULL;
}

void Node::setElement(Usuario* usuario)
{
    this->usuario = usuario;
}

Usuario* Node::getElement()
{
    return this->usuario;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

Node* Node::getNext()
{
    return this->next;
}
