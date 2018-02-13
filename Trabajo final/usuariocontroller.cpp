#include "usuariocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"
#include <string>
#include <sstream>
#include "getpost.h"

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

void UsuarioController::voto(int x){
	if (x==1)(new UsuarioViewer())->yav();
	if (x==0)(new UsuarioViewer())->fail();


}


void UsuarioController::control(string cod){
	map<string,string> Get;
  initializeGet(Get);
	(new UsuarioDAO())->votar(Get["categoria"], cod);
	}


void UsuarioController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new UsuarioDAO())->del(usuario);
}
