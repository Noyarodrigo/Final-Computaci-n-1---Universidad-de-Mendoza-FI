#ifndef QUEUEPARTIDOLISTA_H
#define QUEUEPARTIDOLISTA_H

#include "nodepartidolista.h"

class Queuepartidolista
{
    public:
        Queuepartidolista();
        void setQStart(Nodepartidolista*);
        Nodepartidolista* getQStart();
        void setQEnd(Nodepartidolista*);
        Nodepartidolista* getQEnd();
        void qstore(Partidolista*);
        Partidolista* qretrieve();
        void free();
        void show();

    protected:

    private:
        Nodepartidolista* qstart;
        Nodepartidolista* qend;
};

#endif // QUEUEUSUARIO_H
