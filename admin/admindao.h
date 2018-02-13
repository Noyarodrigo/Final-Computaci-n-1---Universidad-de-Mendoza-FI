#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <string>
#include <sstream>
#include "usuario.h"
#include "queue.h"
using namespace std;

class AdminDAO
{
    public:
        AdminDAO();
        virtual ~AdminDAO();
        void add(Usuario*);
        void update(Usuario*);
        bool exist(Usuario*);
        void save(Usuario*);
        void del(Usuario*);
        Usuario* find(int);
        int checkadmin(string);
        Queue* checkcandidato(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
        void setAux(string);
        string getAux();
    protected:
    private:
};

#endif // UsuarioDAO_H
