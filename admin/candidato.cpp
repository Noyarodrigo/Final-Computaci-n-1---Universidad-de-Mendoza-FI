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
}

Candidato::Candidato(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Candidato::fillObject(sql::ResultSet* rs)
{

    this->setNombre(rs->getString("nombre"));
    this->setApellido(rs->getString("apellido"));
		this->setPartido(rs->getString("partido"));
		this->setIdtc(rs->getString("idtc"));
		this->setTel(rs->getString("telefono"));
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

/*string Candidato::toString()
{
    stringstream ss;
    ss << this->getId();
    return "<div>&nbsp;"+ ss.str() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\t" + this->getNombre() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\t" + this->getApellido() + "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\t"+this->getPartido()+"</div>";
}*/
