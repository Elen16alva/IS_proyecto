#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "citas.h"
#include <fstream>
using namespace std;


void Citas :: menu_citas()
{
	int ele;
	cout<<"*********************"<<endl;
	cout<<"* 0. Salir          *"<<endl;
	cout<<"* 1. Añadir cita    *"<<endl;
	cout<<"* 2. Consultar Cita *"<<endl;
	cout<<"* 3. Eliminar cita  *"<<endl;
	cout<<"* 4. Modificar cita *"<<endl;
	cout<<"*********************"<<endl;
	cout<<"Eleccion >>";
	cin>>ele;
	switch(ele)
	{
		case 1:
		system("clear");
		aniadir_cita();
		reservaCitas();
		break;
		case 2:
		system("clear");
		consultarCitas();	
		break;
		case 3:
		system("clear");
		eliminar();
		break;
		case 4:
		system("clear");
		modificar_Cita();
		break;
		case 0:
		system("clear");
		exit(-1);
		break;
	}
}
void Citas::modificar_Cita()
{
	string dia, mes, anio;
	cout<<"Introduzca el dia de la cita que quiere modificar"<<endl;
	cin>>dia;
	cout<<"Introduzca el mes de la cita"<<endl;
	cin>>mes;
	cout<<"Introduzca el año"<<endl;
	cin>>anio;
	eliminarCita(dia, mes, anio);
	cout<<"Introduzca los nuevos datos de la cita"<<endl;
	aniadir_cita();
	reservaCitas();


}
void Citas::imprimirCitasReservadas(string dia, string mes, string anio)
{
	struct datos_lista_citas da;
	lista_.clear();
	ifstream leer1(dia +"-"+ mes+"-" +anio+"-reservado");
	if(!leer1)
	{
		cout<<"ERROR: No hay ninguna fecha reservada ese dia"<<endl;
	} 	
	else
	{
		char hor[10], minus[10];
		char nom[50];
		while(leer1.getline(hor,10, ','))
		{
			leer1.getline(minus, 10,':');
			leer1.getline(nom, 50,'\n');
	    	da.hora=atoi(hor);
	    	da.minuto=atoi(minus);
	    	da.nombre=nom;	
	  		lista_.push_back(da);
		}
		list<struct datos_lista_citas>::iterator i;
		for(i=lista_.begin(); i!=lista_.end(); i++)
		{
			cout<<(*i).hora<<":"<<(*i).minuto<<"<-Reservada por: "<<(*i).nombre<<"\n";
		}
	}
	leer1.close();
}
void Citas::eliminar()
{
	string dia, mes, anio;
	
	cout<<"Introduzca el dia de la cita"<<endl;
	cin>>dia;
	cout<<"Introduzca el mes de la cita"<<endl;
	cin>>mes;
	cout<<"Introduzca el año"<<endl;
	cin>>anio;
	eliminarCita(dia, mes, anio);	
}

void Citas::eliminarCita(string dia, string mes, string anio)
{

	char hor[10], minus[10];
	char nom[50];
	struct datos_lista_citas da;
	lista_.clear();
	fstream leer1(dia +"-"+ mes+"-" +anio+"-reservado");
	if(!leer1)
	{
		cout<<"ERROR: No hay ninguna fecha reservada ese dia"<<endl;
	} 	
	else
	{
		while(leer1.getline(hor,10, ','))
		{
			leer1.getline(minus, 10,':');
			leer1.getline(nom, 50,'\n');
	    	da.hora=atoi(hor);
	    	da.minuto=atoi(minus);
	    	da.nombre=nom;	
	  		lista_.push_back(da);
		}
		imprimirCitasReservadas(dia, mes, anio);
		cout<<"Inserte la hora"<<endl;
		cout<<"hora -> ";
		cin>>hor;
		cout<<"minuto -> ";
		cin>>minus;
		list<struct datos_lista_citas>::iterator i;
		for(i=lista_.begin(); i!=lista_.end(); i++)
		{
			if((*i).hora==atoi(hor) && (*i).minuto==atoi(minus))
			{
				i=lista_.erase(i);
			}
		}	
		leer1.close();
		ofstream sobreescribir(dia +"-"+ mes+"-" +anio+"-reservado");
		if(!sobreescribir)
		{
			cout<<"Error"<<endl;
		} 	
		for(i=lista_.begin(); i!=lista_.end(); i++)
		{
			leer1 << (*i).hora << "," << (*i).minuto<<":"<<apellido1<<" "<<apellido2<<", "<<nombre<<"\n";	
		}	
		sobreescribir.close();
		lista_.clear();
		ifstream leer1(dia +"-"+ mes+"-" + anio+"-libres");
		if(!leer1)
		{
			cout<<"Error"<<endl;
		} 	
		char h[10], m[10];
		while(leer1.getline(h,10, ','))
		{
			leer1.getline(m, 10,'\n');
			if(atoi(minus)==0)
			{
				if(atoi(h)==atoi(hor)-1 && atoi(m)==45)
				{
				
					da.hora=atoi(h);
					da.minuto=atoi(m);
					lista_.push_back(da);
					da.hora=atoi(hor);
					da.minuto=atoi(minus);
					lista_.push_back(da);
				}
				else
				{
					da.hora=atoi(h);
					da.minuto=atoi(m);
					lista_.push_back(da);
				}
			}
			else
			{

				if(atoi(h)==atoi(hor) && atoi(m)==atoi(minus)-15)
				{
					da.hora=atoi(h);
					da.minuto=atoi(m);
					lista_.push_back(da);
					da.hora=atoi(hor);
					da.minuto=atoi(minus);
					lista_.push_back(da);
					
				}
				else
				{
					da.hora=atoi(h);
					da.minuto=atoi(m);
					lista_.push_back(da);
				}
			}
		}
		ofstream sobreescribirL(dia +"-"+ mes+"-" +anio+"-libres");
		if(!sobreescribirL)
		{
			cout<<"Error"<<endl;
		} 	
		for(i=lista_.begin(); i!=lista_.end(); i++)
		{
			sobreescribirL<< (*i).hora << "," << (*i).minuto<<"\n";	
		}	
		sobreescribirL.close();
		char n;
		cout<<"Pulse una tecla para continuar"<<endl;
		cin>>n;
	}

}

bool Citas :: confirmafecha(string dr, string mr)
{
	char dia[dr.length()+1], mes[mr.length()+1], anio[anio_reserva_.length()+1];
	strcpy(dia, dr.c_str());
	strcpy(mes, mr.c_str());
	strcpy(anio, anio_reserva_.c_str());
	int m=atoi(mes);
	int d=atoi(dia);
	int a=atoi(anio);
	if(stoi(anio_reserva_)<anio_sistema)
	{
		cout<<"Introduzca una fecha válida"<<endl;
		return false;
	}
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
	
	cout<<"Revise la fecha introducida, recuerde que el dia y el mes ha de ser introducido en formato numerico"<<endl;
	return false;
	
	
}
void Citas ::aniadir_cita()
{

	string dr, mr, an;
	int confirmacion;
	do
	{
		cout<<"******************"<<endl;
		cout<<"* Introduzca dia *"<<endl;
		cout<<"******************"<<endl;
		cin>>dr;
		system("clear");
		cout<<"******************"<<endl;
		cout<<"* Introduzca mes *"<<endl;
		cout<<"******************"<<endl;
		cin>>mr;
		system("clear");
		cout<<"******************"<<endl;
		cout<<"* Introduzca año *"<<endl;
		cout<<"******************"<<endl;
		cin>>an;
		setAnio_reserva(an);
		system("clear");
		cout<<"¿La fecha seleccionada es correcta? -> "<<dr<<" / "<<mr<<"/"<<an<<endl;
		cout<<"1 -> SI || 2-> NO"<<endl;
		cin>>confirmacion;
	}
	while(confirmafecha(dr, mr)!=true && confirmacion==1);

	char dia[dr.length()+1], mes[mr.length()+1];
	strcpy(dia, dr.c_str());
	strcpy(mes, mr.c_str());
	setDia_reserva(dia);
	setMes_reserva(mes);
	imprimirCitasLibres();

	
}



void Citas ::  setAnio_reserva(string anio)
{
	anio_reserva_=anio;
}


Citas::Citas()
{

	 struct tm *tiempo;
	 time_t fecha_sistema;
	 time(&fecha_sistema);
	 tiempo=localtime(&fecha_sistema);
 
	 anio_sistema=tiempo->tm_year + 1900;
	 mes_sistema=tiempo->tm_mon + 1;
	 dia_sistema=tiempo->tm_mday;	
	
}

void Citas :: crear_fichero_cl()
{
	int min;
	ofstream salida(getDia_reserva() +"-"+ getMes_reserva()+"-" + getAnio_reserva()+"-libres");
	if(!salida) cout << "ERROR de apertura";
	for(int hor=9; hor<20; hor++)
	{
		for(int m=0; m<4; m++)
		{
			min=m*15;
			salida << hor << "," << min<<"\n";
		}
	}	
	salida.close();
	imprimirCitasLibres();

}

bool Citas :: imprimirCitasLibres()
{
	
	char hora[10], minus[10];
	
	struct datos_lista_citas da;
	lista_.clear();
	ifstream leer1(getDia_reserva() +"-"+ getMes_reserva()+"-" + getAnio_reserva()+"-libres");
	if(!leer1)
	{
		crear_fichero_cl();
		return false;
	} 	
	
	while(leer1.getline(hora,10, ','))
	{
		leer1.getline(minus, 10,'\n');
	 	da.hora=atoi(hora);
    	da.minuto=atoi(minus);
  		lista_.push_back(da);
	}
	list<struct datos_lista_citas>::iterator i;	
	for(i=lista_.begin(); i!=lista_.end(); i++)
	{
		cout<<(*i).hora<<":"<<(*i).minuto<<"\n";
			
	}
	leer1.close();
	return true;
	
		
}

bool Citas :: imprimirCitas(string dr, string mr, string anio)
{
	cout<<"Citas libres"<<endl;
	char hora[10], minus[10];
	
	struct datos_lista_citas da;
	
	ifstream leer1(dr +"-"+ mr+"-" + anio+"-libres");
	if(!leer1)
	{
		cout<<"error al abrir"<<endl;
		return false;
	} 	
	char n;
	lista_.clear();
	while(leer1.getline(hora,10, ','))
	{
		leer1.getline(minus, 10,'\n');
    	da.hora=atoi(hora);
    	da.minuto=atoi(minus);
  		lista_.push_back(da);
	}
	list<struct datos_lista_citas>::iterator i;	
	for(i=lista_.begin(); i!=lista_.end(); i++)
	{
		cout<<(*i).hora<<":"<<(*i).minuto<<"\n";
			
	}
	leer1.close();
	cout<<"Pulse una tecla para mostrar las citas reservadas"<<endl;
	cin>>n;
	system("clear");
	struct datos_lista_citas d;
	char nombre[50];
	lista_.clear();
	ifstream leer2(dr +"-"+ mr+"-" + anio+"-reservado");
	if(!leer2)
	{
		cout<<"error al abrir"<<endl;
		return false;
	} 	
	
	while(leer2.getline(hora,10, ','))
	{
		leer2.getline(minus, 10,':');
		leer2.getline(nombre , 50,'\n');
    	da.hora=atoi(hora);
    	da.minuto=atoi(minus);
    	da.nombre=nombre;
  		lista_.push_back(da);
	}

	for(i=lista_.begin(); i!=lista_.end(); i++)
	{
		cout<<(*i).hora<<":"<<(*i).minuto<<"<-Reservada por: "<<(*i).nombre<<"\n";
			
	}
	leer2.close();
	cout<<"Pulse una tecla para continuar"<<endl;
	cin>>n;
	return true;
	
		
}

bool Citas :: imprimirCitas()
{
	char d[10];
	char m[10];
	char a[10];
	sprintf(d, "%d", dia_sistema);
	sprintf(m, "%d", mes_sistema);
	sprintf(a, "%d", anio_sistema);
	string dr, mr, anio;
	dr=d, mr=m, anio=a;
	

	cout<<"Citas libres"<<endl;
	char hora[10], minus[10];
	
	struct datos_lista_citas da;	

	ifstream leer1(dr +"-"+ mr+"-" + anio+"-libres");
	if(!leer1)
	{
		int min;
		ofstream salida(dr +"-"+ mr+"-" + anio+"-libres");
		if(!salida) cout << "ERROR de apertura";
		for(int hor=9; hor<20; hor++)
		{
			for(int m=0; m<4; m++)
			{
				min=m*15;
				salida << hor << "," << min<<"\n";
			}
		}	
		salida.close();
		imprimirCitas();

	} 	
	char n;
	lista_.clear();
	while(leer1.getline(hora,10, ','))
	{
		leer1.getline(minus, 10,'\n');
    	da.hora=atoi(hora);
    	da.minuto=atoi(minus);
  		lista_.push_back(da);
	}
	list<struct datos_lista_citas>::iterator i;	
	for(i=lista_.begin(); i!=lista_.end(); i++)
	{
		cout<<(*i).hora<<":"<<(*i).minuto<<"\n";
			
	}
	leer1.close();
	cout<<"Pulse una tecla para mostrar las citas reservadas"<<endl;
	cin>>n;
	system("clear");
	char nombre[50];
	lista_.clear();
	ifstream leer2(dr +"-"+ mr+"-" + anio+"-reservado");
	if(!leer2)
	{
		cout<<"No hay citas reservadas para hoy"<<endl;
		return false;
	} 	
	
	while(leer2.getline(hora,10, ','))
	{
		leer2.getline(minus, 10,':');
		leer2.getline(nombre , 50,'\n');
    	da.hora=atoi(hora);
    	da.minuto=atoi(minus);
    	da.nombre=nombre;
  		lista_.push_back(da);
	}

	for(i=lista_.begin(); i!=lista_.end(); i++)
	{
		cout<<(*i).hora<<":"<<(*i).minuto<<"<-Reservada por: "<<(*i).nombre<<"\n";
			
	}
	leer2.close();
	return true;
	
		
}
bool Citas::existe()
{
	char nom[50], apellido_1[50], apellido_2[50];
	ifstream exist("Pacientes.txt");
	if(!exist)
	{
		cout<<"No hay ningun paciente registrado, añada un paciente primero"<<endl;
		return false;
	}
	while(exist.getline(nom, 50, '_'))
	{
		exist.getline(apellido_1, 50, '_');
		exist.getline(apellido_2, 50, '\n');
		if(nom==nombre && apellido_1==apellido1 && apellido_2==apellido2)
		{
			return true;
		}
	}
	cout<<"No esta"<<endl;
	return false;
}
void Citas :: reservaCitas()
{	
	int hora, minute;
	cout<<"Introduzca hora"<<endl;
	cin>>hora;
	cout<<"minuto"<<endl;
	cin>>minute;
	if(hora<9 || hora > 19)
	{
		cout<<"ERROR"<<endl;
	}
	if(minute%15!=0)
	{
		cout<<"ERROR"<<endl;
	}
	else
	{
		hora_reserva=hora;
		minuto_reserva=minute;
		getchar();
		cout<<"Introduzca el primer apellido del paciente \n";
		getline(cin, apellido1);
		cout<<"Introduzca el segundo apellido del paciente \n";
		getline(cin, apellido2);
		cout<<"Nombre del paciente \n";
		getline(cin, nombre);
		string apellidos=(apellido1 + " "+apellido2);
		if(existe()==true)
		{
		
			list<struct datos_lista_citas>::iterator i;	
			for(i=lista_.begin(); i!=lista_.end(); i++)
			{
				if((*i).hora==hora_reserva && (*i).minuto==minuto_reserva)
				{
					cout<<"entra \n";
					fstream fichero_cReservadas;
					fichero_cReservadas.open(getDia_reserva() +"-"+ getMes_reserva()+"-" + getAnio_reserva()+"-reservado", ios::app);
					if(!fichero_cReservadas.is_open()) cout << "ERROR de apertura";			
					fichero_cReservadas << (*i).hora << "," << (*i).minuto<<":"<<apellidos<<", "<<nombre<<"\n";	
					i=lista_.erase(i);
					fichero_cReservadas.close();
				}

			} 
			
			for(i=lista_.begin(); i!=lista_.end(); i++)
			{
				cout<<(*i).hora<<":"<<(*i).minuto<<endl;
			}

			ofstream fichero_cLibres(getDia_reserva() +"-"+ getMes_reserva()+"-" + getAnio_reserva()+"-libres");
			if(!fichero_cLibres) cout << "ERROR de apertura";

			for(i=lista_.begin(); i!=lista_.end(); i++)
			{
				fichero_cLibres << (*i).hora << "," << (*i).minuto<<"\n";
			}
			fichero_cLibres.close();
		
		}
	}
}

void Citas:: consultarCitas()
{
	string anio;
	string dia;
	string mes;
	cout<<"Introduzca dia"<<endl;
	cin>>dia;
	cout<<"Introduzca mes"<<endl;
	cin>>mes;
	cout<<"Introduzca año"<<endl;
	cin>>anio;
	system("clear");
	cout<<"Fecha seleccionada"<<endl;
	imprimirCitas(dia, mes, anio);
}




int main()
{
	system("clear");
	Citas c;
	c.imprimirCitas();
	c.menu_citas();	
}