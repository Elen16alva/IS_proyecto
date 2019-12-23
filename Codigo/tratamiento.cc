//TRATAMIENTO DEL PACIENTE.
#include <iostream>
#include <string.h>
#include <list>
#include <fstream>
#include <cstdlib>
#include "tratamiento.h"
using namespace std;

Tratamiento::Tratamiento(){
	 struct tm *tiempo;
	 time_t fecha_sistema;
	 time(&fecha_sistema);
	 tiempo=localtime(&fecha_sistema);
 
	 year_sistema=tiempo->tm_year + 1900;
	 month_sistema=tiempo->tm_mon + 1;
	 day_sistema=tiempo->tm_mday;	
}

string Tratamiento::choose_paciente(string fich)
{
	ifstream fichero (fich);
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

bool Tratamiento::confirmafecha(string dia, string mes, string anio){
	char day[dia.length()+1], month[mes.length()+1], year[anio.length()+1];
	strcpy(day, dia.c_str());
	strcpy(month, mes.c_str());
	strcpy(year, anio.c_str());
	int m=atoi(month);
	int d=atoi(day);
	int a=atoi(year);

	if(a >= year_sistema){

			if(m == 1 || m== 3|| m== 5|| m==7 || m==8 || m==10 || m==12)
			{
				if(d>=1 && d <=31)
				{
					
					return true;
				}
			}
			else
			{	
				if(m == 4 || m== 6|| m== 9|| m==11)
				{
					if(d>=1 && d<=30)
					{
						return true;
					}
				}	
				if(a % 4==0 && a %10!=0)
				{
					if(m==2)
					{
						if(d>=1 && d<=29)
						{
							return true;
						}
					}	

				}
				else
				{
					if(m==2)
					{
						if(d>=1 && d<=28)
						{
							return true;
						}
					}	
				}
			}	

	}		
			cout<<"Revise la fecha introducida, recuerde que el dia y el mes ha de ser introducido en formato numerico"<<endl;
			return false;
}

void Tratamiento::add_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE AÑADIR TRATAMIENTO\n";

	if(comprobar_fichero("Pacientes.txt")==true)
	{
		mostrar_lista_pacientes("Pacientes.txt");
		string copia_linea=choose_paciente("Pacientes.txt");
		string fichero_tratamiento=copia_linea+"_Tratamiento"+".txt";
		if(comprobar_fichero(fichero_tratamiento)==true){
			string dia, mes, anio;
			int check;
			remove (fichero_tratamiento.c_str());
			ofstream fichero(fichero_tratamiento);
			
			cout << "Introduce nombre del nuevo medicamento para el paciente\n";
			cin.ignore();
			getline(cin, nombre_medicamento);
			fichero<<nombre_medicamento<<endl;cout << "\n";
			cout << "\n";
			do{
			cout << "Introduce fecha de comienzo del tratamento\n";
			cout << "Introduce dia de comienzo\n";
			cin >> dia;
			cout << "Introduzca mes de comienzo\n";
			cin >> mes;
			cout << "Introduzca año de comienzo\n";
			cin >> anio;
			cout<<"¿La fecha seleccionada es correcta? -> "<<dia<<"/"<<mes<<"/"<<anio<<endl;
			cout<<"1 -> SI || 2-> NO"<<endl;
			cin>>check;
			comienzo_tratamiento=dia+"-"+mes+"-"+anio;
			}while(confirmafecha(dia, mes, anio)!=true || check==2);
			fichero << comienzo_tratamiento << endl;
			cout << "\n";
			cout << "Introduce dosis diaria (ej: 2 comprimidos, tres capsulas,...)\n";
			cin.ignore();
			getline(cin, dosis);
			fichero << dosis << endl;
			cout << "\n";
			cout << "Introduce duracion del tratamiento (ej: 2 semanas, tres dias,...)\n";
			getline(cin, duracion_tratamiento);
			fichero << duracion_tratamiento << endl;
			


			cout << "Ha rellenado el tratamiento satisfactoriamente\n";
			fichero.close();
			char n;
			cout<<"Pulse cualquier número para continuar"<<endl;
			cin>>n;
		}
		else{
			string dia, mes, anio;
			int check;

			ofstream fichero(fichero_tratamiento);
			

			cout << "Introduce nombre del nuevo medicamento para el paciente\n";
			cin.ignore();
			getline(cin, nombre_medicamento);
			do{
			cout << "Introduce fecha de comienzo del tratamento\n";
			cout << "Introduce dia de comienha << endl;zo\n";
			cin >> dia;
			cout << "Introduzca mes de comienzo\n";
			cin >> mes;
			cout << "Introduzca año de comienzo\n";
			cin >> anio;
			cout<<"¿La fecha seleccionada es correcta? -> "<<dia<<"/"<<mes<<"/"<<anio<<endl;
			cout<<"1 -> SI || 2-> NO"<<endl;
			cin>>check;
			comienzo_tratamiento=dia+"-"+mes+"-"+anio;
			cout << "fecha: \n"<<comienzo_tratamiento<<endl;
			}while(confirmafecha(dia, mes, anio)!=true || check==2);
			cout << "fecha: \n"<<comienzo_tratamiento<<endl;
			getline(cin, comienzo_tratamiento);
			cout << "Introduce dosis diaria (ej: 2 comprimidos, tres capsulas,...)\n";
			getline(cin, dosis);
			cout << "Introduce duracion del tratamiento (ej: 2 semanas, tres dias,...)\n";
			getline(cin, duracion_tratamiento);
			fichero << nombre_medicamento << endl;
			fichero << comienzo_tratamiento;
			fichero << dosis << endl;
			fichero << duracion_tratamiento << endl;

			cout << "Ha rellenado el tratamiento satisfactoriamente\n";
			fichero.close();
			char n;
			cout<<"Pulse cualquier número para continuar"<<endl;
			cin>>n;
		}
	}
	else
	{
		cout << "No se ha encontrado el fichero 'Pacientes.txt'\n";
		char n;
		cout<<"Pulse cualquier número para continuar"<<endl;
		cin>>n;
	}
}

int Tratamiento::delete_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE ELIMINAR EL TRATAMIENTO\n";
	if(comprobar_fichero("Pacientes.txt")==true)
	{
			mostrar_lista_pacientes("Pacientes.txt");
			cout << "\n";
			string copia_linea=choose_paciente("Pacientes.txt");
			string linea;
			string fecha;
			int i=0;
			cout << "ESTA SEGURO DE QUE QUIERE BORRAR EL TRATAMIENTO EN CURSO DEL PACIENTE?"<< copia_linea <<endl;
			cout << "1.- SI || 2.- NO"<<endl;
			int opcion;
			cin >> opcion;
			if(opcion==2){
				return -1;
			}
			if(comprobar_fichero(copia_linea+"_Tratamiento"+".txt")==true){
				ifstream fich(copia_linea+"_Tratamiento"+".txt");
					while((fich.is_open()) && (getline(fich, linea))){
						if(i==1){
							fecha=linea;
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
		cout << "No se hay pacientes registrados, añada un paciente.\n";
		cout<<"Pulse cualquier número para continuar"<<endl;
		cin>>n;
	}
	return 0;
}

void Tratamiento::see_Tratamiento()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE VER SU TRATAMIENTO\n";
	if(comprobar_fichero("Pacientes.txt")==true)
	{
			mostrar_lista_pacientes("Pacientes.txt");
			cout << "\n";
			string copia_linea=choose_paciente("Pacientes.txt");
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
				do{
				cout << "1.- Se insertará tratamiento nuevo al paciente que no tiene tratamiento alguno en estos momentos\n";
				cout << "2.- Mostrará una lista con los diferentes tratamientos y sus fechas de creacion del paciente elegido\n";
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
								copia_linea=choose_paciente("Tratamientos.txt");
								string fichero_paciente=copia_linea+"_Tratamiento_finalizado"+".txt";
								string linea;
								
								cout << "ESTOS SON LOS DATOS QUE CONTIENE EL FICHERO: * " << fichero_paciente <<" *"<< endl;
								ifstream fichero(fichero_paciente);
								if(fichero.is_open()){
									while(!fichero.eof()){
										getline(fichero, linea);
										cout << linea << endl;
									}
								}
								char n;
								cout<<"Pulse cualquier número para continuar"<<endl;
								cin>>n;
								fichero.close();
							}
							else{
								cout << "El fichero 'Tratamientos.txt' no contiene ningun tratamiento finalizado\n";
								char n;
								cout<<"Pulse cualquier número para continuar"<<endl;
								cin>>n;
							}
						}break;
					}
				}while(!((opcion=1)||(opcion=2)));
			}

	}
	else
	{
		char n;
		cout << "No hay pacientes registrados, añada un paciente\n";
		cout<<"Pulse para continuar"<<endl;
		cin>>n;
	}
}
