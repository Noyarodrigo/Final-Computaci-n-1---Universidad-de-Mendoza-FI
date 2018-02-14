#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <string>
#include <sstream>
#include "usuario.h"
#include "candidato.h"
#include "queue.h"
using namespace std;

class AdminDAO
{
    public:
        AdminDAO();
        virtual ~AdminDAO();
        void addu(Usuario*);
        void addc(Candidato*);
        void update(Usuario*);
        bool exist(Usuario*);
        void save(Usuario*);
        void delu();
        void delc();
        Usuario* find(int);
        int checkadmin(string);
        Queue* checkcandidato(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
        void setAux(string);
        string getAux();
        void setIdaux(string);
        string getIdaux();
        Queue* listarv();
    protected:
    private:
};

#endif // UsuarioDAO_H
