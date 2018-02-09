#ifndef USUARIODAO_H
#define USUARIODAO_H

#include "usuario.h"
#include "queue.h"

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
        int checkcandidato(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
    protected:
    private:
};

#endif // UsuarioDAO_H
