#include "candidatocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"
#include "candidatoviewer.h"
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
