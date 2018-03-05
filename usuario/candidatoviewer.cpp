#include "candidatoviewer.h"
#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "usuariodao.h"
#include "string.h"
#include <sstream>
#include "candidatocontroller.h"
#include "usuariocontroller.h"

using namespace std;

CandidatoViewer::CandidatoViewer()
{
    //ctor
}

CandidatoViewer::~CandidatoViewer()
{
    //dtor
}
void CandidatoViewer::mostrar(){
  map<string,string> Get;
  initializeGet(Get);
  if (Get.find("categoria")!=Get.end()) {
    if (Get["categoria"]== "8" ) {
			(new UsuarioController())->out();
    }else{(new CandidatoController())->exe();}

    }

    else{
      cout<<"Content-type: text/html"<<endl<<endl;
      cout<<"<html><head>"<<endl;
      cout<<"<title>Elecciones 2018</title>"<<endl;
      cout<<"</head>"<<endl;
      cout<<"<body>"<<endl;
      (new UsuarioViewer())->css();
      cout<<"<font color='blue'><h1 align='center'>ELECCIONES 2018</h1></font>"<<endl;
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
      cout<<"	<br>"<<endl;
      cout<<"  <fieldset>"<<endl;
      cout<<"    <legend align='center'>SALIR</legend>"<<endl;
      cout<<"      <p>"<<endl;
      cout<<"          <input type=\"radio\" name=\"categoria\"  class='incat' value=\"8\"> LOG OUT"<<endl;
      cout<<"      </p>"<<endl;
      cout<<"  </fieldset>"<<endl;
      cout<<"	<br>	"<<endl;
      cout<<"	<p align='center'>	"<<endl;
      cout<<"<button  class='button' type='submit'>Siguiente</button>"<<endl;
      cout<<"	</p>	"<<endl;
      cout<<"</form>"<<endl;
      cout<<"</body></html>"<<endl;

  }
}

void CandidatoViewer::listar(Queue* queue){

  cout<<"Content-type: text/html"<<endl<<endl;
  cout<<"<html><head>"<<endl;
  (new UsuarioViewer())->css();
  cout<<"<font color='blue'><h1 align='center'>Listado de candidatos</h1></font>"<<endl;
  cout<<"<font color='grey'><h4 align='center'>Ingrese el codigo del candidato a continuacion</h4></font>"<<endl;
  cout<<"</head>"<<endl;
  cout<<"<body>"<<endl;
  cout<<"<table id='candidatos'>"<<endl;
  cout<<"<tr>"<<endl;
  cout<<"<font color='grey'><th>Codigo</th><th>Nombre</th><th>Apellido</th><th>Partido</th></font>"<<endl;
  cout<<"<br>"<<endl;
  queue->show();
  cout<<"</tr>"<<endl;
  cout<<"</table>"<<endl;
  cout<<"</body></html>"<<endl;

}
