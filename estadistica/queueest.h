#ifndef QUEUEEST_H
#define QUEUEEST_H

#include "nodeest.h"

class Queueest
{
    public:
        Queueest();
        void setQStart(Nodeest*);
        Nodeest* getQStart();
        void setQEnd(Nodeest*);
        Nodeest* getQEnd();
        void qstore(Estadistica*);
        Estadistica* qretrieve();
        void free();
        void show();

    protected:

    private:
        Nodeest* qstart;
        Nodeest* qend;
};

#endif // QUEUEUSUARIO_H
