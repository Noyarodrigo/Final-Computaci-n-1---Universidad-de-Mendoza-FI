#ifndef CANDIDATOVIEWER_H
#define CANDIDATOVIEWER_H

#include "queue.h"
#include <iostream>
#include <string>
#include "usuarioviewer.h"

using namespace std;

class CandidatoViewer
{
    public:
        CandidatoViewer();
        virtual ~CandidatoViewer();
        void listar(Queue*);
        void mostrar();

    protected:
    private:
};

#endif
