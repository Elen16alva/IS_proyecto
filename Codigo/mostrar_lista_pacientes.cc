//mostrar_lista_pacientes.cc
#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

list <string> mostrar_lista_pacientes()
{
	list <string> aux;
	ifstream fichero("Pacientes.txt");
	char nombre[100];
	string nombreS;
	while (fichero.getline(nombre, 100, '\n'))
	{
		nombreS=nombre;
		aux.push_back(nombreS);
	}
	//muestro los pacientes del txt ya en la lista junto con la posicion que ocupan
	list <string>::iterator i;
	int j=0;
	for(i=aux.begin(); i!=aux.end(); i++)
	{
		cout<<j<<" "<<(*i)<<endl;
		j++;
	}

	return aux;
}



int main()
{
	list <string> pacientes;
	pacientes=mostrar_lista_pacientes();

}