#include "Functions.h"
#include "../ico.h"
#include "../Fabrica/Fabrica.h"
#include "../Sistema/ControladorHostal.h"
#include "../Sistema/ControladorUsuario.h"
#include "../Sistema/Hostal/Reserva.h"
#include "../Sistema/Excepciones.h"
#include "../Sistema/Hostal/Hostal.h"
#include "../Sistema/InterfazHostal.h"
#include "../Sistema/InterfazUsuario.h"
#include "../Sistema/ManejadorHostal.h"
#include "../Sistema/ManejadorUsuario.h"
#include "../Sistema/FechaSistema.h"
#include "iomanip"
#include <string.h>
#include <stdlib.h>

//Logica Menu
void statusMenu(int opcion);

void mostrarMenu();
int pedirOpcion();

//Menu
void altaUsuario();
void altaHostalMenu();
void altaHabitacion();
void asignarEmpleadoMain();
void realizarReserva();
void consultaTop3Hostales();
void registrarEstadia();
void finalizarEstadia();
void calificarEstadia();
void comentarCalificacion();
void consultaUsuarioMain();
void consultaHostal();
void consultaReserva();
void consultaEstadia();
void bajaReserva();
void modificarFechaSistema();
void cargarDatos();
void salirSistema();
void Limpiar();