#include "usuariodao.h"
#include "myconnection.h"
#include "string.h"
#include <sstream>
#include "getpost.h"
#include "usuarioviewer.h"
#include "usuariocontroller.h"
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

}
Queue* UsuarioDAO::checkcandidato(string opc){

  Queue* queue = new Queue();
  sql::ResultSet* res = MyConnection::instance()->query("select p.id,p.nombre,p.apellido, d.partido from persona as p inner join partido_politico as d on p.partido=d.id where p.idtc="+opc);
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

void UsuarioDAO::votar(string a, string cod, string idtc){

  map<string,string> Get;
  initializeGet(Get);
  stringstream stringSQL;
  if (Get.find("categoria")!=Get.end()) {
    int x=(new UsuarioDAO())->checkvoto(a);
    (new UsuarioController())->voto(x);
      if (x==1){
      stringSQL <<"UPDATE `elecciones`.`votantes` SET " +a+"= '0' WHERE `votantes`.`id` ='"+getId()+"' AND `votantes`.`"+a+"` ='1' ";
      MyConnection::instance()->execute(stringSQL.str());
      sumarvoto(cod, idtc);
    }
  }
}

int UsuarioDAO::checkvoto(string a)
{
  cout<<"<h3 color='grey'>checkvoto<h3>\n";
    sql::ResultSet* res = MyConnection::instance()->query("Select "+a+" from votantes WHERE `votantes`.`id`  ="+getId()+";");
    res->next();
    int b =res->getInt(""+a+"");
    return b;
}

void UsuarioDAO::sumarvoto(string cod, string idtc)
{
  stringstream stringSQL;
  stringSQL <<"UPDATE `elecciones`.`persona` SET votos= votos+1 WHERE `persona`.`id` ='"+cod+"' AND `persona`.`idtc`="+idtc;
  MyConnection::instance()->execute(stringSQL.str());
}
