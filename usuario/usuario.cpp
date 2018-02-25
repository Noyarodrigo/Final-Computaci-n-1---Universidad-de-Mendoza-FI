#include "usuario.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Usuario::Usuario()
{
		id = 0;
    usuario = "";
    clave = "";
		partido="";
}

Usuario::Usuario(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Usuario::fillObject(sql::ResultSet* rs)
{

    this->setId(rs->getInt("id"));
    this->setUsuario(rs->getString("nombre"));
    this->setClave(rs->getString("apellido"));
		this->setPartido(rs->getString("partido"));
}


void Usuario::setId(int id)
{
    this->id = id;
}

int Usuario::getId()
{
    return this->id;
}

void Usuario::setUsuario(string usuario)
{
    this->usuario = usuario;
}

string Usuario::getUsuario()
{
    return this->usuario;
}

string Usuario::getClave()
{
    return this->clave;
}

void Usuario::setClave(string clave)
{
    this->clave = clave;
}
string Usuario::getPartido(){

	return this->partido;
}

void Usuario::setPartido(string partido){
	this->partido = partido;
}

string Usuario::toString()
{
    stringstream ss;
    ss << this->getId();
		return "<th>"+ ss.str() + "</th><th>" + this->getUsuario() + "</th><th>" + this->getClave() + "</th><th>"+this->getPartido()+"</th>"	;
}
