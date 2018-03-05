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
        void inicio();
        void show(Queueest*, string);
        void reload();
        void css();
    protected:
    private:
};

#endif
