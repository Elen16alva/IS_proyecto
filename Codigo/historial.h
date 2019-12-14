//historial.h
#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

class Historial
{
private:
	list <string> lista_pacientesH_; //en ella se guaradara la lista que se retorna desde la funcion mostrar_lista_pacientes
									//la mayuscula es del nombre de la clase
protected:

public:

	Historial(){};
	list <string> cargar_lista_pacientes();
	void consultar_historial();
	void add_historial();
};

#endif