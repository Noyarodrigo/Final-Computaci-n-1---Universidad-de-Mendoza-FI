#ifndef USUARIOCONTROLLER_H
#define USUARIOCONTROLLER_H

class UsuarioController
{
    public:
        UsuarioController();
        virtual ~UsuarioController();
        void abm();
    protected:
    private:
        void listar();
        void inicio();
        void eliminar();
};

#endif // UsuarioCONTROLLER_H
