#include "estdao.h"
#include "myconnection.h"
#include "string.h"
#include <sstream>
#include "getpost.h"
#include "estviewer.h"
#include "estcontroller.h"
EstDAO::EstDAO()
{
    //ctor
}

EstDAO::~EstDAO()
{
    //dtor
}

Queueest* EstDAO::load(string opc){

  Queueest* queueest = new Queueest();
      sql::ResultSet* res = MyConnection::instance()->query("select p.id,p.nombre,p.apellido, d.partido,p.votos, c.total from persona as p inner join partido_politico as d inner join tipo_candidato as c on p.partido=d.id where p.idtc= "+opc+" and p.idtc=c.id");
      while (res->next())
        queueest->qstore(new Estadistica(res));
      delete res;
      return queueest;

}

string EstDAO::getTipoparcial(string p)
{
  string stringSQL = "SELECT partido FROM partido_politico WHERE id = " + p;
  sql::ResultSet* res = MyConnection::instance()->query(stringSQL);
  res->next();
  string x =res->getString("partido");
  return x;
}
