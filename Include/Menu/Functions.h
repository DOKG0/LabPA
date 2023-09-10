#include <string>
#include "../Datatypes/Datatypes.h"
#include "../ico.h"
#include <cctype>
#include <limits>

//Funciones Main
//void altaHostal();

//Funciones generales
void limpiarBuffer();
std::string pedirString(std::string msg);
int pedirInt(std::string msg);
float pedirFloat(std::string msg);
void pausa(std::string msg);
void imprimirTitulo(int parte);
std::string imprimirObtengoHostales(List* listaHostal);
bool validarExisteOpcionString(ICollection* coleccion, std::string valor);
void borrarLista(ICollection* lista);
char confirmarSN(std::string msg);
bool verificarEnLista(std::string** l, std::string p);
int DiferenciaEnDias(DTFecha* fecha1, DTFecha* fecha2);

//CONFIRMACION
bool confirmarSN(char respuesta);
char confirmarSN2();
//bool validarRespuesta(const std::string& respuesta);
//char Confirmacion(char opcion);
//AltaUsuario
void RegistrarEmpleado();
void RegistrarHuesped();
int opcionAltaUsuario();

//AltaHostal
bool validarNombreHostal(std::string nombreHostal);

//Alta Habitacion
bool habitacionValida(int numerohab, std::string nombreHostal);
bool capacidadValida(int capacidadhab);


//ERROR
void mostrarError(const std::string& mensaje);

//Usuario
std::string obtenerNombreCargo(tipoCargo cargo);
///



