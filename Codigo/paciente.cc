//TRATAMIENTO DEL PACIENTE.
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "paciente.h"
using namespace std;

string Paciente::choose_paciente()
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
				}//if
				contador++;
       		}//while
	}//if
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

bool Paciente::comprobar_fichero(string fichero_paciente) {
	ifstream fichero;
	fichero.open(fichero_paciente.c_str());
	if(fichero.fail()){
		return false;
	}
		fichero.close();
		return true;
}
/**la funcion pide el nombre y apellidos del paciente(comprueba si existe el txt)
si no existe lo crea y pide la direccion (calle y numero), codigo postal, cuidad, provincia, DNI etc...  
lo rellena con los datos todo esto son campos del struct paciente que se usara para leer, escribir y 
modificar los datos del paciente, y los guardara aqui ademas añadira du nombre y apellidos a pacientes.txt
si el fichero ya existe da fallo y dice que ya existe y no lo modifica
*/
void Paciente::add_paciente()
{
	cout << "Introduce el nombre del paciente que quiere añadir(si es un nombre compuesto, ejemplo: Maria.Antonia)\n";
	cin >> nombre_;
	cout << "Introduce el primer apellido(lo mismo ocurre con el apellido, ejemplo: de.las.Heras)\n";
	cin >> apellido1_;
	cout << "Introduce el segundo apellido\n";
	cin >>  apellido2_;
	string fichero_paciente=nombre_+"_"+apellido1_+"_"+apellido2_+".txt";
	if (comprobar_fichero(fichero_paciente) == false) {
		ofstream fichero (fichero_paciente);
		nombre_concatenar=nombre_+"_"+apellido1_+"_"+apellido2_;
		cout << "INTRODUCE DATOS SOBRE EL PACIENTE.\n";
		cout << "Direccion del paciente:\n";
		cin.ignore();
		getline(cin, direccion);
		cout << "Codigo postal:\n";
		cin >> codigo_Postal;
		cout << "Ciudad:\n";
		cin >> ciudad;
		cout << "Provincia:\n";
		cin >> provincia;
		cout << "DNI:\n";
		cin >> DNI;
		cin.ignore();
		fichero <<nombre_concatenar << "\n" << direccion << "\n" << codigo_Postal << "\n" << ciudad << "\n" << provincia << "\n" << DNI << "\n";
		fichero.close();

		string fichero_historial=nombre_+"_"+apellido1_+"_"+apellido2_+"_Historial"+".txt";
		string fichero_tratamiento=nombre_+"_"+apellido1_+"_"+apellido2_+"_Tratamiento"+".txt";
		ofstream fich_historial(fichero_historial);
		fich_historial.close();
		ofstream fich_tratamiento(fichero_tratamiento);
		cout << "me cago en to";
		fich_tratamiento.close();
	}
	else
	{
		cout << "No puede agregar este paciente ya que se encuentra en el sistema.\n";
	}
	if (comprobar_fichero("Pacientes.txt") == false) {
		cout << "tonto";
		ofstream fichero ("Pacientes.txt");
		fichero << nombre_concatenar << endl;
		fichero.close();
		
	}
	else
	{
		fstream fichero;
		cout << "HILIWI";
		fichero.open("Pacientes.txt", ios::app);
		fichero << nombre_concatenar << endl;
		fichero.close();
	}

}
/*la fucion accede al pacientes.txt lo guarda en la lista y la muestra (funcion mostrar_lista_pacientes)
pide el paciente a borrar y se borrara el txt con su nombre, el txt con su tratamiento y el txt de su historial
ademas se borrara el nombre del pacientes.txt 
(se puede borrar de la lista, hacer un resize o algo asi y luego borrar el pacientes.txt y crear uno nuevo escribiendo 
la lista de pacientes con el paciente ya borrado)*/

	
void Paciente::delete_paciente()
{
	cout << "SELECCIONA EL PACIENTE QUE QUIERE QUE SEA BORRADO\n";
	mostrar_lista_pacientes("Pacientes.txt");
	cout << "\n";
	string copia_linea;
	copia_linea=choose_paciente();
	string fichero_paciente=copia_linea+".txt";
	string fichero_historial= copia_linea+"_Historial"+".txt";
	string fichero_tratamiento=copia_linea+"_Tratamiento"+".txt";
	//tengo que eliminar los pacientes txt y fichero demás y además en apcientes.txt debo de borrarlo.
	cout << "NOMBRE FICHERO: "<<fichero_paciente << endl;
	cout << "\n";
	cout << "ESTE PACIENTE " << copia_linea << " ES EL QUE DESEA BORRAR: \n";
	cout << "DESEA BORRAR COMPLETAMENTE ESTE PACIENTE?\n";
	cout << "1.- Si\n";
	cout << "2.- No\n";
	int opcion;
	cin >> opcion;
	string line;
	switch(opcion)
	{
		case 1:
		{
			ifstream fichero("Pacientes.txt");
			ofstream fich("PacientesBorrar.txt");
			while((fichero.is_open()) && (getline(fichero, line)))
			{
				if(line!=copia_linea){
					fich << line << endl;
				}
			}
			remove("Pacientes.txt");
			rename("PacientesBorrar.txt", "Pacientes.txt");
			fich.close();
			fichero.close();
			remove(fichero_paciente.c_str());
			remove(fichero_historial.c_str());
			remove(fichero_tratamiento.c_str());
			cout << "Los archivos y datos del paciente han sido borrados satisfactoriamente";
		}break;
		case 2:
		{
			//iría al mení prinipal de nuevo para hacer otra cosa
		}break;
		default:
		{
			cout << "Ha introducido una opcion incorrecta, de nuevo se mostrará la lista de los pacientes a querer eliminar\n";
			delete_paciente();
		}
	}
}

/*	la fucion accede al pacientes.txt lo guarda en la lista y la muestra (funcion mostrar_lista_pacientes)
		se coje el nombre de quien haya querido se busca su txt se accede a el y se lee
		lo que se lee se guarda en el struct y lo va imprimiendo*/

void Paciente::consultar_datos_personales()
{
	cout << "SELECCIONA PACIENTE AL QUE QUIERE VER SUS DATOS PERSONALES\n";
	mostrar_lista_pacientes("Pacientes.txt");
	cout << "\n";
	string copia_linea;
	copia_linea=choose_paciente();
	string line;
	string fichero_paciente=copia_linea+".txt";
	cout << "NOMBRE FICHERO: "<<fichero_paciente << endl;
	cout << "\n";
	cout << "LOS DATOS DEL PACIENTE " << copia_linea << " SON: \n";
	ifstream fich (fichero_paciente);
	if(fich.is_open())
	{
		int i = 0;
		while(!fich.eof() && (!(i==6)))
		{
				if(i==0){
					getline(fich,line);
					cout << "Nombre completo: " << line << endl;
				}
				if(i==1)
				{
					getline(fich,line);
					cout << "Direccion de la calle: " << line << endl;					
				}
				if(i==2)
				{
					getline(fich,line);
					cout << "Codigo postal: " << line << endl;	
				}
				if(i==3)
				{
					getline(fich,line);
					cout << "Ciudad: " << line << endl;
				}
				if(i==4)
				{
					getline(fich,line);
					cout << "Provincia: " << line << endl;

				}
				if(i==5)
				{
					getline(fich,line);
					cout << "DNI: " << line << endl;
				}
			i++;			
		}
	}
	else
	{
		cout << "No se ha encontrado datos sobre el paciente";
	}
	fich.close();
}
void Paciente::modifica_pacientes(string concatenar, string antiguo)
{
ifstream fichero("Pacientes.txt");
ofstream fich ("Pacientemodificar.txt");
string buscar;
if(fichero.is_open())
{
	while(getline(fichero, buscar))
	{
		if(buscar==antiguo)
		{

			fich << concatenar << endl;
		}
		else{
			fich << buscar << endl;
		}
	}
}
fich.close();
fichero.close();
remove("Pacientes.txt");
rename("Pacientemodificar.txt", "Pacientes.txt");
}

void Paciente::choose_datos_paciente(string fichero_paciente, int opcion, string linea_paciente)
{
	//tengo que pasar a la funcion el nombre del fichero
	ifstream fichero (fichero_paciente);
	string nuevo_fichero=fichero_paciente;
	ofstream fich ("Pacientesmodificar.txt");
	string buscar;
	string aux; //la utilizaremos para poder hacer cambios en el fichero.
	int auxiliar; //para hacer cambios en el fichero.
	int contador = 1; //LO PONGO A UNO PORQUE CONSIFERO QUE LAS OPCIONES COMIENZAN EN 1.
	//RESTRINGIR EL 3, YA QUE SERÁ CUANDO UTILICEMOS EL INT AUX
	string concatenar;
	if (fichero.is_open())
	{
			while(getline(fichero, buscar)) 
			{
				if((opcion == contador)) 
				{	
					if(opcion==3){
						cout << "Introduce nuevo codigo postal\n";
						cin >> auxiliar;
						fich << auxiliar << endl;
					}
					else
					{
						if(opcion==2)
						{
							cout << "Introduce la nueva información del paciente\n";
							cin.ignore();
							getline(cin, aux);
							buscar = aux;
							fich << buscar << endl;
						}
						else{
								if(opcion==1)
								{
									string name, surname1,surname2;
									cout <<"Introduce nuevo nombre\n";
									cin >> name;
									cout << "Introduce primer apellido\n";
									cin >> surname1;
									cout << "Introduce primer apellido\n";
									cin >> surname2;
									concatenar=name+"_"+surname1+"_"+surname2;
									fich << concatenar << endl; //Para cambiar dentro del fichero
									modifica_pacientes(concatenar, buscar); //Para cambiar el archivo pacientes.txt
				
								}
								else
								{
									cout << "Introduce la nueva información del paciente\n";
									cin >> aux;
									buscar = aux;
									fich << buscar << endl;
								}
						}
					}

				}//if
				else{
					fich << buscar << endl;
				}

				contador++;

       		}//while
	}//if
	else
	{
		cout << "No se ha podidio abrir el archivo\n";
	}
	fich.close();
	fichero.close();
	remove(fichero_paciente.c_str());
	rename("Pacientesmodificar.txt",nuevo_fichero.c_str());
	rename(nuevo_fichero.c_str(), (concatenar+".txt").c_str());
	rename((linea_paciente+"_Historial"+".txt").c_str(), (concatenar+"_Historial"+".txt").c_str()); //para el historial
	rename((linea_paciente+"_Tratamiento"+".txt").c_str(), (concatenar+"_Tratamiento"+".txt").c_str()); //para el tratamiento
	cout << "Archivo modificado correctamente\n";
}

/*	la funcion busca pacientes.txt y lo leer guaradando cada paciente en la lista de pacientes
		la muestra y pregunta a que paciente quiere modificar
		se pregunta que parte del struct quiere modificar y lo demas s e deja igual (un swich con una opcion para cada caso(1 para dni, 2 para direccion etc...))
		en cada caso se accede al struct leyendo cada campo (menos el que se quiere modificar) y preguntando cuales son los nuevos datos que quiere
		se iguala lo que se quiere modificar a lo que se ha intoducido y se escribe el struct entero en el fichero sobreescribiendolo entero
		(posible opcion de borrarlo y crearlo de nuevo con los datos nuevos para asi no sobreescribir)*/
	
void Paciente::modificar_datos_paciente()
{
	cout << "SELECCIONA EL PACIENTE AL QUE QUIERE MODIFICAR ALGUN DATO\n";
	mostrar_lista_pacientes("Pacientes.txt");
	cout << "\n";
	string copia_linea;
	copia_linea=choose_paciente();
	string fichero_paciente=copia_linea+".txt";
	cout << "NOMBRE FICHERO: "<<fichero_paciente << endl;
	cout << "\n";
	cout << "QUE DATOS DEL PACIENTE QUIERE MODIDIFICAR?\n";
	cout << "1.- Nombre del paciente\n";
	cout << "2.- Direccion de la calle\n";
	cout << "3.- Codigo Postal\n";
	cout << "4.- Ciudad\n";
	cout << "5.- Provincia\n";
	cout << "6.- DNI\n";
	int opcion;
	cin >> opcion;
	choose_datos_paciente(fichero_paciente, opcion, copia_linea);
	//Ver si se puede hacer hasta aqui, es decir terminar y no escribir mas.
}

//PARA LAS PRUEBAS
int main(){
	Paciente prueba;
	prueba.add_paciente();
	prueba.delete_paciente();
	prueba.consultar_datos_personales();
	prueba.modificar_datos_paciente();
	return 0;
}