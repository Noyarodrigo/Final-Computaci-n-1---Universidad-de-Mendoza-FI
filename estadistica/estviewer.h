#ifndef ADMINVIEWER_H
#define ADMINVIEWER_H

#include "queueest.h"
#include <iostream>
#include <string>
#include "estcontroller.h"
using namespace std;

class EstViewer
{
    public:
        EstViewer();
        virtual ~EstViewer();
        void inicio(Queueest*)
    protected:
    private:
};

#endif
