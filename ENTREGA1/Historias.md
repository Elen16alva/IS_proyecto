#**HISTORIAS DE USUARIO**

*ID*: H01       *Nombre*: **DAR DE ALTA**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero poder registrar un nuevo paciente, junto con sus datos personales y m�dicos.
##*Validaci�n*:
* Se debe poder introducir cualquier nombre con sus correspondientes apellidos.
* Se debe introducir el nombre y apellidos obligatoriamente.
* Se podr�n a�adir los datos del paciente, su historial m�dico y los tratamientos de �ste aunque habr� datos que no se podr�n modificar una vez registrados, tales como el historial m�dico y tratamientos.
 

*ID*: H02       *Nombre*: **BORRAR PACIENTE**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero borrar a cualquier paciente para que este no aparezca en la base de datos.
##*Validaci�n*:
* Se puede borrar a cualquier paciente.
* Se borrar� todo lo referente y relacionado con el paciente.


*ID*: H03       *Nombre*: **CONSULTAR PERSONAS**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero poder encontrar a cualquier paciente para poder consultar sus datos e informaci�n.
##*Validaci�n*:
* Se puede buscar a cualquier paciente.
* Se puede consultar tanto los datos, las citas, los tratamientos y el historial m�dico.


*ID*: H04       *Nombre*: **CONSULTAR CITA**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero poder consultar la cita de un paciente para poder saber a qu� hora hay que atenderle.
##*Validaci�n*:
* Se puede ver las citas que hay disponibles para el dia deseado.
 

*ID*: H05       *Nombre*: **A�ADIR CITA**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero que cualquier paciente pueda escoger cita para que pueda ser atendido por el m�dico.
##*Validaci�n*:
* Se mostrar�n solo las citas que est�n disponibles.
* Las citas ya reservadas no aparecer�n.
* Para que el paciente puede reservar cita deber� introducir su nombre completo.

 
*ID*: H06       *Nombre*: **BORRAR CITA**
*Responsable*: Secretario
*Descripci�n*: Como administrador quiero que cualquier paciente pueda borrar su cita para que �sta vuelva a estar disponible para otro paciente.
##*Validaci�n*:
* Cualquier paciente podr� borrar su cita. 
* No aparece en su historial como que nunca tuvo ninguna cita ese d�a borrado.
* La cita para que sea borrada debe haber sido reservada con antelaci�n.
* En cuanto la cita sea borrada, esta inmediatamente ser� habilitada de nuevo.
