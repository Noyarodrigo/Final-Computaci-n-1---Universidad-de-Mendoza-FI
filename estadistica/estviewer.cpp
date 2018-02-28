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

		map<string,string> Post;
		initializePost(Post);
		cout<<"Content-type: text/html"<<endl<<endl;
		cout<<"<html><head>"<<endl;
		cout<<"<title>Elecciones 2018</title>"<<endl;
    cout<<"<link rel=\"stylesheet\" href=\"http://localhost/css.css\">"<<endl;

		cout<< "</head>" <<endl;
		cout<< "<body>"<<endl;
	  cout<<"<form class='form-signin' method='post'>"<<endl;
	  cout<<"<h2 class='form-signin-heading'>Binvenido a los resultados de 2018</h2>"<<endl;
	  cout<<"<button class='btn btn-lg btn-primary btn-block' type='submit'>Ingresar</button>"<<endl;

		cout<<"</form>"<<endl;

		cout<<"</body></html>"<<endl;


}
