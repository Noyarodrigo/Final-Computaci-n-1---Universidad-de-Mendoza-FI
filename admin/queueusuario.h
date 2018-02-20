#ifndef QUEUEUSUARIO_H
#define QUEUEUSUARIO_H

#include "nodeusuario.h"

class Queueusuario
{
    public:
        Queueusuario();
        void setQStart(Nodeusuario*);
        Nodeusuario* getQStart();
        void setQEnd(Nodeusuario*);
        Nodeusuario* getQEnd();
        void qstore(Usuario*);
        Usuario* qretrieve();
        void free();
        void show();

    protected:

    private:
        Nodeusuario* qstart;
        Nodeusuario* qend;
};

#endif // QUEUEUSUARIO_H
