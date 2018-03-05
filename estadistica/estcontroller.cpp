#include "estcontroller.h"
#include "estviewer.h"
#include "estdao.h"
#include <string>
#include <sstream>
#include <iomanip> // setprecision
#include "getpost.h"
#include "estadistica.h"
#include <cstdlib>

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
	ver();

}


void EstController::cate(){
	map<string,string> Get;
	initializeGet(Get);
	if (Get["categoria"]=="1") {(new EstViewer())->show(((new EstDAO())->load("1")),"1");}
	if (Get["categoria"]=="2") {(new EstViewer())->show(((new EstDAO())->load("2")),"2");}
	if (Get["categoria"]=="3") {(new EstViewer())->show(((new EstDAO())->load("3")),"3");}
	if (Get["categoria"]=="4") {(new EstViewer())->show(((new EstDAO())->load("4")),"4");}
	if (Get["categoria"]=="5") {(new EstViewer())->show(((new EstDAO())->load("5")),"5");}
	if (Get["categoria"]=="6") {(new EstViewer())->show(((new EstDAO())->load("6")),"6");}
	if (Get["categoria"]=="7") {(new EstViewer())->show(((new EstDAO())->load("7")),"7");}
}

void EstController::ver()
{
	(new EstViewer())->inicio();
}

string EstController::parcial(string t, string v)
{
	float c=atoi(t.c_str());
	float b=atoi(v.c_str());
	float	a= (b/c)*100;
	stringstream stream;
	stream << fixed << setprecision(2) << a;
	string s = stream.str();
	return s;
}
