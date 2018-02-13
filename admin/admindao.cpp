#include "admindao.h"
#include "myconnection.h"
#include "string.h"
#include <sstream>
#include "getpost.h"
#include "adminviewer.h"
#include "admincontroller.h"
AdminDAO::AdminDAO()
{
    //ctor
}

AdminDAO::~AdminDAO()
{
    //dtor
}

void AdminDAO::del(Usuario* usuario)
{
    string stringSQL;
    stringstream ss;
    ss << usuario->getId();

    stringSQL = "DELETE FROM persona WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void AdminDAO::save(Usuario* Usuario)
{
    if (exist(Usuario))
        update(Usuario);
    else
        add(Usuario);
}

bool AdminDAO::exist(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "SELECT * FROM persona WHERE id = " + ss.str();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);

    return res->next();
}

void AdminDAO::update(Usuario* Usuario)
{
    string stringSQL;

    stringstream ss;
    ss << Usuario->getId();

    stringSQL = "UPDATE persona SET usuario = '" + Usuario->getUsuario() + "' WHERE id = " + ss.str();
    MyConnection::instance()->execute(stringSQL);
}

void AdminDAO::add(Usuario* Usuario)
{
    string stringSQL;
    stringSQL = "INSERT INTO persona (nombre, apellido, documento) VALUES (" + Usuario->getUsuario() + ", '" + Usuario->getClave() + "','"+Usuario->getDocumento()+"')";
    cout<<"Content-type: text/html"<<endl<<endl;
    cout<<"<h3 color='grey'>QUERY<h3>\n"<<stringSQL<<endl;
  //  MyConnection::instance()->execute(stringSQL);
}

Usuario* AdminDAO::find(int id)
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

int AdminDAO::checkadmin(string id){
  string stringSQL;
  int a =0;
   stringSQL = "SELECT * FROM admin WHERE id = " + id;
   sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
   if (res->next()){
     a=1;
     return a;
 }

}
Queue* AdminDAO::checkcandidato(string opc){

  string a=opc;
  if (a=="consejal"){a="1";}
  if (a=="legislador"){a="2";}
  if (a=="senador"){a="3";}
  if (a=="diputado"){a="4";}
  if (a=="intendente"){a="5";}
  if (a=="gobernador"){a="6";}
  if (a=="presidente"){a="7";}

  Queue* queue = new Queue();
  sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM persona WHERE idtc="+a);
  while (res->next())
  queue->qstore(new Usuario(res));
  delete res;
  return queue;

}

void AdminDAO::setLogin(string l)
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`admin` SET `login` = '1' WHERE `admin`.`id` ='"<<l<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

void AdminDAO::removeLogin()
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`votantes` SET `login` = '0' WHERE `votantes`.`id` ='"<<getId()<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

int AdminDAO::checkLogin()
{
    sql::ResultSet* res = MyConnection::instance()->query("Select * from admin");

    int a=0;
    while (res->next()) {
        if(res->getString("login") != "0" ){
            a=1;
        }
    }
    return a;
}

string AdminDAO::getId()
{
    sql::ResultSet* res = MyConnection::instance()->query("SELECT idvotantes FROM votantes WHERE login =  1;");
    res->next();
    return res->getString("idvotantes");
}
