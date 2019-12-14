//TRATAMIENTO DEL PACIENTE.
#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
//tratamiento.cc
//TRATAMIENTO DEL APCIENTE.
#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;
class Tratamiento
{
private:
	//fecha con sysdate(?)
	string comienzo_tratamiento; //duracion semasnas, meses, dias
	string duracion_tratamiento;
	string dosis;
	string nombre_medicamento;
public:

	//SI HEREDA DE ALGUNA OTRA CLASE HAY QUE REVISARLO.
	//VER SI PONGO CONSTRUCTOR, Y MIRAR SI LO PONGO EN LOS DEMAS ARCHIVOS.
	string choose_paciente();
	bool comprobar_fichero(string fichero_paciente);
	void add_Tratamiento();
	void delete_Tratamiento();
	void see_Tratamiento();
	

	
};

#endif