#ifndef Hostal_H
#define Hostal_H

#include <string>
#include "../../ico.h"
#include "../../Datatypes/DataHostal.h"
#include "Habitacion.h"
#include "Reserva.h"
#include "ReservaGrupal.h"
#include "ReservaIndividual.h"
#include "../Usuario/Huesped.h"

class Hostal: public ICollectible{
private:
	std::string Nombre;
	std::string Direccion;
	std::string Telefono;
	IDictionary* Habitaciones = new OrderedDictionary();
	IDictionary* Reservas;
	int contadorReserva; //autogenerado
	
public:
	Hostal();
	Hostal(std::string nombre, std::string direccion, std::string telefono);
	Hostal(Hostal& host);
	~Hostal();
	//
	void setNombre(std::string nombre); 
	void setDireccion(std::string direccion);
	void setTelefono(std::string telefono);
	//
	std::string getNombre();
	std::string getDireccion();
	std::string getTelefono();
	//
	ICollection* obtenerHabs();
	//Obtiene solo los datos del hostal

	DataHostalLight * getDatosHostal();

	//
	void AltaHabitacion(int numero, float precio, int capacidad);
	void agregarHabitacion(Habitacion* h);
	void modificarHabitacion(Habitacion* h);
	void eliminarHabitacion(Habitacion* h);
	bool existeHabitacion(int numeroHabitacion); //Verifica que exista una habitacion con numero = numeroHabitacion
	//
	void agregarReserva(Reserva* r);
	void modificarReserva(Reserva* r);
	void eliminarReserva(Reserva* r);
	//
	DataHostal* getdataHostal(); //otra que trabaja para adentro
	//
	float PromedioCal(); //Retorna el promedio de las calificaciones asignadas
	//Consulta Reserva
	IDictionary * ObtenerReserva(int codigoReserva);
	//Registrar Estadia
	IDictionary * getReservas(std::string EmailHuesped);
	void CrearEstadiaH(int codigoReserva,DTFecha *FechaCheckIn, std::string Promo);
	//Finalizar Estadia
	IDictionary * ObtenerEstadiasABHostal(std::string EmailHuesped);
	void FinalizarEstadia(int CodigoEstadia, int CodigoReserva, DTFecha *FechaCheckOut);
	//baja reserva
	void EliminarReservaAccHost(int CodigoReserva);
	//ConsultaEstadia
	IDictionary * ConseguirDataEstadiaBasicaHost();
	DataEstadiaExtra * ConseguirDataEstadiaExtraHost(int CodigoReserva, int CodigoEstadia);
	DataReservaLight * ObtenerDataReserva(int CodigoReserva);
	DataCalificacion * ObtenerCalificacionAccHost(int CodigoReserva, int CodigoEstadia);
	//ComentarCalificacion
	IDictionary * ObtenerCalificacionSinRAccHostal();
	void AgregarComentarioCalificacionAccHost(int CodigoEstadia, std::string comentario);
	//
	IDictionary *getDatosHostalprueba();
	DataHostal *getDataPrueba();
	//
	DataHostalLight* getDataL();

	ICollection* ObtenerHab();
	IDictionary* getHabitacionesDisp(DTFecha* FechaCheckIn, DTFecha* FechaCheckOut);
	DataReservaLight* crearReserva(int numeroHab, DTFecha* FechaCheckIn, DTFecha* FechaCheckOut);
	void ConfirmarReserva(Reserva* res);
/*

  

  
  Data HostalLight getHabitaciones() 
  Set DataHabitacion getHabitacionesDisp(FechaCheckIn DTFecha, FechaCheckOut DTFecha)
  DataReserva GetReserva(CodigoReserva Int) 
  set DataReserva getReservas(EmailUsuario string)
  ConfirmarReserva()
  Set DataEstadia ConseguirEstadias()

  DataEstadiaExtra ObtenerEstadias(CodigoEstadia Int)
  DataCalificacion ObtenerCalificacion(CodigoReserva Int, CodigoEstadia Int)
  Set(DataCalificacion) ObtenerCalificacionAccederHostal() 
  AgregarComentarioAccederHostal(CodigoCalficacion int, Respuesta string)
  Set DataReserva ObtenerReservasHostalAccederHostal()
  EliminarReservaAccederHostal(CodigoReserva int)
  ConfirmarEliminarReserva(CodigoReserva int)
  Set (DataEstadia) ObtenerEstadiasFinalizadasAccHost(EmailUsuario string)
  Set(DataEstadia) ObtenerEstadiaAbAccHost(EmailUsuario string)

 FinalizarEstadiaAccHost(CodigoEstadia int, FechaCheckOut DataFecha)

 CalificarEstadiaAccHost(CodigoEstadia int, Califica int, Comentario string)
 

 CancelarCalificacionAccHost()
*/
};

#endif