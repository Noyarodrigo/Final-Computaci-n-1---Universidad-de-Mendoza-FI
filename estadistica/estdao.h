#ifndef ESTDAO_H
#define ESTDAO_H
#include <string>
#include <sstream>
#include "estadistica.h"
#include "queueest.h"

using namespace std;

class EstDAO
{
    public:
        EstDAO();
        virtual ~EstDAO();
        Queueest* load(string);
        string getPart(string);

    protected:
    private:
};

#endif // UsuarioDAO_H
