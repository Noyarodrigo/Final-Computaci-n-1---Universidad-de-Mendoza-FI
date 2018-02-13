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

        void ingresar();
        string getPartido();
        void setPartido(string);
        int getId();
		    void setId(int);
        void setUsuario(string);
        string getUsuario();
        void setClave(string);
        string getClave();
        void fillObject(sql::ResultSet*);
        string toString();


    protected:

    private:
        int id;
        string usuario;
        string clave;
        string partido;
};
#endif
