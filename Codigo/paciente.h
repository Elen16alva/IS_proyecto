//paciente.cc

void Paciente::add_paciente()
{
	/**la funcion pide el nombre y apellidos del paciente(comprueba si existe el txt)
		si no existe lo crea y pide la direccion (calle y numero), codigo postal, cuidad, provincia, DNI etc...  lo rellena con los datos
		todo esto son campos del struct paciente que se usara para leer, escribir y modificar los datos del paciente, y los guardara aqui
		ademas añadira du nombre y apellidos a pacientes.txt
		si el fichero ya existe da fallo y dice que ya existe y no lo modifica
	*/
}

void Paciente::borrar_paciente()
{
	/*la fucion accede al pacientes.txt lo guarda en la lista y la muestra (funcion mostrar_lista_pacientes)
		pide el paciente a borrar y se borrara el txt con su nombre, el txt con su tratamiento y el txt de su historial
		ademas se borrara el nombre del pacientes.txt 
		(se puede borrar de la lista, hacer un resize o algo asi y luego borrar el pacientes.txt y crear uno nuevo escribiendo la lista de pacientes con el paciente ya borrado)
	**/
}

void Paciente::consultar_datos_personales()
{
	/**la fucion accede al pacientes.txt lo guarda en la lista y la muestra (funcion mostrar_lista_pacientes)
		se coje el nombre de quien haya querido se busca su txt se accede a el y se lee
		lo que se lee se guarda en el struct y lo va imprimiendo
	*/
}

void modificar_datos_paciente()
{
	/**la funcion busca pacientes.txt y lo leer guaradando cada paciente en la lista de pacientes
		la muestra y pregunta a que paciente quiere modificar
		se pregunta que parte del struct quiere modificar y lo demas s e deja igual (un swich con una opcion para cada caso(1 para dni, 2 para direccion etc...))
		en cada caso se accede al struct leyendo cada campo (menos el que se quiere modificar) y preguntando cuales son los nuevos datos que quiere
		se iguala lo que se quiere modificar a lo que se ha intoducido y se escribe el struct entero en el fichero sobreescribiendolo entero
		(posible opcion de borrarlo y crearlo de nuevo con los datos nuevos para asi no sobreescribir)

	*/	
}