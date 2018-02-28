#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <string>
#include <sstream>
#include "usuario.h"
#include "queue.h"
using namespace std;

class UsuarioDAO
{
    public:
        UsuarioDAO();
        virtual ~UsuarioDAO();
        int checkusuario(string);
        Queue* checkcandidato(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
        void votar(string, string, string);
        void sumarvoto(string,string);
        int checkvoto(string);
        void sumarest(string);
    protected:
    private:
};

#endif // UsuarioDAO_H
