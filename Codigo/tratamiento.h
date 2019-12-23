//tratamiento.cc
//TRATAMIENTO DEL APCIENTE.
#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

class Tratamiento
{
private:
	string comienzo_tratamiento;
	string duracion_tratamiento;
	string dosis;
	string nombre_medicamento;
	int year_sistema, month_sistema, day_sistema;
	
public:
	Tratamiento();
	string choose_paciente(string fich);
	bool comprobar_fichero(string fichero_paciente);
	bool confirmafecha(string dia, string mes, string anio);
	void add_Tratamiento();
	int delete_Tratamiento();
	void see_Tratamiento();
};
#endif
