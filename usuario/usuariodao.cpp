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
      if (x==1){
        sql::ResultSet* res = MyConnection::instance()->query("Select idtc from persona WHERE `persona`.`id`  ="+cod+";");
        res->next();
        string c =res->getString("idtc");
        if (c ==idtc) {
          stringSQL <<"UPDATE `elecciones`.`votantes` SET " +a+"= '0' WHERE `votantes`.`id` ='"+getId()+"' AND `votantes`.`"+a+"` ='1' ";
          MyConnection::instance()->execute(stringSQL.str());
          //sumar voto, estadistica y mensaje de votado
          sumarvoto(cod, idtc);
          sumarest(idtc);
          (new UsuarioViewer())->yav();
        }else{(new UsuarioViewer())->error();}
      }
      if (x==0) {
        (new UsuarioViewer())->fail();
      }
  }
}

int UsuarioDAO::checkvoto(string a)
{
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

void UsuarioDAO::sumarest(string idtc)
{
  stringstream stringSQL;
  stringSQL <<"UPDATE `elecciones`.`tipo_candidato` SET total= total+1 WHERE `tipo_candidato`.`id` ="+idtc;
  MyConnection::instance()->execute(stringSQL.str());
}
