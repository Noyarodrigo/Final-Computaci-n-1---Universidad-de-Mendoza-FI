#include "partido.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Partido::Partido()
{
    nombre = "";
    socios="";
}

Partido::Partido(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Partido::fillObject(sql::ResultSet* rs)
{
		this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("nombre"));
    this->setSocios(rs->getString("socios"));
}

void Partido::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Partido::getNombre()
{
    return this->nombre;
}

string Partido::getSocios()
{
    return this->socios;
}

void Partido::setSocios(string socios)
{
    this->socios = socios;
}

void Partido::setId(int id)
{
    this->id = id;
}

int Partido::getId()
{
    return this->id;
}

string Partido::toString()
{
    stringstream ss;
    ss << this->getId();
    string uno="<th>"+ ss.str() + "</th><th>" + this->getNombre() + "</th><th>" + this->getSocios() + "</th>";
    return uno;
}
