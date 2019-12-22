### **BORRAR TRATAMIENTO**
*ID:* C11	

__*Descripción:*__ El secretario borrará el tratamiento a un paciente.

__*Actores principales:*__ Secretario       

__*Actores secundarios:*__ Paciente

__*Precondiciones:*__
1. El paciente debe estar ya registrado en la base de datos.
2. El paciente debe tener un tratamiento actualmente.

__*Flujo principal:*__
1. El secretario desea añadir un tratamiento a un paciente.
2. El secretario selecciona el menú de pacientes.
3. El secretario selecciona la opción de tratamiento.
4. El secretario selecciona la opción de borrar tratamiento.
5. El sistema mostrará una lista con todos los pacientes existentes.
6. El secretario buscará y seleccionará el paciente del que desea borrar el tratamiento.
7. El sistema mostrará un mensaje de confirmación para borrar el tratamiento.
8. El sistema borrará todo el tratamiento de ese paciente.

__*Postcondiciones:*__

8.a. A pesar de haber borrado todo el tratamiento, el sistema creara una base de datos de seguridad con lo que ha borrado en caso de querer consultarse de nuevo o recuperarlo.

__*Flujo alternativo*__

7.a. El sistema mostrará un mensaje de confirmación a la hora de borrar el tratamiento.
