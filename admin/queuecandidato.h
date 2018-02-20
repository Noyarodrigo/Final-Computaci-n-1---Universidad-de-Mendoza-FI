#ifndef QUEUECANDIDATO_H
#define QUEUECANDIDATO_H

#include "nodecandidato.h"

class Queuecandidato
{
    public:
        Queuecandidato();
        void setQStart(Nodecandidato*);
        Nodecandidato* getQStart();
        void setQEnd(Nodecandidato*);
        Nodecandidato* getQEnd();
        void qstore(Candidato*);
        Candidato* qretrieve();
        void free();
        void show();

    protected:

    private:
        Nodecandidato* qstart;
        Nodecandidato* qend;
};

#endif // QUEUECANDIDATO_H
