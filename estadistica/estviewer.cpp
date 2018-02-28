#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "estdao.h"
#include "estviewer.h"
#include "estcontroller.h"
#include <string>
using namespace std;

EstViewer::EstViewer()
{
    //ctor
}

EstViewer::~EstViewer()
{
    //dtor
}

void EstViewer::inicio(){

		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		cout<<"<title>Elecciones 2018</title>"<<endl;
    cout<<"<link rel=\"stylesheet\" href=\"http://localhost/css.css\">"<<endl;
		cout<< "</head>" <<endl;
		cout<< "<body>"<<endl;
	  cout<<"<form class='form-signin' method='post'>"<<endl;
	  cout<<"<h2 class='form-signin-heading'>Binvenido a los resultados de 2018</h2>"<<endl;
		cout<<"</form>"<<endl;
		cout<<"</body></html>"<<endl;

}
void EstViewer::show(Queueest* queueest, string opc)
{
	string a;
	if(opc=="1"){a="Consejales";}
	if(opc=="2"){a="Legisladores";}
	if(opc=="3"){a="Senadores";}
	if(opc=="4"){a="Diputados";}
	if(opc=="5"){a="Intendentes";}
	if(opc=="6"){a="Gobernadores";}
	if(opc=="7"){a="Presidentes";}
		cout<<"<html><head>"<<endl;
	  cout<<"<font color='blue'><h4 align='left'>"+a+"</h4></font>"<<endl;
	  cout<<"<tr>"<<endl;
	  queueest->show();
		cout<<"</tr>"<<endl;
	  cout<<"</body></html>"<<endl;

}

void EstViewer::reload()
{
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
cout<<"<input value='Recargar Estadisticas' onClick='document.location.reload()' type='button' class='btn btn-outline-success my-2 my-sm-0'>"<<endl;
}
