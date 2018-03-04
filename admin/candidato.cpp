#include "candidato.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Candidato::Candidato()
{
		idtc = "0";
    nombre = "";
    apellido = "";
		partido="";
		tel="";
		votos="";
		id=0;
}

Candidato::Candidato(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Candidato::fillObject(sql::ResultSet* rs)
{
		this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("nombre"));
    this->setApellido(rs->getString("apellido"));
		this->setPartido(rs->getString("partido"));
		this->setIdtc(rs->getString("idtc"));
		this->setTel(rs->getString("telefono"));
		this->setVotos(rs->getString("votos"));
}

void Candidato::setId(int id)
{
    this->id = id;
}

int Candidato::getId()
{
    return this->id;
}

void Candidato::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Candidato::getNombre()
{
    return this->nombre;
}

string Candidato::getApellido()
{
    return this->apellido;
}

void Candidato::setApellido(string apellido)
{
    this->apellido = apellido;
}
string Candidato::getPartido(){

	return this->partido;
}

void Candidato::setPartido(string partido){
	this->partido = partido;
}

string Candidato::getIdtc(){

	return this->idtc;
}

void Candidato::setIdtc(string idtc){
	this->idtc = idtc;
}

string Candidato::getTel(){

	return this->tel;
}

void Candidato::setTel(string tel){
	this->tel = tel;
}

string Candidato::getVotos(){

	return this->votos;
}

void Candidato::setVotos(string votos){
	this->votos = votos;
}

string Candidato::toString()
{
    stringstream ss;
    ss << this->getId();
    return "<tr><td>"+ ss.str() + "</td><td>" + this->getNombre() + "</td><td>" + this->getApellido() + "</td><td>"+this->getTel()+"</td><td>"+ this->getIdtc()+"</td><td>"+this->getPartido()+"</td><td>"+this->getVotos()+"</td></tr>"	;
}
