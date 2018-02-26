#ifndef QUEUEPARTIDO_H
#define QUEUEPARTIDO_H

#include "nodepartido.h"

class Queuepartido
{
    public:
        Queuepartido();
        void setQStart(Nodepartido*);
        Nodepartido* getQStart();
        void setQEnd(Nodepartido*);
        Nodepartido* getQEnd();
        void qstore(Partido*);
        Partido* qretrieve();
        void free();
        void show();

    protected:

    private:
        Nodepartido* qstart;
        Nodepartido* qend;
};

#endif // QUEUEUSUARIO_H
