#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include <string>
using namespace std;

class AdminController
{
    public:
        AdminController();
        virtual ~AdminController();
        void abm();
        void control(string);
        void votar(string);
        void voto(int);
    protected:
    private:
        void listar();
        void inicio();
        void eliminar();

};

#endif // UsuarioCONTROLLER_H
