## **CLASES DE LA CLÍNICA**

### **Clase:** *Tratamiento*

Esta clase contiene los métodos de los tratamientos de los pacientes.


* **Datos:**

*-Tratamiento_paciente*

Tipo: Vector string

Esta variable contendrá todos una lista con todos los tratamientos del paciente, siendo el último el actual.


* **Métodos:**

*+Consultar_tratamiento*

Este método permitirá consultar el tratamiento en curso del paciente seleccionado.

*+Añadir_tratamiento*

Este método actualizará y añadirá el tratamiento de un paciente.

*+Borrar_tratamiento*

Este método borrará el tratamiento actual y no dejará ningún tratamiento.




### **Clase:** *Historial*

Esta clase contiene los métodos del historial de los pacientes.


* **Datos:**

*-Historial_paciente*

Tipo: Vector string

Esta variable contendrá el historial del paciente al que pertenece.


* **Métodos:**

*+Consultar_historial*

Este método permitirá consultar el historial médico del paciente que se desee.

*+Añadir_historial*

Este método añadirá nueva información al historial de un paciente.



### **Clase:** *Paciente*

Esta clase contiene todas las operaciones posibles que se podrán hacer sobre el paciente.

* **Datos:**

*-Lista_pacientes*

Tipo: Vector string

Esta variable contiene todos los pacientes registrados en la base de datos.

*-Datos_paciente*

Tipo: Struct 

Esta variable contendrá los datos personales del paciente al que pertenece.


* **Métodos:**

*+Añadir_paciente*

Este método añadirá un nuevo paciente, junto con sus datos, a la base de datos.

*+Borrar_paciente*

Este método borrará un paciente ya existente, junto con sus datos historial y tratamientos, a la base de datos.

*+Consultar_datos_paciente*

Este método permitirá consultar los datos generales del paciente que se desee (tales como el DNI, localidad...).

*+Modificar_datos_paciente*

Este método permitirá modificar los datos personales de un paciente.

*-Mostrar_lista_pacientes*

Esta función mostrará un listado de todos los pacientes registrados en la base de datos.




### **Clase:** *Citas*

Esta clase contiene el metodo para consultar las citas que hay disponibles el día que se desee.


* **Datos:**
*-Lista_citas*

Tipo: Vector string

La variable contiene la lista de todas las citas (reservadas o no) del día que se desee consultar.

*-Lista_citas_paciente*

Tipo: Vector string

Esta variable contiene todas las citas que tiene reservadas el paciente al que pertenece la lista.


* **Métodos:**

*+Consulta_día*

Este método mostrará por pantalla un listado de las citas que hay disponibles a un lado y al otro un listado de las citas ya reservadas.

*+Borrar_cita*

Este método cancelará una cita reservada y dejará la cita disponible para poder reservarse de nuevo.

*+Reservar_cita*

Este método reservará una cita para un paciente.

*+Modificar_cita*

Este método eliminará una cita reservada y la pondrá disponible, después reservará una nueva cita distinta a la anterior.

*-Mostrar_lista_citas_disponibles*

Esta función mostrará un listado de las citas disponibles para el día seleccionado.



### **Clase:** *Menú*

Esta clase contiene el método de mostrar las citas diarias.


* **Datos:**

*-Lista_citas_diaria*

Tipo: Vector string

Esta variable contendrá todas las citas reservadas del día en curso.


* **Métodos:**

*-Mostrar_citas_diarias*

Esta función mostrará un listado de las citas previstas para el dia en curso sobre el menu principal.
