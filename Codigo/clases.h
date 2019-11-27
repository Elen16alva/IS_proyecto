#include <string>
#include <>
using namespace std;



/**
se van a tener los siguientes tipos de ficheros
pacientes.txt
nombre_paciente.txt
historial_nombre_paciente.txt
tratamiento_nombre_paciente.txt
(los de citas aun sin pensar)
*/
/**
idea si no hay tratamiento actual o si se borra, escribir ninguno y la fecha en la que empieza (pedir fecha siempre en  tratamiento e histoirial)
*/

//structs

struct historial
{
	//fecha con sysdate(?)
	string dolencias;
	string pruebas;
	string tratamiento;
};

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
};

struct tratamiento //comprobar que no se pueda meter fecha incorrecta
{

	//fecha con sysdate(?)

	int duracion;
	string tratamiento;
	string dosis;
	int cantidad;

};

//clases

class Menu
{
private:
	list <string> lista_pacientes_;
	list <string> lista_citas_;
	void menu_citas();
	void menu_pacientes();

protected:

public:

	Menu(){}
	void menu_historial();
	void menu_tratamiento();
	void menu_principal();
	void menu_pacientes();
	void menu_citas();
	void mostrar_citas_diarias();
	list <string> mostrar_lista_pacientes();	//retornara lista_pacientes_ y se guardara en la lista creada en la clase Pacientes
	list <string> mostrar_citas_();	//retonara lista_citas_ y se guardara en la lista creada en la clase Citas
};

//a partir de aqui todas las clases heredan menu ya que necesitan las funciones de mostrar_lista_pacientes y mostrar_lista_citas
//ademas tambien necesitaran las variables de lista_pacientes (se obtiene en mostrar_lista_pacientes)


class Tratamiento: public Menu
{
private:
	list <string> lista_pacientesT; //en ella se guaradara la lista que se retorna desde la funcion mostrar_lista_pacientes
									//la mayuscula es del nombre de la clase
protected:

public:

	inline Tratamiento(){};
	void borrar_tratamiento();
	void consultar_tatamiento();
	void add_tratamiento();

};


class Historial: public Menu
{
private:
	list <string> lista_pacientesH; //en ella se guaradara la lista que se retorna desde la funcion mostrar_lista_pacientes
									//la mayuscula es del nombre de la clase
protected:

protected:

public:


	Historial(){}
	void consultar_historial();
	void add_historial();
};

class Paciente: public Menu

{
private:
	list <string> lista_pacientesP; //en ella se guaradara la lista que se retorna desde la funcion mostrar_lista_pacientes
									//la mayuscula es del nombre de la clase
protected:

public:

	Paciente(){}

	void consultar_datos_personales();
	void add_paciente(); //por no usar la ñ
	void borrar_paciente();
	void modificar_datos_paciente();
};

