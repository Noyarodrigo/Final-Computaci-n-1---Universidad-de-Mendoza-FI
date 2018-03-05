#include "admindao.h"
#include "myconnection.h"
#include "string.h"
#include <sstream>
#include "getpost.h"
#include "adminviewer.h"
#include "admincontroller.h"
#include "candidato.h"

AdminDAO::AdminDAO()
{
    //ctor
}

AdminDAO::~AdminDAO()
{
    //dtor
}

void AdminDAO::delu()
{
    string stringSQL = "SELECT idaux FROM admin WHERE id = " + getId();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
    res->next();
    string x =res->getString("idaux");
    stringSQL = "DELETE FROM votantes WHERE id = " + x;
    MyConnection::instance()->execute(stringSQL);
      (new AdminViewer())->eliminado();
  }

void AdminDAO::delc()
{
    string stringSQL = "select p.partido,d.idaux from persona as p inner join admin as d on p.id= "+ getIdaux()+"";
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
    res->next();
    string x =res->getString("idaux");
    string p =res->getString("partido");
    if (x!="0") {
      stringSQL = "DELETE FROM persona WHERE id = " + x;
      MyConnection::instance()->execute(stringSQL);
      stringstream stringSQL2;
      stringSQL2 <<"UPDATE `elecciones`.`partido_politico` SET socios = socios-1 WHERE `partido_politico`.`id` ='"+p+"';";
      MyConnection::instance()->execute(stringSQL2.str());
      (new AdminViewer())->eliminado();
    }


}

void AdminDAO::delp()
{
    string stringSQL = "SELECT idaux FROM admin WHERE id = " + getId();
    sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
    res->next();
    string x =res->getString("idaux");
    stringSQL = "DELETE FROM partido_politico WHERE id = " + x;
    MyConnection::instance()->execute(stringSQL);
    (new AdminViewer())->eliminado();
}


void AdminDAO::addu(Usuario* Usuario)
{
  string stringSQL;
  stringSQL = "SELECT documento FROM votantes WHERE documento = " + Usuario->getDocumento();
  sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
  if (res->next())
  {
    (new AdminViewer())->nope();
  }else{
    stringSQL = "INSERT INTO votantes (nombre, apellido, documento) VALUES ('" + Usuario->getNombre() + "', '" + Usuario->getApellido() + "','"+Usuario->getDocumento()+"')";
    MyConnection::instance()->execute(stringSQL);
    (new AdminViewer())->agregado();
  }
}

void AdminDAO::addc(Candidato* Candidato)
{
  string stringSQL;
  stringSQL = "SELECT telefono FROM persona WHERE telefono = " + Candidato->getTel();
  sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
  if (res->next())
  {
    (new AdminViewer())->nope();
  }else{
    stringSQL = "INSERT INTO persona (nombre, apellido, telefono, idtc, partido) VALUES ('" + Candidato->getNombre() + "', '" + Candidato->getApellido() + "','"+Candidato->getTel()+"', '"+Candidato->getIdtc()+"','"+Candidato->getPartido()+"')";
    MyConnection::instance()->execute(stringSQL);
    stringstream stringSQL2;
    stringSQL2 <<"UPDATE `elecciones`.`partido_politico` SET socios = socios+1 WHERE `partido_politico`.`id` ='"+Candidato->getPartido()+"';";
    MyConnection::instance()->execute(stringSQL2.str());
    (new AdminViewer())->agregado();
  }
}

void AdminDAO::addp(Partido* Partido)
{
  string stringSQL;
  stringSQL = "SELECT partido FROM partido_politico WHERE partido = '"+ Partido->getNombre()+"'";
  sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
  if (res->next())
  {
    (new AdminViewer())->nope();
  }else{
    stringSQL = "INSERT INTO partido_politico (partido) VALUES ('" + Partido->getNombre() + "')";
    MyConnection::instance()->execute(stringSQL);
    (new AdminViewer())->agregado();
  }
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

void AdminDAO::setLogin(string l)
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`admin` SET `login` = '1' WHERE `admin`.`id` ='"<<l<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

void AdminDAO::removeLogin()
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`admin` SET `login` = '0' WHERE `admin`.`id` ='"<<getId()<<"';";
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
    sql::ResultSet* res = MyConnection::instance()->query("SELECT id FROM admin WHERE login =  1;");
    res->next();
    return res->getString("id");
}

void AdminDAO::setAux(string l)
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`admin` SET `ultac` = '"+l+"' WHERE `admin`.`id` ='"<<getId()<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

string AdminDAO::getAux(){
  sql::ResultSet* res = MyConnection::instance()->query("Select ultac from admin WHERE `admin`.`id`  ="+getId()+";");
    res->next();
    string a =res->getString("ultac");
    return a;
}

void AdminDAO::setIdaux(string l)
{
    stringstream stringSQL;
    stringSQL <<"UPDATE `elecciones`.`admin` SET `idaux` = '"+l+"' WHERE `admin`.`id` ='"<<getId()<<"';";
    MyConnection::instance()->execute(stringSQL.str());
}

string AdminDAO::getIdaux(){
  sql::ResultSet* res = MyConnection::instance()->query("Select idaux from admin WHERE `admin`.`id`  ="+getId()+";");
    res->next();
    string a =res->getString("idaux");
    return a;
}

Queueusuario* AdminDAO::infu(){

  Queueusuario* queueusuario = new Queueusuario();
      sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM votantes");
      while (res->next())
          queueusuario->qstore(new Usuario(res));
      delete res;
      return queueusuario;

}

Queuecandidato* AdminDAO::infc(){

  Queuecandidato* queuecandidato = new Queuecandidato();
      sql::ResultSet* res = MyConnection::instance()->query("select p.id,p.nombre,p.apellido,p.telefono ,c.idtc, d.partido,p.votos from persona as p inner join partido_politico as d inner join tipo_candidato as c on p.partido=d.id and p.idtc=c.id");
      while (res->next())
          queuecandidato->qstore(new Candidato(res));
      delete res;
      return queuecandidato;

}

Queuepartido* AdminDAO::infp(){

  Queuepartido* queuepartido = new Queuepartido();
      sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM partido_politico");
      while (res->next())
          queuepartido->qstore(new Partido(res));
      delete res;
      return queuepartido;

}

Queuepartidolista* AdminDAO::plista(){

  Queuepartidolista* queuepartidolista = new Queuepartidolista();
      sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM partido_politico");
      while (res->next())
          queuepartidolista->qstore(new Partidolista(res));
      delete res;
      return queuepartidolista;

}
