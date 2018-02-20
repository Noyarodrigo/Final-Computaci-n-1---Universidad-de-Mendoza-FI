#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <string>
#include <sstream>
#include "usuario.h"
#include "candidato.h"
#include "queueusuario.h"
#include "queuecandidato.h"

using namespace std;

class AdminDAO
{
    public:
        AdminDAO();
        virtual ~AdminDAO();
        void addu(Usuario*);
        void addc(Candidato*);
        void delu();
        void delc();
        Queueusuario* infu();
        Queuecandidato* infc();
        Usuario* find(int);
        int checkadmin(string);
        int checkLogin();
        void setLogin(string);
        void removeLogin();
        string getId();
        void setAux(string);
        string getAux();
        void setIdaux(string);
        string getIdaux();


    protected:
    private:
};

#endif // UsuarioDAO_H
