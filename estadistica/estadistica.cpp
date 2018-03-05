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
    total="";

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
    this->setTotal(rs->getString("total"));

}


void Estadistica::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Estadistica::getNombre()
{
    return this->nombre;
}

void Estadistica::setTotal(string total)
{
    this->total = total;
}

string Estadistica::getTotal()
{
    return this->total;
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
    string f= (new EstController())->parcial(this->getTotal(), this->getVotos());
    return "<tr><td>" + this->getNombre() + "</td><td>" + this->getApellido() + "</td><td>"+ this->getPartido() +"</td><td>"+f+"%</td><td>("+this->getVotos()+" votos)</td></tr>"	;

}
