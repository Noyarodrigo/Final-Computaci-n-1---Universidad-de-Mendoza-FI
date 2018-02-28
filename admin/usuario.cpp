#include "usuario.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Usuario::Usuario()
{
    nombre = "";
    apellido = "";
		documento="";
    consejal="";
    legislador="";
    senador="";
    diputado="";
    intendente="";
    gobernador="";
    presidente="";
}

Usuario::Usuario(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Usuario::fillObject(sql::ResultSet* rs)
{
		this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("nombre"));
    this->setApellido(rs->getString("apellido"));
		this->setDocumento(rs->getString("documento"));
		this->setConsejal(rs->getString("consejal"));
    this->setLegislador(rs->getString("legislador"));
		this->setSenador(rs->getString("senador"));
		this->setDiputado(rs->getString("diputado"));
    this->setIntendente(rs->getString("intendente"));
		this->setGobernador(rs->getString("gobernador"));
		this->setPresidente(rs->getString("presidente"));

}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getApellido()
{
    return this->apellido;
}

void Usuario::setApellido(string apellido)
{
    this->apellido = apellido;
}

string Usuario::getDocumento(){

	return this->documento;
}

void Usuario::setDocumento(string documento){
	this->documento = documento;
}

void Usuario::setId(int id)
{
    this->id = id;
}

int Usuario::getId()
{
    return this->id;
}

string Usuario::getConsejal()
{
    return this->consejal;
}

void Usuario::setConsejal(string consejal)
{
    this->consejal = consejal;
}
string Usuario::getLegislador()
{
    return this->legislador;
}

void Usuario::setLegislador(string legislador)
{
    this->legislador = legislador;
}
string Usuario::getSenador()
{
    return this->senador;
}

void Usuario::setSenador(string senador)
{
    this->senador = senador;
}
string Usuario::getDiputado()
{
    return this->diputado;
}

void Usuario::setDiputado(string diputado)
{
    this->diputado = diputado;
}
string Usuario::getIntendente()
{
    return this->intendente;
}

void Usuario::setIntendente(string intendente)
{
    this->intendente = intendente;
}
string Usuario::getGobernador()
{
    return this->gobernador;
}

void Usuario::setGobernador(string gobernador)
{
    this->gobernador = gobernador;
}
string Usuario::getPresidente()
{
    return this->presidente;
}

void Usuario::setPresidente(string presidente)
{
    this->presidente = presidente;
}
string Usuario::toString()
{
    stringstream ss;
    ss << this->getId();
    string uno="<th>"+ ss.str() + "</th><th>" + this->getNombre() + "</th><th>" + this->getApellido() + "</th><th>" + this->getDocumento() + "</th><th>" + this->getConsejal() + "</th><th>" + this->getLegislador() + "</th><th>" + this->getSenador() + "</th><th>" + this->getDiputado()+ "</th>";
    string dos= uno+"</th><th>" + this->getIntendente() +"</th><th>" + this->getGobernador() +"</th><th>" + this->getPresidente()+"</th>";
    return dos;
}
