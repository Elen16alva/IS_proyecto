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
	cout<<"Pulse 0 para salir\n";
	cout<<"Pulse 1 para operaciones de pacientes\n";
	cout<<"Pulse 2 para operaciones de citas\n";
	int opcion; 
	cin>>opcion;
	if((opcion<0)||(opcion<2))
	{
		cout<<"Opción no valida, por favor seleccione otra\n";
		menu_principal(); //recursivo...
	}
	swich(opcion)
	{
		case 0: exit(-1);

		case 1: menu_pacientes() //funcion para mostrar las opciones de pacientes

		case 2: menu_citas() //funcion para mostrar las opciones de citas
	}
}
void menu_citas()
{
	
}

void menu_pacientes()
{
	
}

