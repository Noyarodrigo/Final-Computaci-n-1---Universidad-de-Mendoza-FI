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

void UsuarioController::control(string cod){
	int b = atoi(cod.c_str());
	switch (b) {
			case 1: (new UsuarioViewer())->fail();
			 break;
			case 2: (new UsuarioViewer())->fracaso();
				break;
		}

	//(new UsuarioDAO())->votar(b);
	}


void UsuarioController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new UsuarioDAO())->del(usuario);
}
