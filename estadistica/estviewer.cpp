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

	map<string,string> Get;
	initializeGet(Get);
	if (Get.find("categoria")!=Get.end()){
		(new EstController())->cate();
	}else{

			cout<<"Content-type: text/html"<<endl<<endl;
			cout<<"<html><head>"<<endl;
			cout<<"<title>Estadisticas 2018</title>"<<endl;
			css();
			cout<<"</head>"<<endl;
			cout<<"<body>"<<endl;
			cout<<"<font color='blue'><h1 align='center'>ESTADISTICAS DE 2018</h1></font>"<<endl;
			cout<<"<form class='categoria' method='get'>"<<endl;
			cout<<"  <fieldset >"<<endl;
			cout<<"    <legend align='center'>Elige una categoria luego, haz click en siguiente</legend>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"          <input type=\"radio\" name=\"categoria\" class='incat' value=\"1\"> Consejales"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"           <input type=\"radio\" name=\"categoria\"  class='incat' value=\"2\"> Legisladores"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"          <input type=\"radio\" name=\"categoria\"  class='incat' value=\"3\"> Senadores"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"          <input type=\"radio\" name=\"categoria\"  class='incat' value=\"4\"> Diputados"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"           <input type=\"radio\" name=\"categoria\"  class='incat' value=\"5\"> Intendentes"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"          <input type=\"radio\" name=\"categoria\"  class='incat' value=\"6\"> Gobernadores"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"      <p>"<<endl;
			cout<<"          <input type=\"radio\" name=\"categoria\"  class='incat' value=\"7\"> Presidentes"<<endl;
			cout<<"      </p>"<<endl;
			cout<<"  </fieldset>"<<endl;
			cout<<"	<p align='center'>	"<<endl;
			cout<<"<button  class='button' type='submit'>Siguiente</button>"<<endl;
			cout<<"	</p>	"<<endl;
			cout<<"</form>"<<endl;
			cout<<"</body></html>"<<endl;
			}
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
	cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		css();
		cout<<"<body>"<<endl;
		cout<<"<table id='candidatos'>"<<endl;
		cout<<" <tr><TH COLSPAN=\"5\"style=\"text-align:center;\">"+a+"</th></tr>"<<endl;
		cout<<"<tr><th>Nombre</th><th>Apellido</th><th>Partido</th><th>Parcial (%)</th><th>Votos</th></tr>"<<endl;
	  cout<<"<tr>"<<endl;
	  queueest->show();
		cout<<"</tr>"<<endl;
		cout<<"</table>"<<endl;
		cout<<"<form align='center' class='categoria' method='get'>"<<endl;
		cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
		cout<<"</form>"<<endl;
	  cout<<"</body></html>"<<endl;

}

void EstViewer::reload()
{
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
cout<<"<input value='Recargar Estadisticas' onClick='document.location.reload()' type='button' class='btn btn-outline-success my-2 my-sm-0'>"<<endl;
}

void EstViewer::css()
{
	cout<<"<style type=\"text/css\">"<<endl;
	cout<<"body{background-color: #CEF0EE;}"<<endl;
//form
		cout<<"form {"<<endl;
			cout<<" margin-top: 40px;"<<endl;
			cout<<" margin-left: auto;"<<endl;
			cout<<" margin-right: auto;"<<endl;
			cout<<" margin-bottom: auto;"<<endl;
			 cout<<"border-radius: 3px;"<<endl;
			cout<<"width: 60%;"<<endl;
			cout<<"font: normal bold 12px Verdana, Arial;"<<endl;
			cout<<"}"<<endl;

		cout<<".incat {"<<endl;
			 cout<<" width: 20px;"<<endl;
			 cout<<" margin-bottom: 10px;"<<endl;
			 cout<<" display: inline-block;"<<endl;
			 cout<<"padding: 20px 20px;"<<endl;
			 cout<<"border: 1px solid #b7b7b7;"<<endl;
			 cout<<"border-radius: 3px;"<<endl;
			 cout<<"font: normal 16px/normal \"Times New Roman\", Times, serif;"<<endl;
			 cout<<"color: rgba(0,142,198,1);"<<endl;
			 cout<<"text-overflow: clip;"<<endl;
			 cout<<"background: rgba(206,227,234,1);"<<endl;
				cout<<"font: normal bold 12px Verdana, Arial;"<<endl;
				cout<<"}"<<endl;

		cout<<"	fieldset {   "<<endl;
		  cout<<"-moz-border-radius:5px; "<<endl;
			cout<<"  border-radius: 5px;  "<<endl;
		  cout<<"-webkit-border-radius: 5px;"<<endl;
			 cout<<"}"<<endl;
	/*INPUT*/
		cout<<"form input {"<<endl;
		cout<<" width: 200px;"<<endl;
		cout<<" margin-bottom: 10px;"<<endl;
	 	cout<<" display: inline-block;"<<endl;
	  cout<<"padding: 10px 20px;"<<endl;
	  cout<<"border: 1px solid #b7b7b7;"<<endl;
	  cout<<"border-radius: 3px;"<<endl;
	  cout<<"font: normal 16px/normal \"Times New Roman\", Times, serif;"<<endl;
	  cout<<"color: rgba(0,142,198,1);"<<endl;
	  cout<<"text-overflow: clip;"<<endl;
	  cout<<"background: rgba(206,227,234,1);"<<endl;
		cout<<"}"<<endl;

	/*LaBeL*/
	cout<<"form label {"<<endl;
		cout<<"display: inline-block;"<<endl;
	 	cout<<" width: 150px;"<<endl;
		//cout<<"float: left;"<<endl;
	  cout<<"width: 110px;"<<endl;
	  cout<<"padding: 10px;"<<endl;
	  cout<<"font: normal 16px/1 \"Times New Roman\", Times, serif;"<<endl;
	  cout<<"color: rgba(255,255,255,1);"<<endl;
	  cout<<"text-align: center;"<<endl;
	  cout<<"background: #6ea8bf;"<<endl;
		cout<<"}"<<endl;

		/*boton*/
		cout<<".button {"<<endl;
		cout<<"background-color: #1987E8;"<<endl;
		cout<<"border: none;"<<endl;
		cout<<"color: white;"<<endl;
		cout<<"border-radius: 5px;"<<endl;
		cout<<"padding: 12px 25px;"<<endl;
		cout<<"text-align: center;"<<endl;
		cout<<"text-decoration: none;"<<endl;
		cout<<"display: inline-block;"<<endl;
		cout<<"font-size: 16px;"<<endl;
		cout<<"font: normal 16px/1 \"Times New Roman\", Times, serif;"<<endl;
		cout<<"}"<<endl;

		//contenedor
		cout<<"div {"<<endl;
		cout<<"width:60%;"<<endl;
		cout<<"margin:auto;"<<endl;
    cout<<"border: 1px solid grey;"<<endl;
		cout<<"border-radius: 15px 50px 30px;"<<endl;
    cout<<"padding: 15px;"<<endl;
		cout<<"height:60%;"<<endl;
		cout<<"text-align:center;"<<endl;
		cout<<"background:#97C8E8;"<<endl;
		cout<<"}"<<endl;

		//TABLAS
		cout<<"#candidatos {"<<endl;
		    cout<<"font-family: \"Trebuchet MS\", Arial, Helvetica, sans-serif;"<<endl;
		    cout<<"border-collapse: collapse;"<<endl;
		    cout<<"width: 80%;"<<endl;
				cout<<"margin:auto;"<<endl;
		cout<<"}"<<endl;
		cout<<"#candidatos td, #candidatos th {"<<endl;
		    cout<<"border: 1px solid #ddd;"<<endl;
		    cout<<"padding: 8px;"<<endl;
		cout<<"}"<<endl;
		cout<<"#candidatos tr:nth-child(even){background-color: #f2f2f2;}"<<endl;
		cout<<"#candidatos tr:hover {background-color: #ddd;}"<<endl;
		cout<<"#candidatos th {"<<endl;
		    cout<<"padding-top: 12px;"<<endl;
		    cout<<"padding-bottom: 12px;"<<endl;
		    cout<<"text-align: left;"<<endl;
		    cout<<"background-color: #1987E8;"<<endl;
		    cout<<"color: white;"<<endl;
		 cout<<"}"<<endl;


	cout<<"</style>"<<endl;
}
