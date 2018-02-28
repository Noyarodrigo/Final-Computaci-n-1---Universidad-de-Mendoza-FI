#ifndef ESTCONTROLLER_H
#define ESTCONTROLLER_H
#include <string>
using namespace std;

class EstController
{
    public:
        EstController();
        virtual ~EstController();
        void abm();

    protected:
    private:
      void inicio();
};

#endif // UsuarioCONTROLLER_H
