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


void AdminController::inicio(){
		(new AdminViewer())->inicio();
}



void AdminController::categoria(){
	if ((new AdminDAO())->getAux() =="addu") {addu();}
	if ((new AdminDAO())->getAux() =="delu")delu();
	/*if (opc =="modu")modu();
	if (opc =="infu")infu();
	if (opc =="adda")adda();
	if (opc =="dela")dela();
	if (opc =="moda")moda();
	if (opc =="infa")infa();
	if (opc =="out")out();*/

}

void AdminController::addu()
{
	map<string,string> Get;
	initializeGet(Get);

	Usuario* usuario = new Usuario();
	usuario->setDocumento(Get["documento"]);
	usuario->setUsuario(Get["nombre"]);
	usuario->setClave(Get["apellido"]);
	(new AdminDAO())->add(usuario);

}

void AdminController::delu()
{
	(new AdminDAO())->del();
}

void AdminController::listarv(){
	(new AdminViewer())->listarv((new AdminDAO())->listarv());
	cout<<"<h3 color='grey'>BALBLABLAB<h3>\n";
}

void AdminController::setAux()
{
	map<string,string> Get;
	initializeGet(Get);
	string op=Get["opc"];
	(new AdminDAO())->setAux(op);
}

void AdminController::idAux()
{
	map<string,string> Get;
	initializeGet(Get);
	string op=Get["id"];
	(new AdminDAO())->setIdaux(op);
}
