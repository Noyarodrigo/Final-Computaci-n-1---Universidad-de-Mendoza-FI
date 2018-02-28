#include "estadistica.h"
#include "estdao.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Estadistica::Estadistica()
{
    nombre = "";
    apellido = "";
		partido="";
		votos="";

}

Estadistica::Estadistica(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Estadistica::fillObject(sql::ResultSet* rs)
{

    this->setNombre(rs->getString("nombre"));
    this->setApellido(rs->getString("apellido"));
		this->setPartido(rs->getString("partido"));
		this->setVotos(rs->getString("votos"));
}


void Estadistica::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Estadistica::getNombre()
{
    return this->nombre;
}

string Estadistica::getApellido()
{
    return this->apellido;
}

void Estadistica::setApellido(string apellido)
{
    this->apellido = apellido;
}
string Estadistica::getPartido(){

	return this->partido;
}

void Estadistica::setPartido(string partido){
	this->partido = partido;
}

string Estadistica::getVotos(){

	return this->votos;
}

void Estadistica::setVotos(string votos){
	this->votos = votos;
}

string Estadistica::toString()
{
    return "<th>" + this->getNombre() + "</th><th>" + this->getApellido() + "</th><th>"+(new EstDAO())->getPart(this->getPartido())+"</th><th>"+this->getVotos()+"</th>"	;
}
