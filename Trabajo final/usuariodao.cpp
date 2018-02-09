#include "usuariodao.h"
#include "myconnection.h"
#include "string.h"
#include <sstream>

UsuarioDAO::UsuarioDAO()
{
    //ctor
}

UsuarioDAO::~UsuarioDAO()
{
    //dtor
}

Queue* UsuarioDAO::collection(int opc)
{
    Queue* queue = new Queue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM persona WHERE idtc= "+opc);

    while (res->next())
        queue->qstore(new Usuario(res));

    delete res;

    return queue;
}

void UsuarioDAO::del(Usuario* usuario)
{
    string stringSQL;
    stringstream ss;
    ss << usuario->getId();

    stringSQL = "DELETE FROM persona WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void UsuarioDAO::save(Usuario* Usuario)
{
    if (exist(Usuario))
        update(Usuario);
    else
        add(Usuario);
}

bool UsuarioDAO::exist(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "SELECT * FROM persona WHERE id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void UsuarioDAO::update(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "UPDATE persona SET usuario = '" + Usuario->getUsuario() + "' WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void UsuarioDAO::add(Usuario* Usuario)
{
    stringstream ss;

    string stringSQL;

    ss << Usuario->getId();

    stringSQL = "INSERT INTO persona (id, usuario) VALUES (" + ss.str() + ", '" + Usuario->getUsuario() + "')";
    MyConnection::instance()->execute(stringSQL);
}

Usuario* UsuarioDAO::find(int id)
{
    string stringSQL;

    stringstream ss;
    ss << id;

    stringSQL = "SELECT * FROM persona WHERE id = " + ss.str();

    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    if (res->next())
    {
        Usuario* usuario = new Usuario(res);
        delete res;
        return usuario;
    }

    delete res;
    return new Usuario();
}

int UsuarioDAO::checkusuario(string d){
  int a=0;
  string stringSQL;
  stringstream ss;
  ss << d;
   stringSQL = "SELECT * FROM votantes WHERE documento = " + ss.str();
   sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
   if (res->next()){
     a=1;
     return a;
 }

  /*   int a=0;
    while (res->next()) {
        if(res->getString("documento") == d ){
            a=1;
            return a;
          }else{
              a=0;
              return a;
          }
}*/
}
int UsuarioDAO::checkcandidato(string opc){
  
  Queue* queue = new Queue();
    sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM persona WHERE idtc="opc);

    while (res->next())
        queue->qstore(new Usuario(res));

    delete res;

    return queue;

}

void UsuarioDAO::setLogin(string l)
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`votantes` SET `login` = '1' WHERE `votantes`.`documento` ='"<<l<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

void UsuarioDAO::removeLogin()
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`votantes` SET `login` = '0' WHERE `votantes`.`id` ='"<<getId()<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

int UsuarioDAO::checkLogin()
{
    sql::ResultSet* res = MyConnection::instance()->query("Select * from votantes");

    int a=0;
    while (res->next()) {
        if(res->getString("login") != "0" ){
            a=1;
        }
    }
    return a;
}

string UsuarioDAO::getId()
{
    sql::ResultSet* res = MyConnection::instance()->query("SELECT id FROM votantes WHERE login =  1;");
    res->next();
    return res->getString("id");
}
