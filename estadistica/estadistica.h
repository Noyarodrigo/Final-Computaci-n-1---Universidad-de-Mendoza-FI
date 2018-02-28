#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "estcontroller.h"

using namespace std;

class Estadistica
{
    public:
        Estadistica();
        Estadistica(sql::ResultSet*);
        string getPartido();
        void setPartido(string);
        void setNombre(string);
        string getNombre();
        void setApellido(string);
        string getApellido();
        void fillObject(sql::ResultSet*);
        string toString();;
        void setVotos(string);
        string getVotos();
        void setTotal(string);
        string getTotal();
        float parcial(int);


    protected:

    private:
        string votos;
        string nombre;
        string apellido;
        string partido;
        string total;
};
#endif
