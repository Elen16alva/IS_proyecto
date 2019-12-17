#include "historial.h"
#include "citas.h"
#include "tratamiento.h"
#include "paciente.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void menu_tratamiento();

void menu_historial()
{
	Historial h;
	system("clear");
	cout<<"***************************************"<<endl;
	cout<<"* Pulse 0 para salir                  *"<<endl;
	cout<<"* Pulse 1 para consultar el historial *"<<endl;
	cout<<"* Pulse 2 para añadir al historial    *"<<endl;
	cout<<"***************************************"<<endl;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion>2))
	{
		cout<<"* Opción no valida, por favor seleccione otra *"<<endl;
		cin>>opcion;
	}
	switch(opcion)
	{
		case 0:
		break;
		case 1: h.consultar_historial();
		break;
		case 2: h.add_historial();
		break;
	}
	

}
void menu_pacientes()
{
	Paciente p;
	system("clear");
	cout<<"*****************************************************"<<endl;
	cout<<"* Pulse 0 para salir                                *"<<endl;
	cout<<"* Pulse 1 para añadir un paciente                   *"<<endl;
	cout<<"* Pulse 2 para borrar un paciente                   *"<<endl;
	cout<<"* Pulse 3 para acceder a los datos de un paciente   *"<<endl;
	cout<<"* Pulse 4 para acceder al historial un paciente     *"<<endl;
	cout<<"* Pulse 5 para accder al tratamiento un paciente    *"<<endl;
	cout<<"*****************************************************"<<endl;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion>5))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
		system("clear");
	}
	if (opcion!=0)
	{
		switch(opcion)
		{

			case 1: p.add_paciente();
			break;

			case 2: p.delete_paciente();
			break;

			case 3: p.consultar_datos_personales();
			break;

			case 4: menu_historial();
			break;

			case 5: menu_tratamiento();
			break;

		}
	}
	

}





void menu_tratamiento()
{
	Tratamiento t;
	cout<<"********************************************************"<<endl;
	cout<<"* Pulse 0 para salir                                   *"<<endl;
	cout<<"* Pulse 1 para añadir un nuevo tratamiento             *"<<endl;
	cout<<"* Pulse 2 para borrar el tratamento activo             *"<<endl;
	cout<<"* Pulse 3 para consultar el tratamiento de un paciente *"<<endl;
	cout<<"********************************************************"<<endl;
	int opcion; 
	cin>>opcion;
	while((opcion<0)||(opcion>4))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		cin>>opcion;
	}
	if (opcion!=0)
	{
		switch(opcion)
		{
			case 1: t.add_Tratamiento();
			break;

			case 2: t.delete_Tratamiento();
			break;

			case 3: t.see_Tratamiento();
			break;
		}
	}
}
void menu_operaciones_pacientes()
{
	system("clear");
	Historial h;
	Paciente p;
	Tratamiento t;
	Citas c;
	cout<<"*****************************************"<<endl;
	cout<<"* Pulse 0 para salir                    *"<<endl;
	cout<<"* Pulse 1 para operaciones de pacientes *"<<endl;
	cout<<"* Pulse 2 para operaciones de citas     *"<<endl;
	cout<<"*****************************************"<<endl;
	int opcion; 
	cin>>opcion;
	system("clear");
	while(opcion!=0)
	{
		while((opcion<0)||(opcion>2))
		{	
			cout<<"Opción no valida, por favor seleccione otra"<<endl;
			cin>>opcion;
		}
			switch(opcion)
			{
				case 0:
				exit (-1);
				break;
				case 1: 
				menu_pacientes(); //funcion para mostrar las opciones de pacientes
				break;
				case 2:
				c.menu_citas();
				break; //funcion para mostrar las opciones de citas
			}
		system("clear");
		cout<<"*****************************************"<<endl;
		cout<<"* Pulse 0 para salir                    *"<<endl;
		cout<<"* Pulse 1 para operaciones de pacientes *"<<endl;
		cout<<"* Pulse 2 para operaciones de citas     *"<<endl;
		cout<<"*****************************************"<<endl;
		cin>>opcion;
		system("clear");
		
	}
	
}
int main()
{
	Historial h;
	Paciente p;
	Tratamiento t;
	Citas c;
	c.imprimirCitas(); 
	menu_operaciones_pacientes();

}
