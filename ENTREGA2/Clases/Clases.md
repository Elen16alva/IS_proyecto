## **CLASES DE LA CLÍNICA**

### **Clase:** *Tratamiento*

Esta clase contiene los métodos de las operaciones sobre los tratamientos de los pacientes.


* **Datos:**

*-comienzo_tratamiento*

Tipo: string

Esta variable contendrá la fecha de inicio del tratamiento.

*-duracion_tratamiento*

Tipo: string

Esta variable contendá la duracion del tratamiento.

*-dosis*

Tipo: string

Esta variable contendrá la dosis del medicamento.

*-nombre_medicamento*

Tipo: string

Esta variable contendrá el nombre del medicamento recetado.

*-year_sistema*

Tipo: entero

Esta variable guardará el año del sistema.

*-month_sistema*

Tipo: entero

Esta variable guardará el mes del sistema.

*-day_sistema*

Tipo: entero

Esta variable guardará el día del sistema.



* **Métodos:**

*+see_tratamiento*

Este método permitirá consultar el tratamiento en curso del paciente seleccionado.

*+add_tratamiento*

Este método actualizará y añadirá el tratamiento de un paciente.

*+delete_tratamiento*

Este método borrará el tratamiento actual y no dejará ningún tratamiento.

*+comprobar_fichero*

Esta función comprobará la existencia de la base de datos sonde están los pacientes registrados.

*+choose_paciente*

Esta función seleccionará el paciente sobre el que se quiere operar.

*+confirmafecha*

Esta función 





### **Clase:** *Historial*

Esta clase contiene los métodos de las operaciones sobre el historial de los pacientes.


* **Datos:**

*-lista_pacientesH_*

Tipo: Lista de string

Esta variable contendrá la lista de pacientes que hay registrados.


* **Métodos:**

*+consultar_historial*

Este método permitirá consultar el historial médico del paciente que se desee.

*+add_historial*

Este método añadirá nueva información al historial de un paciente.

*+cargar_lista_pacientes*

Este método devolverá una lista con todos los pacientes existentes en la base de datos.

### **Clase:** *Paciente*

Esta clase contiene todas los métodos de las operaciones sobre pacientes.

* **Datos:**

*-nombre_*

Tipo: string

Esta variable contendrá el nombre del paciente.

*-apellido1_*

Tipo: string

Esta variable contendrá el primer apellido del paciente.

*-apellido2_*

Tipo: string 

Esta variable contendrá el segundo apellido del paciente.

*-direccion*

Tipo: string

Esta variable contendrá la dirección del paciente.

*-codigo_Postal*

Tipo: entero

Esta variable contendrá el código postal del paciente. 

*-ciudad*

Tipo: string  

Esta variable contendrá la ciudad del paciente.

*-provincia*

Tipo: string

Esta variable contendrá la provincia del paciente. 

*-DNI*

Tipo: string

Esta variable contendrá el DNI del paciente.

*-nombre_concatenar*

Tipo: string

Esta variable 


* **Métodos:**

*+comprobar_fichero*

Este método comprobará la existencia de la base de datos sonde están los pacientes registrados.

*+add_paciente*

Este método añadirá un nuevo paciente a la base de datos.

*+delete_paciente*

Este método borrará un paciente y toda su información de la base de datos.

*+choose_paciente*

Este método comprobará la existencia de la base de datos sonde están los pacientes registrados.

*+modifica_pacientes*

Esta función auxiliar actualizará la base de datos tras algunas operaciones como añadir un paciente.

*+choose_datos_paciente*

Esta función seleccionará que parte se quiere modificar de los datos de un paciente.

*+consultar_datos_personales*

Esta función mostrará los datos personales de un paciente.

*+modificar_datos_paciente*

Esta función modificará los datos personales de un paciente.


*+set_codigoPostal*

Este método auxiliar ayudará a comprobar que el código postal es correcto.




### **Clase:** *Citas*

Esta clase contiene los métodos de las operaciones de citas.


* **Datos:**
*-dia_sistema*

Tipo: entero

La variable 

*-mes_sistema*

Tipo: entero

Esta variable 

*-anio_sistema*

Tipo: entero

La variable 

*-hora_reserva*

Tipo: entero

La variable 

*-minuto_reserva*

Tipo: entero

La variable 

*-dia_reserva_*

Tipo: string

La variable 

*-mes_reserva_*

Tipo: string

La variable 

*-anio_reserva_*

Tipo: string

La variable 

*-nombre*

Tipo: string

La variable guardará el nombre del paciente.

*-apellidos*

Tipo: string

La variable guardará los apellidos del paciente.

*-lista_*

Tipo: lista de struct

La variable


* **Métodos:**

*+getDia_reserva*

Este método sirve para usar una variable privada.

*+setDia_reserva*

Este método sirve para dar valor a una variable privada.

*+getMes_reserva*

Este método sirve para usar una variable privada.

*+Set_reserva*

Este método sirve para dar valor a una variable privada.

*-getAnio_reserva*

Esta función sirve para usar una variable privada.

*-setAnio_reserva*

Esta función sirve para dar valor a una variable privada.

*-menuCitas*

Esta función hará de menú entre las distintas operaciones de sobre las citas de un paciente.

*-confirmafecha*

Esta función 

*-aniadir_citas*

Esta función 

*-imprimiCitasLibres*

Esta función

*-imprimirCitas*

Esta función

*-reservaCitas*

Esta función permitirá reservar una cita que este libre.

*-crear_fichero_cl*

Esta función

*-consultarCitas*

Esta función permitirá consultar las citas reservadas de un día concreto.

*-modificar_Cita*

Esta función permitirá cancelar una cita para sustituirla por otra.

*-eliminarCita*

Esta función permitirá borrar una cita ya reservada.

