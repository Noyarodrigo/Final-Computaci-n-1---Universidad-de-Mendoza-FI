#include "usuarioviewer.h"
#include <iostream>
#include <map>
#include <typeinfo>
#include <stdlib.h>
#include "getpost.h"
#include "usuariodao.h"
#include "candidatoviewer.h"
#include "usuariocontroller.h"
using namespace std;

UsuarioViewer::UsuarioViewer()
{
    //ctor
}

UsuarioViewer::~UsuarioViewer()
{
    //dtor
}

void UsuarioViewer::inicio(){
	int z=0,x=0;

	x=(new UsuarioDAO())->checkLogin();

	if (x==0) {
		map<string,string> Post;
		initializePost(Post);
		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		cout<<"<title>Elecciones 2018</title>"<<endl;
		css();
		cout<< "</head>" <<endl;
		cout<< "<body>"<<endl;
		cout<< "<div>"<<endl;
		cout<< "<img src=\"http://www.jusdeleste.com.ar/wp-content/uploads/2017/04/logo-universidad-de-mendoza.png\" width=\"150\" height=\"150\">"<<endl;
		cout<<"<h3>Bienvenido a las elecciones 2018<h>\n";
	  cout<<"<form class='categoria' method='post'>"<<endl;
	  cout<<"<label for='documento' class='label'>Usuario</label>"<<endl;
	  cout<<"<input type='text' name='documento' class='input' placeholder='Documento' required autofocus>"<<endl;
		cout<<"<br>"<<endl;
		cout<<"<br>"<<endl;
	  cout<<"<button class='button' type='submit'>Ingresar</button>"<<endl;
	  cout<<"</form>"<<endl;
	  cout<<"</div>"<<endl;
		cout<<"</body></html>"<<endl;

	      if (Post.find("documento")!=Post.end()) {
					z=(new UsuarioDAO())->checkusuario(Post["documento"]);
	          if(z == 1){
								((new UsuarioDAO()) ->setLogin(Post["documento"]));
								cout<<"<font color='green'><h1 align='center'>Ingreso con Exito!</h1></font>"<<endl;
								cout<<"<form class='categoria' align='center'>"<<endl;
								cout<<"<input value='Ir a las categorias' onClick='document.location.reload()' type='button' class='button'>"<<endl;
								cout<<"</form>"<<endl;
							}else{fracaso();}
						}

	}else{

		(new CandidatoController())->ver();

	}

}

void UsuarioViewer::votar(){
	map<string,string> Post;
	initializePost(Post);
	cout<<"<html><head>"<<endl;
	(new UsuarioViewer())->css();
	cout<< "</head>" <<endl;
	cout<< "<body>"<<endl;
	cout<<"<form  align='center' class='categoria' method='post'>"<<endl;
	cout<<"<label for='codigo' class='label'>Codigo</label>"<<endl;
	cout<<"<input type='text' name='codigo' class='input' placeholder='Ingreselo AQUI' required autofocus>"<<endl;
	cout<<"<button class='button' type='submit'>VOTAR</button>"<<endl;
	cout<<"</form>"<<endl;
	 if (Post.find("codigo")!=Post.end()) {
		 (new UsuarioController())->control(Post["codigo"]);
	 }//else fail();


}

void UsuarioViewer::fracaso()
{
	cout<<"<font color='red'><h3 align='center'>Ingreso Incorrecto!</h3></font>"<<endl;
}

void UsuarioViewer::fail(){

	cout<<"<font color='red'><h4 align='center'>YA HAS VOTADO EN ESTA CATEGORIA!</h4></font>"<<endl;
	cout<<"<form class='categoria' align='center' method='get'>"<<endl;
	cout<<"<button class='button' type='submit'>VOLVER</button>"<<endl;
	cout<<"</form>"<<endl;
}

void UsuarioViewer::yav(){

	cout<<"<font color='green'><h4 align='center'>VOTO INGRESADO!</h4></font>"<<endl;
	cout<<"<form class='categoria' align='center' method='get'>"<<endl;
	cout<<"<button class='button' type='submit'>VOLVER</button>"<<endl;
	cout<<"</form>"<<endl;
}

void UsuarioViewer::out()
{
	cout<<"Content-type: text/html"<<endl<<endl;
	css();
	cout<<"<form class='categoria' width='70\%' method='get' align='center'>"<<endl;
	cout<<"<font color='red'><h3 >Has salido de la app<h3></font>\n";
	cout<<"<button class='button' type='submit'>SALIR</button>"<<endl;
	cout<<"</form>"<<endl;

}

void UsuarioViewer::error()
{
	cout<<"<font color='red'><h4 align='center'>CODIGO NO VALIDO!</h4></font>"<<endl;
	cout<<"<form class='categoria' align='center' method='get'>"<<endl;
	cout<<"</form>"<<endl;
}

void UsuarioViewer::css()
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
