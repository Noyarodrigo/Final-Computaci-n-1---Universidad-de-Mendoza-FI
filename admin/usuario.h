#ifndef USUARIO_H
#define USUARIO_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Usuario
{
    public:
        Usuario();
        Usuario(sql::ResultSet*);
        int getId();
        void setId(int);
        void setNombre(string);
        string getNombre();
        void setApellido(string);
        string getApellido();
        void fillObject(sql::ResultSet*);
        string toString();
        void setDocumento(string);
        string getDocumento();

    protected:

    private:
        int id;
        string documento;
        string nombre;
        string apellido;
};
#endif
