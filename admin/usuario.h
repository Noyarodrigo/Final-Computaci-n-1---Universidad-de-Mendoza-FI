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
        void setFecha(string);
        string getFecha();
        void setLugar(string);
        string getLugar();
        void setDireccion(string);
        string getDireccion();
        //INFORMACION DE VOTOS
        void setConsejal(string);
        string getConsejal();
        void setLegislador(string);
        string getLegislador();
        void setSenador(string);
        string getSenador();
        void setDiputado(string);
        string getDiputado();
        void setIntendente(string);
        string getIntendente();
        void setGobernador(string);
        string getGobernador();
        void setPresidente(string);
        string getPresidente();

    protected:

    private:
        int id;
        string documento;
        string nombre;
        string apellido;
        string fecha;
        string lugar;
        string direccion;
        string consejal;
        string diputado;
        string legislador;
        string senador;
        string intendente;
        string gobernador;
        string presidente;
};
#endif
