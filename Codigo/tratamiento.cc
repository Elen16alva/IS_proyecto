//TRATAMIENTO DEL PACIENTE.
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "tratamiento.h"
using namespace std;

string Tratamiento::choose_paciente()
{
	ifstream fichero ("Pacientes.txt");
	string linea;
	string copia_linea;
	int contador = 0;
	int max;

	if (fichero.is_open())
	{
		cout << "Introduce numero que corresponde al paciente\n";
		cin >> max;
		cout << "\n";
			while(getline(fichero, linea)) 
			{
				if(max == contador) 
				{	
					copia_linea=linea;
					cout << "Este es el paciente que ha seleccionado\n";
					cout << linea << endl;
					cout << "\n";
				}
				contador++;
       		}
	}
	fichero.close();
return copia_linea;
}

list <string> mostrar_lista_pacientes(string fich)
{
	cout << "LISTA DE LOS PACIENTES: \n";
	list <string> aux;
	ifstream fichero(fich);
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
bool Tratamiento::comprobar_fichero(string fichero_paciente) {
	ifstream fichero;
	fichero.open(fichero_paciente.c_str());
	if(fichero.fail()){
		return false;
	}
		fichero.close();
		return true;
}

void Tratamiento::add_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE AÑADIR TRATAMIENTO\n";

	if(comprobar_fichero("Pacientes.txt")==true)
	{
		mostrar_lista_pacientes("Pacientes.txt");
		string copia_linea=choose_paciente();
		string fichero_tratamiento=copia_linea+"_Tratamiento"+".txt";
		if(comprobar_fichero(fichero_tratamiento)==true){
			fstream fichero;
			fichero.open(fichero_tratamiento, ios::app);
			cout << "Introduce nuevo medicamento para el paciente\n"; //se podría poner que el nombre del paciente también apareciera
			cin.ignore();
			getline(cin, nombre_medicamento);
			cout << "Introduce fecha de comienzo del tratamiento (ej: 2 semanas, tres meses,...)\n";
			getline(cin, comienzo_tratamiento);
			cout << "Introduce dosis diaria (ej: 2 comprimidos, tres capsulas,...)\n";
			getline(cin, dosis);
			cout << "Introduce duracion del tratamiento (ej: 2 semanas, tres dias,...)\n";
			getline(cin, duracion_tratamiento);
			fichero << nombre_medicamento << "\n" << comienzo_tratamiento << "\n" << dosis << "\n" << duracion_tratamiento << endl;
			cout << "Ha rellenado el tratamiento satisfactoriamente\n";
			fichero.close();
			char n;
			cout<<"Pulse cualquier número para continuar"<<endl;
			cin>>n;
		}
		else{
			ofstream fichero(fichero_tratamiento);
			cout << "Introduce nuevo medicamento para el paciente\n";
			cin.ignore();
			getline(cin, nombre_medicamento);
			cout << "Introduce fecha de comienzo del tratamiento (ej: 2 semanas, tres meses,...)\n";
			getline(cin, comienzo_tratamiento);
			cout << "Introduce dosis diaria (ej: 2 comprimidos, tres capsulas,...)\n";
			getline(cin, dosis);
			cout << "Introduce duracion del tratamiento (ej: 2 semanas, tres dias,...)\n";
			getline(cin, duracion_tratamiento);
			fichero << nombre_medicamento << "\n" << comienzo_tratamiento << "\n" << dosis << "\n" << duracion_tratamiento << endl;
			cout << "Ha rellenado el tratamiento satisfactoriamente\n";
			fichero.close();
			char n;
			cout<<"Pulse cualquier número para continuar"<<endl;
			cin>>n;
		}
	}
	else
	{
		char n;
		cout<<"Pulse cualquier número para continuar"<<endl;
		cin>>n;
	}
}

void Tratamiento::delete_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE ELIMINAR EL TRATAMIENTO\n";
	if(comprobar_fichero("Pacientes.txt")==true)
	{
			mostrar_lista_pacientes("Pacientes.txt");
			cout << "\n";
			string copia_linea=choose_paciente();
			string linea;
			string fecha;
			int i=0;
			if(comprobar_fichero(copia_linea+"_Tratamiento"+".txt")==true){
				ifstream fich(copia_linea+"_Tratamiento"+".txt");
					while((fich.is_open()) && (getline(fich, linea))){
						if(i==1){
							fecha=linea;
							cout << "ESTA ES LA FECHA:"<<fecha << endl;
						}	
					i++;
					}						
				fich.close();
				fstream file;
				file.open(copia_linea+"_Tratamiento"+".txt", ios::app);
				file << "ESTE TRATAMIENTO HA FINALIZADO" << endl;	
				fich.close();
				rename((copia_linea+"_Tratamiento"+".txt").c_str(), (copia_linea+"_"+fecha+"_Tratamiento_finalizado"+".txt").c_str());
				cout << "SE HA ELIMINADO EL TRATAMIENTO CORRECTAMENTE\n";
				char n;
				cout<<"Pulse cualquier número para continuar"<<endl;
				cin>>n;
			}
			else{
				cout << "El fichero tratamiento correspondiente al paciente no existe\n";
				cout << "Cree un nuevo tratamiento para este paciente\n";
				char n;
			cout << "No se han encontrado pacientes registrados, añada un paciente\n";
			cout<<"Pulse cualquier número para continuar"<<endl;
			cin>>n;
			}
			string nombre=copia_linea+"_"+fecha;
			if(comprobar_fichero("Tratamientos.txt")==true){
				fstream fichero;
				fichero.open("Tratamientos.txt", ios::app);
				fichero << nombre << endl;
				fichero.close();
			}
			else{
				ofstream fichero("Tratamientos.txt");
				fichero << nombre << endl;
				fichero.close();
			}
	}
	else
	{
		char n;
		cout << "No se han encontrado pacientes registrados, añada un paciente\n";
		cout<<"Pulse cualquier número para continuar"<<endl;
		cin>>n;
	}
}

void Tratamiento::see_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE VER SU TRATAMIENTO\n";
	if(comprobar_fichero("Pacientes.txt")==true)
	{
			mostrar_lista_pacientes("Pacientes.txt");
			cout << "\n";
			string copia_linea=choose_paciente();
			string fichero_tratamiento=copia_linea+"_Tratamiento"+".txt";

			if(comprobar_fichero(fichero_tratamiento)==true){
				ifstream fichero(fichero_tratamiento);
				string line;
				if(fichero.is_open()){
					int i=0;
					while(!fichero.eof() && (!(i==5))){
							if(i==0){
								getline(fichero,line);
								cout << "Nombre del medicamento: " << line << endl;
							}
							if(i==1)
							{
								getline(fichero,line);
								cout << "Comienzo del tratamiento: " << line << endl;					
							}
							if(i==2)
							{
								getline(fichero,line);
								cout << "Dosis: " << line << endl;	
							}
							if(i==3)
							{
								getline(fichero,line);
								cout << "Duracion del tratamiento: " << line << endl;
							}
						i++;
					}
				}
				fichero.close();
				char n;
				cout<<"Pulse para continuar"<<endl;
				cin>>n;
			}
			else{
				cout << "EL FICHERO QUE DESEA MOSTRAR HA SIDO BORRADO ANTERIOMENTE O AUN NO SE HA CREADO.\n";
				cout << "ESCOJA UNA DE LAS OPCIONES SIGUIENTES.\n";
				cout << "\n";
				int opcion;
				cout << "1.- Se insertará tratamiento nuevo al paciente que no tiene tratamiento alguno en estos momentos\n";
				cout << "2.- Mostrará una lista con los diferentes tratamientos y sus fechas de creacion del paciente elegido\n";
				cout << "3.- Volver al menu principal a escoger otra opcion\n";
				cout << "Su opcion esocgida es: ";
				cin >> opcion;
				switch(opcion){
					case 1:{
						add_Tratamiento();
					}break;
					case 2: {
						if(comprobar_fichero("Tratamientos.txt")==true){
							cout << "LISTA DEL TRATAMIENTOS FINALIZADOS DE LOS PACIENTES \n";
							mostrar_lista_pacientes("Tratamientos.txt");
							cout << "\n";
							string copia_linea;
							copia_linea=choose_paciente();
							string fichero_paciente=copia_linea+".txt";
							string linea;
							ifstream fichero(fichero_paciente);
							if(fichero.is_open()){
								while(!fichero.eof()){
									getline(fichero, linea);
									cout << linea << endl;
								}
							}
							fichero.close();
						}
					}break;
					case 3: {
						
					}
				}
			}

	}
	else
	{
		char n;
		cout << "No se han encontrado pacientes registrados, añada un paciente\n";
		cout<<"Pulse para continuar"<<endl;
		cin>>n;
	}
}
