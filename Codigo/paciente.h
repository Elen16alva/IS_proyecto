//paciente.cc
//TRATAMIENTO DEL PACIENTE.
#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Paciente
{
private:
	string nombre_;
	string apellido1_;
	string apellido2_;
	//DATOS PACIENTE.
	string direccion;
	int codigo_Postal;
	string ciudad;
	string provincia;
	string DNI;
	string nombre_concatenar;
	
public:
	bool comprobar_fichero(string fichero);
	void add_paciente();
	void delete_paciente();
	string choose_paciente();
	void modifica_pacientes(string concatenar, string antiguo);
	void choose_datos_paciente(string fichero_paciente, int opcion, string linea_paciente);
	void consultar_datos_personales();
	void modificar_datos_paciente();
};

#endif