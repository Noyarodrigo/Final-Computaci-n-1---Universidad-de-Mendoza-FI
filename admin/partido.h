#ifndef PARTIDO_H
#define PARTIDO_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Partido
{
    public:
        Partido();
        Partido(sql::ResultSet*);
        void fillObject(sql::ResultSet*);
        string toString();
        int getId();
        void setId(int);
        void setNombre(string);
        string getNombre();
        void setSocios(string);
        string getSocios();

    protected:

    private:
        int id;
        string nombre;
        string socios;

};
#endif
