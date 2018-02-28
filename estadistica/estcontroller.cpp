#include "estcontroller.h"
#include "estviewer.h"
#include "estdao.h"
#include <string>
#include <sstream>
#include "getpost.h"
#include "estadistica.h"

EstController::EstController()
{
    //ctor
}

EstController::~EstController()
{
    //dtor
}

void EstController::abm()
{
	inicio();

}


void EstController::inicio(){
		(new EstViewer())->inicio();
}



void EstController::cargar(){
	if ((new AdminDAO())->getAux() =="addu") {addu();}

}
void EstController::reload()
{
//solo que refresque la pagina pero creo que lo voy a meter en la funcion cargar que llame a un viewer y fue
}
