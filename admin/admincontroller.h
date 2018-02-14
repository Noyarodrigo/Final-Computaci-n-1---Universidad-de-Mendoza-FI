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
        void categoria();
        void setAux();
        void idAux();
        void out();

    protected:
    private:
        void addc();
        void delc();
        void infc();
        void modc();
        void addu();
        void delu();
        void infu();
        void modu();
        void inicio();
};

#endif // UsuarioCONTROLLER_H
