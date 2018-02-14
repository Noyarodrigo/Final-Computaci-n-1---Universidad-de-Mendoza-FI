#ifndef ADMINVIEWER_H
#define ADMINVIEWER_H

#include "queue.h"
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
       // int buscar();
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void votar();
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
        //void cargar(Usuario*, string);
        //void mensaje(string);
        void yav();
        void listarv(Queue*);
    protected:
    private:
};

#endif
