#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H
#include <string>
using namespace std;

class UsuarioController
{
    public:
        UsuarioController();
        virtual ~UsuarioController();
        void abm();
        void control(string);
        void votar(string);
        void out();
    protected:
    private:
        void listar();
        void inicio();

};

#endif // UsuarioCONTROLLER_H
