#include "estadistica.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Estadistica::Estadistica()
{
    tipo = "";

}

Estadistica::Estadistica(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Estadistica::fillObject(sql::ResultSet* rs)
{
		this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("nombre"));
    

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

string Estadistica::getDocumento(){

	return this->documento;
}

void Estadistica::setDocumento(string documento){
	this->documento = documento;
}

void Estadistica::setId(int id)
{
    this->id = id;
}

int Estadistica::getId()
{
    return this->id;
}

string Estadistica::getConsejal()
{
    return this->consejal;
}

void Estadistica::setConsejal(string consejal)
{
    this->consejal = consejal;
}
string Estadistica::getLegislador()
{
    return this->legislador;
}

void Estadistica::setLegislador(string legislador)
{
    this->legislador = legislador;
}
string Estadistica::getSenador()
{
    return this->senador;
}

void Estadistica::setSenador(string senador)
{
    this->senador = senador;
}
string Estadistica::getDiputado()
{
    return this->diputado;
}

void Estadistica::setDiputado(string diputado)
{
    this->diputado = diputado;
}
string Estadistica::getIntendente()
{
    return this->intendente;
}

void Estadistica::setIntendente(string intendente)
{
    this->intendente = intendente;
}
string Estadistica::getGobernador()
{
    return this->gobernador;
}

void Estadistica::setGobernador(string gobernador)
{
    this->gobernador = gobernador;
}
string Estadistica::getPresidente()
{
    return this->presidente;
}

void Estadistica::setPresidente(string presidente)
{
    this->presidente = presidente;
}
string Estadistica::toString()
{
    stringstream ss;
    ss << this->getId();
    string uno="<th>"+ ss.str() + "</th><th>" + this->getNombre() + "</th><th>" + this->getApellido() + "</th><th>" + this->getConsejal() + "</th><th>" + this->getLegislador() + "</th><th>" + this->getSenador() + "</th><th>" + this->getDiputado()+ "</th>";
    string dos= uno+"</th><th>" + this->getIntendente() +"</th><th>" + this->getGobernador() +"</th><th>" + this->getPresidente()+"</th>";
    return dos;
}
