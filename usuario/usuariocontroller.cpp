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

void UsuarioController::control(string cod){
	map<string,string> Get;
  initializeGet(Get);
	string  a;
	if(Get["categoria"]=="1"){a="consejal";}
	if(Get["categoria"]=="2"){a="legislador";}
	if(Get["categoria"]=="3"){a="senador";}
	if(Get["categoria"]=="4"){a="diputado";}
	if(Get["categoria"]=="5"){a="intendente";}
	if(Get["categoria"]=="6"){a="gobernador";}
	if(Get["categoria"]=="7"){a="presidente";}
	(new UsuarioDAO())->votar(a, cod, Get["categoria"]);
	}


void UsuarioController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new UsuarioDAO())->del(usuario);
}

void UsuarioController::out()
{
	(new UsuarioViewer())->out();
 	(new UsuarioDAO())->removeLogin();
}
