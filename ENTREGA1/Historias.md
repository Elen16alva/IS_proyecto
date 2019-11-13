**HISTORIAS DE USUARIO**

*ID*: H01       
*Nombre*: **DAR DE ALTA**

*Descripción*: Como administrador quiero poder registrar un nuevo paciente, junto con sus datos personales y médicos.
## *Validación*:
* Se debe poder introducir cualquier nombre con sus correspondientes apellidos.
* Se debe introducir el nombre y apellidos obligatoriamente.
* Se podrán añadir los datos del paciente, su historial médico y los tratamientos de éste aunque habrá datos que no se podrán modificar una vez registrados, tales como el historial médico y tratamientos.
 

*ID*: H02       
*Nombre*: **BORRAR PACIENTE**

*Descripción*: Como administrador quiero borrar a cualquier paciente para que este no aparezca en la base de datos.
## *Validación*:
* Se puede borrar a cualquier paciente.
* Se borrará todo lo referente y relacionado con el paciente.


*ID*: H03       
*Nombre*: **CONSULTAR PERSONAS**

*Descripción*: Como administrador quiero poder encontrar a cualquier paciente para poder consultar sus datos e información.
## *Validación*:
* Se puede buscar a cualquier paciente.
* Se puede consultar tanto los datos, las citas, los tratamientos y el historial médico.


*ID*: H04       
*Nombre*: **CONSULTAR CITA**

*Descripción*: Como administrador quiero poder consultar la cita de un paciente para poder saber a qué hora hay que atenderle.
## *Validación*:
* Se puede ver las citas que hay disponibles para el dia deseado.
 

*ID*: H05       
*Nombre*: **AÑADIR CITA**

*Descripción*: Como administrador quiero que cualquier paciente pueda escoger cita para que pueda ser atendido por el médico.
## *Validación*:
* Se mostrarán solo las citas que están disponibles.
* Las citas ya reservadas no aparecerán.
* Para que el paciente puede reservar cita deberá introducir su nombre completo.

 
*ID*: H06       
*Nombre*: **BORRAR CITA**

*Descripción*: Como administrador quiero que cualquier paciente pueda borrar su cita para que ésta vuelva a estar disponible para otro paciente.
## *Validación*:
* Cualquier paciente podrá borrar su cita. 
* No aparece en su historial como que nunca tuvo ninguna cita ese día borrado
* La cita para que sea borrada debe haber sido reservada con antelación.
* En cuanto la cita sea borrada, esta inmediatamente será habilitada de nuevo.
