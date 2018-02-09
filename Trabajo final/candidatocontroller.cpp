#include "candidatocontroller.h"
#include "usuarioviewer.h"
#include "usuariodao.h"

CandidatoController::CandidatoController()
{
    //ctor
}

CandidatoController::~CandidatoController()
{
    //dtor
}


void CandidatoController::listar(string opc)
{
    (new UsuarioDAO())->checkcandidato(opc);

}
