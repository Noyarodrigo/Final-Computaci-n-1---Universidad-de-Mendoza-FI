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

    protected:
    private:
        void adda();
        void dela();
        void infa();
        void moda();
        void addu();
        void delu();
        void infu();
        void modu();
        void out();
        void inicio();
};

#endif // UsuarioCONTROLLER_H
