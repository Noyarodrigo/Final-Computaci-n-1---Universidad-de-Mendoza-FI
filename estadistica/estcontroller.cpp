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
		//uno para cada tipo de Eleccion
		(new EstViewer())->show(((new EstDAO())->load("1")),"1");
		(new EstViewer())->show(((new EstDAO())->load("2")),"2");
		(new EstViewer())->show(((new EstDAO())->load("3")),"3");
		(new EstViewer())->show(((new EstDAO())->load("4")),"4");
		(new EstViewer())->show(((new EstDAO())->load("5")),"5");
		(new EstViewer())->show(((new EstDAO())->load("6")),"6");
		(new EstViewer())->show(((new EstDAO())->load("7")),"7");
		(new EstViewer())->reload();
}
