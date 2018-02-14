#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Candidato
{
    public:
        Candidato();
        Candidato(sql::ResultSet*);
        string getPartido();
        void setPartido(string);
        void setNombre(string);
        string getNombre();
        void setApellido(string);
        string getApellido();
        void fillObject(sql::ResultSet*);
        //string toString();
        void setTel(string);
        string getTel();
        void setIdtc(string);
        string getIdtc();

    protected:

    private:
        string tel;
        string nombre;
        string apellido;
        string partido;
        string idtc;
};
#endif
