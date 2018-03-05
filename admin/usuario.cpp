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
    fecha="";
    lugar="";
    direccion="";
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
    this->setFecha(rs->getString("fecha"));
    this->setLugar(rs->getString("lugar"));
    this->setDireccion(rs->getString("direccion"));
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

string Usuario::getFecha(){

	return this->fecha;
}

void Usuario::setFecha(string fecha){
	this->fecha = fecha;
}

string Usuario::getLugar(){

	return this->lugar;
}

void Usuario::setLugar(string lugar){
	this->lugar = lugar;
}

string Usuario::getDireccion(){

	return this->direccion;
}

void Usuario::setDireccion(string direccion){
	this->direccion = direccion;
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

    string uno="<tr><td>"+ ss.str() + "</td><td>" + this->getNombre() + "</td><td>" + this->getApellido() + "</td><td>" + this->getDocumento() + "</td><td>" + this->getFecha() + "</td><td>" + this->getLugar() + "</td><td>" + this->getDireccion() + "</td>";
    string dos= uno+ "<td>" + this->getConsejal() + "</td><td>" + this->getLegislador() + "</td><td>" + this->getSenador() + "</td>""<td>" + this->getDiputado()+ "</td><td>" + this->getIntendente() +"</td><td>" + this->getGobernador() +"</td>";
    string tres= "<meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\">"+dos+"<td>" + this->getPresidente()+"</td></tr>";
    return tres;
}
