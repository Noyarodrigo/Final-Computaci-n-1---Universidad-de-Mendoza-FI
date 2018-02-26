#ifndef ADMINVIEWER_H
#define ADMINVIEWER_H

#include "queueusuario.h"
#include "queuecandidato.h"
#include "queuepartido.h"
#include <iostream>
#include <string>
#include "admincontroller.h"
using namespace std;

class AdminViewer
{
    public:
        AdminViewer();
        virtual ~AdminViewer();
        int menu();
        void infu(Queueusuario*);
        void infc(Queuecandidato*);
        void infp(Queuepartido*);
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void categoria();
        void fail();
        void info(string, string);
        void ver();
        void dusu();
        void dcan();
        void did();
        void out();
        void nope();
        void agregado();
        void eliminado();
        void dpar();
        //void cargar(Usuario*, string);
        //void mensaje(string);
        void yav();
    protected:
    private:
};

#endif
