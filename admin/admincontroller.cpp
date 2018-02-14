#include "admincontroller.h"
#include "adminviewer.h"
#include "admindao.h"
#include <string>
#include <sstream>
#include "getpost.h"
#include "candidato.h"

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
	if (opc =="infu")infu();*/
	if ((new AdminDAO())->getAux() =="addc"){addc();}
	if ((new AdminDAO())->getAux() =="delc"){delc();}
	/*if (opc =="moda")moda();
	if (opc =="infa")infa();
	if (opc =="out")out();*/

}
//USUARIO
void AdminController::addu()
{
	map<string,string> Get;
	initializeGet(Get);
	Usuario* usuario = new Usuario();
	usuario->setDocumento(Get["documento"]);
	usuario->setUsuario(Get["nombre"]);
	usuario->setClave(Get["apellido"]);
	(new AdminDAO())->addu(usuario);

}
void AdminController::delu()
{
	(new AdminDAO())->delu();
}

//CANDIDATOS
void AdminController::addc()
{
	map<string,string> Get;
	initializeGet(Get);
	Candidato* candidato = new Candidato();
	candidato->setIdtc(Get["idtc"]);
	candidato->setNombre(Get["nombre"]);
	candidato->setTel(Get["telefono"]);
	candidato->setPartido(Get["partido"]);
	candidato->setApellido(Get["apellido"]);
	(new AdminDAO())->addc(candidato);

}
void AdminController::delc()
{
	(new AdminDAO())->delc();
}

//CONTROL
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
void AdminController::out()
{
	(new AdminViewer())->out();
 (new AdminDAO())->removeLogin();
}
