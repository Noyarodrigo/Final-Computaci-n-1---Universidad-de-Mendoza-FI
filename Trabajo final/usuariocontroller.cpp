#include "usuariocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"

UsuarioController::UsuarioController()
{
    //ctor
}

UsuarioController::~UsuarioController()
{
    //dtor
}

void UsuarioController::abm()
{
//	eliminar();
	// listar();
	inicio();

}

void UsuarioController::listar()
{
    //(new UsuarioViewer())->listar((new UsuarioDAO())->collection(opc));
}

void UsuarioController::inicio(){
		(new UsuarioViewer())->inicio();
}

void UsuarioController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new UsuarioDAO())->del(usuario);
}
