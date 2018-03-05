#include "admincontroller.h"
#include "adminviewer.h"
#include "admindao.h"
#include <string>
#include <sstream>
#include "getpost.h"
#include "candidato.h"
#include "usuario.h"
#include "partido.h"
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
	if ((new AdminDAO())->getAux() =="infu")infu();
	if ((new AdminDAO())->getAux() =="infc")infc();
	if ((new AdminDAO())->getAux() =="addc"){addc();}
	if ((new AdminDAO())->getAux() =="delc"){delc();}
	if ((new AdminDAO())->getAux() =="addp"){addp();}
	if ((new AdminDAO())->getAux() =="delp"){delp();}
	if ((new AdminDAO())->getAux() =="infp")infp();

}
//USUARIO
void AdminController::addu()
{
	map<string,string> Get;
	initializeGet(Get);
	Usuario* usuario = new Usuario();
	usuario->setDocumento(Get["documento"]);
	usuario->setNombre(Get["nombre"]);
	usuario->setApellido	(Get["apellido"]);
	usuario->setFecha(Get["fecha"]);
	usuario->setLugar(Get["lugar"]);
	usuario->setDireccion	(Get["direccion"]);
	(new AdminDAO())->addu(usuario);
}
void AdminController::delu()
{
	(new AdminDAO())->delu();
}
void AdminController::infu()
{

	(new AdminViewer())->infu((new AdminDAO())->infu());

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
void AdminController::infc()
{
	(new AdminViewer())->infc((new AdminDAO())->infc());
}
//PARTIDO
void AdminController::addp()
{
	map<string,string> Get;
	initializeGet(Get);
	Partido* partido = new Partido();
	partido->setNombre(Get["nombre"]);
	(new AdminDAO())->addp(partido);
}
void AdminController::delp()
{
	(new AdminDAO())->delp();
}
void AdminController::infp()
{
	(new AdminViewer())->infp((new AdminDAO())->infp());
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
	if (op=="") {
		(new AdminViewer())->nope();
		(new AdminDAO())->setIdaux("0");
	}else{
		(new AdminDAO())->setIdaux(op);
	}

}
void AdminController::out()
{
	(new AdminViewer())->out();
	(new AdminDAO())->removeLogin();
}
