//historial.cc

#include "historial.h"
#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

list <string> Historial::cargar_lista_pacientes()
{
	list <string> aux;
	ifstream fichero("Pacientes.txt");
	if(fichero.is_open())
	{
		char nombre[100];
		string nombreS;
		while (fichero.getline(nombre, 100, '\n'))
		{
			nombreS=nombre;
			aux.push_back(nombreS);
		}
		//muestro los pacientes del txt ya en la lista junto con la posicion que ocupan
		list <string>::iterator i;
		return aux;	}
	else
	{
		cout<<"*************************************"<<endl;
		cout<<"* No hay ningun paciente registrado *"<<endl;
		cout<<"* Añada un paciente primero         *"<<endl;
		cout<<"*************************************"<<endl;
		cout<<"\nPulse para continuar"<<endl;
		char n;
		cin>>n;
	}
	return aux;
}

void Historial::consultar_historial()
{
	
	lista_pacientesH_=cargar_lista_pacientes();
	if(!lista_pacientesH_.empty())
	{
		list <string> :: iterator i;
		int j=0;
		for(i=lista_pacientesH_.begin(); i!=lista_pacientesH_.end(); i++)
		{
			cout<<j<<" "<<(*i)<<endl;
			j++;
		}
		cout<<"Dime el numero del paciente que quiere consultar el historial"<<endl;
		int numero;
		cin>>numero;
		string nombre;
		j=0;
		for(i=lista_pacientesH_.begin(); i!=lista_pacientesH_.end();)
		{
			if (j==numero)
			{
				nombre=(*i);
				i=lista_pacientesH_.end();
			}
			else
			{
				j++;
				i++;
			}
		}
		string nombrefichero=nombre+"_Historial.txt";
		ifstream fichero(nombrefichero.c_str());
		char fecha[100];
		char sintomas[100];
		char pruebas[100];
		char tratamiento[100];
		cout<<endl;
		cout<<"Aqui se mostrara el historial del paciente"<<endl;
		cout<<endl;
		while(fichero.getline(fecha, 100, '\n'))
		{
			cout<<fecha<<endl;
			fichero.getline(sintomas, 100, '\n');
			cout<<"Sintomas"<<endl;
			cout<<sintomas<<endl;
			fichero.getline(pruebas, 100, '\n');
			cout<<"Pruebas"<<endl;
			cout<<pruebas<<endl;
			fichero.getline(tratamiento, 100, '\n');
			cout<<"Tratamiento"<<endl;
			cout<<tratamiento<<endl;
			cout<<endl;
		}
		fichero.close();
		char c;
		cout<<"Pulse para continuar"<<endl;
		cin>>c;
	}
}


void Historial::add_historial()
{
	lista_pacientesH_=cargar_lista_pacientes();
	if(!lista_pacientesH_.empty())
	{
		list <string> :: iterator i;
		int j=0;
		for(i=lista_pacientesH_.begin(); i!=lista_pacientesH_.end(); i++)
		{
			cout<<j<<" "<<(*i)<<endl;
			j++;
		}
		cout<<"Dime el numero del paciente al que quiere añadir al historial"<<endl;
		int numero;
		cin>>numero;
		string nombre;
		j=0;
		for(i=lista_pacientesH_.begin(); i!=lista_pacientesH_.end();)
		{
			if (j==numero)
			{
				nombre=(*i);
				i=lista_pacientesH_.end();
			}
			else
			{
				j++;
				i++;
			}
		}
		string nombrefichero=nombre+"_Historial.txt";
		fstream fichero;
		fichero.open (nombrefichero.c_str(), fstream::app);
		char fecha[100];
		char sintomas[100];
		char pruebas[100];
		char tratamiento[100];
		cout<<endl;
		cout<<"Fecha de hoy"<<endl;
		cout<<"Formato de fecha 00/00/0000"<<endl;
		cin.ignore();
		cin.getline(fecha, 100);
		cout<<"Sintomas que presenta el paciente"<<endl;
		cin.getline(sintomas, 100);
		cout<<"Pruebas realizadas al paciente"<<endl;
		cin.getline(pruebas, 100);
		cout<<"Tratamiento que se le impone al paciente"<<endl;
		cin.getline(tratamiento, 100);

		fichero<<fecha<<endl;
		fichero<<sintomas<<endl;
		fichero<<pruebas<<endl;
		fichero<<tratamiento<<endl;

		cout<<"Se ha actualizado el historial"<<endl;

		fichero.close();
	}
}

/*
int main()
{
	Historial h;

	h.add_historial();
	cout<<endl<<endl<<endl;
	h.consultar_historial();

}*/
