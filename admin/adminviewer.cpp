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
		cout<<"<title>Elecciones 2018</title>"<<endl;
    cout<<"<link rel=\"stylesheet\" href=\"http://localhost/css.css\">"<<endl;

		cout<< "</head>" <<endl;
		cout<< "<body>   <div class='container'>"<<endl;
		cout<<"<div class='header'></div>"<<endl;
		cout<<"<h1>LOG IN<h1>\n";
		cout<<"<div class='input'>"<<endl;
	  cout<<"<form class='form-signin' method='post'>"<<endl;
	  cout<<"<h2 class='form-signin-heading'>Ingrese su id de administrador</h2>"<<endl;
	  cout<<"<label for='id' class='sr-only'>Usuario</label>"<<endl;
	  cout<<"<input type='text' name='id' class='form-control' placeholder='ID' required autofocus>"<<endl;
	  cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar</button>"<<endl;
	  cout<<"</form>"<<endl;
	  cout<<"</div>"<<endl;
		cout<<"</div></body></html>"<<endl;

	      if (Post.find("id")!=Post.end()) {
					z=(new AdminDAO())->checkadmin(Post["id"]);
	          if(z == 1){
								((new AdminDAO()) ->setLogin(Post["id"]));
								cout<<"<font color='green'><h1 align='center'>Ingreso con Exito!</h1></font>"<<endl;
								cout<<"<form align='center'>"<<endl;
								cout<<"<input value='Ir al menu de administracion' onClick='document.location.reload()' type='button' class='btn btn-outline-success my-2 my-sm-0'>"<<endl;
								cout<<"</form>"<<endl;
							}else{fracaso();}
						}

		cout<<"</div></body></html>"<<endl;
	}else{

		(new AdminViewer())->ver();

	}

}

void AdminViewer::fracaso()
{
	cout<<"<font color='red'><h1 align='center'>Ingreso Incorrecto!</h1></font>"<<endl;
}

void AdminViewer::fail(){
	cout<<"<font color='red'><h1 align='center'>Ya has votado en esa categoria!</h1></font>"<<endl;
}

void AdminViewer::info(string id, string categoria) {
	cout<<"<html><head>"<<endl;
  cout<<"	<br>	"<<endl;
	cout<<"<font color='grey'>"<<endl;
  cout<<"</h1>\n";
  cout<<"<h3>categoria: "<<categoria<<endl;
  cout<<"</h3>\n";
	cout<<"<h3>Su id de administrador es:"+id<<endl;
	cout<<"</h3>\n";
	cout<<"</font>"<<endl;
	cout<<"</body></html>"<<endl;
}

void AdminViewer::yav(){
	cout<<"<font color='Green'><h1 align='center'>Voto ingresado !</h1></font>"<<endl;
}

void AdminViewer::ver()
{
	map<string,string> Get;
	initializeGet(Get);
	if (Get.find("opc")!=Get.end()) {
		cout<<"Content-type: text/html"<<endl<<endl;
		(new AdminViewer())->info((new AdminDAO())->getId(), Get["opc"]);
		(new AdminController())->setAux();
		if (Get["opc"]== "addu" ) {
			(new AdminViewer())->dusu();	}

		if (Get["opc"]== "addc") {
			(new AdminViewer())->dcan();	}

		if (Get["opc"]== "addp") {
			(new AdminViewer())->dpar();	}

		if (Get["opc"]== "delu" || Get["opc"]== "delc" || Get["opc"]== "modu" || Get["opc"]== "modc") {

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
				(new AdminController())->categoria();

		}else{
				cout<<"Content-type: text/html"<<endl<<endl;
				cout<<"<html><head>"<<endl;
				cout<<"<font color='blue'><h1 align='center'>Panel de administracion</h1></font>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"	<br>"<<endl;
				cout<<"	<br>"<<endl;
				cout<<"<form class='form-signin' method='get'>"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend>Opciones de Votantes</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" value=\"addu\"> Agregar votante"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"delu\"> Quitar votante "<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" value=\"modu\"> Modificar votante"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" value=\"infu\"> Info de votante"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend>Opciones de Candidatos</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input type=\"radio\" name=\"opc\" value=\"addc\"> Agregar candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"delc\"> Quitar candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"modc\"> Modificar candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"infc\"> info candidato"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend>Opciones de Partido</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"addp\"> Agregar partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"delp\"> Eliminar partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"           <input type=\"radio\" name=\"opc\" value=\"infp\"> Info partido"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"  <fieldset>"<<endl;
				cout<<"    <legend>SALIR DE LA ADMINISTRACION</legend>"<<endl;
				cout<<"      <p>"<<endl;
				cout<<"          <input text-color='grey' type=\"radio\" name=\"opc\" value=\"out\"> LOG OUT"<<endl;
				cout<<"      </p>"<<endl;
				cout<<"  </fieldset>"<<endl;
				cout<<"	<br>	"<<endl;
				cout<<"<div align='center'>"<<endl;
				cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Siguiente</button>"<<endl;
				cout<<"</div>"<<endl;
				cout<<"</form>"<<endl;
			}


		}
	}


void AdminViewer::dusu()
{

	cout<<"<html><head>"<<endl;
	cout<< "</head>" <<endl;
	cout<< "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<h3 color='grey'>Ingrese los datos<h3>\n";
	cout<<"<div class='container'>"<<endl;

	cout<<"<form class='form-signin' method='get'>"<<endl;
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
	//apellido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Apellido</label>"<<endl;
	cout<<"<input type='text' name='apellido' class='form-control' placeholder='Apellido' >"<<endl;
	//DOCUMENTO
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Documento</label>"<<endl;
	cout<<"<input type='text' name='documento' class='form-control' placeholder='Documento' >"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar datos</button>"<<endl;
	cout<<"</div>"<<endl;

}

void AdminViewer::dcan()
{

	cout<<"<html><head>"<<endl;
	cout<< "</head>" <<endl;
	cout<< "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<h3 color='grey'>Ingrese los datos<h3>\n";
	cout<<"<div class='container'>"<<endl;

	cout<<"<form class='form-signin' method='get'>"<<endl;
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
	//apellido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Apellido</label>"<<endl;
	cout<<"<input type='text' name='apellido' class='form-control' placeholder='Apellido' >"<<endl;
	//telefono
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='telefono' class='sr-only'>Telefono</label>"<<endl;
	cout<<"<input type='text' name='telefono' class='form-control' placeholder='Telefono' >"<<endl;
	//idtc
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='idtc' class='sr-only'>Tipo de candidato:</label>"<<endl;
	cout<<"<input type='text' name='idtc' class='form-control' placeholder='IDTC' >"<<endl;
	//partido
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<label for='partido' class='sr-only'>Partido</label>"<<endl;
	cout<<"<input type='text' name='partido' class='form-control' placeholder='Partido' >"<<endl;

	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar datos</button>"<<endl;
	cout<<"</div>"<<endl;

}
void AdminViewer::dpar()
{
	cout<<"<html><head>"<<endl;
	cout<< "</head>" <<endl;
	cout<< "<body>   <div class='container'>"<<endl;
	cout<<"<div class='centrar'></div>"<<endl;
	cout<<"<h3 color='grey'>Ingrese el nombre<h3>\n";
	cout<<"<div class='container'>"<<endl;

	cout<<"<form class='form-signin' method='get'>"<<endl;
	//NOMBRE
	cout<<"<br>"<<endl;
	cout<<"<label for='nombre' class='sr-only'>Nombre del partido</label>"<<endl;
	cout<<"<input type='text' name='nombre' class='form-control' placeholder='Nombre del partido' required autofocus>"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar</button>"<<endl;
	cout<<"</div>"<<endl;
}

void AdminViewer::did()	{
	cout<<"<h3 color='grey'>Ingrese el id<h3>\n";
	cout<<"<form class='form-signin' method='get'>"<<endl;
	cout<<"<label for='id' class='sr-only'>ID</label>"<<endl;
	cout<<"<input type='text' name='id' class='form-control' placeholder='Ingrese el id AQUI' >"<<endl;
	//boton
	cout<<"<br>"<<endl;
	cout<<"<br>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Aceptar</button>"<<endl;
	cout<<"</div>"<<endl;
	cout<<"</form>"<<endl;

}

void AdminViewer::infu(Queueusuario* queueusuario){

  cout<<"<html><head>"<<endl;
  cout<<"<font color='blue'><h3 align='center'>Informacion de ususario</h3></font>"<<endl;
  cout<<"</h1></font>"<<endl;
  cout<<"<div>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Apellido</th><th>Documento</th><th>Consejal</th><th>Legislador</th><th>senador</th><th>Diputado</th><th>Intendente</th><th>Gobernador</th><th>Presidente</th></font>"<<endl;
  cout<<"</div>"<<endl;
  cout<<"<br>"<<endl;
  queueusuario->show();
  cout<<"</body></html>"<<endl;

}

void AdminViewer::infc(Queuecandidato* queuecandidato){

  cout<<"<html><head>"<<endl;
  cout<<"<font color='blue'><h3 align='center'>Informacion de Candidato</h3></font>"<<endl;
	cout<<"<tr>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Apellido</th><th>Telefono</th><th>IDTC</th><th>Partido</th><th>Votos</th></font>"<<endl;
  cout<<"<br>"<<endl;
  queuecandidato->show();
	cout<<"</tr>"<<endl;
  cout<<"</body></html>"<<endl;

}

void AdminViewer::infp(Queuepartido* queuepartido){

  cout<<"<html><head>"<<endl;
  cout<<"<font color='blue'><h3 align='center'>Informacion de Partidos</h3></font>"<<endl;
	cout<<"<tr>"<<endl;
  cout<<"<th>ID</th><th>Nombre</th><th>Cant. de socios</th></font>"<<endl;
  cout<<"<br>"<<endl;
  queuepartido->show();
	cout<<"</tr>"<<endl;
  cout<<"</body></html>"<<endl;

}

void AdminViewer::out()
{
	cout<<"<font color='red'><h3 >Has salido de la app<h3></font>\n";
	cout<<"<form class='form-signin' method='get'>"<<endl;
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>SALIR</button>"<<endl;
	cout<<"</form>"<<endl;

}

void AdminViewer::nope()
{
	cout<<"<form class='form-signin' method='get'>"<<endl;
	cout<<"<font color='red'><h3 >Algo salio mal<h3></font>\n";
	cout<<"<font color='grey'><h4 >Resiva los datos ingresados<h4></font>\n";
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}

void AdminViewer::agregado()
{
	cout<<"<form class='form-signin' method='get'>"<<endl;
	cout<<"<font color='green'><h3>Agregado correctamente<h3>\n";
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}

void AdminViewer::eliminado()
{
	cout<<"<form class='form-signin' method='get'>"<<endl;
	cout<<"<font color='green'><h3>Eliminado correctamente<h3>\n";
	cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Volver</button>"<<endl;
	cout<<"</form>"<<endl;

}
