#ifndef USUARIODAO_H
#define USUARIODAO_H
#include <string>
#include <sstream>
#include "usuario.h"
#include "candidato.h"
#include "partido.h"
#include "partidolista.h"
#include "queueusuario.h"
#include "queuecandidato.h"
#include "queuepartido.h"
#include "queuepartidolista.h"

using namespace std;

class AdminDAO
{
    public:
        AdminDAO();
        virtual ~AdminDAO();
        void addu(Usuario*);
        void addc(Candidato*);
        void addp(Partido*);
        void delu();
        void delc();
        void delp();
        Queueusuario* infu();
        Queuecandidato* infc();
        Queuepartido* infp();
        Queuepartidolista* plista();
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
