#ifndef InterfazHostal_H
#define InterfazHostal_H

#include "string.h"
#include "../Datatypes/Datatypes.h"
#include "../ico.h"

class InterfazHostal {
public:
	//***************************************************************************************************************************************************
	virtual void altaHostal(string nombreHostal, string direccion, string telefono) = 0;
	virtual IDictionary* ObtenerHostales() = 0;
	virtual IDictionary * ListarHostal() = 0; //PENDIENTE A REVISION
	//virtual Listarhostales(nombrehostal) = 0;
			////////////////////////////~AltaHabitacion////////////////////////////
	virtual bool ExisteHabitacion(int numero) = 0;
	virtual bool ingresoDataHab(int numero, std::string nombreHostal) = 0; // CONFIRMA SI EXISTE LA HAB, LA DE ARRIBA TA MAL CREO
	virtual void ConfirmarAltaHabitacion(float precio, int capacidad) = 0;
			////////////////////////////ConsultarReserva////////////////////////////
	virtual DataReserva * ObtenerReservasHostal(std::string NombreHostal, int CodigoReserva) = 0;
    		////////////////////////////ConsultaHostal////////////////////////////
	virtual DataHostal * InformacionHostal(std::string NombreHostal) = 0;
			/////////////////////////////RegistrarEstadia////////////////////////////
	virtual IDictionary * ObtenerReservas(std::string NombreHostal, std::string EmailHuesped) = 0;
	virtual void CrearCheckIn(std::string NombreHostal, int codigoReserva, DTFecha *FechaCheckin, std::string Promo) = 0;
			////////////////////////////FinalizarEstadia////////////////////////////
	virtual DataEstadia * ObtengoEstadiasAb(std::string NombreHostal, std::string EmailHuesped) = 0;
	virtual void FinalizarEstadia(int CodigoEstadia, int CodigoReserva, DTFecha *FechaCheckOut) = 0;
			////////////////////////////BajaReserva////////////////////////////
	virtual void EliminarReserva(std::string NombreHostal, int CodigoReserva) = 0;
			////////////////////////////ConsultarEstadia////////////////////////////
	virtual IDictionary * ObtenerDataEstadiaBasica(std::string NombreHostal) = 0;
	virtual DataEstadiaExtra * ObtenerDataEstadiaExtra(std::string NombreHostal, int CodigoReserva, int CodigoEstadia) = 0;
	virtual DataReservaLight * ObtenerInfoReserva(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia) = 0;
	virtual DataCalificacion * ObtenerCalificacion(std::string NombreHostal, std::string EmailUsuario, int CodigoReserva, int CodigoEstadia) = 0;
			////////////////////////////ComentarCalificacion////////////////////////////
	virtual IDictionary * ObtenerCalificacionesSinRespuesta(std::string NombreHostal) = 0;
    virtual void AgregarComentarioCalificacion(std::string NombreHostal, int CodigoEstadia, std::string comentario) = 0;
			////////////////////////////ModificarFechaSistema////////////////////////////
	virtual IDictionary* ListarHabitacionDisponible(string nombreHostal, DTFecha *FechaCheckIn, DTFecha *FechaCheckOut) = 0;

	//***************************************************************************************************************************************************
};

#endif