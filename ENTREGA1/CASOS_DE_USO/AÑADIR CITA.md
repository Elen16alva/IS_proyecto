### **AÑADIR CITA** 
*ID:* C05	

__*Descripción:*__ El secretario reservará una cita para un paciente.

__*Actores principales:*__ Secretario       _*Actores secundarios:*_ Paciente

__*Precondiciones:*__
El paciente debe estar registrado en la base de datos y la cita debe estar disponible.

__*Flujo principal:*__ 
1. El secretario desea reservar una cita para un paciente.
2. El secretario selecciona el menú de citas.
3. El secretario selecciona el menú de reserva.
4. El sistema preguntará el dia que se quiere la cita.
5. El secretario introduce la fecha en la cual quiere la cita.
6. El sistema mostrará por pantalla las citas que están disponibles para ese dia.
7. El secretario seleccionará la cita que quiere reservar.
8. El secretario introducirá el nombre completo de la persona a la que se le reserva la cita.

__*Postcondiciones:*__
La cita reservada ya no estará disponible.

__*Flujos alternativos:*__

4.a Se validará la fecha hasta que sea válida.

7.a Validará que la cita introducida esté libre.

8.a Si el nombre no pertenece a un paciente registrado, mostrará un mensaje de error y terminará la instrucción.

