#ifndef PARTIDOLISTA_H
#define PARTIDOLISTA_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Partidolista
{
    public:
        Partidolista();
        Partidolista(sql::ResultSet*);
        void fillObject(sql::ResultSet*);
        string toString();
        int getId();
        void setId(int);
        void setNombre(string);
        string getNombre();

    protected:

    private:
        int id;
        string nombre;

};
#endif
