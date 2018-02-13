#include "admincontroller.h"
#include "adminviewer.h"
#include "admindao.h"
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
  //  (new AdminViewer())->listar((new AdminDAO())->collection(opc));
}

void AdminController::inicio(){
		(new AdminViewer())->inicio();
}

void AdminController::voto(int x){
	if (x==1)(new AdminViewer())->yav();
	if (x==0)(new AdminViewer())->fail();


}


void AdminController::control(string cod){
	map<string,string> Get;
  initializeGet(Get);
	//(new AdminDAO())->votar(Get["categoria"], cod);
	}


void AdminController::eliminar()
{
	Usuario* usuario = new Usuario();
	usuario->setId(11);
	(new AdminDAO())->del(usuario);
}
