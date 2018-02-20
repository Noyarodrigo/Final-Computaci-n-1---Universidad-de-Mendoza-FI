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
        int getId();
        void setId(int);
        void setNombre(string);
        string getNombre();
        void setApellido(string);
        string getApellido();
        void fillObject(sql::ResultSet*);
        string toString();
        void setTel(string);
        string getTel();
        void setIdtc(string);
        string getIdtc();
        void setVotos(string);
        string getVotos();


    protected:

    private:
        int id;
        string votos;
        string tel;
        string nombre;
        string apellido;
        string partido;
        string idtc;
};
#endif
