#include "admincontroller.h"
#include "adminviewer.h"
#include "admindao.h"
#include <string>
#include <sstream>
#include "getpost.h"
#include "candidato.h"
#include "usuario.h"

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


}
//USUARIO
void AdminController::addu()
{
	map<string,string> Get;
	initializeGet(Get);
	cout<<"<font color='blue'><h3 align='center'>DOCUMENTO: "+Get["documento"] +" </h3></font>"<<endl;

	Usuario* usuario = new Usuario();
	usuario->setDocumento(Get["documento"]);
	//cout<<"<font color='blue'><h3 align='center'>DOCUMENTO: "+Usuario->getDocumento() +" </h3></font>"<<endl;

	usuario->setNombre(Get["nombre"]);
	usuario->setApellido	(Get["apellido"]);

	//string stringSQL = "INSERT INTO votantes (nombre, apellido, documento) VALUES ('" + Usuario->getUsuario() + "', '" + Usuario->getClave() + "','"+Usuario->getDocumento()+"')";
	//cout<<"<font color='red'><h3 >QUERY: "+stringSQL+"<h3></font>\n";
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
