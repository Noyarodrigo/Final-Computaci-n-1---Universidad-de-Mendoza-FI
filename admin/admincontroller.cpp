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



void AdminController::categoria(string opc){
	if (opc =="addu") {addu();}
	/*if (opc =="delu")delu();
	if (opc =="modu")modu();
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
	//Usuario* usuario = new Usuario();
	cout<<"Content-type: text/html"<<endl<<endl;
	cout<<"<html><head>"<<endl;
	cout<<"<h3 color='grey'>Nombre<h3>\n"<<Get["nombre"]<<endl;
	cout<<"<h3 color='grey'>Apellido<h3>\n"<<Get["apellido"]<<endl;
	cout<<"<h3 color='grey'>Documento<h3>\n"<<Get["documento"]<<endl;
	/*usuario->setDocumento(Get["documento"]);
	usuario->setUsuario(Get["nombre"]);
	usuario->setClave(Get["apellido"]);
	(new AdminDAO())->add(usuario);*/
}
