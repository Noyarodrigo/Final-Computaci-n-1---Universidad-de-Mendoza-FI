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
        void add(Usuario*);
        void update(Usuario*);
        bool exist(Usuario*);
        void save(Usuario*);
        void del(Usuario*);
        Usuario* find(int);
        int checkusuario(string);
        Queue* collection(int);
        Queue* checkcandidato(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
        void votar(string, string);
        void sumarvoto(string);
        int checkvoto(string);
    protected:
    private:
};

#endif // UsuarioDAO_H
