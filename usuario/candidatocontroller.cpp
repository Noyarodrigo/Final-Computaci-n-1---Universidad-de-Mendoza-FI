#include "candidatocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"
#include "candidatoviewer.h"
#include "usuariodao.h"
#include "getpost.h"

CandidatoController::CandidatoController()
{
    //ctor
}

CandidatoController::~CandidatoController()
{
    //dtor
}


void CandidatoController::listar()
{
  //  (new UsuarioDAO())->checkcandidato(Get["categoria"]);

}
void CandidatoController::ver(){
  (new CandidatoViewer())->mostrar();

}

void CandidatoController::exe()
{
  map<string,string> Get;
  initializeGet(Get);
  (new CandidatoViewer())->listar((new UsuarioDAO())->checkcandidato(Get["categoria"]));
  (new UsuarioViewer())->votar();
}
