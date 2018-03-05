#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "admindao.h"
#include "adminviewer.h"
#include "admincontroller.h"
#include <string>
using namespace std;

AdminViewer::AdminViewer()
{
    //ctor
}

AdminViewer::~AdminViewer()
{
    //dtor
}

void AdminViewer::inicio(){
	int z=0,x=0;

	x=(new AdminDAO())->checkLogin();

	if (x==0) {
		map<string,string> Post;
		initializePost(Post);
		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		css();
		cout<<"<title>Elecciones 2018</title>"<<endl;
  	cout<< "</head>" <<endl;
		cout<< "<body>"<<endl;
		cout<< "<div>"<<endl;
		cout<< "<br>"<<endl;
		cout<< "<img src=\"http://www.jusdeleste.com.ar/wp-content/uploads/2017/04/logo-universidad-de-mendoza.png\" width=\"150\" height=\"150\">"<<endl;
		cout<< "<br>"<<endl;
	  cout<<"<form class='categoria' method='post'>"<<endl;
	  cout<<"<h2 class='form-signin-heading'>INGRESE SU ID DE ADMINISTRADOR</h2>"<<endl;
		cout<< "<br>"<<endl;
	  cout<<"<label for='id' class='label'>Administrador</label>"<<endl;
	  cout<<"<input type='text' name='id' class='input' placeholder='AQUI' required autofocus>"<<endl;
	  cout<<"<button class='button' type='submit'>Ingresar</button>"<<endl;
	  cout<<"</form>"<<endl;
	  cout<<"</div>"<<endl;
		cout<<"</body></html>"<<endl;

	      if (Post.find("id")!=Post.end()) {
					z=(new AdminDAO())->checkadmin(Post["id"]);
	          if(z == 1){
								((new AdminDAO()) ->setLogin(Post["id"]));
								cout<<"<font color='green'><h1 align='center'>Ingreso con Exito!</h1></font>"<<endl;
								cout<<"<form align='center' class='categoria'>"<<endl;
							//	cout<<"<input value='Ir al menu' ' type='input' class='input'>"<<endl;
								cout<<"<button class='button' onClick='document.location.reload() type='submit'>Ir al Menu</button>"<<endl;
								cout<<"</form>"<<endl;
							}else{fracaso();}
						}
	}else{

		(new AdminViewer())->ver();

	}

}

void AdminViewer::fracaso()
{
	cout<<"<font color='red'><h1 align='center'>Ingreso Incorrecto!</h1></font>"<<endl;
}

void AdminViewer::ver()
{
	map<string,string> Get;
	initializeGet(Get);
	if (Get.find("opc")!=Get.end()) {
		cout<<"Content-type: text/html"<<endl<<endl;
		(new AdminController())->setAux();
		if (Get["opc"]== "addu" ) {
			(new AdminViewer())->dusu();	}

		if (Get["opc"]== "addc") {
			(new AdminViewer())->dcan((new AdminDAO())->plista());	}

		if (Get["opc"]== "addp") {
			(new AdminViewer())->dpar();	}

		if (Get["opc"]== "delu" || Get["opc"]== "delc" || Get["opc"]== "delp" || Get["opc"]== "modc") {

				(new AdminViewer())->did();
				}

		if (Get["opc"]== "out" ) {
			(new AdminController())->out();
				}
			if (Get["opc"]== "infu" || Get["opc"]== "infc" || Get["opc"]== "infp") {
				(new AdminController())->categoria();
			}
	}else{

		if (Get.find("nombre")!=Get.end() || Get.find("apellido")!=Get.end() || Get.find("documento")!=Get.end() || Get.find("id")!=Get.end()) {

			if (Get.find("id")!=Get.end()) {

			(new AdminController())->idAux();
			}
				cout<<"Content-type: text/html"<<endl<<endl;
				cout<<"<font color='blue'><h1 align='center'>PANEL DE ADMINISTRACION</h1></font>"<<endl;
				(new AdminController())->categoria();

		}else{
				cout<<"Content-type: text/html"<<endl<<endl;
				cout<<"<html><head>"<<endl;
				css();
				cout<<"<font color='blue'><h1 align='center'>PANEL DE ADMINISTRACION</h1></font>"<<endl;
				cout<<"<form class='categoria' method='get'>"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend align='center'>Opciones de Votantes</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" class='incat' value=\"addu\"> Agregar votante"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"delu\"> Eliminar votante "<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" class='incat' value=\"infu\"> Info de votantes"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend align='center'>Opciones de Candidatos</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" class='incat' value=\"addc\"> Agregar candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"delc\"> Eliminar candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"infc\"> info candidatos"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend align='center'>Opciones de Partido</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"addp\"> Agregar partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"delp\"> Eliminar partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" class='incat' value=\"infp\"> Info partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend align='center'>SALIR DE LA ADMINISTRACION</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input text-color='grey' type=\"radio\" name=\"opc\" class='incat' value=\"out\"> LOG OUT"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"	<p align='center'>	"<<endl;
				cout<<"<button class='button' type='submit'>Siguiente</button>"<<endl;
				cout<<"	<p>	"<<endl;
				cout<<"</form>"<<endl;
			}


		}
	}
void AdminViewer::dusu()
{
	cout<<"<html><head>"<<endl;
	css();
	cout<< "</head>" <<endl;
	cout<< "<body>"<<endl;
	cout<<"<form class='categoria' method='get'>"<<endl;
	cout<< "<div>"<<endl;
	cout<< "<br>"<<endl;
	cout<< "<br>"<<endl;
	cout<< "<br>"<<endl;
	cout<<"<h3 color='grey'>INGRESE LOS DATOS<h3>\n";
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Nombre</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='input' placeholder='Nombre' required autofocus>"<<endl;
	//apellido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Apellido</label>"<<endl;
	cout<<"<input type='text' name='apellido' class='input' placeholder='Apellido' >"<<endl;
	//DOCUMENTO
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Documento</label>"<<endl;
	cout<<"<input type='text' name='documento' class='input' placeholder='Documento' >"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<< "</div>"<<endl;
	cout<<"<p align='center'>"<<endl;
	cout<<"<button class='button' type='submit'>Ingresar datos</button>"<<endl;
	cout<<"</p>"<<endl;
	cout<<"</form></body>"<<endl;

}
void AdminViewer::dcan(Queuepartidolista* queuepartidolista)
{

	cout<<"<html><head>"<<endl;
	css();
	cout<< "</head>" <<endl;
	cout<< "<body>"<<endl;
	cout<< "<div>"<<endl;
	cout<<"<form class='categoria' method='get'>"<<endl;
	cout<<"<h3 color='grey'>INGRESE LOS DATOS<h3>\n";
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Nombre</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='input' placeholder='Nombre' required autofocus>"<<endl;
	//apellido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Apellido</label>"<<endl;
	cout<<"<input type='text' name='apellido' class='input' placeholder='Apellido' >"<<endl;
	//telefono
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='telefono' class='label'>Telefono</label>"<<endl;
	cout<<"<input type='text' name='telefono' class='input' placeholder='Telefono' >"<<endl;
	//idtc con lista desplegable
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='idtc' class='label'>Cargo</label>"<<endl;
			// lista
				cout<<"<select name=\"idtc\">"<<endl;
				cout<<"<option selected value=\"0\"> Elige una categoria </option>"<<endl;
				cout<<"<option value=\"1\">Consejal</option>"<<endl;
				cout<<"<option value=\"2\">Legislador</option>"<<endl;
				cout<<"<option value=\"3\">Senador</option>"<<endl;
				cout<<"<option value=\"4\">Diputado</option>"<<endl;
				cout<<"<option value=\"5\">Intendente</option>"<<endl;
				cout<<"<option value=\"6\">Gobernador</option>"<<endl;
				cout<<"<option value=\"7\">Presidente</option>"<<endl;
				cout<<"</select>"<<endl;

	//partido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='partido' class='class='label'>Partido</label>"<<endl;
				//lista con base de datos
				cout<<"<select name=\"partido\">"<<endl;
				cout<<"<option selected value=\"0\"> Elige un partido </option>"<<endl;
				queuepartidolista->show();
				cout<<"</select>"<<endl;
	cout<< "</div>"<<endl;
	//boton
	cout<< "<p align='center'>"<<endl;
	cout<<"<button align='center' class='button' type='submit'>Ingresar datos</button>"<<endl;
	cout<< "<p>"<<endl;
	cout<<"</form></body>"<<endl;
}
void AdminViewer::dpar()
{
	cout<<"<html><head>"<<endl;
	css();
	cout<< "</head>" <<endl;
	cout<< "<body>" <<endl;
	cout<< "<div>" <<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<form class='categoria' method='get'>"<<endl;
	cout<<"<h3 color='grey'>NUEVO PARTIDO<h3>\n";
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='label'>Nombre</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='input' placeholder='Nombre del partido' required autofocus>"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<< "</div>" <<endl;
	cout<< "<p align='center'>"<<endl;
	cout<<"<button align='center' class='button' type='submit'>Ingresar datos</button>"<<endl;
	cout<< "<p>"<<endl;
	cout<<"</form><body>"<<endl;

}
void AdminViewer::did()
{
	css();
	cout<<"<div>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<form margin='auto' class='categoria' method='get'>"<<endl;
	cout<<"<h3 color='grey'>INGRESE EL ID A ELIMINAR<h3>\n";
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='id' class='label'>ID</label>"<<endl;
	cout<<"<input type='text' name='id' class='input' placeholder='AQUI' >"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<< "</div>" <<endl;
	cout<< "<p align='center'>"<<endl;
	cout<<"<button align='center' class='button' type='submit'>Eliminar</button>"<<endl;
	cout<< "<p>"<<endl;
	cout<<"</form><body>"<<endl;;

}

void AdminViewer::infu(Queueusuario* queueusuario){

  cout<<"<html><head>"<<endl;
	css();
  cout<<"<font color='blue'><h3 align='center'>INFORMACION DE USUARIOS</h3></font>"<<endl;
	cout<<"</head>"<<endl;
	cout<<"<body>"<<endl;
  cout<<"</h1></font>"<<endl;
	cout<<"<table id='candidatos'>"<<endl;;
	cout<<"<tr>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Apellido</th><th>Documento</th><th>Consejal</th><th>Legislador</th><th>senador</th><th>Diputado</th><th>Intendente</th><th>Gobernador</th><th>Presidente</th></font>"<<endl;
	queueusuario->show();
	cout<<"</tr>"<<endl;
	cout<<"</table>"<<endl;
	cout<<"<form align='center' class='categoria' method='get'>"<<endl;
	cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;
  cout<<"</body></html>"<<endl;

}

void AdminViewer::infc(Queuecandidato* queuecandidato){

  cout<<"<html><head>"<<endl;
	css();
	cout<<"</head>"<<endl;
  cout<<"<font color='blue'><h2 align='center'>INFORMACION DE CANDIDATOS</h2></font>"<<endl;
	cout<<"<body>"<<endl;
	cout<<"<table id='candidatos'>"<<endl;
	cout<<"<tr>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Apellido</th><th>Telefono</th><th>Cargo</th><th>Partido</th><th>Votos</th></font>"<<endl;
  cout<<"<br>"<<endl;
  queuecandidato->show();
	cout<<"</tr>"<<endl;
	cout<<"</table>"<<endl;
	cout<<"<form align='center' class='categoria' method='get'>"<<endl;
	cout<<"<button class='button' type='submit'>volver</button>"<<endl;
	cout<<"</form>"<<endl;
  cout<<"</body></html>"<<endl;

}

void AdminViewer::infp(Queuepartido* queuepartido){

  cout<<"<html><head>"<<endl;
	css();
  cout<<"<font color='blue'><h3 align='center'>INFORMACION DE PARTIDOS</h3></font>"<<endl;
	cout<<"</head>"<<endl;
	cout<<"<body>"<<endl;
	cout<<"<table id='candidatos'>"<<endl;
	cout<<"<tr>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Cant. de socios</th></font>"<<endl;
  cout<<"<br>"<<endl;
  queuepartido->show();
	cout<<"</tr>"<<endl;
	cout<<"</table>"<<endl;
	cout<<"<form align='center' class='categoria' method='get'>"<<endl;
	cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;
	cout<<"</body></html>"<<endl;

}

void AdminViewer::out()
{

	css();
	cout<<"<font color='red' align='center'><h3 >HAS SALIDO CORRECTAMENTE<h3></font>\n";
	cout<<"<form class='categoria' width='70\%' method='get' align='center'>"<<endl;
	cout<<"<button class='button' type='submit'>Salir</button>"<<endl;
	cout<<"</form>"<<endl;
}
void AdminViewer::nope()
{
	css();
	cout<<"<form class='categoria'align='center' method='get'>"<<endl;
	cout<<"<font color='red'><h3 >ALGO SALIO MAL<h3></font>\n";
	cout<<"<font color='grey'><h4 >Resiva los datos ingresados<h4></font>\n";
	cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}
void AdminViewer::agregado()
{
	css();
	cout<<"<form class='categoria' align='center' method='get'>"<<endl;
	cout<<"<font color='green'><h3>AGREGADO CORRECTAMENTE<h3>\n";
	cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}
void AdminViewer::eliminado()
{
	css();
	cout<<"<form class='categoria'align='center' method='get'>"<<endl;
	cout<<"<font color='green'><h3>ELIMINADO CORRECTAMENTE<h3>\n";
	cout<<"<button class='button' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}

void AdminViewer::css()
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
