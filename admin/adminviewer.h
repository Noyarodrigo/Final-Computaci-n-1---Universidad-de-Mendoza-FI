#ifndef ADMINVIEWER_H
#define ADMINVIEWER_H

#include "queueusuario.h"
#include "queuecandidato.h"
#include "queuepartido.h"
#include "queuepartidolista.h"
#include <iostream>
#include <string>
#include "admincontroller.h"
using namespace std;

class AdminViewer
{
    public:
        AdminViewer();
        virtual ~AdminViewer();
        void infu(Queueusuario*);
        void infc(Queuecandidato*);
        void infp(Queuepartido*);
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void categoria();
        void ver();
        void dusu();
        void dcan(Queuepartidolista*);
        void did();
        void out();
        void nope();
        void agregado();
        void eliminado();
        void dpar();
        void css();
    protected:
    private:
};

#endif
