#ifndef USUARIOVIEWER_H
#define USUARIOVIEWER_H

#include "queue.h"
#include <iostream>
#include <string>
#include "candidatocontroller.h"
using namespace std;

class UsuarioViewer
{
    public:
        UsuarioViewer();
        virtual ~UsuarioViewer();
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void votar();
        void categoria();
        void fail();
        void out();
        void yav();
    protected:
    private:
};

#endif
