#include "estadistica.h"
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
		id=0;
}

Estadistica::Estadistica(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Estadistica::fillObject(sql::ResultSet* rs)
{
		this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("nombre"));
    this->setApellido(rs->getString("apellido"));
		this->setPartido(rs->getString("partido"));
		this->setVotos(rs->getString("votos"));
}

void Estadistica::setId(int id)
{
    this->id = id;
}

int Estadistica::getId()
{
    return this->id;
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
    stringstream ss;
    ss << this->getId();
    return "<th>"+ ss.str() + "</th><th>" + this->getNombre() + "</th><th>" + this->getApellido() + "</th><th>"+this->getPartido()+"</th><th>"+this->getVotos()+"</th>"	;
}
