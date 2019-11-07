+ publico - privado

## **CLASES DE LA CLINICA**

### **Clase:** *Paciente*
Esta clase contiene todas las operaciones posibles que se podrán hacer sobre el paciente.

* **Datos:**


* **Métodos:**

*+Añadir_paciente*

Este método añadirá un nuevo paciente, junto con sus datos, a la base de datos.

*+Borrar_paciente*

Este método borrará un paciente ya existente, junto con sus datos historial y tratamientos, a la base de datos.

*+Consultar_datos_paciente*

Este método permitirá consultar los datos generales del paciente que se desee(tales como el DNI, localidad...).

*+Consultar_historial*

Este método permitirá consultar el historial médico del paciente que se desee.

*+Añadir_historial*

Este método añadirá nueva información al historial de un paciente.

*+Consultar_tratamiento*

Este método permitirá consutar el tratamiento en curso del paciente seleccionado.

*+Añadir_tratamiento*

Este método actualizará y añadira el tratamiento de un paciente.

*+Borrar_tratamiento*

Este método borrará el tratamiento actual y no dejara ningun tratamiento.

*+Borrar_cita*

Este método cancelará una cita reservada y dejará la cita disponible para poder reservarse de nuevo.

*+Reservar_cita*

Este método reservará una cita para un paciente.

*+Modificar_cita*

Este método eliminará una cita riservada y la pondra dispnible y reservará una nueva cita distinta a la anterior.

*+Modificar_datos_paciente*

Este método permitirá modificar los datos personales de un paciente.

*-Mostrar_lista_citas_disponibles*

Esta función mostrará un listado de las citas dispnibles para el día seleccionado.

*-Mostrar_lista_pacientes*

Esta función mostrará un listado de todos los pacientes registrados en la base de datos.

*-Mostrar_citas_diarias*

Esta funcion mostrará un listado de las citas previstas para el dia en curso sobre el menu principal.


### **Clase:** *Cita*

Esta clase contiene el metodo para consultar las citas que hay disponibles el día que se desee.


* **Datos:**
*Lista_dia*

La variable contiene la lista de todas las citas (reservadas o no) del día que se desee consultar.


* **Métodos:**
*Consulta_dia*

Este metodo mostrará por pantalla un listado de las citas que hay disponbles a un lado y al otro un listado de las citas ya reservadas.
