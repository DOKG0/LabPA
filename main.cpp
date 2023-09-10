#include <iostream>
#include <string.h>
#include "Include/Menu/Menu.h"

int main(int argc, char *argv[]){
	int op = 0;

	do {
		op = pedirOpcion();

		switch (op){
		case 1:
			//Altausuario
			altaUsuario();
			break;

		case 2:
			//AltaHostal
			altaHostalMenu();
			break;

		case 3:
			//AltaHabitacion
			altaHabitacion();
			break;

		case 4:
			//AsignarEmpleado
			asignarEmpleadoMain();
			break;

		case 5:
			//RealizarReserva
			realizarReserva();
			break;

		case 6:
			//Consulta Top 3 Hostales
			consultaTop3Hostales();
			break;

		case 7:
			//Registrar Estadia
			registrarEstadia();
			break;

		case 8:
			//Finalizar Estadia
			finalizarEstadia();
			break;
		
		case 9:
			//Calificar Estadia
			calificarEstadia();
			break;

		case 10:
			//Comentar Calificacion
			comentarCalificacion();
			break;
			
		case 11:
			//Consulta de Usuario
			consultaUsuarioMain();
			break;
		
		case 12:
			//Consulta de Hostal
			consultaHostal();
			break;

		case 13:
			//Consulta Reserva
			consultaReserva();
			break;

		case 14:
			//Consulta Estadia
			consultaEstadia();
			break;

		case 15:
			//Baja de Reserva
			bajaReserva();
			break;

		case 16:
			//Modificar Fecha Sistema
			modificarFechaSistema();
			break;

		case 17:
			//Pre-cargar datos en el sistema
			cargarDatos();
			break;

		case 18:
			//Salir del sistema
			salirSistema();
			break;
		};

	} while (op != 18);

	return 0;
}
