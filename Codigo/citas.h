#ifndef CITAS_H
#define CITAS_H

#include <list>
using namespace std;

	struct datos_lista_citas
	{
		int hora, minuto;
		string nombre;
	};

	class Citas
	{
	private:
		int dia_sistema, mes_sistema, anio_sistema;
		int hora_reserva; int minuto_reserva;
		list<struct datos_lista_citas> lista_;
		string dia_reserva_, mes_reserva_, anio_reserva_;
		string nombre, apellido1, apellido2;


		
	public:
		Citas();
		inline string getDia_reserva() {return dia_reserva_;}
		inline void setDia_reserva(string dr){dia_reserva_=dr;}
		inline string getMes_reserva() {return mes_reserva_;}
		inline void setMes_reserva(string mr){mes_reserva_=mr;}
		inline string getAnio_reserva() {return anio_reserva_;}
		void setAnio_reserva(string anio);
		void menu_citas();
		bool confirmafecha(string dr,string mr);
		void aniadir_cita();
		bool imprimirCitasLibres();
		bool imprimirCitas(string dr, string mr, string anio);
		bool imprimirCitas();
		void reservaCitas();
		void crear_fichero_cl();
		void consultarCitas();
		void modificar_Cita();
		void eliminarCita(string dia, string mes, string anio);
		void imprimirCitasReservadas(string dia, string mes, string anio);
		void eliminar();
		bool existe();
		
	};




#endif