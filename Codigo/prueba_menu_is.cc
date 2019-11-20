/** todo esto es un esquema, hay que aplicarle las clases y demas...
#include <> //falta hacer los includes...
using namespace std;
void mostrar_citas_diarias(//) //mirar nombre en diagramd e clases y demas
{
	//traerse la lista de la citas del dia que es hoy y mostrarla (solo las reservadas)
}

void menu_principal(//recibe)
{
	mostrar_citas_diarias(); //mirar nombre en diagrama de clases y demas
	cout<<"Pulse 0 para salir\n";
	cout<<"Pulse 1 para operaciones de pacientes\n";
	cout<<"Pulse 2 para operaciones de citas\n";
	int opcion; //meter como variable en la clase(?) //no porque es algo del programador(?)
	cin>>opcion;
	if((opcion<0)||(opcion<2))
	{
		cout<<"Opción no valida, por favor seleccione otra\n";
		menu_principal(//recibe); //recursivo...
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

*/