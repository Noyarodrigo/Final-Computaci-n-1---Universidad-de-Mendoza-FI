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
        void infu();
        void infc();


    protected:
    private:
        void addc();
        void delc();
        void addu();
        void delu();
        void inicio();
        void addp();
        void delp();
        void infp();
};

#endif // UsuarioCONTROLLER_H
