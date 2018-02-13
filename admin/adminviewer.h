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
        void listar(Queue*);
       // int buscar();
        void mostrar(Usuario*);
        void inicio();
        void fracaso();
        void votar();
        void categoria();
        void fail();
        void info(string, string);
        void ver();
        //void cargar(Usuario*, string);
        //void mensaje(string);
        void yav();
    protected:
    private:
};

#endif
