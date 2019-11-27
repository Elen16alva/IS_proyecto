// todo esto es un esquema, hay que aplicarle las clases y demas...
#include <> //falta hacer los includes...
using namespace std;

void Menu::mostrar_lista_pacientes()
{
	/**la funcion busca un fichero de texto llamado pacientes.txt
		si no existe lo crea y muestra un mensaje de que aun no hay pacientes y que debe dar de alta alguno
		si extiste lee del txt con separados el \n y los guarda en la posicion i+1 (ya que no va a haber un cliente con el id=0) de la lista
		muestra la lista 
	*/
}


void mostrar_citas_diarias() 
{
	
}

void menu_principal()
{
	mostrar_citas_diarias(); 
	cout<<"Pulse 0 para salir"<<endl;
	cout<<"Pulse 1 para operaciones de pacientes"<<endl;
	cout<<"Pulse 2 para operaciones de citas"<<endl;
	int opcion; 
	cin>>opcion;
	if((opcion<0)||(opcion<2))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		menu_principal(); //recursivo...
	}
	while (opcion!=0)
	{
		swich(opcion)
		{

			case 1: menu_pacientes() //funcion para mostrar las opciones de pacientes

			case 2: menu_citas() //funcion para mostrar las opciones de citas
		}
		extit (-1);
	}
}


void menu_citas()
{
	cout<<"Pulse 1 para reservar una cita"<<endl;
	cout<<"Pulse 2 para borrar una cita"<<endl;
	cout<<"Pulse 3 para consultar las ditas de un dia"<<endl;
	cout<<"Pulse 4 para modificaruna cita"<<endl;
	int opcion; 
	cin>>opcion;
	if((opcion<0)||(opcion<2))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		menu_citas(); //recursivo...
	}
	while (opcion!=0)
	{
		swich(opcion)
		{

			case 1: menu_pacientes() //funcion para mostrar las opciones de pacientes

			case 2: menu_citas() //funcion para mostrar las opciones de citas
		}
		extit (-1);
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
	if((opcion<1)||(opcion<5))
	{
		cout<<"Opción no valida, por favor seleccione otra"<<endl;
		menu_pacientes(); //recursivo...
	}
	while (opcion!=0)
	{
		swich(opcion)
		{

			case 1: menu_pacientes() //funcion para mostrar las opciones de pacientes

			case 2: menu_citas() //funcion para mostrar las opciones de citas
		}
		extit (-1);
	}
}

