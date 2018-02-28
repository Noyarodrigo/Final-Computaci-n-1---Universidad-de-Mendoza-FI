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
      sql::ResultSet* res = MyConnection::instance()->query("SELECT * FROM persona where idtc="+opc);
      while (res->next())
          queueest->qstore(new Estadistica(res));
      delete res;
      return queueest;

}
