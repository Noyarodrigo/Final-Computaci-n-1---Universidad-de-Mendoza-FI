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
    this->setApellido(rs->getString("legislador"));
		this->setDocumento(rs->getString("senador"));
		this->setNombre(rs->getString("diputado"));
    this->setApellido(rs->getString("intendente"));
		this->setDocumento(rs->getString("gobernador"));
		this->setDocumento(rs->getString("presidente"));

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

string Usuario::toString()
{
    stringstream ss;
    ss << this->getId();
    return "<th>"+ ss.str() + "</th><th>" + this->getNombre() + "</th><th>" + this->getApellido() + "</th>"	;
}
