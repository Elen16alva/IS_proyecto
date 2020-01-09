clinica.exe: menu.cc paciente.cc citas.cc tratamiento.cc historial.cc
	g++ -o clinica.exe menu.cc paciente.cc citas.cc tratamiento.cc historial.cc -std=c++11
