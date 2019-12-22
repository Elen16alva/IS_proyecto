# **HISTORIAS DE USUARIO**

## *Nombre*: **AÑADIR UN PACIENTE** 
*ID*: H01 

__*Descripción*__: Como administrador quiero poder registrar un nuevo paciente, junto con sus datos personaleS.

 __*Validación*__:
* Se debe introducir nombre y apellidos obligatoriamente.
* Se debe introducir los datos personales del mismo para que el paciente sea creado de forma correcta.
* Se añadirá el paciente recien inscrito a la base de datos de Pacientes.
 

      
## *Nombre*: **BORRAR PACIENTE**
*ID*: H02 

__*Descripción*__: Como administrador quiero borrar a cualquier paciente para que este no aparezca en la base de datos.

 __*Validación*__:
* Se seleccionará el paciente a borrar de la base de datos de pacientes.
* Se borrará los datos del paciente, el historial y el tratamiento en curso (si el tratamieno aun no ha finalizado) del mismo.


      
## *Nombre*: **CONSULTAR DATOS PERSONALES**
*ID*: H03 

__*Descripción*__: Como administrador quiero poder encontrar a cualquier paciente para poder consultar sus datos personales.

 __*Validación*__:
* Se seleccionará el paciente a borrar de la base de datos de pacientes.
* Se puede consultar sólo los datos personales del paciente.



## *Nombre*: **MODIFICAR DATOS PERSONALES**
*ID*: H04

__*Descripción*__: Como administrador quiero poder modificar los datos de cualquier paciente en cualquier momento. 

 __*Validación*__:
* Se seleccionará el paciente del que se quiere modificar sus datos personales.
* Se seleccionará que dato se quiere modificar del paciente.



       
## *Nombre*: **CONSULTAR CITA** 
*ID*: H05

__*Descripción*__: Como administrador quiero poder consultar la cita de un paciente para poder saber a qué hora hay que atenderle. 

 __*Validación*__:
* Se puede ver las citas que hay disponibles, y reservadas para el día deseado.
 

      
## *Nombre*: **AÑADIR CITA**  
*ID*: H06 

__*Descripción*__: Como administrador quiero que cualquier paciente pueda escoger cita para que pueda ser atendido por el médico. 

 __*Validación*__:
* Se mostrarán las citas que están disponibles.
* Se mostrará una lista con las citas reservadas al final a modo de comprobación.
* Para que el paciente puede reservar cita deberá introducir su nombre completo, y que dicho paciente haya sido previamente registrado.

 
      
## *Nombre*: **BORRAR CITA**
*ID*: H07 

__*Descripción*__: Como administrador quiero que cualquier paciente pueda borrar su cita para que ésta vuelva a estar disponible para otro paciente.

 __*Validación*__:
* Cualquier paciente registrado podrá borrar su cita. 
* La cita para que sea borrada debe haber sido reservada previamente.
* En cuanto la cita sea borrada, ésta, inmediatamente, será habilitada de nuevo.



## *Nombre*: **MODIFICAR CITA**

*ID*: H08

__*Descripción*__: Como administrador quiero poder modificar cualquier cita, pudiendo escoger otra cualquiera disponible. 

 __*Validación*__:
* Solo podrá escoger citas disponibles.
* En cuanto la cita sea modificada la anterior, será habilitada de nuevo.



## *Nombre*: **AÑADIR TRATAMIENTO**
*ID*: H09

__*Descripción*__: Como administrador quiero añadir cualquier tratamiento a cualquier paciente.

 __*Validación*__:
* Se seleccionará el paciente al quiere añadir el tratamiento de la bse de datos.
* Se introducirán los datos requeridos para que el tratamiento sea creado de forma correcta.




## *Nombre*: **BORRAR TRATAMIENTO**
*ID*: H10

__*Descripción*__: Como administrador quiero borrar el tratamiento actual del paciente. 

 __*Validación*__:
* Se selecciona el paciente con su tratamiento en curso para que sea borrado.
* Una vez terminado el tratamiento este no será borrado.
* El tratamiento ya borrado se añadira a la base de datos de Tratamientos.



## *Nombre*: **CONSULTAR TRATAMIENTOS**
*ID*: H11

__*Descripción*__: Como administrador quiero poder consultar cualquier tratamiento ya sea en curso o finalizado. 

 __*Validación*__:
* Se selecciona el paciente del que se quiere consultar su tratamiento en curso.
* Se podrán consultar tramientos ya finalizados, si el tratamiento en curso del paciente ha sido borrado anteriormente.



## *Nombre*: **AÑADIR HISTORIAL MÉDICO**
*ID*: H12

__*Descripción*__: Como administrador quiero añadir a cualquier paciente un historial.

__*Validación*__:
* Se seleccionará el paciente al que se quiere añadir un historial.
* Se introduciran los datos necesarios en el historial para que se cree correctamente.



## *Nombre*: **CONSULTAR HISTORIAL MÉDICO** 
*ID*: H13

__*Descripción*__: Como administrador quiero consultar el historial médico del paciente. 

 __*Validación*__: 
* Se seleccionará el paciente del que se quiere consultar su historial.
* Se mostrará todos los datos contenidos en el historial.



## *Nombre*: **MENÚ PRINCIPAL**
*ID*: H14

__*Descripción*__: Como administrador quiero tener un menú para poder hacer cualquier tarea requerida.

__*Validación*__:
* Este aparecerá al iniciar la aplicación.
* Habrá diferentes menu para pacientes y citas.
* Se mostrarán las citas diarias, tanto las citas reservadas como no.
