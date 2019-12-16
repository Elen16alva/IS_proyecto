#include "historial.h"
//#include "citas.h"
#include "tratamiento.h"
#include "paciente.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	Historial h;
	Paciente p;
	Tratamiento t;
	//Citas c;
	//c.consultarCitasDia(); 

	cout<<"Pulse 0 para salir"<<endl;
	cout<<"Pulse 1 para operaciones de pacientes"<<endl;
	cout<<"Pulse 2 para operaciones de citas"<<endl;

	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion<2))
	{	
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
	}
		switch(opcion)
		{

			case 1: menu_pacientes() //funcion para mostrar las opciones de pacientes

			case 2: //c.menu_citas() //funcion para mostrar las opciones de citas
		}
	if (opcion==0)
	{
		return (-1);
	}
}



void menu_pacientes()
{

	cout<<"Pulse 0 para salir"<<endl;
	cout<<"Pulse 1 para añadir un paciente"<<endl;
	cout<<"Pulse 2 para borrar un paciente"<<endl;
	cout<<"Pulse 3 para acceder a los datos de un paciente"<<endl;
	cout<<"Pulse 4 para acceder al historial un paciente"<<endl;
	cout<<"Pulse 5 para accder al tratamiento un paciente"<<endl;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion>5))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
	}
	while (opcion!=0)
	{
		switch(opcion)
		{

			case 1: p.add_paciente();

			case 2: p.delete_paciente();

			case 3: p.consultar_datos_personales();

			case 4: menu_historial();

			case 5: menu_tratamiento();

		}
	}
	exit (-1);
}


void menu_historial()
{
	cout<<"Pulse 0 para salir"<<endl;
	cout<<"Pulse 1 para consultar el historial"<<endl;
	cout<<"Pulse 2 para añadir al historial"<<endl;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion<2))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
	}
	while (opcion!=0)
	{
		switch(opcion)
		{
			case 1: h.consultar_historial();

			case 2: h.add_historial();
		}
	}
	exit (-1);

}


void menu_tratamiento()
{
	cout<<"Pulse 0 para salir"<<endl;
	cout<<"Pulse 1 para añadir un nuevo tratamiento"<<endl;
	cout<<"Pulse 2 para borrar el tratamento activo"<<endl;
	cout<<"Pulse 3 para consultar el tratamiento de un paciente"<<endl;;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion<4))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
	}
	while (opcion!=0)
	{
		switch(opcion)
		{
			case 1: t.add_Tratamiento();

			case 2: t.delete_Tratamiento();

			case 3: t.see_Tratamiento():
		}
	}
	exit (-1);
}
