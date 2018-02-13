#include "admincontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"
#include <string>
#include <sstream>
#include "getpost.h"

AdminController::AdminController()
{
    //ctor
}

AdminController::~AdminController()
{
    //dtor
}

void AdminController::abm()
{
	inicio();

}

void AdminController::listar()
{
    (new AdminViewer())->listar((new UsuarioDAO())->collection(opc));
}

void AdminController::inicio(){
		(new AdminViewer())->inicio();
}

void AdminController::voto(int x){
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
