### **AÑADIR PACIENTE**
*ID:* C01	

__*Descripción:*__ El secretario añadirá a la base de datos un nuevo paciente.

__*Actores principales:*__ Secretario	

__*Actores secundarios:*__ Paciente

__*Precondiciones:*__
* El paciente no puede estar ya registrado.
* No puede haber dos pacientes con el mismo nombre, aunque los datos sean distintos.

__*Flujo principal:*__
1. El secretario desea añadir un nuevo paciente.
2. El secretario selecciona el menú de pacientes.
3. El secretario selecciona la opción de añadir un paciente.
4. El secretario rellenará los campos con la información que se le pide sobre el cliente.

__*Postcondiciones:*__
El cliente quedará guardado en la base de datos.

__*Flujos alternativos:*__

4.a Si se introduce algun campo erróneo, como un codigo postal con 7 cifras, se pedira de nuevo hasta que sea correcto

