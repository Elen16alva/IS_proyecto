#include <string>
#include <>
using namespace std;

struct paciente
{
	string nombre;
	string apellido1;
	string apllido2;
	string dni;
	int telefono;
	string direccion;
	string localidad;
	string ciudad;
	string pais;
	string codigo_postal;
	//string tratamiento; duda
	//string historial;  duda
	//string citas;  duda
};

/**
se van a tener los siguientes tips de ficheros
pacientes.txt
nombre_paciente.txt
historial_nombre_paciente.txt
tratamiento_nombre_paciente.txt
(los de citas aun sin pensar)
*/
/**
idea si no hay tratamiento actual o si se borra, escribir ninguno y la fecha en la que empieza (pedir fecha siempre en  tratamiento e histoirial)
*/

class Menu
{
private:
	void menu_citas();
	void menu_pacientes();
public:
	inline Menu(){}
	void menu_principal();
	void mostrar_citas_diarias();	
};

class Paciente
{
private:

protected:
	list <string> lista_pacientes; //sacara del fichero el nombre de todos los pacientes y y los guardara para luego mostrarlos

public:
	inline Paciente(){}
	void mostrar_lista_pacientes();
	void consultar_datos_personales();
	void alta_paciente(); //por no usar la ñ
	void borrar_paciente();

};

