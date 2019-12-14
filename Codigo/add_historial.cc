//add_historial.cc
#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
	/**
	lo que se deberia hacer es esto
	list <string> aux=mostrar_lista_pacientes;
	se seguiria el codigo a partir de crear el iterador
	*/
	//esto lo hago porque no tenemos la funcion para leer el fichero de pacientes
	//asi tengo una lista con el nombre de pacientes
	string nombre_paciente;
	list <string> aux;
	nombre_paciente="Rafa_Egea";
	aux.push_back(nombre_paciente);
	nombre_paciente="Jesus_Izquierdo";
	aux.push_back(nombre_paciente);
	nombre_paciente="Elena_Alvarez";
	aux.push_back(nombre_paciente);

	list <string> :: iterator i;
	int j=0;
	for(i=aux.begin(); i!=aux.end(); i++)
	{
		cout<<j<<" "<<(*i)<<endl;
		j++;
	}
	cout<<"Dime el numero del paciente al que quiere añadir al historial"<<endl;
	int numero;
	cin>>numero;
	string nombre;
	j=0;
	for(i=aux.begin(); i!=aux.end();)
	{
		if (j==numero)
		{
			nombre=(*i);
			i=aux.end();
			cout<<nombre<<endl;
		}
		else
		{
			j++;
			i++;
		}
	}
	string nombrefichero=nombre+"_Historial.txt";
	cout<<nombrefichero<<endl;
	fstream fichero;
	fichero.open (nombrefichero.c_str(), fstream::app);
	char fecha[100];
	char sintomas[100];
	char pruebas[100];
	char tratamiento[100];
	cout<<endl;
	cout<<"Fecha de hoy"<<endl;
	cin>>fecha;
	cout<<"Sintomas que presenta el paciente"<<endl;
	cin>>sintomas;
	cout<<"Pruebas realizadas al paciente"<<endl;
	cin>>pruebas;
	cout<<"Tratamiento que se le impone al paciente"<<endl;
	cin>>tratamiento;

	fichero<<fecha<<endl;
	fichero<<sintomas<<endl;
	fichero<<pruebas<<endl;
	fichero<<tratamiento<<endl;

	cout<<"Se ha actualizado el historial"<<endl;

	fichero.close();
}




 /** 
 std::fstream fs;
  fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::app);

  fs << " more lorem ipsum";

  fs.close();

  return 0;
  */
