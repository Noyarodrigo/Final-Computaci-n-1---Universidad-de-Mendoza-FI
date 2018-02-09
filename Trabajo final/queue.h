#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class Queue
{
    public:
        Queue();
        void setQStart(Node*);
        Node* getQStart();
        void setQEnd(Node*);
        Node* getQEnd();
        void qstore(Usuario*);
        Usuario* qretrieve();
        void free();
        void show();

    protected:

    private:
        Node* qstart;
        Node* qend;
};

#endif // QUEUE_H
