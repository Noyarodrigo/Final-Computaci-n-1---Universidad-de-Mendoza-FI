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
        int menu();
        void listar(Queue*);
       // int buscar();
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void votar();
        void categoria();
        void fail();
        void info(string, string);
        //void cargar(Usuario*, string);
        //void mensaje(string);
        void yav();
    protected:
    private:
};

#endif
