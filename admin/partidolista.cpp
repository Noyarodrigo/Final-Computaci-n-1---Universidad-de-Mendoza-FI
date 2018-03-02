#include "partidolista.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Partidolista::Partidolista()
{
    nombre = "";
    id = 0;
}

Partidolista::Partidolista(sql::ResultSet* res)
{
    this->fillObject(res);
}


void Partidolista::fillObject(sql::ResultSet* rs)
{
    this->setId(rs->getInt("id"));
    this->setNombre(rs->getString("partido"));
}

void Partidolista::setId(int id)
{
    this->id = id;
}

int Partidolista::getId()
{
    return this->id;
}

void Partidolista::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Partidolista::getNombre()
{
    return this->nombre;
}


string Partidolista::toString()
{
    stringstream ss;
    ss << this->getId();
    string uno="<option value="+ ss.str()+">"+this->getNombre()+"</option>";
    return uno;

}
