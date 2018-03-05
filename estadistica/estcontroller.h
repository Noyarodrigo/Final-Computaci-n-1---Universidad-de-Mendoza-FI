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
        string parcial(string, string);
        void cate();
    protected:
    private:
      void ver();

};

#endif // UsuarioCONTROLLER_H
